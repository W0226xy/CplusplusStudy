#pragma once
#include<vector>
#include<utility>

//红黑树规则：重点2,4,5
// 1.节点颜色：每个节点不是红色就是黑色。
// 2.根节点是黑色：根节点必须为黑色。
// 3.叶子节点是黑色：这里的"叶子"指 NIL 空节点（哨兵节点），也必须是黑色。也就是说，红色节点的左右孩子不能为空。
// 4.红色节点不能有红色孩子（不能出现连续红节点）：即红色节点的两个子节点必须都是黑色，每个红节点的父节点也必须是黑色。
// 5.黑色高度相同：从任意节点到其每个叶子（NIL）的路径上，经过的黑色节点数量必须相同（每条路径黑节点数量相同）。
enum Colour
{
	RED,
	BLACK
};

template<typename K, typename V>
struct RBTreeNode
{
    RBTreeNode<K,V>* _parent;
    RBTreeNode<K,V>* _left;
    RBTreeNode<K,V>* _right;
    Colour _col;
    pair<K,V> _kv;

    RBTreeNode(const pair<K, V>& kv)
    :_left(nullptr)
    , _right(nullptr)
    , _parent(nullptr)
    , _kv(kv)
    , _col(RED)
	{}

};

template<typename K, typename V>
class RBTree
{
    typedef RBTreeNode<K,V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
            _root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
        cur->_col=RED;//新增节点给红色
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

        //如果父节点是红色，需要进行调整（黑色结束）
        while(parent && parent->_col==RED)
        {
            Node* grandparent = parent->_parent;
            if (grandparent == nullptr)
            {
                parent->_col = BLACK;
                break;
            }
            if(parent == grandparent->_left)
            {
                Node* uncle = grandparent->_right;
                // 如果叔叔节点是红色，变色即可
                if(uncle && uncle->_col == RED)
                {
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandparent->_col = RED;
                    //继续往上处理
                    cur = grandparent;
                    parent = cur->_parent;
                }
                else//叔叔节点不存在或者为黑色，需要进行变色+旋转调整
                {
                    if(cur==parent->_left)
                    {
                        // 右旋
                        RotateRight(grandparent);
                        parent->_col=BLACK;
                        grandparent->_col = RED;
                        
                    }
                    else
                    {
                        // 左旋
                        RotateLeft(parent);
                        RotateRight(grandparent);
                        cur->_col=BLACK;
                        grandparent->_col = RED;
                       
                    }
                    break;
                }
            }
            else
            {
                Node* uncle = grandparent->_left;
                // 如果叔叔节点是红色，变色即可
                if(uncle && uncle->_col == RED)
                {
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandparent->_col = RED;
                    //继续往上处理
                    cur = grandparent;
                    parent = cur->_parent;
                }
                else//叔叔节点不存在或者为黑色，需要进行变色+旋转调整
                {
                    if(cur==parent->_right)
                    {
                        // 左旋
                        RotateLeft(grandparent);
                        parent->_col=BLACK;
                        grandparent->_col = RED;
                    }
                    else
                    {
                        // 右旋
                        RotateRight(parent);
                        RotateLeft(grandparent);
                        cur->_col=BLACK;
                        grandparent->_col = RED;
                    }
                    break;
                }
            }

        }


        // 最后根节点必须是黑色
        _root->_col = BLACK;
        ++_size;
        return true;
    }

    	void RotateRight(Node* parent)
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

	void RotateLeft(Node* parent)
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
        std::cout << std::endl;
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
    Node* _root=nullptr;
    size_t _size=0;
    void _InOrder(Node* node)
    {
        if (!node) return;
        _InOrder(node->_left);
        std::cout << node->_kv.first << " ";
        _InOrder(node->_right);
    }

    
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


public:
    RBTree() : _root(nullptr) {}
    
};

void TestRBTree1()
{
	//int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14,8, 3, 1, 10, 6, 4, 7, 14, 13 };
	RBTree<int, int> t1;
	for (auto e : a)
	{
		if (e == 10)
		{
			int i = 0;
		}

		// 1、先看是插入谁导致出现的问题
		// 2、打条件断点，画出插入前的树
		// 3、单步跟踪，对比图一一分析细节原因
		t1.Insert({ e,e });

		cout << "Insert:" << e  << endl;
	}

	t1.InOrder();

}

void TestRBTree2()
{
	const int N = 100;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
		//cout << v.back() << endl;
	}

	size_t begin2 = clock();
	RBTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
		cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	size_t end2 = clock();

}
