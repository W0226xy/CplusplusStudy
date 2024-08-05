#include<iostream>
using std::cout;
using std::endl;
using std::cin;
//namespace wxy
//{
//	int add(int x, int y)
//	{
//		return x + y;
//	}
//
//	double add(double x, double y)
//	{
//		return x + y;
//	}
//	//函数重载：不同参数类型，或者参数数量不同。
//	//返回值不作为评判函数重载的标准
//
//	namespace qwy
//	{
//		//命名空间可以嵌套使用
//		int a = 0;
//	}
//}
//int main()
//{
//	cout << "hello" << endl;
//	cout << wxy::add(1, 2) << endl;
//	cout << wxy::add(1.1, 2.2) << endl;
//	cout << wxy::qwy::a << endl;
//}

//io流
//int main()
//{
//	//1.左移
//	int i = 100;
//	i=i << 1;
//
//	//2.流插入
//	cout << "100左移一位是" << i << endl;
//	//可以多个流插入
//	//流插入可以自动识别类型
//
//	int x=0;
//	cout << "请输入数字x" << endl;
//	cin >> x;
//	//cin符号是>>，表示流入变量
//	cout << "您输入的数字是" << x;
//}


//缺省参数
//1.全缺省：
//void func(int x=1)
//{
//	cout << x << endl;
//}
//
//void func1(int a = 10, int b = 20,int c=30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
////2.半缺省
//void func2(int a,int b=20,int c=30)
//{//半缺省的参数必须从右往左连续给
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//int main()
//{
//	func();//1
//	//不传参则用函数的默认参数
//	func(2);//2
//
//	func1();//10,20,30
//	func1(1, 2);//1 2 30
//	//如果少某个参数，则从左到右依次先填补，剩下的那个用缺省参数
//	
//	cout << "分割线-----------" << endl;
//
//	//func2();//半缺省不能一个参数都没有，会报错
//	func2(1);//1,20,30
//	func2(1, 2);//1,2,30
//	return 0;
//}