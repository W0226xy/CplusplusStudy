#pragma once
#include "HashTable.h"

namespace wxy{
    template<class K, class V, class Hash = HashFunc<K>>
    class unordered_map {
        private:
        struct MapKeyOfT{
            const K& operator()(const pair<K, V>& kv) const {
                return kv.first;
            }
        };  
        hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT, Hash> _ht;

        public:
        //因为这里的 HashTable<...> 是一个依赖模板参数的类型
        // 需要使用 typename 来告诉编译器这是一个类型，而不是静态成员
        typedef typename hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT, Hash>::iterator iterator;
        iterator begin() {
            return _ht.begin();
        }
        iterator end() {
            return _ht.end();
        }

        bool insert(const pair<K, V>& kv) {
            return _ht.insert(kv);
        }
        bool erase(const K& key) {
            return _ht.Erase(key);
        }
        bool find(const K& key) {
            return _ht.find(key);
        }
        
        
    };

    void test_unordered_map() {
        unordered_map<int, int> um;
        um.insert({1, 1}); // 示例插入操作
        um.insert({2, 2}); // 示例插入操作
        um.insert({3, 3}); // 示例插入操作
        for (auto it = um.begin(); it != um.end(); ++it) {
            cout << it->first << " : " << it->second << endl;
        }
    }
}