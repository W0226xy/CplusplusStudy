#include<iostream>
using namespace std;

//����
//int main()
//{
//	int a = 0;
//	int& b = a;//��aȡ����Ϊb��ps�����ñ����ʼ��
//	cout << &b << endl;
//	cout << &a << endl;
//	//a��b��ַһ����˵��a����b��b����a
//
//	cout << "a=" << a << endl;//0
//	cout << "b=" << b << endl;//0
//
//	a++;
//
//	cout << "a=" << a << endl;//1
//	cout << "b=" << b << endl;//1
//}

//����������
//void change(int& x, int& y)//�βλ�Ӱ��ʵ��
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int  main()
//{
//	int a = 0;
//	cout << "������a"<<endl;
//	cin >> a;
//
//	int b = 0;
//	cout << "������b" << endl;
//	cin >> b;
//
//	change(a, b);
//	cout << "�������a��bֵΪ" << endl;
//
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//}


//int main()
//{
//	int a = 0;
//	//1.���ñ����ʼ��
//	int& b = a;
//	//ps��һ�����������ж������
//
//	//2.���ñ�������ܸı�ָ��
//	int c = 2;
//	b = c;//���ﲻ�Ǹı�ָ�򣬶��Ǹ�ֵ
//	
//	cout << "&a=" << &a << endl;//a,bͬ��ַ
//	cout << "&b=" << &b << endl;
//	cout << "&c=" << &c << endl;//c��ͬ��ַ
//
//	cout << "a=" << a << endl;//2
//	cout << "b=" << b << endl;//2
//	cout << "c=" << c << endl;//2
//	return 0;
//}

//���ÿ������ָ��Ĵ󲿷ֹ���
//�����������ò��ܸı�ָ��������Щ��Ҫ�ı�ָ��ĳ�������Ҫָ��
//��������Ҫɾĳ���ڵ㣬ǰ��ڵ���Ҫ�ı�ָ��

//��ֵ�ʹ�����Ч�ʶԱ�
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


//����������ֵ
//int func()
//{
//	int a = 0;
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
//	//�������۷�����һ�����ֵ
//	//��Ϊfunc��ջ֡�����������ˣ�a�Ƿ���ԭ�ȵ�ֵ��δ֪��
//	//fun������main�����м������һ����ʱ����tmp�洢a��ֵ
//	//Ȼ���tmpֵ����ret
//	//��Ȼ���������ģ�����Ȼ�ǰ�ȫ��
//	cout <<"����1ret="  << ret << endl;
//	test();
//	cout << "����2ret=" << ret << endl;
//
//
//	int ret1 = func1();
//	//������һ��Ұ����
//	//ջ֡�Ѿ����٣��������û�������ԭ���ǿ��ַ��ֵ
//	//�ǲ���ȫ��
//	cout << "����1ret1=" << ret1 << endl;
//	test();
//	cout << "����2ret1=" << ret1 << endl;
//
//	//���ص㣩ʲô��������÷��أ�
//	//���ر�����������������������Ȼû�н���
//	//���羲̬����static���ε�
//	//����malloc�����ı�����ȫ�ֱ�������ջ�ı���
//	return 0;
//}

//#include<assert.h>
////����ʾ��
//struct Seqlist
//{
//	//����
//	int* a;//ͷ�ڵ�
//	int size;//��ǰ����
//	int capacity;//�������
//
//	//����
//	//����ṹ�����ܶ��庯������Ϊc++��struct����������
//	void Init()
//	{
//		a= (int*)malloc(sizeof(int) * 4);
//		size = 0;
//		capacity = 4;
//	}
//
//	void PushBack(int x)//β��
//	{
//		//..����
//		a[size++] = x;
//	}
//
//	int& SLGet(int pos)//��ȡposλ�ýڵ�ֵ
//	{
//		assert(pos >= 0);
//		assert(pos < size);
//		return a[pos];
//	}
//	//���ﷵ�ؽڵ�����ã������ط�����ֱ�ӶԽڵ�ֵ�޸�
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
//	cout <<"�ڵ�ֵ*2"<< endl;
//
//	for (int i = 0; i < 4; i++)
//	{
//		s.SLGet(i) *= 2;
//		cout << s.SLGet(i) << endl;
//	}
//	return 0;
//}


//���ú�ָ�������
//����1.������������Ͳ���������ϴ󣬼��ٿ��������Ч�ʣ�
//����2.������ֵ���޸ķ��ض��󣬼��ٿ��������Ч�ʣ�

//�﷨�ϣ�
//�����Ǳ����������ռ䣬ָ�뿪�ռ�
//�ײ��ϣ�
//���ú�ָ�붼���˿ռ䣨���õײ����ָ��ʵ�ֵģ�

//���ò��ܸı�ָ��ָ�����
//������԰�ȫ��û�п����ã����п�ָ��

#define add(a,b) ((a)+(b))
//c���Եĺ꣬���ab������������Ϊa��b�����Ǳ��ʽ
//�������Ԥ����׶ν����滻
//���ȱ����ǿӶ࣬�����׿��ƣ��Ҳ��ܵ��ԣ�û�����Ͱ�ȫ���

//c++�������Ժ�����˸Ľ�
//inline���εĺ������ڵ��õĵط�����չ��(������ջ֡)
inline int Add(int x ,int y)
{
	return x + y;
}
int main()
{
	int ret = Add(1,2) * 3;
	cout << ret << endl;
}