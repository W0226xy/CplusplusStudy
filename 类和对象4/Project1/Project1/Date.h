#pragma once
#include<iostream>
#include<assert.h>

using namespace std;
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1);

	Date(const Date& d);
	

	bool operator==(const Date& d2);
	

	Date& operator=(const Date& d2);//这里返回值返回Date也可以，不过返回一个大类型的值空间比较浪费，返回引用比较省空间
	
	bool operator<(const Date& d2);

	bool operator>(const Date& d2);

	bool operator>=(const Date& d2);

	bool operator<=(const Date& d2);

	bool operator!=(const Date& d2);

	Date& operator+=(int day);//日期+天数

	Date operator+(int day);

	Date operator-=(int day);

	Date operator-(int day);

	Date operator++();//前置++

	Date operator++(int);//后置++
	//前置++和后置++为了区分，祖师爷强行增加了一个int形参，构成了重载区分

	Date operator--();//前置--

	Date operator--(int);//后置--

	int operator-(const Date& d);

	int GetMonthDay(int year, int month)//获取某年某月一共多少天
	{
		assert(month > 0 && month < 13);
		int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//判断是否为闰年2月
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (month == 2)
			{
				return 29;
			}
		}
		return monthDays[month];
	}

	void print()
	{
		cout << _Year << "-" << _Month << "-" << _Day<<endl;
	}

	int tongNianCha(Date d)//相同年份的d1和d2差多少天
	{
		int sum = GetMonthDay(d._Year, d._Month) - d._Day;//先算出d到次月还有几天
		Date tmp(d);
		while (tmp < *this)//tmp的年<=原对象的年
		{
			if ((tmp._Month == _Month) && (tmp._Year == _Year))
			{
				sum += tmp._Day;
				return sum;
			}
			else
			{
				if (tmp._Month == _Month - 1)
				{
					sum += _Day;
					return sum;
				}
				else
				{
					tmp._Month++;
					if (tmp._Month > 12)
					{
						tmp._Year++;
						tmp._Month = 1;
					}
					sum += GetMonthDay(tmp._Year, tmp._Month);
				}
			}
		}
		return sum;
	}

	int YearDay()//获取当年一共多少天
	{
		if ((_Year % 4 == 0 && _Year % 100 != 0) || (_Year % 400 == 0))
		{
			return 366;
		}
		else
		{
			return 365;
		}
	}
private:
	int _Year;
	int _Month;
	int _Day;
};
