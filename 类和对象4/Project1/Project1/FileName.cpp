#include<iostream>
using namespace std;
//class Date
//{
//public:
//	Date(int year = 1,int month = 1,int day=1)
//	{
//		_Year = year;
//		_Month = month;
//		_Day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_Year = d._Year;
//		_Month = d._Month;
//		_Day = d._Day;
//	}
//
//	bool operator==(const Date& d2)
//	{
//		return _Year == d2._Year
//		&& _Month == d2._Month
//			&& _Day == d2._Day;
//	}
//
//	Date& operator=(const Date& d2)//���ﷵ��ֵ����DateҲ���ԣ���������һ�������͵�ֵ�ռ�Ƚ��˷ѣ��������ñȽ�ʡ�ռ�
//	{
//		if (this == &d2)//�Լ����Լ���ֵ
//		{
//			return *this;
//		}
//		this->_Day = d2._Day;
//		this->_Month = d2._Month;
//		this->_Year = d2._Year;//����thisҲ���Բ�д��Ĭ�Ϸ��ʳ�Ա��������this
//		return *this;
//	}
//
//	bool operator<(const Date& y)
//	{
//		if (this->_Year < y._Year)
//		{
//			return true;
//		}
//		else if (this->_Year == y._Year)
//		{
//			if (this->_Month < y._Month)
//			{
//				return true;
//			}
//			else if (this->_Month == y._Month)
//			{
//				if (this->_Day < y._Day)
//				{
//					return true;
//				}
//				else
//				{
//					return false;
//				}
//			}
//			else
//			{
//				return false;
//			}
//		}
//	}
//
//	void print()
//	{
//		cout << _Year << "-" << _Month << "-" << _Day<<endl;
//	}
//private:
//	int _Year;
//	int _Month;
//	int _Day;
//};
//int main()
//{
//	Date d1(2024, 8, 18);
//	Date d2(2024, 7, 16);
//	cout << (d1 == d2) << endl;
//	cout << (d1.operator==(d2)) << endl;//��������һ����Ч��
//
//	cout << (d2 < d1) << endl;
//
//	Date d3(d1);//ͬ���Ͷ�����г�ʼ����һ�����ڣ�һ�������ڣ�
//	
//	d3.print();
//
//	d1 = d2;//��ֵ�����������ڣ�
//	d1.print();
//
//	Date d4(2024, 8, 19);
//	d1 = d2 = d3 = d4;
//	
//	d1.print();
//	return 0;
//}
//��һ������d1=d2���Ǹ�ֵ
//��Ҫ���Ƿ�����ԭ�ȶ�����
//����ԭ�ȶ����ڡ�����ֵ
//һ�����ڣ�һ�������ڡ�����������


#include"Date.h"
int main()
{
	Date d1(2024, 8, 19);
	Date d2 = d1 + 20;
	/*d2.print();
	d1.print();

	d2 -= 20;
	d2.print();*/

	d1 += 5000;
	d1.print();

	/*d2++;
	d2.print();*/

	Date d3(2038, 4, 28);
	Date d4(2024, 8, 19);
	int x = d3 - d4;
	cout << x << endl;
	return 0;
}