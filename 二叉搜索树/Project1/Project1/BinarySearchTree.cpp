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

	// 构造一棵BST
	int arr[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
	for (int x : arr)
	{
		t.Insert(x);
	}

	cout << "===== 初始中序遍历 =====" << endl;
	t.InOrder(t.Get_root());

	// 1. 删除叶子节点（7）
	cout << "\n===== 删除叶子节点 7 =====" << endl;
	t.Erase(7);
	t.InOrder(t.Get_root());

	// 2. 删除只有左子树的节点（14 -> 删除后只有13）
	cout << "\n===== 删除节点 14（只有左子树情况） =====" << endl;
	t.Erase(14);
	t.InOrder(t.Get_root());

	// 3. 删除只有右子树的节点（1）
	cout << "\n===== 删除节点 1（无子/单边情况） =====" << endl;
	t.Erase(1);
	t.InOrder(t.Get_root());

	// 4. 删除左右子树都有的节点（3）
	cout << "\n===== 删除节点 3（左右子树都有） =====" << endl;
	t.Erase(3);
	t.InOrder(t.Get_root());

	// 5. 删除根节点（8）
	cout << "\n===== 删除根节点 8 =====" << endl;
	t.Erase(8);
	t.InOrder(t.Get_root());

	// 6. 删除不存在节点（100）
	cout << "\n===== 删除不存在节点 100 =====" << endl;
	bool ret = t.Erase(100);
	cout << "Erase 100 result = " << ret << endl;

	cout << "\n===== 最终中序遍历 =====" << endl;
	t.InOrder(t.Get_root());
}


void TestBSTree2()
{

}

int main()
{
	//TestBSTree1();//12345678910
	/*TestBSTree2();
	==== = 初始中序遍历 ==== =
	1 3 4 6 7 8 10 13 14
	==== = 删除叶子节点 7 ==== =
	1 3 4 6 8 10 13 14
	==== = 删除节点 14（只有左子树情况） ==== =
	1 3 4 6 8 10 13
	==== = 删除节点 1（无子 / 单边情况） ==== =
	3 4 6 8 10 13
	==== = 删除节点 3（左右子树都有） ==== =
	4 6 8 10 13
	==== = 删除根节点 8 ==== =
	4 6 10 13
	==== = 删除不存在节点 100 ==== =
	Erase 100 result = 0

	==== = 最终中序遍历 ==== =
	4 6 10 13*/
}