#pragma once
#include<vector>
#include <string>
#include <iostream>
using namespace std;

template<class K>
struct HashFunc
{
    size_t operator()(const K& key) const {
        return (size_t)key;
    }
};

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
    template<class T>
    struct HashNode {
        T _data;
        HashNode<T>* _next = nullptr;
        HashNode(const T& data, HashNode<T>* next) : 
        _data(data), 
        _next(next)
         {}
    };
    
    // 前置声明 HashTable 类
    template<class K,class T,class KeyOfT,class Hash>
    class HashTable;

    template<class K,class T,class KeyOfT,class Hash>
    struct _HTIterator {
        typedef HashNode<T> Node;
        typedef _HTIterator<K, T, KeyOfT, Hash> Self;
        Node* _node;
        HashTable<K, T, KeyOfT, Hash>* _pht;

        _HTIterator(Node* node, HashTable<K, T, KeyOfT, Hash>* pht) 
        : _node(node), 
        _pht(pht) 
        {}

        Self& operator++() {
            // 当前链表还有下一个节点
            if (_node->_next) {
                _node = _node->_next;
                return *this;
            }

            KeyOfT kot;
            Hash hs;

            size_t start =
                hs(kot(_node->_data)) % _pht->_tables.size();

            size_t hash = start+1;

            // 查找后面的非空桶
            while (hash < _pht->_tables.size() && !_pht->_tables[hash]) {
                hash++;
            }

            if (hash == _pht->_tables.size()) {
                // 已经遍历完所有桶
                _node = nullptr;
            } else {
                // 移动到下一个非空桶的头节点
                _node = _pht->_tables[hash];
            }
            return *this;
        }

        bool operator!=(const Self& other) const {
            return _node != other._node;
        }
        
        T& operator*() const {
            return _node->_data;
        }

        T* operator->() const {
            return &_node->_data;
        }
    };
    


    template<class K,class T,class KeyOfT,class Hash = HashFunc<K>>
    class HashTable {
    public:
        //声明 _HTIterator 为友元，使其可以访问 HashTable 的私有成员
        //后面的四个 class 是四个模板参数，
        //只是因为在友元声明中不需要使用它们的名字，所以省略了参数名。
        template<class ,class ,class ,class >
        friend struct _HTIterator;

        HashTable() {
            _tables.resize(10,nullptr);
        }
        typedef _HTIterator<K, T, KeyOfT, Hash> iterator;
        iterator begin() {
            for (size_t i = 0; i < _tables.size(); ++i) {
                if (_tables[i]) {
                    return iterator(_tables[i], this);
                }
            }
            return end();
        }

        iterator end() {
            return iterator(nullptr, this);
        }

        typedef HashNode<T> Node;

        ~HashTable() {
            for(size_t i = 0; i < _tables.size(); ++i) {
                Node* cur = _tables[i];
                while (cur) {
                    Node* next = cur->_next;
                    delete cur;
                    cur = next;
                }
                _tables[i] = nullptr;// 清空桶指针，防止悬空指针
            }
        }

    bool insert(const T& data) {
        KeyOfT kot;
        if(find(kot(data))) {
            return false;
        }

        Hash hs;
        //扩容
        if (_n >= _tables.size()) {
            vector<Node*> new_tables(_tables.size() * 2, nullptr);// 新的桶数组，大小是原来的两倍，每个桶位置初始化为空指针
            for (auto node : _tables) {//这里的node类型是 Node*
                while (node) {
                    Node* next = node->_next;// 保存下一个节点，防止修改链表指针后丢失
                    size_t hash = hs(kot(node->_data)) % new_tables.size();// 重新计算新表哈希值
                    node->_next = new_tables[hash];// 将节点插入到新桶的链表头部
                    new_tables[hash] = node;
                    node = next;// 继续处理下一个节点
                }
            }
            _tables.swap(new_tables);//_tables 变成扩容后的新桶数组,new_tables 变成旧桶数组；new_tables 随函数结束自动销毁。
        }

        size_t hash = hs(kot(data)) % _tables.size();

        Node* cur = _tables[hash];

        // 查找是否存在相同 key
        while (cur) {
            if (kot(cur->_data) == kot(data)) {
                return false;
            }

            cur = cur->_next;
        }

        // 头插新节点
        Node* node = new Node{data, _tables[hash]};
        _tables[hash] = node;

        ++_n;
        return true;
        }

        Node* find(const K& key) {
            KeyOfT kot;
            Hash hs; 
            size_t hash = hs(key) % _tables.size();
            Node* cur = _tables[hash];
            while (cur) {
                if (kot(cur->_data) == key) {
                    return cur;
                }
                cur = cur->_next;
            }
            return nullptr;
    }

    bool Erase(const K& key) {
        KeyOfT kot;
        Hash hs;    
        size_t hash = hs(key) % _tables.size();
        Node* cur = _tables[hash];
        Node* prev = nullptr;
        while (cur) {
            if (kot(cur->_data) == key) {
                if (prev) {
                    prev->_next = cur->_next;
                } else {
                    _tables[hash] = cur->_next;
                }
                delete cur;
                --_n;
                return true;
            }
            prev = cur;
            cur = cur->_next;
        }
        return false;
    }

    private:
        vector<Node*> _tables;
        size_t _n = 0; // 有效数据个数
    };

    // void TestHash1(){
    //     HashTable<int, int> ht;
    //     int arr[]={1,2,3,4,5,6,11,92,7,8,28,31,41};
        
    //     for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
    //         ht.insert({arr[i], arr[i]});
    //     }
        
    //     ht.Erase(1); // 删除键为 1 的元素
    //     ht.Erase(11); // 删除键为 11 的元素
    //     ht.Erase(31); // 删除键为 31 的元素
    //     ht.Erase(41); // 删除键为 41 的元素
    // }

}

