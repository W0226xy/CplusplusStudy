#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
void test1()
{
	srand(time(0));
	const int N = 1000000;
	list<int> lt1;
	list<int> lt2;
	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		auto e = rand();
		lt1.push_back(e);
		v.push_back(e);
	}

	int begin1 = clock();
	//排序
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	lt1.sort();
	int end2 = clock();

	printf("vector sort time:%d\n", end1 - begin1);
	printf("list sort time:%d\n", end2 - begin2);
	//vector sort time:303
	//list sort time : 754
	//vector排序时间明显要比list快很多
}

int main()
{
	test1();
}