#define _CRT_SECURE_NO_DEPRECATE

#pragma once
#include <iostream>
#include<assert.h>
#include <cstring>
using namespace std;
namespace wxy
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		/*string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}*/

		//下面这种全缺省的，既可以传参，有可以不传参
		string(const char* str="")//这里要给""表示一个空字符串，如果你给'\0'则是char类型，没办法赋给char*类型
			:_size(strlen(str))//上面const char* str如果用nullptr初始化，这里没办法strlen
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy_s(_str, _capacity+1,str);
		}

		//拷贝构造
		string(const string& s)
		{
			_str = new char[s._capacity + 5];
			strcpy_s(_str,s._size+1,s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		//析构函数
		~string()
		{
			delete[] _str;//c++中更推荐new和delete
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		const char* c_str()
		{
			return _str;
		}

		//遍历
		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);//断言，防止越界
			return _str[pos];//_str是new出来的，变量在堆上，出了作用域仍然存在，可以用引用返回
		}

		const char& operator[](size_t pos) const
		{
			//返回类型前的const：表示返回一个常引用，也就是通过这个操作符返回的引用不能用于修改字符串中的字符
			//eg：
			//const wxy::string s("hello");
			//char ch = s[0];       // 可以读取
			//s[0] = 'H';           // 编译错误，因为返回的是 const char&，不能修改字符

			//返回类型后的const：表示这个成员函数为常量成员函数，在这个函数内部不能修改类的成员变量，这意味着该函数可以被const对象调用
			//eg：
			//const wxy::string s("hello");
			//char ch = s[0];  // 可以调用，因为 operator[] 是 const 成员函数




			assert(pos < _size);//断言，防止越界
			return _str[pos];//_str是new出来的，变量在堆上，出了作用域仍然存在，可以用引用返回
		}

		void reserve(size_t n)//当前_capacity扩容到n个空间
		{
			if (n > _capacity)
			{
				char* tmp = new char[n];//开新空间
				strcpy_s(tmp, _capacity+1,_str);//拷贝数据
				//strcpy_s（char *strDestination, size_t numberOfElements, const char *strSource）:
				//第一个参数：目标字符串的指针
				//第二个参数：需要拷贝的元素个数
				//第三个参数：源字符串的指针
				delete[] _str;//释放旧空间
				_str = tmp;//指针指向新空间

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			//扩容
			if (_size == _capacity-1|| _size == _capacity)
			{
				reserve(_capacity==0 ? 4 : 2 * _capacity);
			}

			_str[_size] = ch;//新字符放进去
			_size++;
			_str[_size] = '\0';//标志字符串结尾

		}

		void append(const char* str)
		{
			// 计算要追加的字符串长度
			size_t len = strlen(str);

			// 检查是否需要扩容
			if (_size + len > _capacity)
			{
				// 扩容到可以容纳现有字符串加上新字符串的长度
				reserve(_size + len+1);//这里扩容不好用2*capacity，因为你不知道加过来的字符串有多长，如果长度很长，这里扩容就失效了
			}

			// 拷贝新字符串到现有字符串末尾
			// 注意这里的 _capacity - _size + 1 为目标缓冲区剩余空间
			strcpy_s(_str + _size, len+1 , str);

			// 更新 _size，使其包括新追加的字符串长度
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, char ch)//size_t>=0
		{
			assert(pos <= _size);//pos=_size时是尾插
			//扩容
			if (_size == _capacity - 1 || _size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			int end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				end--;
				if (end == -1)//如果不加这个if，后面end=-1和pos=0比的时候,-1会大于0，因为这里运算符两边类型不同，会发生类型提升，变成无符号数进行比较
				{//还有一种办法，你在while里面比较的时候加一个强转，强转成两个Int比较
					break;
				}
			}

			_str[pos] = ch;
			_size++;

		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);//pos=_size时是尾插
			int len=strlen(str);//获取要插入字符串的长度
			if (_size+len>=_capacity)
			{
				reserve(_size + 2*len);//扩容到_size + len + 1
			}

			int end = _size;
			while (end >= (int)pos)//插入位置后的原字符串部分后移len个
			{
				int posnew = end + len;
				_str[posnew] = _str[end];
				end--;
			}

			memcpy(_str + pos,str, len);//新加入字符串的拷贝进原字符串
			//memcpy 只会按照指定的字节数进行复制，不会自动加上 \0。
			//如果这里用strcpy_s,会把str最后的\0也复制进去，这与我们的逻辑相悖

			//更新字符串大小
			_size = _size + len;

		}

		void erase(size_t pos, size_t len = npos)//从pos位置删len个字符
		{
			assert(pos < _size);//这里删除，不需要考虑\0——\0不需要你删除

			//如果len给的npos，则意味着从pos位置开始到字符串结尾全部删除
			if (len == npos||len>= _size-pos)
			{
				_str[pos] = '\0';//后续扫描str,扫到\0就默认结束了
				_size = pos;
			}
			else
			{
				strcpy_s(_str + pos, _size-pos-len+1, _str + pos + len);
				_size -= len;
			}
		}


		void resize(size_t n, char ch = '\0')//重新划大小，如果比原来小就删，比原来大就用字符ch填充
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n+1);//如果n比capacity小，啥也不会做；n比capacity大，则会扩容
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}

		string& operator=(const string& s)
		{
			char* tmp = new char[s._capacity + 1];
			strcpy_s(tmp, s._size + 1, s._str);
			delete[] _str;//删s1原先的空间
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
		static const int npos;
	};

	const int string::npos = -1;//静态成员变量，属于整个类，属于每个对象

	void test1()
	{
		string s1("hello world");//传参
		string s2;//不传参

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i]++ << " ";//s1[i]可写
		}

		
		cout << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";//s1[i]可读
		}

		cout << endl;
		//s1[100];//这里越界，会断言报错


		const string s3("xxx");
		for (size_t i = 0; i < s3.size(); i++)
		{
			cout << s3[i] << " ";//const对象只能调用const成员函数
			//const对象只可读，不能写
		}
	}

	void test2()
	{
		string s1("hello");
		string::iterator it = s1.begin();//迭代器
		while (it != s1.end())
		{
			cout << *it << " ";//可读
			it++;
		}

		cout << endl;
		it = s1.begin();
		while (it != s1.end())
		{
			*it -= 1;//可写
			cout << *it << " ";//可读
			it++;
		}

		cout << endl;

		for (auto ch : s1)//范围for,调用iterator begin()和iterator end()
		{
			cout << ch << " ";
		}

		cout << endl;

		const string s2("xxxx");
		for (auto ch : s2)//会调用const_iterator begin() const和const_iterator end() const
		{
			cout << ch << " ";
		}

	}


	void test3()
	{
		string s1("hello world");
		s1.push_back('w');
		s1.push_back('x');
		s1.push_back('y');
		cout << s1.c_str() << endl;

		cout << "-----" << endl;

		s1.append("hhhh");
		cout << s1.c_str() << endl;
	}


	void test4()
	{
		string s1("hello");

		s1 += "world";
		cout << s1.c_str() << endl;

		s1 += 'w';
		cout << s1.c_str() << endl;

		s1 += "xy";
		cout << s1.c_str() << endl;

		s1 += "1234567890";
		cout << s1.c_str() << endl;
	}


	void test5()
	{
		string s1 = "abcdefg";
		s1.insert(3, 'x');//3号下标插入x
		cout << s1.c_str() << endl;//helxlo

		s1.insert(6, 'y');//尾插（pos==size情况）
		cout << s1.c_str() << endl;//helxloy

		s1.insert(0, 'w');//头插

		s1.insert(2, "wxy");
		cout << s1.c_str() << endl;
	}

	void test6()
	{
		string s1 = "hello world";
		s1.erase(2, 3);
		cout << s1.c_str() << endl;

		string s2 = "hello world";
		s2.erase(2);
		cout << s2.c_str() << endl;

		string s3 = "hello world";
		s3.erase(2, 30);
		cout << s3.c_str() << endl;
	}
	
	void test7()
	{
		string s1 = "hello world";
		s1.resize(3);
		cout << s1.c_str() << endl;//hel

		string s2 = "hello world";
		s2.resize(7,'x');//比原来的小，会删。填充字符只会在resize比原先字符大的情况使用
		cout << s2.c_str() << endl;

		string s3 = "hello world";
		s3.resize(20, 'x');//比原来的小，会删。填充字符只会在resize比原先字符大的情况使用
		cout << s3.c_str() << endl;
	}

	void test8()
	{
		string s1 = "hhhhwxy";
		string s2(s1);
		cout << s2.c_str() << endl;

		s1[2] = 'x';
		cout << s1.c_str() << endl;//修改s1不会影响s2
		cout << s2.c_str() << endl;

		cout << "--------" << endl;
		string s3 = s1;
		cout << s3.c_str() << endl;
		
	}
}
