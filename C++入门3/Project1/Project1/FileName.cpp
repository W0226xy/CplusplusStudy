#include<iostream>
using namespace std;

//引用
//int main()
//{
//	int a = 0;
//	int& b = a;//给a取别名为b，ps：引用必须初始化
//	cout << &b << endl;
//	cout << &a << endl;
//	//a和b地址一样，说明a就是b，b就是a
//
//	cout << "a=" << a << endl;//0
//	cout << "b=" << b << endl;//0
//
//	a++;
//
//	cout << "a=" << a << endl;//1
//	cout << "b=" << b << endl;//1
//}

//引用做参数
//void change(int& x, int& y)//形参会影响实参
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int  main()
//{
//	int a = 0;
//	cout << "请输入a"<<endl;
//	cin >> a;
//
//	int b = 0;
//	cout << "请输入b" << endl;
//	cin >> b;
//
//	change(a, b);
//	cout << "交换后的a，b值为" << endl;
//
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//}


//int main()
//{
//	int a = 0;
//	//1.引用必须初始化
//	int& b = a;
//	//ps：一个变量可以有多个引用
//
//	//2.引用被定义后不能改变指向
//	int c = 2;
//	b = c;//这里不是改变指向，而是赋值
//	
//	cout << "&a=" << &a << endl;//a,b同地址
//	cout << "&b=" << &b << endl;
//	cout << "&c=" << &c << endl;//c不同地址
//
//	cout << "a=" << a << endl;//2
//	cout << "b=" << b << endl;//2
//	cout << "c=" << c << endl;//2
//	return 0;
//}

//引用可以完成指针的大部分工作
//但是由于引用不能改变指向，所以有些需要改变指向的场景还需要指针
//比如链表要删某个节点，前后节点需要改变指向

//传值和传引用效率对比
//struct A
//{
//	int a[10000];
//};
//void TestFunc1(A a) {};
//void TestFunc2(A& a) {};
//int main()
//{
//	A a;
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; i++)
//	{
//		TestFunc1(a);
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; i++)
//	{
//		TestFunc2(a);
//	}
//	size_t end2 = clock();
//
//	cout << "TestFunc1(A)-time" << end1 - begin1 << endl;//7ms
//	cout << "TestFunc1(A&)-time" << end2 - begin2 << endl;//0ms
//}


//引用做返回值
//int func()
//{
//	int a =1;
//	return a;
//}
//
//int& func1()
//{
//	int a = 0;
//	return a;
//}
//
//void test()
//{
//	int b = 1;
//}
//int main()
//{
//	int ret = func();
//	//这里理论返回是一个随机值
//	//因为func的栈帧结束就销毁了，a是否还是原先的值是未知的
//	//fun函数到main函数中间会生成一个临时变量tmp存储a的值
//	//然后把tmp值赋给ret
//	//是安全的
//	cout <<"测试1ret="  << ret << endl;
//	test();
//	cout << "测试2ret=" << ret << endl;
//
//
//	int ret1 = func1();
//	//这里是一个野引用
//	//栈帧已经销毁，但是引用还返回了原先那块地址的值，这里原先地方的值中途是有可能被其他程序修改，所以这里的值是随机的（可能是原先值，可能是其他值）
//	//是不安全的
//	cout << "测试1ret1=" << ret1 << endl;
//	test();
//	cout << "测试2ret1=" << ret1 << endl;
//
//	//（重点）什么情况用引用返回？
//	//返回变量出了作用域生命周期仍然没有结束
//	//比如静态变量static修饰的
//	//比如malloc出来的变量，全局变量，堆栈的变量
//	return 0;
//}

//#include<assert.h>
////引用示例
//struct Seqlist
//{
//	//变量
//	int* a;//头节点
//	int size;//当前容量
//	int capacity;//最大容量
//
//	//函数
//	//这里结构体内能定义函数是因为c++把struct上升到类了
//	void Init()
//	{
//		a= (int*)malloc(sizeof(int) * 4);
//		size = 0;
//		capacity = 4;
//	}
//
//	void PushBack(int x)//尾插
//	{
//		//..扩容
//		a[size++] = x;
//	}
//
//	int& SLGet(int pos)//获取pos位置节点值
//	{
//		assert(pos >= 0);
//		assert(pos < size);
//		return a[pos];
//	}
//	//这里返回节点的引用，其他地方可以直接对节点值修改
//	
//};
//
//int main()
//{
//	Seqlist s;
//	s.Init();
//	s.PushBack(1);
//	s.PushBack(2);
//	s.PushBack(3);
//	s.PushBack(4);
//	for (int i = 0; i < 4; i++)
//	{
//		cout << s.SLGet(i) << endl;
//	}
//
//	cout <<"节点值*2"<< endl;
//
//	for (int i = 0; i < 4; i++)
//	{
//		s.SLGet(i) *= 2;
//		cout << s.SLGet(i) << endl;
//	}
//	return 0;
//}


//引用和指针的区别
//引用1.作参数（输出型参数，对象较大，减少拷贝，提高效率）
//引用2.作返回值（修改返回对象，减少拷贝，提高效率）

//语法上：
//引用是别名，不开空间，指针开空间
//底层上：
//引用和指针都开了空间（引用底层就是指针实现的）

//引用不能改变指向，指针可以
//引用相对安全，没有空引用，但有空指针

//#define add(a,b) ((a)+(b))
////c语言的宏，里层ab还加括号是因为a，b可能是表达式
////宏就是在预处理阶段进行替换
////宏的缺点就是坑多，不容易控制，且不能调试，没有类型安全检查
//
////c++用内联对宏进行了改进
////inline修饰的函数会在调用的地方进行展开(不建立栈帧)
//inline int Add(int x ,int y)
//{
//	return x + y;
//}
//int main()
//{
//	int ret = Add(1,2) * 3;
//	cout << ret << endl;
//}


inline int add(int a, int b)//inline修饰的函数不会建立栈帧，而是在调用的地方进行展开(一般是较小的函数，并且这个函数调用次数非常多才用内联)
{//内联展开会额外占用空间，会导致代码膨胀问题
	return a + b;
}
int main()
{
	int ret = add(1, 2) * 3;
	cout << ret << endl;//9
}
//内联导致代码膨胀举例
//比如func函数100行，其中有1w个位置调用了这个函数
//inline展开，则占用100*1w的内存
//不展开，则占用1w+100的内存