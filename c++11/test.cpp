#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;


struct Point
{
	int _x;
	int _y;
};

class A
{
public:
	//explicit A(int x, int y)
	A(int x, int y)
		:_x(x)
		,_y(y)
	{}

	A(int x)
		:_x(x)
		,_y(x)
	{}
private:
	int _x;
	int _y;
};
// int main()
// {
//     int arr1[]={1,2,3,4};
//     int arr2[5]={0};
//     Point p={1, 2};

//     //a1,a2,a3用的是普通构造函数，
//     //这些写法虽然使用了 =，叫“拷贝初始化形式”，但实际是在直接构造 A 对象，并不是调用拷贝构造函数。
//     //单参数隐式转换
//     A a1 = {4}; // 调用 A(int)
//     A a2 = 5; // 调用 A(int)

//     //多参数隐式转换
//     A a3 = {1, 2}; // 调用 A(int, int)
    
    
    
//     //const A& a5 绑定到了一个临时的 A 对象。临时对象不能绑定到普通的 A&，但可以绑定到 const A&，并且临时对象的生命周期会延长到 a5 离开作用域。
//     const A& a4={1, 2}; // 调用 A(int, int)

//     //列表初始化，可以省略=
//     A a5{1, 2}; // 调用 A(int, int)
//     A a6{3};    // 调用 A(int)

//     //拷贝构造必须是用一个已有的 A 对象初始化另一个 A 对象
//     A a7 = a3; // 调用拷贝构造函数，a7是a3的副本

    
// }

// int main()
// {   
//     //隐式类型转化
//     vector<int> v1 = {1, 2, 3, 4};
//     vector<int> v2 (10,1);
//     //构造，直接初始化
//     vector<int> v3({1, 2, 3, 4});

//     auto il1={10,20,30};

//     //initializer_list 是 C++11 提供的“初始化列表类型”，专门用于保存一组同类型的初始值。
//     initializer_list<int> il2 = {40, 50, 60};
//     cout<<typeid(il1).name()<<endl;//St16initializer_listIiE
//     cout<<sizeof(il1)<<endl;//16
//     cout<<typeid(il2).name()<<endl;//St16initializer_listIiE
//     cout<<sizeof(il2)<<endl;//16

//      initializer_list<int> il3 = {40, 50, 60,70,80};

//     // 使用 initializer_list 初始化 vector，可以直接将 initializer_list 作为构造函数的参数传入。
//     vector<int> v4(il1); 
//     vector<int> v5(il3); 
//     // 使用 initializer_list 初始化 map
//     //可以理解为初始化列表中的每个元素都是一个 pair<const string, string>
//     //因为 map 的 key 不能被修改，所以标准库中的元素类型是：pair<const string, string>
//     map<string,string> m1 = {{"one", "1"}, {"two", "2"}, {"three", "3"}};

// }


// int main()
// {
// 	int i = 0;
// 	auto x = i;
// 	auto& x1 = i;
// 	x1++;
//     cout << x1 << endl;//1，类型 int&
//     cout << x << endl;//0，类型 int
//     cout << i << endl;//1

// 	int& j = i;
// 	auto y = j;
// 	auto& y1 = j;
//     cout << y1 << endl;//1，类型 int&
//     cout << y << endl;//1，类型 int
//     cout << j << endl;//1，类型 int&

// 	return 0;
// }

// int main()
// {
//     list<int>::iterator it1;
//     cout<<typeid(it1).name()<<endl;//输出 it1 的类型名称,St14_List_iteratorIiE
//     //typeid(it1).name() it2错误，不能直接用 it1 的类型初始化 it2，必须使用 decltype

//     decltype(it1) it2;
//     cout<<typeid(it2).name()<<endl;//输出 it2 的类型名称,St14_List_iteratorIiE

//     auto it3 = it1;
//     cout<<typeid(it3).name()<<endl;//输出 it3 的类型名称,St14_List_iteratorIiE
// }

// int main()
// {
//     map<string, string> m={{"one", "1"}, {"two", "2"}, {"three", "3"}};
//     for(const auto& p : m)
//     {
//         cout << p.first << " : " << p.second << endl;
//     }
//     // 效果和上面的 for(const auto& p : m) 是一样的
//     // 使用结构化绑定遍历 map，C++17 引入的特性，可以直接将 pair 的 key 和 value 绑定到两个变量上
//     for(auto [key, value] : m)
//     {
//         cout << key << " : " << value << endl;
//     }

//     pair<string, string> p = {"four", "4"};
//     auto [key, value] = p;
//     cout << key << " : " << value << endl;//four : 4
// }

// int main()
// {
//     //左值是一个表示数据的表达式，可以出现在赋值运算符的左边，可以取地址
//     int a=1;
//     int b=a;
//     const int c=1;
//     int*p=&a;
//     cout<<p<<endl; //0x7fffffffd7a4

//     cout<<&a<<endl;//0x7fffffffd7a4
//     cout<<&b<<endl;//0x7fffffffd7a8
//     cout<<&c<<endl;//0x7fffffffd7ac

//     //右值是一个表示数据的临时值，不能出现在赋值运算符的左边，不能取地址
//     cout << 1 + 2 << endl; // 3，1+2 是右值，不能取地址
//     //cout << & (1 + 2) << endl; // 错误，右值不能取地址
//     cout << (a + b) << endl; // 3，a+b 是右值，不能取地址
//     //cout << & (a + b) << endl; // 错误，右值不能取地址
//     cout<<string("123")<<endl; // 匿名对象string("123") 是右值，不能取地址
//     //cout << &string("123") << endl; // 错误，右值不能取地址

//     //给右值取别名
//     const int& r = a + b; // a+b 是右值，使用 const 引用给右值取别名
//     cout << r << endl; // 2
//     int&& rr = a + b; // a+b 是右值，使用右值引用给右值取别名
//     cout << rr << endl; // 2
//     string&& sr = string("123"); // 匿名对象 string("123") 是右值，使用右值引用给右值取别名
//     cout << sr << endl; // "123"

//     //右值引用给move后的左值取别名
//     int&& rrr = std::move(a); // std::move(a) 将左值 a 转换为右值，使用右值引用给其取别名
//     cout << rrr << endl; // 1
// }


// class Buffer {
// public:
//     Buffer(size_t n)
//         : _size(n)
//         , _data(new int[n])
//     {}

//     ~Buffer() {
//         delete[] _data;
//     }

//     // 移动构造
//     Buffer(Buffer&& other) noexcept//noexcept 表示该函数不会抛出异常
//         : _size(other._size)
//         , _data(other._data)
//     {
//         // 把资源转移给新对象
//         other._size = 0;
//         other._data = nullptr;
//     }

// private:
//     size_t _size;
//     int* _data;
// };

// int main()
// {
//     //右值引用的意义：可以延长右值的生命周期，避免不必要的拷贝，提高性能

//     //需要调用拷贝构造，把 a 中的一百万个元素复制到 b 的新空间中，代价很大。
// 	// Buffer a(1000000);
//     // Buffer b = a;

//     // 使用移动构造，这里不会重新申请并复制一百万个元素，而是直接把 a 的指针交给 b,速度非常快
//     Buffer a(1000000);
//     Buffer b = std::move(a);//std::move 把左值转换成一种可以被移动的右值引用类型。
//     //std::move(a),告诉编译器 a 后面不准备继续使用了，可以把它内部的资源转走。

//     string s1="11111111111111111111";
//     string s2=s1;// 拷贝构造，s2 会有一份 s1 的副本，s1的资源还在
//     string s3=std::move(s1);// 移动构造，s3 接管 s1 的资源，s1 变为空字符串

//     //右值引用本身是左值，只有右值引用本身处理成左值，才能实现移动构造和移动赋值
//     string&& s4 = string("1111"); // 右值引用绑定到临时对象，string&&，声明类型是右值引用，但是 s4 本身是一个左值，可以取地址
//     cout << s4 << endl; // 输出 "1111"
//     cout << &s4 << endl; // 输出 s4 的地址0x7fffffffd5e0
//     //cout << &string("1111") << endl; // string("1111")是一个临时对象，属于右值，不能直接取地址。这里会报错
// 	return 0;
// }

// int main()
// {
//     string s = "1111";
//     string&s1 = s;//左值引用
//     string&& s2 = std::move(s);//右值引用，s2本身是左值
// }


// // 完美转发示例
// void Fun(int& x) { cout << "左值引用" << endl; }
// void Fun(const int& x) { cout << "const 左值引用" << endl; }

// void Fun(int&& x) { cout << "右值引用" << endl; }
// void Fun(const int&& x) { cout << "const 右值引用" << endl; }


// template<typename T>
// //实参传左值，T 会被推导为 int&，T&& 实际上是 int& &，折叠为 int&
// //实参传右值，T 会被推导为 int，T&& 实际上是 int&&
// //引用折叠规则：只要出现一个左值引用 &，最终结果就是左值引用；只有两个 && 组合时，结果才是右值引用。
// // | 原类型    | 组合后的类型       | 折叠结果 |
// // | `T& &`   | 左值引用 + 左值引用 | `T&` |
// // | `T& &&`  | 左值引用 + 右值引用 | `T&` |
// // | `T&& &`  | 右值引用 + 左值引用 | `T&` |
// // | `T&& &&` | 右值引用 + 右值引用 | `T&&` |
// void PerfectForward(T&& t)// 完美转发模板函数，调用时优先匹配普通函数，模板函数实际上基本不会被调用
// {
// 	//Fun((T&&)t);
// 	Fun(forward<T>(t));//标准的完美转发写法
// }

// void PerfectForward(int&& t)
// {
// 	Fun((int&&)t);
// }

// void PerfectForward(int& t)
// {
// 	Fun((int&)t);
// }

// void PerfectForward(const int&& t)
// {
// 	Fun((const int&&)t);
// }

// void PerfectForward(const int& t)
// {
// 	Fun((const int&)t);
// }

// int main()
// {
// 	PerfectForward(10);           // 右值引用

// 	int a;
// 	PerfectForward(a);            // 左值引用
// 	PerfectForward(std::move(a)); // 右值引用

// 	const int b = 8;
// 	PerfectForward(b);		      // const 左值引用
// 	PerfectForward(std::move(b)); // const 右值引用

// 	return 0;
// }


// int main()
// {
//     //lambda 表达式示例
//     auto add = [](int a, int b) -> int { return a + b; };
//     auto add1=[](int a, int b) { return a - b; };//如果不写返回类型，编译器会根据 return 语句自动推导类型
//     auto func=[]{ cout << "Hello, Lambda!" << endl; };// 不带参数的 lambda 表达式
//     cout << add(3, 4) << endl;// 输出 7
//     cout << add1(7, 4) << endl;// 输出 3
//     func(); // 输出 "Hello, Lambda!"
// }


// int main()
// {
// 	int a=1, b=2;
// 	auto swap = [](int& x, int& y) { int temp = x; x = y; y = temp; };
// 	swap(a, b); // 调用 lambda 表达式交换 a 和 b
// 	cout << "a = " << a << ", b = " << b << endl; // a = 2, b = 1

// 	a=1,b=2;
// 	//捕捉外部变量 a 和 b，并允许在 lambda 内部修改它们的副本
// 	auto swap2=[a,b]()mutable { int temp = a; a = b; b = temp; };//这里捕捉的是 a 和 b 的副本，mutable 允许修改副本，不会影响外部的 a 和 b
// 	swap2(); // 调用 lambda 表达式交换 a 和 b
// 	cout << "a = " << a << ", b = " << b << endl; // a = 1, b = 2

// 	a=1,b=2;
// 	auto swap3=[&a,&b] { int temp = a; a = b; b = temp; };//捕捉外部变量的引用，直接修改外部变量
// 	swap3();
// 	cout << "a = " << a << ", b = " << b << endl; // a = 2, b = 1
// }


// int main()
// {
// 	int a=1, b=2,c=3;
// 	auto func1=[=](){return a + b + c; };//传值捕捉所有外部变量
// 	cout << func1() << endl;
// 	auto func2=[&](){a++,b++,c++; };//传引用捕捉所有外部变量
// 	func2();
// 	cout << a << " " << b << " " << c	 << endl;// 输出 2 3 4
// 	auto func3=[a,&b,&c](){b++,c++; };//混合捕捉，a 传值捕捉，b 和 c 引用捕捉
// 	func3();
// 	cout << a << " " << b << " " << c << endl;// 输出 2 4 5
// 	auto func4=[=,&c](){c++; };//混合捕捉，a 和 b 传值捕捉，c 引用捕捉
// 	func4();
// 	cout << a << " " << b << " " << c << endl;// 输出 2 4 6
// 	//mutable 允许你修改 Lambda 按值捕获的变量副本
// 	auto func5=[&a, b, c]()mutable {a++,b++,c++; };//混合捕捉，a 引用捕捉，b 和 c 传值捕捉
// 	func5();
// 	cout << a << " " << b << " " << c << endl;// 输出 3 4 6
// }

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str) -- 构造" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& ss)
		{
			::swap(_str, ss._str);
			::swap(_size, ss._size);
			::swap(_capacity, ss._capacity);
		}

		// 拷贝构造
		// 左值
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// 移动构造  -- 移动将亡值对象的资源
		// 右值(将亡值)
		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(s);
		}

		// 赋值重载
		// s3 = 左值
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			char* tmp = new char[s._capacity + 1];
			strcpy(tmp, s._str);

			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;

			return *this;
		}

		// s3 = 将亡值
		string& operator=(string&& s)
		{
			cout << "string(string&& s) -- 移动赋值" << endl;
			swap(s);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};

	bit::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		bit::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());

		// return move(str);
		return str;
	}
}



class Person
{
public:
	Person(const char* name = "张三", int age = 18)
		:_name(name)
		, _age(age)
	{}
	
	// 强制生成
	Person(const Person& p) = default;
	Person& operator=(const Person & p) = default;
	Person(Person&& p) = default;
	Person& operator=(Person&& p) = default;

	~Person()
	{}
private:
	bit::string _name;
	int _age;
};

// int main()
// {
// 	Person s1;//打印string(char* str) -- 构造
// 	Person s2 = s1; //打印string(const string& s) -- 深拷贝
// 	// 默认拷贝构造
// 	//内置类型值拷贝，自定义类型会调用对应的自定义类型拷贝构造函数

// 	 Person s3 = std::move(s1); //打印string(string&& s) -- 移动构造
// 	 //这句执行完，s1就被s3接管，s1处于有效但未定义状态。s1的值不再可预测。

// 	 Person s4;//打印string(char* str) -- 构造
// 	 s4 = std::move(s2); //打印string(string&& s) -- 移动赋值

// 	 //移动构造和移动赋值区别：
// 	 //移动构造是在对象创建时发生的，直接接管将亡值的资源。
// 	 //移动赋值是在对象已经存在的情况下发生的，先释放自身资源，再接管将亡值的资源。

// 	return 0;
// }

//可变参数模版
// template<class T>
// void showList(const T & t)
// {
// 	cout<< t << " ";
// }
// template <class T,class... Args>
// void showList(const T & t,const Args&... args)
// {
// 	cout << t << " ";
// 	// cout<<sizeof...(args) << " ";//打印剩余参数的个数
// 	// cout<<endl;
// 	showList(args...);
// }
// int main()
// {
// 	showList("Hello", 1, 2, 3, 4, 5);//Hello 1 2 3 4 5 
// 	cout << endl;
// 	showList("Hello", "World",std::string("Test"));//Hello World Test 
// 	cout << endl;
// 	showList(1, 2, 3, 4, 5);//1 2 3 4 5 
// 	return 0;
// }

// template<class T>
// int PrintArg(T t)
// {
// 	cout << t << " ";
// 	return 0;
// }

// template<class ...Args>
// void PrintArg(Args... args)//Args表示参数包，包含任意数量的参数, args表示参数包中的具体参数,会自动推导类型
// {
// 	int arr[] = {PrintArg(args)...};//展开参数包，依次调用PrintArg打印每个参数
// 	cout << "arg_size: " << sizeof...(args) << " ";
// 	cout << endl;
// }

// int main()
// {
// 	PrintArg("Hello", 1, 2, 3, 4, 5);
// 	PrintArg("Hello", "World", std::string("Test"));
// 	PrintArg(1, 2, 3, 4, 5);
// 	return 0;
// }

// int main()
// {	
// 	bit::string s = "Hello";//string(char* str) -- 构造
// 	list<bit::string> lst;
// 	lst.push_back(s);//string(const string& s) -- 深拷贝
// 	lst.push_back(move(s));//string(string&& s) -- 移动构造
// 	cout<<"============="<<endl;

// 	//emplace 的意思可以理解成：在容器内部直接构造对象。
// 	//它和 push 系列的主要区别是：
// 	//- push_back：先有一个对象，再把它放进容器。
// 	//- emplace_back：把构造对象需要的参数直接交给容器，容器在自己的存储位置上构造对象。
// 	bit::string s1="hello";//string(char* str) -- 构造
// 	lst.emplace_back(s1);//string(const string& s) -- 深拷贝
// 	lst.emplace_back(move(s1));//string(string&& s) -- 移动构造
// 	//这里看不出区别
// 	cout<<"============="<<endl;

// 	list<pair<bit::string, int>> lst2;
// 	pair<bit::string, int> p("Charlie", 40);//pair(const string& s, int age) -- 构造
// 	lst2.push_back(p);//pair(const pair& p) -- 深拷贝
// 	//直接传pair的参数包
// 	lst2.emplace_back("Alice", 30);//pair(const string& s, int age) -- 构造
// 	lst2.emplace_back("Bob", 25);//pair(const string& s, int age) -- 构造


// 	return 0;
// }


//C++ 中的 std::function 是一个“函数包装器”，可以把普通函数、函数指针、Lambda 表达式、仿函数、`bind` 对象等统一保存起来，并像函数一样调用。
// #include <functional>

// int Add(int a, int b)
// {
//     return a + b;
// }

// struct Multiply
// {
//     int operator()(int a, int b)
//     {
//         return a * b+1;
//     }
// };

// int main()
// {
// 	//1.基本用法
//     function<int(int, int)> f = Add;//返回值类型int，参数类型为int, int，变量名f
//     cout << f(2, 3) << endl;  // 5

// 	//2.使用Lambda表达式
//     function<int(int, int)> f2 = [](int a, int b) { return a + b; };
//     cout << f2(4, 5) << endl;  // 9

// 	//3.包装多个不同类型的可调用对象
//     function<int(int, int)> f3 = Add;
//     function<int(int, int)> f4 = [](int a, int b) { return a * b; };
//     function<int(int, int)> f5 = Multiply();
//     cout << f3(2, 3) << endl;  // 5
//     cout << f4(2, 3) << endl;  // 6
//     cout << f5(2, 3) << endl;  // 7

//     return 0;
// }


// #include <iostream>
// #include <functional>
// using namespace std;

// void Calculate(int a, int b, function<int(int, int)> operation)
// {
//     cout << "计算结果：" << operation(a, b) << endl;
// }

// int main()
// {
//     Calculate(10, 5, [](int x, int y)
//     {
//         return x + y;
//     }//计算结果：15
// 	);

//     Calculate(10, 5, [](int x, int y)
//     {
//         return x * y;
//     }
// 	);//计算结果：50

//     return 0;
// }


#include <iostream>
#include <functional>
using namespace std;

int Add(int a, int b)
{
    return a + b;
}

int Sub(int a, int b)
{
    return a - b;
}

int main()
{
    // 把 Add 的第一个参数固定为 10
    auto f = bind(Add, 10, placeholders::_1);// 把 Add 的第一个参数固定为 10
    auto g = bind(Sub, placeholders::_1, placeholders::_2);// 不固定参数，按顺序传入
	auto g1 = bind(Sub, placeholders::_2, placeholders::_1);
	//placeholders::_1 表示第一个参数，placeholders::_2 表示第二个参数

    cout << f(5) << endl;  // Add(10, 5)，输出 15
    cout << g(10, 5) << endl;  // Sub(10, 5)，输出 5
    cout << g1(10, 5) << endl;  // Sub(5, 10)，输出 -5

    return 0;
}