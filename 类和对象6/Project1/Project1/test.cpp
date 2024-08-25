#include<iostream>
using namespace std;

//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

//class Sum
//{
//public:
//    Sum()
//    {
//        _i++;
//        _ret += _i;
//    }
//    
//    static int GetRet()
//    {
//        return _ret;
//    }
//
// 
//private:
//    static int _i;//声明
//    static int _ret;
//};
//
//int Sum::_i = 0;
//int Sum::_ret = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        Sum s[n];//通过创建n个Sum对象来实现_i++，_i是静态成员变量，属于所有成员
//        return Sum::GetRet();
//    }
//};

//根据输入的日期，计算是这一年的第几天。保证年份为4位数且日期合法。
//示例：输入2012 12 31  输出366

//int main()
//{
//	int y = 0;
//	int m = 0;
//	int d = 0;
//
//	cin >> y >> m >> d;
//
//	int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//	{
//		MonthDay[2] = 29;
//	}
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < m; i++)
//	{
//		sum += MonthDay[i];
//	}
//	sum += d;
//	cout << sum;
//}


//给出年分m和一年中的第n天，算出第n天是几月几号。
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int y = 0;
//	int n = 0;
//	cin >> y >> n;
//	int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//	{
//		MonthDay[2] = 29;
//	}
//
//	int m = 0;
//	int d = 0;
//	while (n > 0)
//	{
//		d = n;
//		n = n - MonthDay[m];
//		if (n > 0)
//		{
//			m++;
//		}
//	}
//	if (m < 10 && d < 10)
//	{
//		cout << y << "-" << 0 << m << "-" << 0 << d;
//	}
//
//	if (m < 10 && d >= 10)
//	{
//		cout << y << "-" << 0 << m << "-" << d;
//	}
//
//	if (m > 10 && d >= 10)
//	{
//		cout << y << "-" << m << "-" << d;
//	}
//
//	if (m > 10 && d < 10)
//	{
//		cout << y << "-" << m << "-" << 0 << d;
//	}
//
//	return 0;
//}
//	

//友元（慎用）

//友元函数
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}

//友元函数可访问类的私有和保护成员，但不是类的成员函数
//友元函数不能用const修饰
//友元函数可以在类定义的任何地方声明，不受类访问限定符限制
//一个函数可以是多个类的友元函数
//友元函数的调用与普通函数的调用原理相同

//class Time
//{
//	friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d(2024, 8, 23);
//	d.SetTimeOfDate(1, 1, 1);
//
//}


//内部类
//class A
//{
//public:
//	class B
//	{
//		//1.B类受A类的类域限制
//		//2.内部类天生是外部类的友元类,可以直接访问外部类的私有
//	public:
//		void func(A* p)
//		{
//			p->_a1++;
//		}
//	private:
//		int _b1;
//	};
//private:
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	cout << sizeof(A) << endl;//打印8
//	//A里面的B类是一个声明，不占用空间
//
//	
//	A a;
//	A::B b;//创建B类，需要指明是A类下的
//
//}

//匿名对象
//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};

//int main()
//{
//	//有名对象，生命周期在当前作用域
//	A a1;
//	A a2(10);
//
//	//匿名对象,生命周期只在当前一行
//	A();
//	A(10);
//
//	// 匿名对象在这样场景下就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
//	Solution().Sum_Solution(10);
//
//	//匿名对象就是某些场景方便一些，用普通的有名对象也完全可以
//}

//拷贝对象时的一些编译器优化
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void f1(A aa)
{}

void f2(const A& aa)
{

}

A f3()
{
	A aa;
	return aa;
}

A f4()
{
	return A();//返回一个匿名对象
}
int main()
{
	//编译器的优化
	//A aa1 = 2;//构造+拷贝构造——》构造
	//const A& aa2 = 2;//直接构造了，没有拷贝（直接用的引用）
	//
	//f1(aa1);//拷贝构造，用aa1拷贝构造了函数f1的aa
	//f2(aa1);//传引用不会发生拷贝构造

	//f1(A(2));//传匿名对象，先构造匿名对象，再拷贝构造aa，相当于是构造+拷贝构造——》构造
	
	//A tmp=f3();//这里是优化了，正常是构造+拷贝构造+拷贝构造，这里全优化了成一个构造

	//A ret = f4();//构造+拷贝构造+拷贝构造——》优化成：构造

	A ret2;//构造
	ret2 = f4();//构造+A& operator=(const A& aa)
	return 0;
}

