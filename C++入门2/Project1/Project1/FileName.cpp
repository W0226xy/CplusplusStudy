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
//	//�������أ���ͬ�������ͣ����߲���������ͬ��
//	//����ֵ����Ϊ���к������صı�׼
//
//	namespace qwy
//	{
//		//�����ռ����Ƕ��ʹ��
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

//io��
//int main()
//{
//	//1.����
//	int i = 100;
//	i=i << 1;
//
//	//2.������
//	cout << "100����һλ��" << i << endl;
//	//���Զ��������
//	//����������Զ�ʶ������
//
//	int x=0;
//	cout << "����������x" << endl;
//	cin >> x;
//	//cin������>>����ʾ�������
//	cout << "�������������" << x;
//}


//ȱʡ����
//1.ȫȱʡ��
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
////2.��ȱʡ
//void func2(int a,int b=20,int c=30)
//{//��ȱʡ�Ĳ��������������������
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//int main()
//{
//	func();//1
//	//���������ú�����Ĭ�ϲ���
//	func(2);//2
//
//	func1();//10,20,30
//	func1(1, 2);//1 2 30
//	//�����ĳ������������������������ʣ�µ��Ǹ���ȱʡ����
//	
//	cout << "�ָ���-----------" << endl;
//
//	//func2();//��ȱʡ����һ��������û�У��ᱨ��
//	func2(1);//1,20,30
//	func2(1, 2);//1,2,30
//	return 0;
//}