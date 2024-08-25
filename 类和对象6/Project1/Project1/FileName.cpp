#include<iostream>
using namespace std;
int mian()
{
	int y = 0;
	int n = 0;
	cin >> y >> n;
	int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
	{
		MonthDay[2] = 29;
	}

	int m = 0;
	int d = 0;
	while (n > 0)
	{
		d = n;
		n = n - MonthDay[m];
		if (n > 0)
		{
			m++;
		}
	}
	cout << y << "-" << m << "-" << d;
	return 0;
}