#pragma once
#include<vector>
#include <string>
#include <iostream>
using namespace std;

namespace open_address {
enum class State {
        EMPTY,
        OCCUPIED,
        DELETED
    };

template<class K,class V>
struct HashData {
    pair<K, V> data;
    State _state=State::EMPTY;
};

template<class K>
struct HashFunc
{
    size_t operator()(const K& key) const {
        return (size_t)key;
    }
};

struct StringHashFunc
{
    size_t operator()(const string& key) const {
        size_t hash = 0;
        //StringHashFunc 的映射规则可以自己定义。
        //下面是BKDR Hash算法的实现
        for(char c : key) {
            hash = hash * 131 + c;
        }
        return hash;
    }
};

template<class K,class V,class Hash=HashFunc<K>>
class HashTable {
    public:
        HashTable()
        {
            _tables.resize(8);
            for(auto& item : _tables) {
                item._state = State::EMPTY;
            }
        }

        HashData<K, V>* find(const K& key) {
            size_t hashi = _hash(key) % _tables.size();
            size_t start = hashi;
            do {
                if(_tables[hashi]._state == State::OCCUPIED && _tables[hashi].data.first == key) {
                    return &_tables[hashi];
                }
                hashi = (hashi + 1) % _tables.size();
            } while(hashi != start);
            return nullptr;
        }

        bool Erase(const K& key) {
            HashData<K, V>* item = find(key);
            if(item) {
                item->_state = State::DELETED;
                _n--;
                return true;
            }
            return false;
        }

        bool insert(const pair<K, V>& kv) {
            // 检查是否已经存在相同的键, 如果存在则直接返回 false
            if(find(kv.first)) {
                return false;
            }

            //扩容(扩容后原有的值不能直接拷贝，需要重新计算哈希位置，重新插入到新的哈希表中)
            if(_n*10 / _tables.size() > 7) {
                // 扩容逻辑
                vector<HashData<K, V>> new_tables(_tables.size() * 2);
                for(auto& item : new_tables) {
                    item._state = State::EMPTY;
                }
                for(auto& item : _tables) {
                    if(item._state == State::OCCUPIED) {
                        size_t hashi = _hash(item.data.first) % new_tables.size();
                        size_t start = hashi;
                        do {
                            if(new_tables[hashi]._state == State::EMPTY) {
                                new_tables[hashi] = item;
                                break;
                            }
                            hashi = (hashi + 1) % new_tables.size();
                        } while(hashi != start);
                    }
                }
                _tables = move(new_tables);
            }

            //线性探测
            size_t hashi=_hash(kv.first)%_tables.size();
            size_t start=hashi;
            do {
                if(_tables[hashi]._state==State::EMPTY || _tables[hashi]._state==State::DELETED) {
                    _tables[hashi].data=kv;
                    _tables[hashi]._state=State::OCCUPIED;
                    _n++;
                    return true;
                }
                hashi=(hashi+1)%_tables.size();
            } while(hashi!=start);
            return false;
        }

        void Print() const {
            for(auto& item : _tables) {
                if(item._state == State::OCCUPIED) {
                    cout << item.data.first << " : " << item.data.second << endl;
                }
            }
        }
    private:
        vector<HashData<K, V>> _tables;
        size_t _n=0;//有效数据个数
        Hash _hash;
    };
    
    void TestHash1(){
    HashTable<int, string> ht;
    ht.insert({1, "one"});
    ht.insert({2, "two"});
    ht.insert({3, "three"});
    ht.insert({3, "three1"});// 尝试插入重复的键，应该返回 false
    try {
        auto* item = ht.find(2);
        if(item) {
            cout << item->data.second << endl;
        }
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    ht.Erase(2);
    try {
        auto* item = ht.find(2);
        if(item) {
            cout << item->data.second << endl;
        }
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    ht.Print();
}

    void TestHash2(){
        //key不支持默认哈希函数，需要提供自定义哈希函数
        HashTable<string, string, StringHashFunc> ht;
        ht.insert({"one", "1"});
        ht.insert({"two", "2"});
        ht.insert({"three", "3"});
        ht.Print();
    }
}

namespace hash_bucket{
    template<class K,class V>
    struct HashNode {
        pair<K, V> _kv;
        HashNode* _next = nullptr;
    };

    template<class K,class V>
    class HashTable {
    public:
        HashTable() {
            _tables.resize(10,nullptr);
        }
        typedef HashNode<K, V> Node;

    bool insert(const pair<K, V>& kv) {
    //扩容
    if (_n >= _tables.size()) {
        vector<Node*> new_tables(_tables.size() * 2, nullptr);
        for (auto node : _tables) {
            while (node) {
                Node* next = node->_next;
                size_t hash = node->_kv.first % new_tables.size();
                node->_next = new_tables[hash];
                new_tables[hash] = node;
                node = next;
            }
        }
        _tables.swap(new_tables);
    }

    size_t hash = kv.first % _tables.size();

    Node* cur = _tables[hash];

    // 查找是否存在相同 key
    while (cur) {
        if (cur->_kv.first == kv.first) {
            return false;
        }

        cur = cur->_next;
    }

    // 头插新节点
    Node* node = new Node{kv, _tables[hash]};
    _tables[hash] = node;

    ++_n;
    return true;
}

    Node* find(const K& key) {
        size_t hash = key % _tables.size();
        Node* cur = _tables[hash];
        while (cur) {
            if (cur->_kv.first == key) {
                return cur;
            }
            cur = cur->_next;
        }
        return nullptr;
    }
    private:
        vector<Node*> _tables;
        size_t _n = 0; // 有效数据个数
    };
}

