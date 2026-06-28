#pragma once
#include<iostream>
using namespace std;
template<class k>

struct BSTreeNode//BinarySearchTree二叉搜索树
{
	BSTreeNode<k>* _left;
	BSTreeNode<k>* _right;
	k _key;

	BSTreeNode(const k& key)
		: _left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template<class k>
class BSTree
{
	typedef BSTreeNode<k> Node;
public:
	bool Insert(const k& key)
	{
		
		if (_root == nullptr)//判断是不是空树
		{
			_root = new BSTreeNode<int>(key);
		}
		Node* cur = _root;

		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return false;//已经有相同值，不让继续插入
			}
		}
		//找到对应位置了
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	void InOrder(Node* root)//中序遍历:左子树，中间节点，右子树
	{
		if (root == nullptr)
		{
			return;
		}
		InOrder(root->_left);
		cout << root->_key << " ";
		InOrder(root->_right);
	}

	Node* Get_root()//获得根节点
	{
		return _root;
	}

	bool Find(const k& key)
	{
		Node* cur = _root;

		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;//找到对应位置了
			}
		}
		return false;
	}

	bool Erase(const k& key)//删除值为k的节点（用左子树最大节点替换，或者用右子树最小节点替换）
	{
		Node* cur = _root;

		Node* parent = nullptr;
		while (cur)
		{
			
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else//找到了对应值为k的节点(当前cur指向这个节点)
			{
				//删除
				if (cur->_left == nullptr)//左子树为空，父节点指向当前节点右子树
				{
					if (cur == _root)//它自己就是根节点，上面已经没有父节点了
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)//当前节点是父节点左孩子
						{
							parent->_left = cur->_right;
						}
						else//当前节点是父节点右孩子
						{
							parent->_right = cur->_right;
						}
						delete cur;
					}
					
				}
				else if(cur->_right==nullptr)//右子树为空，父节点指向当前节点左子树
				{
					if (cur == _root)//它自己就是根节点，上面已经没有父节点了
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)//当前节点是父节点左孩子
						{
							parent->_left = cur->_left;
						}
						else//当前节点是父节点右孩子
						{
							parent->_right = cur->_left;
						}
						delete cur;
					}
				}
				else//左右子树都不为空，替换法删除（用左子树最大（左字数最右节点）或者右子树最小（右子树最左节点）来替换）
				{
					//以找右子树最小为例
					Node* rightMinParent = cur;//记录右子树最小节点的父节点
					Node* rightMin = cur->_right;
					while (rightMin->_left)
					{
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}
					//到这里说明已经没有更左的节点了（但是当前节点是否有右子树不确定）
					
					swap(cur->_key, rightMin->_key);
					if (rightMinParent->_left == rightMin)//右边最小是它父节点的左孩子
					{
						rightMinParent->_left = rightMin->_right;//右边最小说明它自己没有左孩子了
					}
					else//右边最小是它父节点的右孩子
					{
						rightMinParent->_right = rightMin->_right;
					}
					
					delete rightMin;
				}
				return true;
			}
		}
		return false;//没有值为k的节点
	}

private:

private:
	Node* _root = nullptr;
};


