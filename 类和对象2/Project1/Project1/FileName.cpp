#include<iostream>
using namespace std;
//�ڴ����
//class A {
//	int a;//4
//	char b;//1
//};
//
//class B {
//	char x;//1
//	int y;//4
//};
//int main()
//{
//	cout << sizeof(A) << endl;//8
//	
//	//���� int ���͵Ķ���Ҫ���� 4 �ֽڣ�������ܴ�СҲͨ����Ҫ��������Ҫ������������������������ 4 �ֽڣ���
//	//��˱������� char b ��������� 3 ���ֽڵ���䣬ʹ��������Ĵ�СΪ 8 �ֽڡ�
//
//	//A�ڴ����ƣ�4��1��3
//
//	cout << sizeof(B) << endl;//8
//	//int y ���� 4 �ֽڶ���Ҫ��洢������� char x ֮�󣬱����������� 3 ���ֽڵ���䡣
//	//��ˣ�int y ��һ������� 4 �ֽڵ�ַ��ʼ��ռ�� 4 �ֽ�
//	
//	//B�ڴ�����:1��3��4
//}

//�ṹ���ڴ�������
//1. ��һ����Ա����ṹ��ƫ����Ϊ0�ĵ�ַ����
//2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
//		ע�⣺������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
//		VS��Ĭ�ϵĶ�����Ϊ8
//3. �ṹ���ܴ�СΪ���������������б������������  ��  Ĭ�϶������  ȡ��С������������
//4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ��������С��������������������Ƕ�׽ṹ��Ķ�����������������


//thisָ��
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//Print�����������ᴦ�����������
//	/*void Print(Date* this)
//	{
//		cout << this->_year << "-" << this->_month << "-" <<this-> _day << endl;
//	}*/
//
//	//ps:
//	// const Date* p,const��*ǰ����ָ������ݣ�p���ܸı䣬����pָ������ݿɱ�
//	// Date* const p,const��*������ָ�뱾��
//
//	//thisָ�����ջ�ϣ�����һ���βΣ�
//private:
//	int _year;     // ��
//	int _month;    // ��
//	int _day;      // ��
//};
//int main()
//{
//	Date d1, d2;
//	d1.Init(2024, 8, 13);
//	d2.Init(2024, 8, 14);
//	d1.Print();
//	d2.Print();
//	return 0;
//}



//class A
//{
//	public:
//		void Print()
//		{
//			cout << "Print()" << endl;
//		}
//	private:
//		int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
// //��Ա�������ڶ����У���Ȼ�����м�ͷ->���ǲ�������ã���ΪPrint�����������ڹ����ռ��ϣ�������Ҫͨ��pȥ�ҵ�
// //���Կ����������д�ӡPrint()
//	return 0;
//}

//class A
//{
//public:
//    void PrintA()
//    {
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A* p = nullptr;
//    p->PrintA();
//    //���б���,��Ȼ��ָ��Ҳ���Ե���PrintA��������������û�г�ʼ�����󣬲���_a��Ҫͨ��p�ҵ�����Ҫ�����ã�����p�ǿ�ָ�룬�޷������á�
//    //������������б���
//    return 0;
//}

//class A
//{
//public:
//    void PrintA()
//    {
//        cout << this << endl;
//        cout << "��������" << endl;
//    }
//private:
//    int _a;
//};
//
//int main()
//{
//    A* p = nullptr;
//    (*p).PrintA();//�ȼ���p->PrintA(),����PrintA����û�д��ڶ����У�thisָ�벢����Ҫͨ��p�ҵ������Բ����ý�����p
//    return 0;
//}


//���캯��:��ʼ������
//1. ��������������ͬ��
//2. �޷���ֵ��
//3. ����ʵ����ʱ�������Զ����ö�Ӧ�Ĺ��캯����
//4. ���캯���������ء�
//class Date
//{
//public:
//	Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;//���û�г�ʼ�����Զ����ù��캯�����Date()��ʼ��
//	d1.Print();//1-1-1
//
//	Date d2(2024, 8, 13);//����Date(int year, int month, int day)
//	d2.Print();//2024-8-13
//}


//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack()
//	{
//		cout << "Stack()" << endl;
//	}
//};
//
//class MyQueue
//{
//private:
//	Stack st1;
//	Stack st2;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();//-858993460--858993460--858993460
//	//Ĭ�����ɵĹ��캯�������������Ͳ��������Զ������ͻ�ȥ��������Ĭ�Ϲ���
//	//�������ͣ��������ͣ���int/char/double/ָ��...
//	//�Զ������ͣ�struct/class
//
//	MyQueue q1;//����õ�Stack�Ĺ��캯������ӡ����Stack����
//
//}


//����������������Դ����ֹ�ڴ�й¶
//1. ������������������ǰ�����ַ� ~��
//2. �޲����޷���ֵ���͡�
//3. һ����ֻ����һ��������������δ��ʽ���壬ϵͳ���Զ�����Ĭ�ϵ�����������ע�⣺����������������
//4. �����������ڽ���ʱ��C++����ϵͳϵͳ�Զ�������������

typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	// ��������...
	~Stack()
	{
		cout << "����~Stack()" << endl;
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};
void TestStack()
{
	Stack s;
	s.Push(1);
	s.Push(2);
}
int main()
{
	TestStack();//ջS���ٺ���Զ�����~Stack����,��ӡ"����~Stack()"
	//����Stack�Ŀռ���malloc�����ģ����ý���������������������ᷢ���ڴ�й¶
}
//�ȶ�����ȹ���
//�����������

//���������͹��캯�����ƣ�
//�������Ͳ������Զ�������ȥ������