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
	

	Date& operator=(const Date& d2);//���ﷵ��ֵ����DateҲ���ԣ���������һ�������͵�ֵ�ռ�Ƚ��˷ѣ��������ñȽ�ʡ�ռ�
	
	bool operator<(const Date& d2);

	bool operator>(const Date& d2);

	bool operator>=(const Date& d2);

	bool operator<=(const Date& d2);

	bool operator!=(const Date& d2);

	Date& operator+=(int day);//����+����

	Date operator+(int day);

	Date operator-=(int day);

	Date operator-(int day);

	Date operator++();//ǰ��++

	Date operator++(int);//����++
	//ǰ��++�ͺ���++Ϊ�����֣���ʦүǿ��������һ��int�βΣ���������������

	Date operator--();//ǰ��--

	Date operator--(int);//����--

	int operator-(const Date& d);

	int GetMonthDay(int year, int month)//��ȡĳ��ĳ��һ��������
	{
		assert(month > 0 && month < 13);
		int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//�ж��Ƿ�Ϊ����2��
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

	int tongNianCha(Date d)//��ͬ��ݵ�d1��d2�������
	{
		int sum = GetMonthDay(d._Year, d._Month) - d._Day;//�����d�����»��м���
		Date tmp(d);
		while (tmp < *this)//tmp����<=ԭ�������
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

	int YearDay()//��ȡ����һ��������
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
