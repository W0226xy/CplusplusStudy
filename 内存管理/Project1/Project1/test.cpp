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
//ѡ��: A.ջ  B.��  C.���ݶ�(��̬��)  D.�����(������)
//globalVar�����__c__   staticGlobalVar�����__c__

//staticVar�����__c__   localVar�����__a__

//num1 �����__a__
//
//char2�����__a__* char2�����__a__ 
// //*char2��ȡchar2�������Ԫ�أ���Ԫ����ջ��

//pChar3�����__a__* pChar3�����_d___ 
// //const���εĲ�һ�����ڳ�������pchar3��ջ�ϴ��һ��������ָ��abcd����ַ�����*pchar3�����ҵ�"abcd"����ַ������ڳ�����

//ptr1�����__a__* ptr1�����__b__
//ptr1����ջ�ϴ洢ָ����Ͽռ��ָ�룬*ptr1�ǰ�ָ������õõ������ǿ�ռ�

//ȫ�ֵı�����ȫ�ֵľ�̬���ֲ��ľ�̬���ڡ���̬����
//��ջ֡�еı������ڡ�ջ����

//sizeof(num1) = __40__;

//sizeof(char2) = __5__;      strlen(char2) = __4__;
//char2������һ��\0��sizeof����㣬strlen�������\0

//sizeof(pChar3) = __4/8__;     strlen(pChar3) = __4__;
//ָ���С4/8ȡ����ϵͳ��32λ����64λ

//sizeof(ptr1) = __4/8__;

//C++�ڴ����ʽ
//new��delete������������
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
//ListNode* CreateList(int n)//����һ������
//{
//	ListNode head(-1);
//	ListNode* tail = &head;
//	int val;
//	printf("����������%d���ڵ�ֵ",n);
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
//	//1.�÷����
//	int* p1 = new int;
//	int* p2 = new int[10];
//	
//	delete p1;
//	delete[] p2;//new��ʱ����[]��deleteҲ��Ҫ[]
//
//
//	//2.�ɳ�ʼ��
//	int* p3 = new int(10);//newһ��int��ʼ��Ϊ10��Ȼ����p3ָ�����ռ�
//	int* p4 = new int[10] {1, 2, 3, 4, 5};//p4ָ��Ŀռ�Ϊ1234500000
//
//	//3.�Զ������ͣ����ռ�+���캯��
//	ListNode* n1 = new ListNode(1);//�Զ�newһ��ListNode��С�Ŀռ䣬����ʼ���ڵ�ֵΪ1
//	//�����ʼ����Ҫдһ�����캯��
//
//	//4.newʧ����֮����Զ����쳣������Ҫ�ֶ����
//
//	ListNode* list1 = CreateList(5);
//	return 0;
//}


//operator new ��operator delete
//operator new�Ƕ�malloc�ķ�װ
//operator delete�Ƕ�free�ķ�װ


//new=operator new+����
//operator new �ײ���malloc

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
//	int* p1 = (int*)operator new(10 * 4);//һ��Ͱ�������malloc����
//
//	A* ptr = new A(1);//operator new +1�ι���
//
//	cout << "-----------------" << endl;
//
//	A* ptr2 = new A[10];//operator new[] +10�ι���
//	//����ʵ�ʻῪ��44�Ŀռ��С
//	//����40�ֽڻ�Ҫ4�ֽ�Ҫ�洢10
//	//���10�Ǻ���delete[] ptr2�õ�
//	//delete��ʱ���������10���Ͳ�֪��������ɾ���ٸ�A�ռ�
//
//	cout << sizeof(A) << endl;//4
//	
//	cout << sizeof(ptr) << endl;//8
//	cout << sizeof(ptr2) << endl;//8
//
//	cout << sizeof(*ptr) << endl;//4,�����õõ�ptrָ��ռ�ĵ�һ��ֵ
//	cout << sizeof(*ptr2) << endl;//4
//
//	delete p1;
//	delete ptr; //1������+operator delete
//	cout << "-----------------" << endl;
//	delete[] ptr2;//�������� + operator delete
//
//
//	int* p1 = new int[10];//�������Ͳ���Ҫ���������������������������40�ֽ�
//	return 0;
//}

//new:��operator new �ٹ���
//delete:����������operator delete

//sizeof���������������ʱ���������ʹ�С���壬�Զ������ͻ�����ڴ��������������С(�����������\0)
//strlen��������������ʱ���������鲻����\0��

//int main()
//{
//	int* p1 = new int[10];
//	delete p1;//�������������ͣ�û����delete[]Ҳ�������ڴ�й©
//
//	//A* p2 = new A[10];
//	//delete p2;//�Զ�������������ϸ���delete[]����������
//	//A������������new��ʱ�����ָ����40�ռ䣬������⿪4�ռ���10
//	//������delete��ʱ���֪��Ҫdelete����A��С�Ŀռ䣩
//
//	//����û����delete[]���õ�delete������������operator delete���ͻ���Ϊֻ��һ������
//	//��delete��ʱ���ֱ������ǰ���10��4�ֽڣ��ӵ�һ��A�ռ俪ʼ�ͷ�
//	// �������ͷ��ǲ��ܴ�����ռ���м俪ʼ�ͷţ��ͻ���������
//}


int main()
{
	A* p2 = (A*)operator new(sizeof(A));
	//��ʾ���ù��캯����һ�����еĿռ��ʼ��
	new(p2)A(1);
	
	//��������Ч��=delete(p2)
	p2->~A();
	operator delete(p2);
	//delete=����+operator delete
	return 0;
}

//malloc / free��new / delete�Ĺ�ͬ���ǣ����ǴӶ�������ռ䣬������Ҫ�û��ֶ��ͷš���ͬ�ĵ�
//���ǣ�
//1. malloc��free�Ǻ�����new��delete�ǲ�����
//2. malloc����Ŀռ䲻���ʼ����new���Գ�ʼ��
//3. malloc����ռ�ʱ����Ҫ�ֶ�����ռ��С�����ݣ�newֻ���������Ͽռ�����ͼ��ɣ�
//����Ƕ������[]��ָ�������������
//4. malloc�ķ���ֵΪvoid*, ��ʹ��ʱ����ǿת��new����Ҫ����Ϊnew������ǿռ������
//5. malloc����ռ�ʧ��ʱ�����ص���NULL�����ʹ��ʱ�����пգ�new����Ҫ������new��
//Ҫ�����쳣
//6. �����Զ������Ͷ���ʱ��malloc / freeֻ�Ὺ�ٿռ䣬������ù��캯����������������new
//������ռ�����ù��캯����ɶ���ĳ�ʼ����delete���ͷſռ�ǰ����������������
//�ռ�����Դ������

