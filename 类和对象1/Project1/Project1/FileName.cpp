#include "stack.h"
//int main()
//{
//	int x = Add(1, 2);
//	cout << x << endl;
//}


//auto的使用：
//#include<map>
//#include<string>
//void func(int a, int b)
//{
//	;
//}
//int main()
//{
//	int i = 0;
//	float j = 0;
//
//	auto k = i;//auto可以自动推导类型
//	auto m = j;
//	//auto必须赋初值
//
//	auto p1 = &i;//p1是指针类型,auto是int*
//	auto* p2=&j;//p2也是指针类型，auto是float
//	//auto* p3 = i;
//	//auto*就一定是指针类型，但是这里i不是地址，所以会报错
//
//	auto& a = i;//a是i的别名
//	cout << "a地址="<<  &a << endl;
//	cout << "i地址=" << &i << endl;//a,i两个地址相同
//
//	void(*pf1)(int, int) = func;//函数指针
//	auto pf2 = func;
//
//	cout << "pf1=" << pf1 << endl;
//	cout << "pf2=" << pf1 << endl;//pf1,pf2两个地址相同
//	
//	cout << typeid(pf1).name() << endl;//打印类型
//	cout << typeid(pf2).name() << endl;
//	//类型均为void (__cdecl*)(int,int)
//
//	std::map<std::string, std::string> dict;
//	auto it = dict.begin();
//
//	return 0;
//}


//int main()
//{
//	int array[] = { 1,2,3,4,5 };
//	//遍历数组法一
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
//	{
//		cout << array[i] <<" ";
//	}
//
//	cout << endl;
//
//	//遍历数组法二
//	for (int* p = array; p < array + sizeof(array)/sizeof(array[0]); p++)
//	{
//		cout << *p <<" ";
//	}
//
//	cout << endl;
//
//	//遍历数组法三
//	for (auto x : array)
//	{
//		cout << x << " ";
//	}
//	//依次取数组中值赋给x，自动迭代，自动判断结束
//
//	cout << endl;
//
//	for (auto& x : array)//数组中值*2
//	{
//		x *= 2;
//		cout << x << " ";
//	}
//
//
//	return 0;
//}

//关于NULL和nullptr
//void func(int i)
//{
//	cout << "func(int i)" << endl;
//}
//void func(int* p)
//{
//	cout << "func(int* p)" << endl;
//}
//
//int main()
//{
//	func(0);//func(int i)
//	func(NULL);//func(int i)
//	//C++98中NULL底层是数字0
//	func(nullptr);//func(int* p)
//	//为了改进NULL，提出了nullptr
//	return 0;
//}

//类和对象
//class Stack
//{
//	//成员变量
//	int* a;
//	int top;
//	int capacity;
//	//成员函数
//public:
//	void Init(int n=4)
//	{
//		a = (int*)malloc(sizeof(int) * n);
//		if (a == nullptr)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		top = 0;
//		capacity = n;
//	}
//	
//	void push(int x)
//	{
//		//扩容...
//		a[top++] = x;
//	}
//
//	void print()
//	{
//		for (int i=0;i<top;i++)
//		{
//			cout << a[i] << endl;
//		}
//	}
//};
//
//int main()
//{
//	Stack s;
//	s.Init();
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	s.print();
//}


class Date
{
	int _year;
	int _month;
	int _day;

public://类内类外都可以访问
	void init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;;
	}
};
//public类内类外都可以访问
//protect和private类外不可直接访问
//不加访问限定符，则默认private


//class A
//{
//
//};
//int main()
//{
//	Date d1;
//	d1.init(2024, 8, 12);
//	d1.print();
//	cout << sizeof(d1) << endl;//12
//
//	Date d2;
//	d2.init(2024, 8, 13);
//	d2.print();
//	//看汇编，可以发现d1.print()和d2.print()地址是一样的
//
//	//计算对象大小只算了成员变量
//	//在一个公告区域存成员函数，各个成员共用这个函数
//	
//
//	cout << sizeof(Date) << endl;//12
//	//sizeof(Date)算的也是实例化出对象后的大小
//
//	cout << sizeof(A) << endl;
//	//如果类里面啥也没有，计算他大小默认是1
//	//（必须给个空间占位，标识对象的存在）
//}


class A2
{
public:
	void f2()
	{
		cout << "void f2()";
	}
};
int main()
{
	A2 a2;
	A2* p1 = &a2;
	p1->f2();//void f2()

	A2* p2 = nullptr;
	p2->f2();//void f2()
	//成员函数是在额外开辟的公用空间里，是各个实例共用的
}