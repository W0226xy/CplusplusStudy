#include<iostream>
using namespace std;
//内存对其
//class A {
//	int a;//4
//	char b;//1
//};
//
//class B {
//	char x;//1
//	int y;//4
//};
//int main()
//{
//	cout << sizeof(A) << endl;//8
//	
//	//由于 int 类型的对齐要求是 4 字节，而类的总大小也通常需要是最大对齐要求的整数倍（在这个例子中是 4 字节），
//	//因此编译器在 char b 后面插入了 3 个字节的填充，使得整个类的大小为 8 字节。
//
//	//A内存类似：4，1，3
//
//	cout << sizeof(B) << endl;//8
//	//int y 按照 4 字节对齐要求存储，因此在 char x 之后，编译器插入了 3 个字节的填充。
//	//因此，int y 从一个对齐的 4 字节地址开始，占用 4 字节
//	
//	//B内存类似:1，3，4
//}

//结构体内存对齐规则
//1. 第一个成员在与结构体偏移量为0的地址处。
//2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
//		注意：对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
//		VS中默认的对齐数为8
//3. 结构体总大小为：最大对齐数（所有变量类型最大者  与  默认对齐参数  取最小）的整数倍。
//4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。


//this指针
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//Print函数编译器会处理成下面这样
//	/*void Print(Date* this)
//	{
//		cout << this->_year << "-" << this->_month << "-" <<this-> _day << endl;
//	}*/
//


//	//ps:
//	// const Date* p,const在*前修饰指向的内容，p指向的内容可变,但是通过 p 不能修改它指向的对象的值。
//	// Date* const p,const在*后修饰指针本身 指针p不能改变，一旦初始化就固定了。但是可以通过 p 修改它指向的对象。
////举例说明1
////const Date d1(2025, 9, 4);
////const Date d2(2024, 1, 1);
////
////const Date* p = &d1;  // p 可以指向 d1
////p = &d2;              // p 可以改为指向 d2
//// p->year = 2030;    // ❌ 错误，不能修改 *p 的内容
////举例说明2
////Date d1(2025, 9, 4);
////Date d2(2024, 1, 1);
////
////Date* const p = &d1;  // p 必须在定义时初始化
////// p = &d2;           // ❌ 错误，p 是 const 指针，不能重新指向别的对象
////p->year = 2030;       // ✅ 可以修改 *p 的内容

//总结口诀
//const 在* 左边 → 指向的对象是常量（不能通过指针改内容）。
//const 在* 右边 → 指针本身是常量（不能改指针指向）。


//	//this指针存在栈上（它是一个形参）
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//};
//int main()
//{
//	Date d1, d2;
//	d1.Init(2024, 8, 13);
//	d2.Init(2024, 8, 14);
//	d1.Print();
//	d2.Print();
//	return 0;
//}



//class A
//{
//	public:
//		void Print()
//		{
//			cout << "Print()" << endl;
//		}
//	private:
//		int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
// //成员函数不在对象中，虽然这里有箭头->但是不会解引用，因为Print（）函数是在公共空间上，并不需要通过p去找到
// //所以可以正常运行打印Print()
//	return 0;
//}

//class A
//{
//public:
//    void PrintA()
//    {
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A* p = nullptr;
//    p->PrintA();
//    //运行崩溃,虽然空指针也可以调用PrintA（），但是由于没有初始化对象，并且_a需要通过p找到，需要解引用，但是p是空指针，无法解引用。
//    //所以这里会运行崩溃
//    return 0;
//}

//class A
//{
//public:
//    void PrintA()
//    {
//        cout << this << endl;
//        cout << "正常运行" << endl;
//    }
//private:
//    int _a;
//};
//
//int main()
//{
//    A* p = nullptr;
//    (*p).PrintA();//等价于p->PrintA(),函数PrintA（）没有存在对象中，this指针并不需要通过p找到，所以并不用解引用p
//    return 0;
//}


//构造函数:初始化对象
//1. 函数名与类名相同。
//2. 无返回值。
//3. 对象实例化时编译器自动调用对应的构造函数。
//4. 构造函数可以重载。
//class Date
//{
//public:
//	Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;//如果没有初始化，自动调用构造函数里的Date()初始化
//	d1.Print();//1-1-1
//
//	Date d2(2024, 8, 13);//调用Date(int year, int month, int day)
//	d2.Print();//2024-8-13
//}


//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack()
//	{
//		cout << "Stack()" << endl;
//	}
//};
//
//class MyQueue
//{
//private:
//	Stack st1;
//	Stack st2;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();//-858993460--858993460--858993460
//	//默认生成的构造函数，对内置类型不做处理，自定义类型会去调用它的默认构造
//	//内置类型（基本类型）：int/char/double/指针...
//	//自定义类型：struct/class
//
//	MyQueue q1;//会调用到Stack的构造函数，打印两个Stack（）
//
//}


//析构函数：清理资源，防止内存泄露
//1. 析构函数名是在类名前加上字符 ~。
//2. 无参数无返回值类型。
//3. 一个类只能有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。注意：析构函数不能重载
//4. 对象生命周期结束时，C++编译系统系统自动调用析构函数

typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	// 其他方法...
	~Stack()
	{
		cout << "调用~Stack()" << endl;
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};
void TestStack()
{
	Stack s;
	s.Push(1);
	s.Push(2);
}
int main()
{
	TestStack();//栈S销毁后会自动调用~Stack（）,打印"调用~Stack()"
	//由于Stack的空间是malloc出来的，调用结束后如果不进行析构，会发生内存泄露
}
//先定义的先构造
//后定义的先析构

//析构函数和构造函数类似，
//内置类型不处理，自定义类型去调析构