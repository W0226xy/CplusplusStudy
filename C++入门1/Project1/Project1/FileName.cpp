#include<stdio.h>
#include<iostream>
int x = 0;
using namespace std;
namespace wxy
{
	int x = 2;
	int add(int a, int b)
	{
		return a + b;
	}

	struct	Node
	{
		int a = 4;
	};
}
int main()
{
	int x = 1;
	printf("%d\n", x);//1
	printf("%d\n", ::x);//0
	printf("%d\n", wxy::x);//2
	//::�������޶���
	//::x��ʾȫ�ֵ�x
	//wxy::x��ʾ�����ռ�wxy�µ�x
	//�����ָ������Ĭ�ϵ�ǰ��
	//�����ͬ���������ռ䣬������������ռ��µ����ݺϲ�
	// ����ͬ�ռ��²�������ͬ���ݣ�����ϲ��ᱨ��
	int y = wxy::add(1, 2);
	printf("%d\n", y);//3

	struct wxy::Node node;
	//�����ռ�ṹ��Ķ��巽ʽ��
	//struct �����ռ���::�ṹ������ �ṹ����
	printf("%d\n", node.a);//4

	cout << "hello" << endl;
	return 0;
}


