#include<iostream>
using namespace std;
//模板

//函数模板
//模板格式
//template<typename T1,typename T2...typename Tn>
//返回值类型  函数名（参数列表）{}

//template<typename T>//template模板的意思
//void Swap(T& x ,T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<typename T>
//T Add(const T& l, const T& r)
//{
//	return l + r;
//}
//
////也可以写两个不同的参数，这样就不要求函数的参数类型统一了
//template<class T1 ,class T2>//template可以用class替换
//T1 Add(const T1& l, const T2& r)
//{
//	return l + r;//返回值是T1类型，T2会统一强转为T1（如果T2和T1类型不一样）
//}
//
//int Add(const int& l, const int& r)//函数和模板可以同时存在，如果函数参数匹配，会优先使用函数
//{
//	return l + r;
//}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//
//	double c = 1.234;
//	double d = 3.141;
//	Swap(a, b);
//	Swap(c, d);
//	cout <<"a=" << a <<"b=" <<b<< endl;//a=2,b=1
//	cout << "c=" << c << "d=" << d << endl;//c=3.141,d=1,234
//
//	//Swap(a, c);这样就会报错，模板参数类型不明确
//	//编译器不知道到底是强转成int，还是强转成double
//	
//	//显示实例化
//	cout<<Add<int>(a, c)<<endl;//Add<int>指明模板中的T全是int类型，c会发生强转
//
//	cout << Add(b, d) << endl;//调用T1 Add(const T1& l, const T2& r)
//
//	return 0;
//}


//类模板
template<class T>
class Stack
{
public:
	void Push(const T& x)
	{}
private:
	T* _a;
	int _top;
	int _capacity;
};

int main()
{
	Stack<int> s1;
	Stack<double> s2;
}