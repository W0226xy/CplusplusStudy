#include "stack.h"
//int main()
//{
//	int x = Add(1, 2);
//	cout << x << endl;
//}


//auto��ʹ�ã�
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
//	auto k = i;//auto�����Զ��Ƶ�����
//	auto m = j;
//	//auto���븳��ֵ
//
//	auto p1 = &i;//p1��ָ������,auto��int*
//	auto* p2=&j;//p2Ҳ��ָ�����ͣ�auto��float
//	//auto* p3 = i;
//	//auto*��һ����ָ�����ͣ���������i���ǵ�ַ�����Իᱨ��
//
//	auto& a = i;//a��i�ı���
//	cout << "a��ַ="<<  &a << endl;
//	cout << "i��ַ=" << &i << endl;//a,i������ַ��ͬ
//
//	void(*pf1)(int, int) = func;//����ָ��
//	auto pf2 = func;
//
//	cout << "pf1=" << pf1 << endl;
//	cout << "pf2=" << pf1 << endl;//pf1,pf2������ַ��ͬ
//	
//	cout << typeid(pf1).name() << endl;//��ӡ����
//	cout << typeid(pf2).name() << endl;
//	//���;�Ϊvoid (__cdecl*)(int,int)
//
//	std::map<std::string, std::string> dict;
//	auto it = dict.begin();
//
//	return 0;
//}


//int main()
//{
//	int array[] = { 1,2,3,4,5 };
//	//�������鷨һ
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
//	{
//		cout << array[i] <<" ";
//	}
//
//	cout << endl;
//
//	//�������鷨��
//	for (int* p = array; p < array + sizeof(array)/sizeof(array[0]); p++)
//	{
//		cout << *p <<" ";
//	}
//
//	cout << endl;
//
//	//�������鷨��
//	for (auto x : array)
//	{
//		cout << x << " ";
//	}
//	//����ȡ������ֵ����x���Զ��������Զ��жϽ���
//
//	cout << endl;
//
//	for (auto& x : array)//������ֵ*2
//	{
//		x *= 2;
//		cout << x << " ";
//	}
//
//
//	return 0;
//}

//����NULL��nullptr
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
//	//C++98��NULL�ײ�������0
//	func(nullptr);//func(int* p)
//	//Ϊ�˸Ľ�NULL�������nullptr
//	return 0;
//}

//��Ͷ���
//class Stack
//{
//	//��Ա����
//	int* a;
//	int top;
//	int capacity;
//	//��Ա����
//public:
//	void Init(int n=4)
//	{
//		a = (int*)malloc(sizeof(int) * n);
//		if (a == nullptr)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		top = 0;
//		capacity = n;
//	}
//	
//	void push(int x)
//	{
//		//����...
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

public://�������ⶼ���Է���
	void init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;;
	}
};
//public�������ⶼ���Է���
//protect��private���ⲻ��ֱ�ӷ���
//���ӷ����޶�������Ĭ��private


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
//	//����࣬���Է���d1.print()��d2.print()��ַ��һ����
//
//	//��������Сֻ���˳�Ա����
//	//��һ������������Ա������������Ա�����������
//	
//
//	cout << sizeof(Date) << endl;//12
//	//sizeof(Date)���Ҳ��ʵ�����������Ĵ�С
//
//	cout << sizeof(A) << endl;
//	//���������ɶҲû�У���������СĬ����1
//	//����������ռ�ռλ����ʶ����Ĵ��ڣ�
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
	//��Ա�������ڶ��⿪�ٵĹ��ÿռ���Ǹ���ʵ�����õ�
}