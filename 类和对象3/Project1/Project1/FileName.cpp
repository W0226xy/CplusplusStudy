#include<iostream>
using namespace std;
//析构函数
//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour ;
//	int _minute ;
//	int _seconde ;
//};
//
//class Date
//{
//	
//private:
//	int _Year;
//	int _Month;
//	int _Day;
//	Time t;
//};
//
//int main()
//{
//	Date d1;
//}
// 程序运行结束后输出：~Time()
// 在main方法中根本没有直接创建Time类的对象，为什么最后会调用Time类的析构函数？
// 因为：main方法中创建了Date对象d，而d中包含4个成员变量，其中_year, _month, _day三个是
// 内置类型成员，销毁时不需要资源清理，最后系统直接将其内存回收即可；
// 
// 而_t是Time类对象，所以在d销毁时，要将其内部包含的Time类的_t对象销毁，所以要调用Time类的析构函数。
// 但是：main函数中不能直接调用Time类的析构函数，实际要释放的是Date类对象，所以编译器会调用Date类的析构函数，
// 而Date没有显式提供，则编译器会给Date类生成一个默认的析构函数，目的是在其内部调用Time
// 类的析构函数，即当Date对象销毁时，要保证其内部每个自定义对象都可以正确销毁
// main函数中并没有直接调用Time类析构函数，而是显式调用编译器为Date类生成的默认析构函数
// 注意：创建哪个类的对象则调用该类的析构函数，销毁那个类的对象则调用该类的析构函数


class Date
{
public:
	Date(int year=1)
	{
		_Year = year;
		cout << "Date()" << _Year << endl;
	}

	~Date()
	{
		cout << "~Date()"<<_Year << endl;
	}
private:
	int _Year;
	int _Month;
	int _Day;
	
};

void func()
{
	Date d3(3);
	static Date d4(4);
}

Date d5(5);

static Date d6(6);
int main()
{
	Date d1(1);
	Date d2(2);
	func();
	
	//先定义的先构造，后定义的先析构
		
		/*Date()5
		Date()6
		Date()1
		Date()2
		Date()3
		Date()4
		~Date()3
		~Date()2
		~Date()1
		~Date()4
		~Date()6
		~Date()5*/

	//创建：先创全局的，后创局部的（先创的先构造）
	//销毁：先销局部的，后销全局的（后创先销毁）

	//全局的和静态的是最先创建
	

	//销毁顺序：局部对象（后定义的先析构）——局部静态——全局对象（后定义的先析构）
}


//拷贝构造

//class Time
//{
//public:
//	Time() = default;//强制编译器生成构造函数，因为下面有一个拷贝构造，编译器就不会生成默认构造了，这里强制生成一个
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//	Time(const Time& t)
//	{
//		cout << "Time(const Time& t)" << endl;
//		_hour = t._hour;
//		_minute = t._minute;
//		_seconde = t._seconde;
//	}
//private:
//	int _hour ;
//	int _minute ;
//	int _seconde ;
//};
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1,int day=1)
//	{
//		_Year = year;
//		_Month = month;
//		_Day = day;
//	}
//	Date(const Date& d)//拷贝构造，这里参数需要传引用，防止出现“无穷递归”的情况
//	{//加const是为了保护d不能被修改
//		_Year = d._Year;
//		_Month = d._Month;
//		_Day = d._Day;
//	}
//	void print()
//	{
//		cout << _Year << "-" << _Month << "-" << _Day<<endl;
//	}
//private:
//	int _Year;
//	int _Month;
//	int _Day;
//	Time t;
//};
//
//int main()
//{
//	Date d1(2024, 8, 15);
//	Date d2(d1);//拷贝构造：用同类型的其他对象来构造当前对象
//	d1.print();//2024-8-15
//	d2.print();//2024-8-15
//}

//拷贝构造函数也是特殊的成员函数，其特征如下：
//1. 拷贝构造函数是构造函数的一个重载形式。
//2. 拷贝构造函数的参数只有一个且必须是同类型对象的引用，使用传值方式编译器直接报错，因为会引发无穷递归调用。
// 3. 若未显式定义，编译器会生成默认的拷贝构造函数。 默认的拷贝构造函数对象按内存存储按字节序完成拷贝，这种拷贝叫做浅拷贝，或者值拷贝。
// 
// 

//void func1(Date d)
//{
//
//}
//
//void func2(Date& rd)
//{
//
//}
//
//int main()
//{
//	Date d1(2024, 8, 15);
//	//C++规定自定义类型传值传参都会先调用拷贝构造
//	func1(d1);//这里会先调用拷贝构造，然后才会进func1函数
//	
//	func2(d1);//这里是传引用，不会调用拷贝构造，rd就是d1
//	return 0;
//}


// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}
//这里用s1拷贝构造s2（浅拷贝）
//s2的_array和s1的_array两指针是指向一块空间
//s2析构之后，s1再析构，会让同一块空间被释放了两次


//代码改进
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	//拷贝构造
//	Stack(const Stack& s)
//	{
//		DataType* tmp = (DataType*)malloc(s._capacity * (sizeof(DataType)));
//		if (tmp == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memcpy(tmp, s._array, sizeof(DataType)*s._size);//s._array的内容拷贝到tmp里
//		_array = tmp;
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//class MyQueue
//{
//private:
//	Stack _s1;
//	Stack _s2;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//
//	MyQueue q1;//自定义的成员会调用自定义成员的拷贝构造
//	MyQueue q2(q1);
//	return 0;
//}




//void func(int& x)
//{
//
//}
//
//void func1(const int& x)
//{
//
//}
//int main()
//{
//	//引用正常使用
//	int a = 0;
//	int& b = a;
//	b++;
//	func(a);
//
//	//权限可缩小
//	const int& c = a;
//	
//	const int& x = 10;
//
//	//权限不可放大
//	//int& d = c;//这样写会报错，原先c是不可改的，这里d既然是c的别名也应该是不可改的
//
//	const int& z = 10;
//	
//	const int& m = a + x;//可修改+不可修改=不可修改
//	//int& n = a + x;//会报错
//
//	//func(10);这里会报错，因为10是常量，你传过去变成了可修改的了，权限放大了
//	//func(a + x);会报错，a+x是不可修改，传过去变成了可修改的了，权限放大了
//
//	func1(10);//可正常使用，原先是常量不可修改，传过去也是不可修改，权限没有放大
//	func1(a + x);//可正常使用
//
//}


//int main()
//{
//	double d = 1.1;
//	int i = d;//类型转换，中间会产生一个临时变量，临时变量再赋值给i
//	
//	//int& ri = d;//会报错
//	const int& ri = d;
//	//d会先拷贝成一个int型的临时变量，然后临时变量赋给ri
//	//临时变量具有常性，所以要求ri也是不可修改的
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 1, int month = 1,int day=1)
//	{
//		_Year = year;
//		_Month = month;
//		_Day = day;
//	}
//	
//	Date(const Date& d)//拷贝构造，这里参数需要传引用，防止出现“无穷递归”的情况
//	{//加const是为了保护d不能被修改
//		_Year = d._Year;
//		_Month = d._Month;
//		_Day = d._Day;
//	}
//	
//	void print()
//	{
//		cout << _Year << "-" << _Month << "-" << _Day<<endl;
//	}
//	
//	
//	bool operator==( const Date& y)
//	{
//		return this->_Year == y._Year
//			&& this->_Month == y._Month
//			&& this->_Day == y._Day;
//	}
//
//	bool operator<( const Date& y)
//	{
//		if (this->_Year < y._Year)
//		{
//			return true;
//		}
//		else if (this->_Year == y._Year)
//		{
//			if (this->_Month < y._Month)
//			{
//				return true;
//			}
//			else if (this->_Month == y._Month)
//			{
//				if (this->_Day < y._Day)
//				{
//					return true;
//				}
//				else
//				{
//					return false;
//				}
//			}
//			else
//			{
//				return false;
//			}
//		}
//	}
//	
//
//private:
//	int _Year;
//	int _Month;
//	int _Day;
//
//};
//
//int main()
//{
//	Date d1(2023, 3, 1);
//	Date d2(2023, 1, 9);
//	
//	cout<<d1.operator<(d2)<<endl;
//
//	cout << (d1< d2) << endl;//这里中间加一个括号，<<优先级高于<
//
//	cout << (d1 == d2) << endl;
//
//}