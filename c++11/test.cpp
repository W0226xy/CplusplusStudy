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


int main()
{
    //lambda 表达式示例
    auto add = [](int a, int b) -> int { return a + b; };
    auto add1=[](int a, int b) { return a - b; };//如果不写返回类型，编译器会根据 return 语句自动推导类型
    auto func=[]{ cout << "Hello, Lambda!" << endl; };// 不带参数的 lambda 表达式
    cout << add(3, 4) << endl;// 输出 7
    cout << add1(7, 4) << endl;// 输出 3
    func(); // 输出 "Hello, Lambda!"
}

