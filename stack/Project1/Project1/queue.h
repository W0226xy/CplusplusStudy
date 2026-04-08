#pragma once
#include<vector>
#include<list>
#include<deque>
namespace wxy
{
	//这里的container可以是list或者vector
	template <class T, class container = deque<T> >//stack 类只是一个“壳”，所有数据其实都是存放在 container _con 里面的
	class queue
	{
	public:
		void adjust_up(size_t parent)
		{

		}

		void push(const T& x)
		{
			_con.push_back(x);//这里的push_back需要用到的容器原本就有这个方法
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		size_t size()
		{
			return _con.size();
		}

		const T& top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

		const T& front()
		{
			return _con.front();
		}

		const T& back()
		{
			return _con.back();
		}
	private:
		container _con;
	};

	template<class T,class Container=vector<T>>
	class priority_queue
	{
	public:
		void adjust_up(size_t child)
		{

		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}
		
		void pop()
		{

		}

		bool empty()
		{

		}

		size_t size()
		{

		}

		const T& top()
		{

		}
	private:
		Container _con;
	};
}

