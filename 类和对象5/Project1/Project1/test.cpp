#include<iostream>
using namespace std;
//class A
//{
//public:
//	A* operator&()//�����и����ز���A* this
//	{
//		return this;
//	}
//
//	const A* operator&() const
//	{
//		return this;
//	}
//	//���������������㲻д��������Ҳ���Զ�����
//	//���Ǽ򵥵ķ��ض���ĵ�ַ
//
//	//��Ҫ��д�������������ĳ��������粻����ͨ���������ĵ�ַ��������д����һ��nullptr
//};

//int main()
//{
//	A a1;
//	const A a2;
//
//	cout << &a1 << endl;
//	cout << &a2 << endl;
//}

//��ʼ���б�

//1. ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��(��ʼ��ֻ�ܳ�ʼ��һ��)
//2. ���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ����
//���ó�Ա����
//const��Ա����
//�Զ������ͳ�Ա(�Ҹ���û��Ĭ�Ϲ��캯��ʱ)

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)����" << endl;
//	}
//private:
//	int _a;
//};
//
//
//class Date
//{
//public:
//	Date(int year, int month, int day, int& x)//��ʼ���б�����ͨ�Ĺ��캯��ûɶ���𣬶��ǳ�ʼ��
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _n(1)//const��Ա�����߳�ʼ���б�
//		, _ref(x)
//		,_aa(1)//����A�Ĺ���
//	{
//		cout << "Date(int year, int month, int day, int& x)����" << endl;
//	}
//
//	//��ʼ���б�Ҳ���Ժ͹��캯������
//	//Date(int year, int month, int day)//��ʼ���б�����ͨ�Ĺ��캯��ûɶ���𣬶��ǳ�ʼ��
//	//	: _n(1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	//�������������߳�ʼ���б��ʼ�������������޷��������������г�ʼ����
//	const int _n;//const����Ķ����Ա�������ڶ����ʱ��ͳ�ʼ������Ϊ��ֻ��һ���޸Ļ���
//	int& _ref;
//	A _aa;
//};
//int main()
//{
//	int x = 32;
//	Date d1(2024, 1, 31,x);
//	return 0;
//}


//��ʽ����ת��
//class A
//{
//public:
//	A(int a1)
//		:_a1(a1)
//	{}
//
//private:
//	int _a1;
//	
//};
//
//class B
//{
//public:
//	B(int b1,int b2)
//		:_b1(b1)
//		,_b2(b2)
//	{}
//
//private:
//	int _b1;
//	int _b2;
//};
//
//int main()
//{
//	A a = 1;//����ᷢ��һ����ʽ����ת��������1����һ��A(1),Ȼ��ֵ��a
//	B b = { 1,2 };//������һ�����൱���ȹ���һ��B(1,2)��Ȼ��ֵ��b
//}

//�����Ͷ������ϰ��
//class A
//{
//public:
//    A(int a)
//        :_a1(a)
//        , _a2(_a1)
//    {}
//
//    void Print() {
//        cout << _a1 << " " << _a2 << endl;
//    }
//private:
//    int _a2;
//    int _a1;
//};
//int main() {
//    A aa(1);
//    //��1��ȥ����A
//    //���ǲ��ܳ�ʼ��˳����Σ�ʵ�ʳ�ʼ����˳���ǰ��ն�������
//    //���������ȶ�����a2���������ȳ�ʼ��a2
//    
//    aa.Print();//��ӡ 1 -858993460
//}


//explict
//class Date
//{
//public:
//	// 1. ���ι��캯����û��ʹ��explicit���Σ���������ת������
//	 // explicit���ι��캯������ֹ����ת��---explicitȥ��֮�󣬴������ͨ������
//	explicit Date(int year)
//		:_year(year)
//	{}
//	/*
//	// 2. ��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���
//   ������ת������
//	// explicit���ι��캯������ֹ����ת��
//	explicit Date(int year, int month = 1, int day = 1)
//	: _year(year)
//	, _month(month)
//	, _day(day)
//	{}
//	*/
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2022);
//	// ��һ�����α������������Ͷ���ֵ
//	
//	// ʵ�ʱ������������2023����һ������������������������d1������и�ֵ
//	//d1 = 2023;//�������explicit��û�а취������ʽת�������Ҫʹ��d1=2023�ɹ����룬����Ҫ����explicit
//}


//��̬��Ա����
//Ӧ�ð������㴴���˼�������
class A
{
public:
	A()
	{
		n++;
	}

	A(const A& aa)
	{
		n++;
	}

	static void GetN()//��̬��Ա����������ĳ���ض�����������Ҳû��thisָ��
	{
		cout << n << endl;
	}
public:
	//��̬��Ա��������
	static int n;//���������࣬��������ĳ������
};

int A::n = 0;//��̬��Ա����������Ҫ��������

A func()
{
	A aa;//3
	return aa;//ʵ�������ﴫֵ���ػ�������һ�Σ�ֻ����������������Ż��ˣ���������㲻��ȡ����ͬ������
}

int main()
{
	A aa1;//1
	A aa2;//2
	func();//����������Ż��ˣ�ֻ����1��
	A* ptr = nullptr;//û�д�������

	//�����ĸ���һ��������n���ھ�̬��Ա����������������
	cout << aa1.n << endl;//��ӡ3
	cout << aa2.n << endl;
	cout << A::n << endl;
	
	cout << ptr->n << endl;//��ӡ3����Ȼptrָ��n������n������ptrָ��Ķ����У����ھ�̬��������Ҫ��ptr������

	//ps�������n�ķ��ʻ���n��public�ģ����n��private��������ṩһ�����ʺ���,������ʾ
	aa1.GetN();//��̬��Ա����Ҳ�����ڹ��е�
	aa2.GetN();
	A::GetN();
}