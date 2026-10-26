#pragma once
#include "RBTree.h"
#include <iostream>
using namespace std;
namespace Myset {
    template<typename K>
    class Set {
        struct SetKeyOfT {
            const K& operator()(const K& key) const {
                return key;
            }
        };
    public:
        bool insert(const K& key) {
            return _t.Insert(key).second;
        }
        
    private:
        RBTree<K, K, SetKeyOfT> _t;

    public:
        typedef typename RBTree<K, K, SetKeyOfT>::Iterator Iterator;
        typedef typename RBTree<K, K, SetKeyOfT>::ConstIterator ConstIterator;
        Iterator begin() {
            return _t.Begin();
        }

        Iterator end() {
            return _t.End();
        }

        Iterator find(const K& key) {
            return _t.Find(key);
        }


        ConstIterator begin() const {
            return _t.Begin();
        }

        ConstIterator end() const {
            return _t.End();
        }

        ConstIterator find(const K& key) const {
            return _t.Find(key);
        }
    };

    void PrintSet(const Set<int> &s) {
        for(auto e: s)
            cout << e << " ";
        cout << endl;
    }

    void test_set() {
        Set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(9);
        s.insert(7);
        s.insert(19);
        s.insert(7);
        Set<int>::Iterator it = s.begin();
        while (it != s.end()) {
            cout << *it << " ";
            ++it;
        }
        for(auto e: s) {
            cout << e << " ";
        }
        PrintSet(s);

        Set<int> s2=s;
        for(auto e: s2) {
            cout << e << " ";
        }
        PrintSet(s2);
        cout << endl;
    }
}
		