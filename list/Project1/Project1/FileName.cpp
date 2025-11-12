#include<list>
#include <iostream>
using namespace std;
//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";//12341234
//		it++;
//	}
//	cout << endl << "==========" << endl;
//	
//	lt.reverse();
//	lt.sort();//默认排序是升序
//	for (auto e : lt)
//	{
//		cout << e << " ";//11223344
//	}
//	cout << endl<< "==========" << endl;
//	
//	lt.sort(greater<int>());//降序排序，加一个参数
//	for (auto e : lt)
//	{
//		cout << e << " ";//44332211
//	}
//	cout << endl << "==========" << endl;
//	lt.unique();//去重
//	for (auto e : lt)
//	{
//		cout << e << " ";//4321
//	}
//	cout << endl << "==========" << endl;
//	lt.splice(lt.end(), lt, lt.begin());//将begin位置的值转移到end位置，原先是4321，4转移到end的位置（1后面），begin变成了3，也就是3214
//	for (auto e : lt)
//	{
//		cout << e << " ";//3214
//	}
//
//}