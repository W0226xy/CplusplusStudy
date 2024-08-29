#include<iostream>
using namespace std;
int globalVar = 1;
static int staticGlobalVar = 1;
void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	const char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	free(ptr1);
	free(ptr3);
}
//选项: A.栈  B.堆  C.数据段(静态区)  D.代码段(常量区)
//globalVar在哪里？__c__   staticGlobalVar在哪里？__c__

//staticVar在哪里？__c__   localVar在哪里？__a__

//num1 在哪里？__a__
//
//char2在哪里？__a__* char2在哪里？__a__ 
// //*char2是取char2数组的首元素，首元素在栈上

//pChar3在哪里？__a__* pChar3在哪里？_d___ 
// //const修饰的不一定就在常量区，pchar3是栈上存的一个变量，指向abcd这个字符串。*pchar3才是找到"abcd"这个字符串，在常量区

//ptr1在哪里？__a__* ptr1在哪里？__b__
//ptr1是在栈上存储指向堆上空间的指针，*ptr1是把指针解引用得到堆上那块空间

//全局的变量，全局的静态，局部的静态都在“静态区”
//在栈帧中的变量，在“栈”上

//sizeof(num1) = __40__;

//sizeof(char2) = __5__;      strlen(char2) = __4__;
//char2隐藏了一个\0，sizeof会计算，strlen不会计算\0

//sizeof(pChar3) = __4/8__;     strlen(pChar3) = __4__;
//指针大小4/8取决于系统是32位还是64位

//sizeof(ptr1) = __4/8__;

//C++内存管理方式
//new和delete操作内置类型
//#include<malloc.h>
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int val;
//
//	ListNode(int v)
//	{
//		_next = nullptr;
//		_prev = nullptr;
//		val = v;
//	}
//
//};
//
//struct ListNode* CreateListNode(int val)
//{
//	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		return NULL;
//	}
//	newnode->_next = NULL;
//	newnode->_prev = NULL;
//	newnode->val = val;
//	return newnode;
//}
//
//ListNode* CreateList(int n)//创建一个链表
//{
//	ListNode head(-1);
//	ListNode* tail = &head;
//	int val;
//	printf("请依次输入%d个节点值",n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> val;
//		tail->_next = new ListNode(val);
//		tail = tail->_next;
//	}
//	return head._next;
//}
//
//int main()
//{
//	//1.用法简介
//	int* p1 = new int;
//	int* p2 = new int[10];
//	
//	delete p1;
//	delete[] p2;//new的时候是[]，delete也需要[]
//
//
//	//2.可初始化
//	int* p3 = new int(10);//new一个int初始化为10，然后让p3指向这快空间
//	int* p4 = new int[10] {1, 2, 3, 4, 5};//p4指向的空间为1234500000
//
//	//3.自定义类型，开空间+构造函数
//	ListNode* n1 = new ListNode(1);//自动new一个ListNode大小的空间，并初始化节点值为1
//	//这里初始化需要写一个构造函数
//
//	//4.new失败了之后会自动抛异常，不需要手动检查
//
//	ListNode* list1 = CreateList(5);
//	return 0;
//}


//operator new 和operator delete
//operator new是对malloc的封装
//operator delete是对free的封装


//new=operator new+构造
//operator new 底层是malloc

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" <<this<< endl;
	}
	~A()
	{
		cout << "~A()" <<this<<endl;
	}
private:
	int _a;
};

//int main()
//{
//	int* p1 = (int*)operator new(10 * 4);//一般就把他当成malloc即可
//
//	A* ptr = new A(1);//operator new +1次构造
//
//	cout << "-----------------" << endl;
//
//	A* ptr2 = new A[10];//operator new[] +10次构造
//	//这里实际会开辟44的空间大小
//	//除了40字节还要4字节要存储10
//	//这个10是后面delete[] ptr2用的
//	//delete的时候如果不存10，就不知道到底是删多少个A空间
//
//	cout << sizeof(A) << endl;//4
//	
//	cout << sizeof(ptr) << endl;//8
//	cout << sizeof(ptr2) << endl;//8
//
//	cout << sizeof(*ptr) << endl;//4,解引用得到ptr指向空间的第一个值
//	cout << sizeof(*ptr2) << endl;//4
//
//	delete p1;
//	delete ptr; //1次析构+operator delete
//	cout << "-----------------" << endl;
//	delete[] ptr2;//？次析构 + operator delete
//
//
//	int* p1 = new int[10];//内置类型不需要调用析构函数，这里就是正常开40字节
//	return 0;
//}

//new:先operator new 再构造
//delete:先析构，再operator delete

//sizeof（运算符），编译时，根据类型大小定义，自定义类型会根据内存对齐规则计算对象大小(遇到数组计算\0)
//strlen（函数），运行时（遇到数组不计算\0）

//int main()
//{
//	int* p1 = new int[10];
//	delete p1;//这里是内置类型，没有用delete[]也不会有内存泄漏
//
//	//A* p2 = new A[10];
//	//delete p2;//自定义类型如果不严格用delete[]，程序会崩溃
//	//A有析构函数，new的时候除了指定的40空间，还会额外开4空间存放10
//	//（后面delete的时候才知道要delete几个A大小的空间）
//
//	//这里没有用delete[]，用的delete（先析构，再operator delete）就会认为只有一个对象
//	//它delete的时候会直接跳过前面存10的4字节，从第一个A空间开始释放
//	// （但是释放是不能从申请空间的中间开始释放，就会程序崩溃）
//}


int main()
{
	A* p2 = (A*)operator new(sizeof(A));
	//显示调用构造函数对一块已有的空间初始化
	new(p2)A(1);
	
	//下面两行效果=delete(p2)
	p2->~A();
	operator delete(p2);
	//delete=析构+operator delete
	return 0;
}

//malloc / free和new / delete的共同点是：都是从堆上申请空间，并且需要用户手动释放。不同的地
//方是：
//1. malloc和free是函数，new和delete是操作符
//2. malloc申请的空间不会初始化，new可以初始化
//3. malloc申请空间时，需要手动计算空间大小并传递，new只需在其后跟上空间的类型即可，
//如果是多个对象，[]中指定对象个数即可
//4. malloc的返回值为void*, 在使用时必须强转，new不需要，因为new后跟的是空间的类型
//5. malloc申请空间失败时，返回的是NULL，因此使用时必须判空，new不需要，但是new需
//要捕获异常
//6. 申请自定义类型对象时，malloc / free只会开辟空间，不会调用构造函数与析构函数，而new
//在申请空间后会调用构造函数完成对象的初始化，delete在释放空间前会调用析构函数完成
//空间中资源的清理

