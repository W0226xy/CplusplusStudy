#include<iostream>
using namespace std;
//class A
//{
//public:
//	A* operator&()//这里有个隐藏参数A* this
//	{
//		return this;
//	}
//
//	const A* operator&() const
//	{
//		return this;
//	}
//	//上面两个函数，你不写，编译器也会自动生成
//	//就是简单的返回对象的地址
//
//	//需要重写上面两个函数的场景：比如不想普通对象获得他的地址，可以重写返回一个nullptr
//};

//int main()
//{
//	A a1;
//	const A a2;
//
//	cout << &a1 << endl;
//	cout << &a2 << endl;
//}

//初始化列表

//1. 每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)
//2. 类中包含以下成员，必须放在初始化列表位置进行初始化：
//引用成员变量
//const成员变量
//自定义类型成员(且该类没有默认构造函数时)

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)构造" << endl;
//	}
//private:
//	int _a;
//};
//
//
//class Date
//{
//public:
//	Date(int year, int month, int day, int& x)//初始化列表，和普通的构造函数没啥区别，都是初始化
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _n(1)//const成员必须走初始化列表
//		, _ref(x)
//		,_aa(1)//调用A的构造
//	{
//		cout << "Date(int year, int month, int day, int& x)构造" << endl;
//	}
//
//	//初始化列表也可以和构造函数混用
//	//Date(int year, int month, int day)//初始化列表，和普通的构造函数没啥区别，都是初始化
//	//	: _n(1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	//下面三个必须走初始化列表初始化（函数体内无法对下面三个进行初始化）
//	const int _n;//const定义的对象成员，必须在定义的时候就初始化，因为它只有一次修改机会
//	int& _ref;
//	A _aa;
//};
//int main()
//{
//	int x = 32;
//	Date d1(2024, 1, 31,x);
//	return 0;
//}


//隐式类型转换
//class A
//{
//public:
//	A(int a1)
//		:_a1(a1)
//	{}
//
//private:
//	int _a1;
//	
//};
//
//class B
//{
//public:
//	B(int b1,int b2)
//		:_b1(b1)
//		,_b2(b2)
//	{}
//
//private:
//	int _b1;
//	int _b2;
//};
//
//int main()
//{
//	A a = 1;//这里会发生一个隐式类型转换，先用1构造一个A(1),然后赋值给a
//	B b = { 1,2 };//和上面一样，相当于先构造一个B(1,2)，然后赋值给b
//}

//声明和定义的练习题
//class A
//{
//public:
//    A(int a)
//        :_a1(a)
//        , _a2(_a1)
//    {}
//
//    void Print() {
//        cout << _a1 << " " << _a2 << endl;
//    }
//private:
//    int _a2;
//    int _a1;
//};
//int main() {
//    A aa(1);
//    //传1过去构造A
//    //但是不管初始化顺序如何，实际初始化的顺序是按照定义来的
//    //定义中是先定义了a2，所以是先初始化a2
//    
//    aa.Print();//打印 1 -858993460
//}


//explict
//class Date
//{
//public:
//	// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
//	 // explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
//	explicit Date(int year)
//		:_year(year)
//	{}
//	/*
//	// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具
//   有类型转换作用
//	// explicit修饰构造函数，禁止类型转换
//	explicit Date(int year, int month = 1, int day = 1)
//	: _year(year)
//	, _month(month)
//	, _day(day)
//	{}
//	*/
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2022);
//	// 用一个整形变量给日期类型对象赋值
//	
//	// 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
//	//d1 = 2023;//这里加了explicit，没有办法进行隐式转换，如果要使得d1=2023成功编译，则需要屏蔽explicit
//}


//静态成员变量
//应用案例：算创建了几个对象
class A
{
public:
	A()
	{
		n++;
	}

	A(const A& aa)
	{
		n++;
	}

	static void GetN()//静态成员函数不属于某个特定对象，所以它也没有this指针
	{
		cout << n << endl;
	}
public:
	//静态成员变量声明
	static int n;//属于整个类，不是属于某个对象
};

int A::n = 0;//静态成员变量定义需要在类外面

A func()
{
	A aa;//3
	return aa;//实际在这里传值返回还会再算一次，只不过编译器把这个优化了，具体这次算不算取决不同编译器
}

int main()
{
	A aa1;//1
	A aa2;//2
	func();//这里编译器优化了，只算了1次
	A* ptr = nullptr;//没有创建对象

	//下面四个是一个东西，n属于静态成员变量，属于整个类
	cout << aa1.n << endl;//打印3
	cout << aa2.n << endl;
	cout << A::n << endl;
	
	cout << ptr->n << endl;//打印3，虽然ptr指向n，但是n并不在ptr指向的对象中，是在静态区，不需要对ptr解引用

	//ps：上面对n的访问基于n是public的，如果n是private在类可以提供一个访问函数,如下所示
	aa1.GetN();//静态成员函数也是属于公有的
	aa2.GetN();
	A::GetN();
}