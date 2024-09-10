#include<iostream>
#include<string>
#include<vector>
using namespace std;

//����ģ��
//template<typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = b;
//	b = a;
//	a = tmp;
//}
//
////��ģ��
//template<typename T>//����TҲ������������ĸ
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
////��������Ͷ�����룺
//template<class T>
//void Stack<T>::push(const T& x)
//{
//	//...
//}
////��ģ�岻�������Ͷ�����뵽�����ļ�
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
//	//ͬһ��ģ��ʵ��������ͬ����s1,s2
//	Stack<int> s1;
//	Stack<double> s2;
//	return 0;
//}


void test_string1()
{
	//����
	string s1="hello world";
	string s2(s1);
	string s3(s1, 5,2);//��s1��5���±�ȡ2����Ϊ�Ӵ�
	string s4("def");
	string s5(s1, 5);//��s1��5���±꿪ʼȡ����β

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
		//��ȡs1��i��λ���ַ�
		cout << s1[i];//�൱��s1.operator[](i)
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
		
		cout << ++s1[i];//��ӡifmmp!xpsme
		//�ֱ��Ӧhello world��ASCII��ĺ�һλ
	}
}
//int main()
//{
//	/*test_string1();*/
//	/*test_string2();*/
//	/*test_string3();*/
//
//	string s = "hello world";//�������string��һ���ַ�˳���
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//
//	//��������ʹ��
//	string::iterator it = s.begin();//���Լ����Ϊһ��ָ��
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//}

//����������������ʱ���ӷ���
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

	//��������:��Χfor
	//(�ײ���ǵ�����)
	for (auto e : v)
	{
		cout << e << " ";//��ӡ1 2 3 4
	}

	cout << endl;

	string s("abcd");
	for (auto e : s)
	{
		cout << e << " ";//��ӡa b c d
	}
}