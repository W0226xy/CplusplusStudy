#include<iostream>
#include<string>
#include<vector>
using namespace std;

//函数模板
//template<typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = b;
//	b = a;
//	a = tmp;
//}
//
////类模板
//template<typename T>//除了T也可以用其他字母
//class Stack
//{
//	T* _a;
//	int top;
//	int _capacity;
//
//public:
//	void Init(const T& x)
//	{
//		//...
//	}
//	void push(const T& x);
//};
//
////如果声明和定义分离：
//template<class T>
//void Stack<T>::push(const T& x)
//{
//	//...
//}
////类模板不能声明和定义分离到两个文件
//
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(a, b);
//
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//
//	//同一类模板实例化出不同类型s1,s2
//	Stack<int> s1;
//	Stack<double> s2;
//	return 0;
//}


void test_string1()
{
	//构造
	string s1="hello world";
	string s2(s1);
	string s3(s1, 5,2);//从s1的5号下标取2个作为子串
	string s4("def");
	string s5(s1, 5);//从s1的5号下标开始取到结尾

	cout << "s1=" << s1 << endl;//s1=hello world
	cout << "s2=" << s2 << endl;//s2=hello world
	cout << "s3=" << s3 << endl;//s3= w
	cout << "s4=" << s4 << endl;//s4=def
	cout << "s5=" << s5 << endl;//s5= world
}

void test_string2()
{
	string s1("hello world");
	for (size_t i=0;i<s1.size();i++)
	{
		//获取s1第i个位置字符
		cout << s1[i];//相当于s1.operator[](i)
		/*cout << s1.operator[](i);*/

		//ps:int a[10]
		//a[i]==*(a+i)
	}
}

void test_string3()
{
	string s1("hello world");
	for (size_t i = 0; i < s1.size(); i++)
	{
		
		cout << ++s1[i];//打印ifmmp!xpsme
		//分别对应hello world在ASCII码的后一位
	}
}
//int main()
//{
//	/*test_string1();*/
//	/*test_string2();*/
//	/*test_string3();*/
//
//	string s = "hello world";//可以理解string是一个字符顺序表
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	//迭代器的使用
//	string::iterator it = s.begin();//可以简单理解为一个指针
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//}

//迭代器遍历容器有时更加方便
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";//1 2 3 4
		it++;
	}

	cout << endl;

	//遍历法二:范围for
	//(底层就是迭代器)
	for (auto e : v)
	{
		cout << e << " ";//打印1 2 3 4
	}

	cout << endl;

	string s("abcd");
	for (auto e : s)
	{
		cout << e << " ";//打印a b c d
	}
}