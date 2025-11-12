#pragma once
#pragma once
#include<assert.h>
#include <iostream>
using namespace std;
namespace wxy
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}

	};

	template<class T,class Ref,class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;

		Node* _node;
		ListIterator(Node* node)
			:_node(node)
		{
		}

		//*it解引用
		T& operator*()
		{
			return _node->_data;
		}

		//it->
		T* operator->()
		{
			return &_node->_data;
		}

		//++it
		Self& operator++()//前置++
		{
			_node = _node->_next;
			return *this;
		}

		//it++
		Self& operator++(int)//后置++
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		//--it
		Self& operator--()//前置--
		{
			_node = _node->_prev;
			return *this;
		}

		//it--
		Self& operator--(int)//后置--
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

	template<class T>
	class list//带哨兵位的头节点
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;//让外部用户可以用统一的名字 iterator，内部可以根据不同的类型（比如 T& 或 const T&）灵活调整迭代器行为。
		typedef ListIterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head); 
		}

		//const iterator it 是迭代器指向的内容不能被修改，也就是*it不能被修改
		//前面的const限制返回值类型，也就是不能通过这个迭代器修改容器中的元素
		//后面的const则是限定成员函数本身
		/*const iterator begin() const
		{
			return iterator(_head->_next);
		}*/

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}


		list()//构造函数
		{
			empty_init();
		}

		list(const list<T>& lt)//拷贝构造
		{
			empty_init();//创建一个哨兵位头节点
			for (auto& e : lt)//依次遍历lt的节点，从创建的哨兵位头节点后面开始尾插即可
			{
				push_back(e);
			}
		}

		void swap()
		{
			std::swap(_head, lt.head);
			std::swap(_size, lt.size);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void clear()//这里清数据不会清头节点
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);//删除完当前的迭代器指向节点，下一个节点就是新的it
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

		void push_back(const T& x)//尾插
		{
			insert(end(), x);
		}

		void push_front(const T& x)//头插
		{
			insert(begin(), x);
		}

		void pop_back()//尾删
		{
			erase(--end());//这里不能写end()-1，end返回值是迭代器，并且end迭代器指向的是哨兵位头节点
			//也不能写end()--，否则是返回end()
		}

		void pop_front()//头删
		{
			erase(begin());
		}

		void insert(iterator pos, const T& val)//当前位置插入值为val的节点
		{
			Node* cur = pos._node;//cur是当前迭代器指向的节点
			Node* newnode = new Node(val);//要插入的节点
			Node* prev = cur->_prev;//获取当前节点的前一个节点

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		iterator erase(iterator pos)//删除当前位置节点
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			//先连
			prev->_next = next;
			next->_prev = prev;

			//后断
			delete cur;
			return iterator(next);
		}

		
		
		

	private:
		Node* _head;
		int _size;
	};


	void test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
	}

	struct A
	{
		int _a1;
		int _a2;
		A(int a1=0,int a2=0)
			:_a1(a1)
			,_a2(a2)
		{}
	};

	void test2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";//1 2 3 4 5 6
			++it;
		}

		cout << endl;
		lt.push_front(7);//头插789
		lt.push_front(8);
		lt.push_front(9);
		for (auto e : lt)
		{
			cout << e << " ";//9 8 7 1 2 3 4 5 6
		}

		cout << endl;
		lt.pop_front();//头删3次
		lt.pop_front();
		lt.pop_front();
		for (auto e : lt)
		{
			cout << e << " ";//1 2 3 4 5 6
		}

		cout << endl;
		lt.pop_back();//尾删3次
		lt.pop_back();
		lt.pop_back();
		for (auto e : lt)
		{
			cout << e << " ";//1 2 3 4 5 6
		}
	}

	void test3()
	{
		list<A> lt;
		A aa1(1, 1);
		lt.push_back(aa1);//结构体链表插入，参数可以写有名对象
		lt.push_back(A(2,2));//也可以写匿名对象
		lt.push_back({3,3});//多参数类型函数也可以支持隐式类型转换，ps：单参数用()，多参数用{}

		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << (*it)._a1 << " " << (*it)._a2 << endl;//*it返回值是一个A对象
			//这里调用的是T& operator*()，返回的是return _node->_data，而data又是T _data;其实就是aa1这种
			it++;
		}
		//1 1
		//2 2
		//3 3
		cout << endl;

		while (it != lt.end())
		{
			cout << it->_a1 << " " << it->_a2 << endl;//*it返回值是一个A对象，也就是aa1
			//这里调用的是T* operator->()，返回的是return &_node->_data;相当于是aa1的地址，也就是说it就是&aa1，it->就是对aa1地址解引用得到其数据
			it++;
		}
	}


	void printList(const list<int>& clt)
	{
		list<int>::const_iterator it = clt.begin();
		while (it != clt.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}


	void test4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);

		list<int>::iterator it = lt.begin();
		printList(lt);//1 2 3 4 5 6

		list<int> lt1(lt);
		printList(lt1);//1 2 3 4 5 6

	}

}

