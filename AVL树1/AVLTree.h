#pragma once

#include <cassert>
#include <iostream>
#include <utility>

template<class K, class V>
struct AVLTreeNode
{
    AVLTreeNode<K, V>* _left;
    AVLTreeNode<K, V>* _right;
    AVLTreeNode<K, V>* _parent;

    std::pair<K, V> _kv;   // 键值对
    int _bf;               // 平衡因子：右子树高度 - 左子树高度

    AVLTreeNode(const std::pair<K, V>& kv)
        : _left(nullptr)
        , _right(nullptr)
        , _parent(nullptr)
        , _kv(kv)
        , _bf(0)
    {
    }
};

template<class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;

public:
    AVLTree()
        : _root(nullptr)
    {
    }

    // 防止发生浅拷贝
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    ~AVLTree()
    {
        _Destroy(_root);
        _root = nullptr;
    }

    bool Insert(const std::pair<K, V>& kv)
    {
        // 插入第一个节点
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }

        Node* parent = nullptr;
        Node* cur = _root;

        // 按照二叉搜索树规则查找插入位置
        while (cur)
        {
            if (cur->_kv.first < kv.first)
            {
                // 新节点应该放到右子树
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > kv.first)
            {
                // 新节点应该放到左子树
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                // key 已经存在，不允许重复插入
                return false;
            }
        }

        // 创建新节点
        cur = new Node(kv);

        // 将新节点连接到父节点
        if (parent->_kv.first < kv.first)
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }

        cur->_parent = parent;

        // 向上更新平衡因子
        while (parent)
        {
            if (cur == parent->_left)
            {
                parent->_bf--;
            }
            else
            {
                parent->_bf++;
            }

            // 父节点平衡因子为 0，说明高度没有继续增加
            if (parent->_bf == 0)
            {
                break;
            }
            // 平衡因子为 1 或 -1，继续向上更新
            else if (parent->_bf == 1 || parent->_bf == -1)
            {
                cur = parent;
                parent = parent->_parent;
            }
            // 平衡因子为 2 或 -2，需要旋转
            else if (parent->_bf == 2 || parent->_bf == -2)
            {
                // LL 型：右旋
                if (parent->_bf == -2 && cur->_bf == -1)
                {
                    RotateR(parent);
                }
                // RR 型：左旋
                else if (parent->_bf == 2 && cur->_bf == 1)
                {
                    RotateL(parent);
                }
                // RL 型：先右旋 cur，再左旋 parent
                else if (parent->_bf == 2 && cur->_bf == -1)
                {
                    RotateRL(parent);
                }
                // LR 型：先左旋 cur，再右旋 parent
                else if (parent->_bf == -2 && cur->_bf == 1)
                {
                    RotateLR(parent);
                }

                // 插入场景旋转后，该子树高度恢复
                break;
            }
            else
            {
                assert(false);
            }
        }

        return true;
    }

    Node* Find(const K& key)
    {
        Node* cur = _root;

        while (cur)
        {
            if (cur->_kv.first < key)
            {
                cur = cur->_right;
            }
            else if (cur->_kv.first > key)
            {
                cur = cur->_left;
            }
            else
            {
                return cur;
            }
        }

        return nullptr;
    }

    void InOrder()
    {
        _InOrder(_root);
        std::cout << std::endl;
    }

private:
    // 右旋
    void RotateR(Node* parent)
    {
        assert(parent != nullptr);
        assert(parent->_left != nullptr);

        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        // subLR 接到 parent 的左边
        parent->_left = subLR;

        if (subLR)
        {
            subLR->_parent = parent;
        }

        // parent 接到 subL 的右边
        subL->_right = parent;

        Node* ppNode = parent->_parent;
        parent->_parent = subL;

        // parent 原来是根节点
        if (parent == _root)
        {
            _root = subL;
            _root->_parent = nullptr;
        }
        else
        {
            // 将 subL 接回原来的父节点
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

        // 插入场景下，右旋后的平衡因子为 0
        parent->_bf = 0;
        subL->_bf = 0;
    }

    // 左旋
    void RotateL(Node* parent)
    {
        assert(parent != nullptr);
        assert(parent->_right != nullptr);

        Node* subR = parent->_right;
        Node* subRL = subR->_left;

        // subRL 接到 parent 的右边
        parent->_right = subRL;

        if (subRL)
        {
            subRL->_parent = parent;
        }

        // parent 接到 subR 的左边
        subR->_left = parent;

        Node* ppNode = parent->_parent;
        parent->_parent = subR;

        // parent 原来是根节点
        if (parent == _root)
        {
            _root = subR;
            _root->_parent = nullptr;
        }
        else
        {
            // 将 subR 接回原来的父节点
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

        // 插入场景下，左旋后的平衡因子为 0
        parent->_bf = 0;
        subR->_bf = 0;
    }

    // 右左双旋：先右旋 parent 的右孩子，再左旋 parent
    void RotateRL(Node* parent)
    {
        assert(parent != nullptr);
        assert(parent->_right != nullptr);

        RotateR(parent->_right);
        RotateL(parent);
    }

    // 左右双旋：先左旋 parent 的左孩子，再右旋 parent
    void RotateLR(Node* parent)
    {
        assert(parent != nullptr);
        assert(parent->_left != nullptr);

        RotateL(parent->_left);
        RotateR(parent);
    }

    void _InOrder(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }

        _InOrder(root->_left);

        std::cout << root->_kv.first
                  << ":"
                  << root->_kv.second
				  << "(" << root->_bf << ")"
                  << std::endl;

        _InOrder(root->_right);
    }

    void _Destroy(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }

        _Destroy(root->_left);
        _Destroy(root->_right);

        delete root;
    }
public:
	bool IsBalance()
	{
		return _isBalance(_root);
	}

	
private:
    Node* _root;
	int _height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int leftHeight=_height(root->_left);
		int rightHeight=_height(root->_right);

		return std::max(leftHeight, rightHeight) + 1;
	}

	bool _isBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftHeight=_height(root->_left);
		int rightHeight=_height(root->_right);

		if (abs(leftHeight - rightHeight) > 1)//abs()求左右子树高度差的绝对值
		{
			return false;
		}

		return _isBalance(root->_left) && _isBalance(root->_right);
	}
};

void TestAVLTree1()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 2,13,5 };
	AVLTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(std::make_pair(e, e));
	}

	t1.InOrder();
	std::cout << "Is balanced: " << t1.IsBalance() << std::endl;
}

