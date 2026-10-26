#pragma once
#include <utility>
// 如果 RBTree 在其他头文件中，还需要包含它
 #include "RBTree.h"
#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "RBTree.h"
namespace Mymap
{
    template<typename K, typename V>
    class Map
    {
        struct MapKeyOfT
        {
            const K& operator()(const std::pair<const K, V>& kv) const
            {
                return kv.first;
            }
        };

    public:
        bool insert(const std::pair<const K, V>& kv)
        {
            return _t.Insert(kv).second;
        }

        //允许你像使用数组一样访问 map,例如 m["苹果"] = 2;
        //返回的是Value的引用，因此可以修改 value：m["苹果"] = 22;
        V& operator[](const K& key)
        {
            //typedef typename RBTree<K, std::pair<const K, V>, MapKeyOfT>::Iterator Iterator;
            Iterator it = find(key);
            if (it != end())
            {
                //key存在，直接返回对应的value的引用
                return it->second;
            }
            else
            {
                //key不存在，插入一个默认值的键值对,这里V=int，V()会生成0
                insert(std::make_pair(key, V()));
                // 再次查找新插入的键值对的迭代器
                it = find(key);
                return it->second;
            }
        }

    private:
        RBTree<K, std::pair<const K, V>, MapKeyOfT> _t;
    public:
        typedef typename RBTree<K, std::pair<const K, V>, MapKeyOfT>::Iterator Iterator;
        Iterator begin() {
            return _t.Begin();
        }

        Iterator end() {
            return _t.End();
        }

        Iterator find(const K& key) {
            return _t.Find(key);
        }

    };

    void test_map()
    {
        Map<std::string, int> m;

        m.insert(std::make_pair("苹果", 2));
        m.insert(std::make_pair("香蕉", 4));
        m.insert(std::make_pair("橘子", 3));

        Map<std::string, int>::Iterator it = m.begin();
        while (it != m.end()) {
            std::cout << it->first << ": " << it->second << std::endl;
            ++it;
        }
    }
    void test_map2()
    {
        Map<std::string, int> m;
        m.insert(std::make_pair("苹果", 2));
        m.insert(std::make_pair("香蕉", 4));
        m.insert(std::make_pair("橘子", 3));
        m.insert(std::make_pair("苹果", 5));
        m.insert(std::make_pair("苹果", 6));
        m.insert(std::make_pair("橘子", 1));

        Map<std::string, int>::Iterator it = m.begin();
        while (it != m.end()) {
            std::cout << it->first << ": " << it->second << std::endl;
            ++it;
        }
        //这里依旧打印,重复键不会覆盖原来的值
        //橘子: 3
        //苹果: 2
        //香蕉: 4
    }

    void test_map3()
    {
        //词频统计
        Map<std::string, int> m;
        string arr[] = {"苹果", "香蕉", "橘子","苹果", "香蕉","苹果"};
        for (const auto& s : arr) {
            m[s]++;
        }
        Map<std::string, int>::Iterator it = m.begin();
        while (it != m.end()) {
            std::cout << it->first << "词频: " << it->second << std::endl;
            ++it;
        }
    }
}