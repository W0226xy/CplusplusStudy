#include "Date.h"
Date::Date(int year , int month , int day )
{
	_Year = year;
	_Month = month;
	_Day = day;
}

Date::Date(const Date& d)
{
	_Year = d._Year;
	_Month = d._Month;
	_Day = d._Day;
}

bool Date::operator==(const Date& d2)
{
	return _Year == d2._Year
		&& _Month == d2._Month
		&& _Day == d2._Day;
}

Date& Date::operator=(const Date& d2)//���ﷵ��ֵ����DateҲ���ԣ���������һ�������͵�ֵ�ռ�Ƚ��˷ѣ��������ñȽ�ʡ�ռ�
{
	if (this == &d2)//�Լ����Լ���ֵ
	{
		return *this;
	}
	this->_Day = d2._Day;
	this->_Month = d2._Month;
	this->_Year = d2._Year;//����thisҲ���Բ�д��Ĭ�Ϸ��ʳ�Ա��������this
	return *this;
}

bool Date::operator<(const Date& y)
{
	if (this->_Year < y._Year)
	{
		return true;
	}
	else if (this->_Year == y._Year)
	{
		if (this->_Month < y._Month)
		{
			return true;
		}
		else if (this->_Month == y._Month)
		{
			if (this->_Day < y._Day)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}

bool Date::operator>(const Date& d2)
{
	return !(*this <= d2);
}


bool Date::operator>=(const Date& d2)
{
	return *this > d2 || *this == d2;
}

bool Date::operator<=(const Date& d2)
{
	return *this < d2 || *this == d2;
}

bool Date::operator!=(const Date& d2)
{
	return !(*this == d2);
}


Date& Date::operator+=(int day)
{
	//eg:ԭ����1��20�ţ���15��
	//1��35�ţ�35>31,35-31=4������2��4��
	_Day += day;
	while (_Day > GetMonthDay(_Year,_Month))
	{
		_Day -= GetMonthDay(_Year, _Month);
		_Month++;
		if (_Month == 13)
		{
			_Year++;
			_Month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp(*this);//�õ�ǰ���󿽱�����һ��tmp����
	//����Ҳ����дDate tmp=*this����Ҳ�ǿ�������
	//����ԭ�ȶ����ڡ�����ֵ
	//һ�����ڣ�һ�������ڡ�����������
	tmp += day;
	return tmp;
	//�������������tmp�Ͳ����ˣ����������÷���
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date Date::operator-=(int day)
{
	_Day -= day;
	while (_Day <= 0)
	{
		_Month--;
		if (_Month < 0)
		{
			_Year--;
			_Month = 12;
		}

		_Day += GetMonthDay(_Year,_Month);
	}
	return *this;
}

Date Date::operator++()//ǰ��++
{
	Date tmp(*this);
	tmp += 1;
	return tmp;
}

Date Date::operator++(int)//����++
{
	Date tmp = *this;
	*this += 1;
	return tmp;//����ԭ�����ݣ�������+1
}

Date Date::operator--()
{
	Date tmp(*this);
	tmp -= 1;
	return tmp;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}




//date1-date2
int Date::operator-(const Date& d)//Ĭ��ԭ��������>d����
{
	int sum = 0;
	if (_Year == d._Year)
	{
		return tongNianCha(d);
	}
	//�ߵ���˵��ԭ������ݴ���d���

	//�ȼ����d���ڵ���ĩ������
	Date tmp1(d._Year, 12, 31);
	sum += tmp1.tongNianCha(d);

	Date tmp(d._Year+1,1,1);

	while (tmp._Year < this->_Year)//��ȡ�м�����ݵ�����
	{
		tmp._Year++;
		sum += tmp.YearDay();
	}
	
	sum += tongNianCha(tmp);//������ԭ�������Ѿ���ȥ������
	sum += 1;
	return sum;
}