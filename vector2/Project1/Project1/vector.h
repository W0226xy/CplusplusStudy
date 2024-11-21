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


        vector(const vector<T>& v)
        {
            reserve(v.capacity());
            for (auto& e : v)
            {
                push_back(e);
            }
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
                memcpy(tmp, _start, size() * sizeof(T));
                delete[] _start;

                _start = tmp;
                _finish = tmp + old_size;
                _endofstorage = tmp + n;

            }
        }

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
}


