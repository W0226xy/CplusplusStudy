#pragma once
#include<vector>
#include<list>
#include<deque>
namespace wxy
{
	//这里的container可以是list或者vector
	template <class T,class container=deque<T> >//stack 类只是一个“壳”，所有数据其实都是存放在 container _con 里面的
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);//这里的push_back需要用到的容器原本就有这个方法
		}

		void pop()
		{
			_con.pop_back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

		const T& top()
		{
			return _con.back();
		}
	private:
		container _con;
	};
}
