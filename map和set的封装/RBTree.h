#pragma once
#include<vector>
using namespace std;
#include <iostream>
enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

//T: 节点存储的数据类型
//Ref: 迭代器解引用类型
//Ptr: 迭代器指针类型
template<class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
            //中序遍历（左，根，右），当前节点的下一个节点，是右树最左节点
			Node* leftMin = _node->_right;
			while (leftMin->_left)
			{
				leftMin = leftMin->_left;
			}

			_node = leftMin;
		}
		else
		{
			// 下一个，孩子等于父亲左的那个祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}
};

template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
	Node* _root = nullptr;

public:
	typedef __RBTreeIterator<T, T&, T*> Iterator;
	typedef __RBTreeIterator<T, const T&, const T*> ConstIterator;

public:
    RBTree() = default;//要求编译器自动生成 RBTree 的默认构造函数。

	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

	RBTree(const RBTree<K,T,KeyOfT>& r)
	{
		_root = Copy(r._root);
	}
private:
	void Destroy(Node* root)
	{
		if (root)
		{
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}
	}
public:
	Node* Copy(Node* root)
	{
		if(root==nullptr)
			return nullptr;
		Node* newNode = new Node(root->_data);
		newNode->_col = root->_col;
		newNode->_left = Copy(root->_left);
		if(newNode->_left)
			newNode->_left->_parent = newNode;
		newNode->_right = Copy(root->_right);
		if(newNode->_right)
			newNode->_right->_parent = newNode;
		return newNode;
	}	
	
	Iterator Begin()
	{
		Node* leftMin = _root;
		while (leftMin && leftMin->_left)
		{
			leftMin = leftMin->_left;
		}

		return Iterator(leftMin);
	}

	Iterator End()
	{
		return Iterator(nullptr);
	}

	Iterator Find(const K& key)
{
    KeyOfT kot;
    Node* cur = _root;

    while (cur)
    {
        const K& curKey = kot(cur->_data);

        if (curKey < key)
        {
            cur = cur->_right;
        }
        else if (curKey > key)
        {
            cur = cur->_left;
        }
        else
        {
            return Iterator(cur);
        }
    }

    return End();
}

	ConstIterator Begin() const
	{
		Node* leftMin = _root;
		while (leftMin && leftMin->_left)
		{
			leftMin = leftMin->_left;
		}

		return ConstIterator(leftMin);
	}

	ConstIterator End() const
	{
		return ConstIterator(nullptr);
	}

	ConstIterator Find(const K& key) const
	{
		Node* cur = _root;
		while (cur)
		{
            KeyOfT kot;
			const K& curKey = kot(cur->_data);
			if (curKey < key)
			{
				cur = cur->_right;
			}
			else if (curKey > key)
			{
				cur = cur->_left;
			}
			else
			{
				return ConstIterator(cur);
			}
		}

		return End();
	}
public:
	pair<Iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(Iterator(_root), true);
		}

		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			// K
			// pair<K, V>
			// kot对象，是用来取T类型的data对象中的key
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else//有相同的key，说明已经存在
			{
				return make_pair(Iterator(cur), false);
			}
		}

		cur = new Node(data);
		cur->_col = RED; // 新增节点给红色
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		// parent的颜色是黑色也结束
		while (parent && parent->_col == RED)
		{
			// 关键看叔叔
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// 叔叔存在且为红，-》变色即可
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 叔叔不存在，或者存在且为黑
				{
					if (cur == parent->_left)
					{
						//     g  
						//   p   u
						// c 
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//      g  
						//   p     u
						//      c 
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				// 叔叔存在且为红，-》变色即可
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 叔叔不存在，或者存在且为黑
				{
					// 情况二：叔叔不存在或者存在且为黑
					// 旋转+变色
					//      g
					//   u     p
					//            c
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//		g
						//   u     p
						//      c
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;

		return make_pair(Iterator(cur), true);
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}

			subL->_parent = ppNode;
		}
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;

		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_right == parent)
			{
				ppNode->_right = subR;
			}
			else
			{
				ppNode->_left = subR;
			}
			subR->_parent = ppNode;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{
		if (_root->_col == RED)
		{
			return false;
		}

		int refNum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++refNum;
			}

			cur = cur->_left;
		}

		return Check(_root, 0, refNum);
	}

private:
	bool Check(Node* root, int blackNum, const int refNum)
	{
		if (root == nullptr)
		{
			//cout << blackNum << endl;
			if (refNum != blackNum)
			{
				cout << "存在黑色节点的数量不相等的路径" << endl;
				return false;
			}

			return true;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "存在连续的红色节点" << endl;
			return false;
		}

		if (root->_col == BLACK)
		{
			blackNum++;
		}

		return Check(root->_left, blackNum, refNum)
			&& Check(root->_right, blackNum, refNum);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

};
