#include<iostream>
using namespace std;

//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

//class Sum
//{
//public:
//    Sum()
//    {
//        _i++;
//        _ret += _i;
//    }
//    
//    static int GetRet()
//    {
//        return _ret;
//    }
//
// 
//private:
//    static int _i;//����
//    static int _ret;
//};
//
//int Sum::_i = 0;
//int Sum::_ret = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        Sum s[n];//ͨ������n��Sum������ʵ��_i++��_i�Ǿ�̬��Ա�������������г�Ա
//        return Sum::GetRet();
//    }
//};

//������������ڣ���������һ��ĵڼ��졣��֤���Ϊ4λ�������ںϷ���
//ʾ��������2012 12 31  ���366

//int main()
//{
//	int y = 0;
//	int m = 0;
//	int d = 0;
//
//	cin >> y >> m >> d;
//
//	int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//	{
//		MonthDay[2] = 29;
//	}
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < m; i++)
//	{
//		sum += MonthDay[i];
//	}
//	sum += d;
//	cout << sum;
//}


//�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int y = 0;
//	int n = 0;
//	cin >> y >> n;
//	int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//	{
//		MonthDay[2] = 29;
//	}
//
//	int m = 0;
//	int d = 0;
//	while (n > 0)
//	{
//		d = n;
//		n = n - MonthDay[m];
//		if (n > 0)
//		{
//			m++;
//		}
//	}
//	if (m < 10 && d < 10)
//	{
//		cout << y << "-" << 0 << m << "-" << 0 << d;
//	}
//
//	if (m < 10 && d >= 10)
//	{
//		cout << y << "-" << 0 << m << "-" << d;
//	}
//
//	if (m > 10 && d >= 10)
//	{
//		cout << y << "-" << m << "-" << d;
//	}
//
//	if (m > 10 && d < 10)
//	{
//		cout << y << "-" << m << "-" << 0 << d;
//	}
//
//	return 0;
//}
//	

//��Ԫ�����ã�

//��Ԫ����
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}

//��Ԫ�����ɷ������˽�кͱ�����Ա����������ĳ�Ա����
//��Ԫ����������const����
//��Ԫ�����������ඨ����κεط�����������������޶�������
//һ�����������Ƕ�������Ԫ����
//��Ԫ�����ĵ�������ͨ�����ĵ���ԭ����ͬ

//class Time
//{
//	friend class Date;   // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time��
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d(2024, 8, 23);
//	d.SetTimeOfDate(1, 1, 1);
//
//}


//�ڲ���
//class A
//{
//public:
//	class B
//	{
//		//1.B����A�����������
//		//2.�ڲ����������ⲿ�����Ԫ��,����ֱ�ӷ����ⲿ���˽��
//	public:
//		void func(A* p)
//		{
//			p->_a1++;
//		}
//	private:
//		int _b1;
//	};
//private:
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	cout << sizeof(A) << endl;//��ӡ8
//	//A�����B����һ����������ռ�ÿռ�
//
//	
//	A a;
//	A::B b;//����B�࣬��Ҫָ����A���µ�
//
//}

//��������
//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};

//int main()
//{
//	//�����������������ڵ�ǰ������
//	A a1;
//	A a2(10);
//
//	//��������,��������ֻ�ڵ�ǰһ��
//	A();
//	A(10);
//
//	// �������������������¾ͺܺ��ã���Ȼ����һЩ����ʹ�ó�������������Ժ���������˵
//	Solution().Sum_Solution(10);
//
//	//�����������ĳЩ��������һЩ������ͨ����������Ҳ��ȫ����
//}

//��������ʱ��һЩ�������Ż�
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void f1(A aa)
{}

void f2(const A& aa)
{

}

A f3()
{
	A aa;
	return aa;
}

A f4()
{
	return A();//����һ����������
}
int main()
{
	//���������Ż�
	//A aa1 = 2;//����+�������졪��������
	//const A& aa2 = 2;//ֱ�ӹ����ˣ�û�п�����ֱ���õ����ã�
	//
	//f1(aa1);//�������죬��aa1���������˺���f1��aa
	//f2(aa1);//�����ò��ᷢ����������

	//f1(A(2));//�����������ȹ������������ٿ�������aa���൱���ǹ���+�������졪��������
	
	//A tmp=f3();//�������Ż��ˣ������ǹ���+��������+�������죬����ȫ�Ż��˳�һ������

	//A ret = f4();//����+��������+�������졪�����Ż��ɣ�����

	A ret2;//����
	ret2 = f4();//����+A& operator=(const A& aa)
	return 0;
}

