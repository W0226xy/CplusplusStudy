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

Date& Date::operator=(const Date& d2)//这里返回值返回Date也可以，不过返回一个大类型的值空间比较浪费，返回引用比较省空间
{
	if (this == &d2)//自己给自己赋值
	{
		return *this;
	}
	this->_Day = d2._Day;
	this->_Month = d2._Month;
	this->_Year = d2._Year;//这里this也可以不写，默认访问成员变量就是this
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
	//eg:原先是1月20号，加15天
	//1月35号，35>31,35-31=4，就是2月4日
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
	Date tmp(*this);//用当前对象拷贝构造一个tmp对象
	//这里也可以写Date tmp=*this，这也是拷贝构造
	//两个原先都存在——赋值
	//一个存在，一个不存在——拷贝构造
	tmp += day;
	return tmp;
	//这里出了作用域tmp就不在了，不能用引用返回
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

Date Date::operator++()//前置++
{
	Date tmp(*this);
	tmp += 1;
	return tmp;
}

Date Date::operator++(int)//后置++
{
	Date tmp = *this;
	*this += 1;
	return tmp;//先用原先数据，后面再+1
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
int Date::operator-(const Date& d)//默认原对象日期>d日期
{
	int sum = 0;
	if (_Year == d._Year)
	{
		return tongNianCha(d);
	}
	//走到这说明原对象年份大于d年份

	//先计算出d日期到年末多少天
	Date tmp1(d._Year, 12, 31);
	sum += tmp1.tongNianCha(d);

	Date tmp(d._Year+1,1,1);

	while (tmp._Year < this->_Year)//获取中间差的年份的天数
	{
		tmp._Year++;
		sum += tmp.YearDay();
	}
	
	sum += tongNianCha(tmp);//最后加上原对象当年已经过去多少天
	sum += 1;
	return sum;
}