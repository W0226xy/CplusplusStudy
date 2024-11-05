#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
	//(int)顺序表
	vector<int> v;

	//尾插
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//遍历方法1
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;

	//遍历方法二
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	
}


void test2()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow" << endl;

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed" << sz << endl;
		}
	}

}

void test3()
{
	vector<int> a;
	a.resize(10, 0);//创建大小为10的顺序表a，用0进行初始化

	for (auto e : a)
	{
		cout << e << " ";//0 0 0 0 0 0 0 0 0 0
	}
	cout << endl;
}

void test4()
{
	vector<int> a;
	a.resize(100, 0);//创建大小为100的顺序表a，用0进行初始化

	cout << a.size() << endl;//100
	cout << a.capacity() << endl;//100
	cout << "--------" << endl;

	a.resize(10);//size变为10
	cout << a.size() << endl;//10
	cout << a.capacity() << endl;//100
	//这里size虽然变小了，但是capacity不会因此改变
	//如果size变大，并且超过capacity，capacity才会变

	cout << "------------" << endl;

	//如果需要缩容
	a.shrink_to_fit();
	cout << a.size() << endl;//10
	cout << a.capacity() << endl;//10
}

void test5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(9);
	v.push_back(3);
	for (auto e : v)
	{
		cout << e << " ";
	}

	cout << endl<<"---------" << endl;

	vector<int>::iterator pos=find(v.begin(), v.end(),3);//从顺序表begin查到end，查元素3在哪个位置
	//find函数需要头文件algorithm
	auto pos2 = find(v.begin(), v.end(), 3);//和上面一个效果

	if (pos != v.end())//在第一个3出现的位置前插入一个30
	{
		v.insert(pos, 30);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
}


void test6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v.insert(v.begin(), 0);//头插0
	for (auto e : v)
	{
		cout << e << " ";
	}

	cout << "---------" << endl;
	v.insert(v.begin()+2, 20);//2号下标位置插20
	for (auto e : v)
	{
		cout << e << " ";
	}


}

void test7()
{
	//对象数组
	vector<string> v;
	string s1("apple");
	v.push_back(s1);
	v.push_back(string("banana"));
	for (auto e : v)
	{
		cout << e << " ";
	}

	cout << endl << "----------" << endl;


	vector<vector<int>> vv;//类似哈希表的结构
	

}

class Solution {
public:
	int singleNumber(vector<int>& v) {
		int value = 0;
		for (auto e : v)
		{
			value ^= e;
			//x异或0=x
			//x异或x=0
			cout << value << endl;

		}
		return value;
	}
};

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();

	//test6();
	test7();
	return 0;
}


//int main() {
//	// 定义一个整数向量，包含一个数字只出现一次，其它数字出现两次
//	vector<int> nums = { 4, 1, 2, 1, 2 };
//
//	// 创建 Solution 对象
//	Solution solution;
//
//	// 调用 singleNumber 方法，并将结果输出
//	int result = solution.singleNumber(nums);
//	cout << "数组中唯一出现一次的数字是: " << result << endl;
//
//	return 0;
//}