#pragma once
#include<assert.h>
#include<utility>
#include<initializer_list>
#include<algorithm>
#include<iostream>
#include<type_traits>
#include<cstddef>
using namespace std;
namespace bit
{
	// 基类节点：只保存前后指针，作为哨兵头结点使用
	// 哨兵头结点不需要构造 T，因此 list 可以支持“不可默认构造”的类型（与 std::list 一致）
	struct ListBaseNode
	{
		ListBaseNode* _next;
		ListBaseNode* _prev;

		ListBaseNode()
			:_next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T>
	struct ListNode : ListBaseNode
	{
		T _data;

		// 默认构造：供 emplace_back()/emplace 零参时使用
		ListNode()
			:_data()
		{}

		// 从 T 的左值拷贝数据
		ListNode(const T& x)
			:_data(x)
		{}

		// 完美转发构造：
		//   1) 单个右值实参 -> 移动构造
		//   2) 多个实参     -> emplace 就地构造
		// 用 enable_if 约束，避免它“劫持”ListNode 自身的拷贝/移动构造
		template <class... Args,
			class Enable = typename std::enable_if<std::is_constructible<T, Args...>::value>::type>
		ListNode(Args&&... args)
			:_data(std::forward<Args>(args)...)
			//这里的 forward 指的是 std::forward，作用是：完美转发参数。它会根据 Args 的类型，决定把 args 作为左值传出去，还是作为右值传出去。
		{}
		
		/*ListNode(const char* str, int val)
			: _data(str, val)
		{}*/
	};

	// typedef ListIterator<T, T&, T*> iterator;
	// typedef ListIterator<T, const T&, const T*> const_iterator;

	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;          // 带数据的节点
		typedef ListBaseNode BaseNode;     // 哨兵/链接节点
		typedef ListIterator<T, Ref, Ptr> Self;

		BaseNode* _node;

		ListIterator(BaseNode* node)
			:_node(node)
		{}

		// *it
		//T& operator*()
		Ref operator*()
		{
			return static_cast<Node*>(_node)->_data;
		}
		
		// it->
		//T* operator->()
		Ptr operator->()
		{
			return &static_cast<Node*>(_node)->_data;
		}

		// ++it
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;

			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	//template<class T>
	//struct ListConstIterator
	//{
	//	typedef ListNode<T> Node;
	//	typedef ListConstIterator<T> Self;

	//	Node* _node;

	//	ListConstIterator(Node* node)
	//		:_node(node)
	//	{}

	//	// *it
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	// it->
	//	const T* operator->()
	//	{
	//		return &_node->_data;
	//	}

	//	// ++it
	//	Self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	Self operator++(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_next;

	//		return tmp;
	//	}

	//	Self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	Self operator--(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_prev;

	//		return tmp;
	//	}

	//	bool operator!=(const Self& it)
	//	{
	//		return _node != it._node;
	//	}

	//	bool operator==(const Self& it)
	//	{
	//		return _node == it._node;
	//	}
	//};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef ListBaseNode BaseNode;
	public:
		//typedef ListIterator<T> iterator;
		//typedef ListConstIterator<T> const_iterator;

		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		// const迭代器，需要是迭代器不能修改，还是迭代器指向的内容？
		// 迭代器指向的内容不能修改！const iterator不是我们需要const迭代器

		// T* const p1
		// const T* p2
		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		void empty_init()
		{
			// 哨兵头结点不需要构造 T
			_head = new BaseNode;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		list(initializer_list<T> il)
		{
			empty_init();

			for (auto& e : il)
			{
				push_back(e);
			}
		}


		// lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		// 需要析构，一般就需要自己写深拷贝
		// 不需要析构，一般就不需要自己写深拷贝，默认浅拷贝就可以

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		// lt1 = lt3
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		/*void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}*/

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_back(T&& x)
		{
			insert(end(), std::forward<T>(x));
		}

		template <class... Args>
		void emplace_back(Args&&... args)
		{
			emplace(end(), std::forward<Args>(args)...);
		}

		/*void emplace_back(const char* str, int val)
		{
			emplace(end(), str, val);
		}*/

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& val)
		{
			BaseNode* cur = pos._node;
			BaseNode* newnode = new Node(val);
			BaseNode* prev = cur->_prev;

			// prev newnode cur;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;
		}

		void insert(iterator pos, T&& val)
		{
			BaseNode* cur = pos._node;
			BaseNode* newnode = new Node(std::forward<T>(val));
			BaseNode* prev = cur->_prev;

			// prev newnode cur;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;
		}

		template <class... Args>
		void emplace(iterator pos, Args&&... args)
		{
			BaseNode* cur = pos._node;
			BaseNode* newnode = new Node(std::forward<Args>(args)...);//把 args 这一组参数，按照它们原本是左值还是右值的身份，逐个转发给 Node 的构造函数
			BaseNode* prev = cur->_prev;

			// prev newnode cur;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;
		}

		//void emplace(iterator pos, const char* str, int val)
		//{
		//	Node* cur = pos._node;
		//	Node* newnode = new Node(str, val);
		//	Node* prev = cur->_prev;
		//	//...
		//}

		iterator erase(iterator pos)
		{
			BaseNode* cur = pos._node;
			BaseNode* prev = cur->_prev;
			BaseNode* next = cur->_next;
			
			prev->_next = next;
			next->_prev = prev;
			// cur 指向的一定是带数据的节点（不会是哨兵），可安全向下转型后删除
			delete static_cast<Node*>(cur);
			_size--;

			return iterator(next);
		}

		std::size_t size() const
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

	private:
		BaseNode* _head;
		std::size_t _size;
	};


	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it += 10;
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);

		for (auto e : lt)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;

		lt.pop_back();
		lt.pop_back();
		lt.pop_front();
		lt.pop_front();
		
		for (auto e : lt)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

	struct A
	{
		int _a1;
		int _a2;

		A(int a1 = 0, int a2 = 0)
			:_a1(a1)
			,_a2(a2)
		{}
	};

	void test_list2()
	{
		list<A> lt;
		A aa1(1, 1);
		A aa2 = { 1, 1 };
		lt.push_back(aa1);
		lt.push_back(aa2);
		lt.push_back(A(2, 2));
		lt.push_back({3, 3});
		lt.push_back({4, 4});

		A* ptr = &aa1;
		(*ptr)._a1;
		ptr->_a1;

		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it += 10;
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			std::cout << it->_a1 << ":" << it->_a2 << std::endl;
			std::cout << it.operator->()->_a1 << ":" << it.operator->()->_a2 << std::endl;

			++it;
		}
		cout << endl;
	}

	void PrintList(const list<int>& clt)
	{
		list<int>::const_iterator it = clt.begin();
		while (it != clt.end())
		{
			//*it += 10;

			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		PrintList(lt);

		list<int> lt1(lt);
		PrintList(lt1);
	}
}
