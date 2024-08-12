#include"Stack.h"
int Add(int a, int b)
{
	cout << a + b << endl;
	return a + b;
}

//如果类使用声明和定义分离
//void Stack::Init(int n = 4)//这里需要指明是哪个域的Init
//{//类本身也是一个域
//	a = (int*)malloc(sizeof(int) * n);
//	if (a == nullptr)
//	{
//		perror("malloc申请空间失败");
//		return;
//	}
//	top = 0;
//	capacity = n;
//	//如果不指明是哪个域的init
//	//这里的top和capacity就相当于是凭空冒出来的
//}
