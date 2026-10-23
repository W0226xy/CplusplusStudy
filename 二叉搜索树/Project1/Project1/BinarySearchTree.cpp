#include<iostream>
#include "BinarySearchTree.h"
using namespace std;
void TestBSTree1()
{
	int a[] = { 9,7,5,8,10,1,4,3,2,6 };
	BSTree<int> t1;
	for (auto e : a)
	{
		t1.Insert(e);
	}

	BSTreeNode<int>* root = t1.Get_root();
	t1.InOrder(root);

}

void TestBSTree2()
{
	BSTree<int> t;

	// ����һ��BST
	int arr[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	for (int x : arr)
	{
		t.Insert(x);
	}

	cout << "===== ��ʼ������� =====" << endl;
	t.InOrder(t.Get_root());

	// 1. ɾ��Ҷ�ӽڵ㣨7��
	cout << "\n===== ɾ��Ҷ�ӽڵ� 7 =====" << endl;
	t.Erase(7);
	t.InOrder(t.Get_root());

	// 2. ɾ��ֻ���������Ľڵ㣨14 -> ɾ����ֻ��13��
	cout << "\n===== ɾ���ڵ� 14��ֻ������������� =====" << endl;
	t.Erase(14);
	t.InOrder(t.Get_root());

	// 3. ɾ��ֻ���������Ľڵ㣨1��
	cout << "\n===== ɾ���ڵ� 1������/��������� =====" << endl;
	t.Erase(1);
	t.InOrder(t.Get_root());

	// 4. ɾ�������������еĽڵ㣨3��
	cout << "\n===== ɾ���ڵ� 3�������������У� =====" << endl;
	t.Erase(3);
	t.InOrder(t.Get_root());

	// 5. ɾ�����ڵ㣨8��
	cout << "\n===== ɾ�����ڵ� 8 =====" << endl;
	t.Erase(8);
	t.InOrder(t.Get_root());

	// 6. ɾ�������ڽڵ㣨100��
	cout << "\n===== ɾ�������ڽڵ� 100 =====" << endl;
	bool ret = t.Erase(100);
	cout << "Erase 100 result = " << ret << endl;

	cout << "\n===== ����������� =====" << endl;
	t.InOrder(t.Get_root());
}


void TestBSTree2()
{

}

int main()
{
	//TestBSTree1();//12345678910
	/*TestBSTree2();
	==== = ��ʼ������� ==== =
	1 3 4 6 7 8 10 13 14
	==== = ɾ��Ҷ�ӽڵ� 7 ==== =
	1 3 4 6 8 10 13 14
	==== = ɾ���ڵ� 14��ֻ������������� ==== =
	1 3 4 6 8 10 13
	==== = ɾ���ڵ� 1������ / ��������� ==== =
	3 4 6 8 10 13
	==== = ɾ���ڵ� 3�������������У� ==== =
	4 6 8 10 13
	==== = ɾ�����ڵ� 8 ==== =
	4 6 10 13
	==== = ɾ�������ڽڵ� 100 ==== =
	Erase 100 result = 0

	==== = ����������� ==== =
	4 6 10 13*/
}