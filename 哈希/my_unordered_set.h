#pragma once
#include "HashTable.h"
namespace wxy{
    template<class K, class Hash = HashFunc<K>>
    class unordered_set {
        private:
        struct SetKeyOfT{
            const K& operator()(const K& key) const {
                return key;
            }
        };
        hash_bucket::HashTable<K, K, SetKeyOfT, Hash> _ht;

        public:
        typedef typename hash_bucket::HashTable<K, K, SetKeyOfT, Hash>::iterator iterator;
        iterator begin() {
            return _ht.begin();
        }

        iterator end() {
            return _ht.end();
        }



        bool insert(const K& key) {
            return _ht.insert(key);
        }
        bool erase(const K& key) {
            return _ht.Erase(key);
        }
        bool find(const K& key) {
            return _ht.find(key);
        }
        
    };
    void test_unordered_set() {
        unordered_set<int> us;
        us.insert(1); // 示例插入操作
        us.insert(2); // 示例插入操作
        us.insert(3); // 示例插入操作
        for (auto it = us.begin(); it != us.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}