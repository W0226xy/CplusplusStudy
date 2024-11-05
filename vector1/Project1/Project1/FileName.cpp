#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
	//(int)˳���
	vector<int> v;

	//β��
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//��������1
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;

	//����������
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
	a.resize(10, 0);//������СΪ10��˳���a����0���г�ʼ��

	for (auto e : a)
	{
		cout << e << " ";//0 0 0 0 0 0 0 0 0 0
	}
	cout << endl;
}

void test4()
{
	vector<int> a;
	a.resize(100, 0);//������СΪ100��˳���a����0���г�ʼ��

	cout << a.size() << endl;//100
	cout << a.capacity() << endl;//100
	cout << "--------" << endl;

	a.resize(10);//size��Ϊ10
	cout << a.size() << endl;//10
	cout << a.capacity() << endl;//100
	//����size��Ȼ��С�ˣ�����capacity������˸ı�
	//���size��󣬲��ҳ���capacity��capacity�Ż��

	cout << "------------" << endl;

	//�����Ҫ����
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

	vector<int>::iterator pos=find(v.begin(), v.end(),3);//��˳���begin�鵽end����Ԫ��3���ĸ�λ��
	//find������Ҫͷ�ļ�algorithm
	auto pos2 = find(v.begin(), v.end(), 3);//������һ��Ч��

	if (pos != v.end())//�ڵ�һ��3���ֵ�λ��ǰ����һ��30
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

	v.insert(v.begin(), 0);//ͷ��0
	for (auto e : v)
	{
		cout << e << " ";
	}

	cout << "---------" << endl;
	v.insert(v.begin()+2, 20);//2���±�λ�ò�20
	for (auto e : v)
	{
		cout << e << " ";
	}


}

void test7()
{
	//��������
	vector<string> v;
	string s1("apple");
	v.push_back(s1);
	v.push_back(string("banana"));
	for (auto e : v)
	{
		cout << e << " ";
	}

	cout << endl << "----------" << endl;


	vector<vector<int>> vv;//���ƹ�ϣ��Ľṹ
	

}

class Solution {
public:
	int singleNumber(vector<int>& v) {
		int value = 0;
		for (auto e : v)
		{
			value ^= e;
			//x���0=x
			//x���x=0
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
//	// ����һ����������������һ������ֻ����һ�Σ��������ֳ�������
//	vector<int> nums = { 4, 1, 2, 1, 2 };
//
//	// ���� Solution ����
//	Solution solution;
//
//	// ���� singleNumber ����������������
//	int result = solution.singleNumber(nums);
//	cout << "������Ψһ����һ�ε�������: " << result << endl;
//
//	return 0;
//}