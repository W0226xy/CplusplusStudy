#include<iostream>
using namespace std;
//ģ��

//����ģ��
//ģ���ʽ
//template<typename T1,typename T2...typename Tn>
//����ֵ����  �������������б�{}

//template<typename T>//templateģ�����˼
//void Swap(T& x ,T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<typename T>
//T Add(const T& l, const T& r)
//{
//	return l + r;
//}
//
////Ҳ����д������ͬ�Ĳ����������Ͳ�Ҫ�����Ĳ�������ͳһ��
//template<class T1 ,class T2>//template������class�滻
//T1 Add(const T1& l, const T2& r)
//{
//	return l + r;//����ֵ��T1���ͣ�T2��ͳһǿתΪT1�����T2��T1���Ͳ�һ����
//}
//
//int Add(const int& l, const int& r)//������ģ�����ͬʱ���ڣ������������ƥ�䣬������ʹ�ú���
//{
//	return l + r;
//}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//
//	double c = 1.234;
//	double d = 3.141;
//	Swap(a, b);
//	Swap(c, d);
//	cout <<"a=" << a <<"b=" <<b<< endl;//a=2,b=1
//	cout << "c=" << c << "d=" << d << endl;//c=3.141,d=1,234
//
//	//Swap(a, c);�����ͻᱨ��ģ��������Ͳ���ȷ
//	//��������֪��������ǿת��int������ǿת��double
//	
//	//��ʾʵ����
//	cout<<Add<int>(a, c)<<endl;//Add<int>ָ��ģ���е�Tȫ��int���ͣ�c�ᷢ��ǿת
//
//	cout << Add(b, d) << endl;//����T1 Add(const T1& l, const T2& r)
//
//	return 0;
//}


//��ģ��
template<class T>
class Stack
{
public:
	void Push(const T& x)
	{}
private:
	T* _a;
	int _top;
	int _capacity;
};

int main()
{
	Stack<int> s1;
	Stack<double> s2;
}