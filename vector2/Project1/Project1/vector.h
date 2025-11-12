#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

namespace wxy
{
    template<class T>
    class vector
    {
    public:
        typedef T* iterator;

        typedef const T* const_iterator;

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }


        vector() : _start(nullptr), _finish(nullptr), _endofstorage(nullptr) {}


        vector(const vector<T>& v)//拷贝构造
        {
            reserve(v.capacity());
            for (auto& e : v)
            {
                push_back(e);
            }
        }

        //vector<int> v1={1,2,3,4}
        vector(initializer_list<T> il)
        {
            reserve(il.size());
            for (auto& e : il)
            {
                push_back(e);
            }
        }

        //类模板的成员函数可以是函数模板
        template <class InputIterator>
        vector(InputIterator first, InputIterator last)//区间构造函数
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        vector(size_t n,const T& val=T())//用n个val去初始化
        {
            reserve(n);
            for (size_t i = 0; i < n; i++)
            {
                push_back(val);
            }
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endofstorage, v._endofstorage);
        }

        vector<T>& operator=(vector<T> v)
        {
            swap(v);//这里隐藏了this
            return *this;
        }


        ~vector()
        {
            delete[] _start;
            _start = _finish = _endofstorage = nullptr;
        }

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _endofstorage - _start;
        }

        T& operator[](size_t pos)
        {
            assert(pos < size());
            return _start[pos];
        }

        const T& operator[](size_t pos) const
        {
            assert(pos < size());
            return _start[pos];
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                T* tmp = new T[n];
                size_t old_size = size();
                /*memcpy(tmp, _start, size() * sizeof(T));*/ //这里如果只是拷贝int那种简单类型没问题，但是如果是拷贝string等一些复杂类型会出现浅拷贝，导致后面释放空间释放两次
                for (size_t i = 0; i < old_size; i++)
                {
                    tmp[i] = _start[i];
                }
                delete[] _start;

                _start = tmp;
                _finish = tmp + old_size;
                _endofstorage = tmp + n;

            }
        }
        //浅拷贝：浅拷贝在复制对象时，只是按位复制（bitwise copy） 对象的成员变量。

        /*如果对象中有 指针成员，浅拷贝只会复制指针的值（即地址），而不是复制指针指向的内容。

        因此，原对象和新对象会指向同一块内存区域。

        当一个对象释放内存后，另一个对象的指针会变成“悬空指针”，容易导致重复释放（double free） 或 程序崩溃。*/

        //深拷贝：深拷贝在复制对象时，除了复制普通成员，还会为指针成员重新分配内存并复制内容。
        /*这样两个对象的内存是独立的。

        修改一个对象不会影响另一个对象。

        不会出现重复释放的问题。*/


        void resize(size_t n, const T& val = T())//const T& val = T()用匿名对象表示缺省值
        {//重置大小（少了用val填充，多了则删除）
            if (n > size())
            {
                //插入
                reserve(n);//重置容量到n
                while (_finish < _start + n)
                {
                    *_finish = val;
                    ++_finish;
                }
            }
            else
            {
                //删除
                _finish = _start + n;
            }
        }

        void push_back(const T& val)
        {
            //if (_finish == _endofstorage) // 满了，需要扩容
            //{
            //    size_t old_size = size();
            //    size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
            //    T* tmp = new T[newcapacity];
            //    for (size_t i = 0; i < size(); ++i)
            //    {
            //        tmp[i] = _start[i];
            //    }
            //    delete[] _start;

            //    _start = tmp;
            //    _finish = tmp + old_size;
            //    _endofstorage = tmp + newcapacity;
            //}
            //*_finish = val; // 尾部插入数据
            //++_finish;      // 已有数据量+1

            insert(end(), val);
        }

        bool empty()
        {
            return _start == _finish;
        }

        void pop_back()
        {
            assert(!empty());//看一下是不是非空（还有东西可出）
            --_finish;
        }

        void insert(iterator pos, const T& val)
        {
            assert(pos >= _start);
            assert(pos <= _finish);

            if (_finish == _endofstorage)
            {
                size_t len = pos - _start;//记录一下扩容前，pos的位置（扩容后，原先pos指向的被销毁了）
                reserve(capacity() == 0 ? 4 : capacity() * 2);
                //如果扩容需要更新pos
                pos = _start + len;
            }
            iterator it = _finish - 1;
            while (it >= pos)
            {
                *(it + 1) = *it;
                it--;
            }
            *pos = val;
            ++_finish;
        }

        void erase(iterator pos)//删除pos位置的值
        {
            assert(pos >= _start);
            assert(pos < _finish);
            iterator it = pos + 1;
            while (it < _finish)
            {
                *(it - 1) = *it;
                it++;
            }
            _finish--;
        }

        

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    };

    template<class T>
    void print_vector(const vector<T>& v)
    {
        for (size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        /* vector<int>::const_iterator it= v.begin();
         while (it != v.end())
         {
             cout << *it << " ";
             it++;
         }

         cout << endl;

         for (auto e : v)
         {
             cout << e << " ";
         }*/

    }

    void test1()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);

        for (size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void test2()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        vector<int>::iterator it = v.begin();

        while (it != v.end())
        {
            cout << *it << " ";
            it++;
        }

        cout << endl;

        for (auto e : v)
        {
            cout << e << " ";
        }

    }

    void test3()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        print_vector(v);
    }

    void test4()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        v1.push_back(6);
        print_vector(v1);

        vector<double> v2;
        v2.push_back(1.1);
        v2.push_back(2.2);
        v2.push_back(3.3);
        v2.push_back(4.4);
        v2.push_back(5.5);
        v2.push_back(6.6);
        print_vector(v2);

    }

    void test5()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.insert(v1.begin(), 0);
        v1.insert(v1.begin()+2, 10);
        print_vector(v1);
    }

    void test6()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.erase(v1.begin());
        print_vector(v1);

        v1.pop_back();
        print_vector(v1);
    }

    void test7()
    {
        int i = 1;
        int j = int();
        int k = int(2);

        cout << i << " " << j << " " << k;//1,0,2
        //内置类型也可以用对象初始化
    }

    void test8()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);

        v1.resize(2);
        print_vector(v1);//1 2

        v1.resize(8, 1);
        print_vector(v1);//1 2 1 1 1 1 1 1

    }

    void test9()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        
        vector<int> v2(v1);//用v1拷贝构造v2
        print_vector(v2);//1 2 3 4
    }

    void test10()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        vector<int> v2 = v1;
        print_vector(v2);//1 2 3 4
    }

    void test11()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        vector<int> v2(v1.begin(), v1.end());//区间拷贝构造
        print_vector(v2);//1 2 3 4

        vector<int> v3(v1.begin()+1, v1.end()-1);//区间拷贝构造
        print_vector(v3);//2 3

        string str("abcd");
        vector<int> v4(str.begin() + 1, str.end() - 1);//这里区间拷贝构造是模板，可以用str，会转换成ASCII码（因为vector<int>，存的是int类型）
        print_vector(v4);//98 99
    }

    void test12()
    {
       /* vector<int> v1(10, 1);
        print_vector(v1);*/
        //10是int，1也是int
        // 编译器看到两个构造函数 
        // 1.区间构造函数vector(InputIterator first, InputIterator last) 2.填充值构造vector(size_t n,const T& val=T()) 都可以匹配
        //这里编译器就会报错“10 和 1 是不是两个迭代器？还是要我建 10 个 1？”
        


        vector<int> v1(10u, 1);//10u表示10个unsigned int
        print_vector(v1);//1 1 1 1 1 1 1 1 1 1

        vector<int> v2(10, 'a');
        print_vector(v2);//97 97 97 97 97 97 97 97 97 97
    }

    void test13()
    {
        auto x = { 1,2,3,4,5 };
        cout << typeid(x).name() << endl;//class std::initializer_list<int>
        cout << sizeof(x) << endl;//16
        initializer_list<int> y = { 1,2,3,4,5,6,7 };


        //单参数的构造函数，隐式类型转换
        string str = "12345";//这里是构造+拷贝构造，会优化成直接构造
        const string& str1 = "12345";//构造临时对象，引用的是临时对象
        vector<string> v;
        v.push_back(str);
        v.push_back(string("222"));
        v.push_back("333");
        for (auto e : v)
        {
            cout << e << " ";//12345 222 333
        }

        //隐式类型转换+优化
        vector<int> v1 = { 7,7,7,7,7 };
        for (auto e : v1)
        {
            cout << e << " ";//7 7 7 7 7 
        }


        std::vector<int> v2{ 1,2,3,4,5,6 };
        for (auto e : v2)
        {
            cout << e << " ";//1 2 3 4 5 6
        }
    }

    void test14()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        print_vector(v1);//1 2 3 4
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        vector<int>::iterator it = v1.begin() + 3;
        v1.insert(it, 40);
        print_vector(v1);//1 2 3 40 4 1 2 3 4 1 2 3 4
        //ps:有的编译器上，在insert之后，it会失效，所以尽量在insert之后不要再用*it
        cout << *it << endl;//40

    }

    void test15()
    {
        std::vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        //删除偶数
        std::vector<int>::iterator it = v1.begin();
        while (it != v1.end())
        {
             if (*it % 2 == 0)
            {
                it=v1.erase(it);
            }
            else
            {
                it++;
            }
           }
    }
}


