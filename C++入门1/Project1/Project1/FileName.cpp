#include<stdio.h>
#include<iostream>
int x = 0;
using namespace std;
namespace wxy
{
	int x = 2;
	int add(int a, int b)
	{
		return a + b;
	}

	struct	Node
	{
		int a = 4;
	};
}
int main()
{
	int x = 1;
	printf("%d\n", x);//1
	printf("%d\n", ::x);//0
	printf("%d\n", wxy::x);//2
	//::域作用限定符
	//::x表示全局的x
	//wxy::x表示命名空间wxy下的x
	//如果不指定域，则默认当前域
	//如果有同名的命名空间，编译器会把两空间下的内容合并
	// （不同空间下不能有相同内容，否则合并会报错）
	int y = wxy::add(1, 2);
	printf("%d\n", y);//3

	struct wxy::Node node;
	//命名空间结构体的定义方式：
	//struct 命名空间名::结构体名称 结构体名
	printf("%d\n", node.a);//4

	cout << "hello" << endl;
	return 0;
}


