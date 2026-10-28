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


class Buffer {
public:
    Buffer(size_t n)
        : _size(n)
        , _data(new int[n])
    {}

    ~Buffer() {
        delete[] _data;
    }

    // 移动构造
    Buffer(Buffer&& other) noexcept//noexcept 表示该函数不会抛出异常
        : _size(other._size)
        , _data(other._data)
    {
        // 把资源转移给新对象
        other._size = 0;
        other._data = nullptr;
    }

private:
    size_t _size;
    int* _data;
};

int main()
{
    //右值引用的意义：可以延长右值的生命周期，避免不必要的拷贝，提高性能

    //需要调用拷贝构造，把 a 中的一百万个元素复制到 b 的新空间中，代价很大。
	// Buffer a(1000000);
    // Buffer b = a;

    // 使用移动构造，这里不会重新申请并复制一百万个元素，而是直接把 a 的指针交给 b,速度非常快
    Buffer a(1000000);
    Buffer b = std::move(a);//std::move 把左值转换成一种可以被移动的右值引用类型。
    //std::move(a),告诉编译器 a 后面不准备继续使用了，可以把它内部的资源转走。
	return 0;
}


