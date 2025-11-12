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
//	Date& operator=(const Date& d2)//这里返回值返回Date也可以，不过返回一个大类型的值空间比较浪费，返回引用比较省空间
//	{
//		if (this == &d2)//自己给自己赋值
//		{
//			return *this;
//		}
//		this->_Day = d2._Day;
//		this->_Month = d2._Month;
//		this->_Year = d2._Year;//这里this也可以不写，默认访问成员变量就是this
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
//	cout << (d1.operator==(d2)) << endl;//和上面是一样的效果
//
//	cout << (d2 < d1) << endl;
//
//	Date d3(d1);//同类型对象进行初始化（一个存在，一个不存在）
//	
//	d3.print();
//
//	d1 = d2;//赋值（两个都存在）
//	d1.print();
//
//	Date d4(2024, 8, 19);
//	d1 = d2 = d3 = d4;
//	
//	d1.print();
//	return 0;
//}
//不一定所有d1=d2都是赋值
//主要看是否两个原先都存在
//两个原先都存在——赋值
//一个存在，一个不存在——拷贝构造


#include"Date.h"
//int main()
//{
//	Date d1(2024, 8, 19);
//	Date d2 = d1 + 20;
//	/*d2.print();
//	d1.print();
//
//	d2 -= 20;
//	d2.print();*/
//
//	d1 += 5000;
//	d1.print();
//
//	/*d2++;
//	d2.print();*/
//
//	Date d3(2038, 4, 28);
//	Date d4(2024, 8, 19);
//	int x = d3 - d4;
//	cout << x << endl;
//	return 0;
//}

/*int main()
{
	Date d(2024, 8, 20);
	cout << d << endl;;

	Date d1(2024, 8, 30);
	cout << d << d1 << endl;
}*/	