#include<iostream>
using namespace std;
//��������
//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour ;
//	int _minute ;
//	int _seconde ;
//};
//
//class Date
//{
//	
//private:
//	int _Year;
//	int _Month;
//	int _Day;
//	Time t;
//};
//
//int main()
//{
//	Date d1;
//}
// �������н����������~Time()
// ��main�����и���û��ֱ�Ӵ���Time��Ķ���Ϊʲô�������Time�������������
// ��Ϊ��main�����д�����Date����d����d�а���4����Ա����������_year, _month, _day������
// �������ͳ�Ա������ʱ����Ҫ��Դ�������ϵͳֱ�ӽ����ڴ���ռ��ɣ�
// 
// ��_t��Time�����������d����ʱ��Ҫ�����ڲ�������Time���_t�������٣�����Ҫ����Time�������������
// ���ǣ�main�����в���ֱ�ӵ���Time�������������ʵ��Ҫ�ͷŵ���Date��������Ա����������Date�������������
// ��Dateû����ʽ�ṩ������������Date������һ��Ĭ�ϵ�����������Ŀ���������ڲ�����Time
// �����������������Date��������ʱ��Ҫ��֤���ڲ�ÿ���Զ�����󶼿�����ȷ����
// main�����в�û��ֱ�ӵ���Time������������������ʽ���ñ�����ΪDate�����ɵ�Ĭ����������
// ע�⣺�����ĸ���Ķ�������ø�������������������Ǹ���Ķ�������ø������������


//class Date
//{
//public:
//	Date(int year=1)
//	{
//		_Year = year;
//		cout << "Date()" << _Year << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date()"<<_Year << endl;
//	}
//private:
//	int _Year;
//	int _Month;
//	int _Day;
//	
//};

//void func()
//{
//	Date d3(3);
//	static Date d4(4);
//}
//
//Date d5(5);
//
//static Date d6(6);
//int main()
//{
//	Date d1(1);
//	Date d2(2);
//	func();
//	
//	//�ȶ�����ȹ��죬�����������
//		
//		/*Date()5
//		Date()6
//		Date()1
//		Date()2
//		Date()3
//		Date()4
//		~Date()3
//		~Date()2
//		~Date()1
//		~Date()4
//		~Date()6
//		~Date()5*/
//
//	//�������ȴ�ȫ�ֵģ��󴴾ֲ��ģ��ȴ����ȹ��죩
//	//���٣������ֲ��ģ�����ȫ�ֵģ��������٣�
//
//	//ȫ�ֵĺ;�̬�������ȴ���
//	
//
//	//����˳�򣺾ֲ����󣨺�����������������ֲ���̬����ȫ�ֶ��󣨺������������
//}


//��������

//class Time
//{
//public:
//	Time() = default;//ǿ�Ʊ��������ɹ��캯������Ϊ������һ���������죬�������Ͳ�������Ĭ�Ϲ����ˣ�����ǿ������һ��
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//	Time(const Time& t)
//	{
//		cout << "Time(const Time& t)" << endl;
//		_hour = t._hour;
//		_minute = t._minute;
//		_seconde = t._seconde;
//	}
//private:
//	int _hour ;
//	int _minute ;
//	int _seconde ;
//};
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1,int day=1)
//	{
//		_Year = year;
//		_Month = month;
//		_Day = day;
//	}
//	Date(const Date& d)//�������죬���������Ҫ�����ã���ֹ���֡�����ݹ顱�����
//	{//��const��Ϊ�˱���d���ܱ��޸�
//		_Year = d._Year;
//		_Month = d._Month;
//		_Day = d._Day;
//	}
//	void print()
//	{
//		cout << _Year << "-" << _Month << "-" << _Day<<endl;
//	}
//private:
//	int _Year;
//	int _Month;
//	int _Day;
//	Time t;
//};
//
//int main()
//{
//	Date d1(2024, 8, 15);
//	Date d2(d1);//�������죺��ͬ���͵��������������쵱ǰ����
//	d1.print();//2024-8-15
//	d2.print();//2024-8-15
//}

//�������캯��Ҳ������ĳ�Ա���������������£�
//1. �������캯���ǹ��캯����һ��������ʽ��
//2. �������캯���Ĳ���ֻ��һ���ұ����������Ͷ�������ã�ʹ�ô�ֵ��ʽ������ֱ�ӱ�����Ϊ����������ݹ���á�
// 3. ��δ��ʽ���壬������������Ĭ�ϵĿ������캯���� Ĭ�ϵĿ������캯�������ڴ�洢���ֽ�����ɿ��������ֿ�������ǳ����������ֵ������
// 
// 

//void func1(Date d)
//{
//
//}
//
//void func2(Date& rd)
//{
//
//}
//
//int main()
//{
//	Date d1(2024, 8, 15);
//	//C++�涨�Զ������ʹ�ֵ���ζ����ȵ��ÿ�������
//	func1(d1);//������ȵ��ÿ������죬Ȼ��Ż��func1����
//	
//	func2(d1);//�����Ǵ����ã�������ÿ������죬rd����d1
//	return 0;
//}


// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ�����
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}
//������s1��������s2��ǳ������
//s2��_array��s1��_array��ָ����ָ��һ��ռ�
//s2����֮��s1������������ͬһ��ռ䱻�ͷ�������


//����Ľ�
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	//��������
//	Stack(const Stack& s)
//	{
//		DataType* tmp = (DataType*)malloc(s._capacity * (sizeof(DataType)));
//		if (tmp == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memcpy(tmp, s._array, sizeof(DataType)*s._size);//s._array�����ݿ�����tmp��
//		_array = tmp;
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//class MyQueue
//{
//private:
//	Stack _s1;
//	Stack _s2;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//
//	MyQueue q1;//�Զ���ĳ�Ա������Զ����Ա�Ŀ�������
//	MyQueue q2(q1);
//	return 0;
//}




//void func(int& x)
//{
//
//}
//
//void func1(const int& x)
//{
//
//}
//int main()
//{
//	//��������ʹ��
//	int a = 0;
//	int& b = a;
//	b++;
//	func(a);
//
//	//Ȩ�޿���С
//	const int& c = a;
//	
//	const int& x = 10;
//
//	//Ȩ�޲��ɷŴ�
//	//int& d = c;//����д�ᱨ��ԭ��c�ǲ��ɸĵģ�����d��Ȼ��c�ı���ҲӦ���ǲ��ɸĵ�
//
//	const int& z = 10;
//	
//	const int& m = a + x;//���޸�+�����޸�=�����޸�
//	//int& n = a + x;//�ᱨ��
//
//	//func(10);����ᱨ����Ϊ10�ǳ������㴫��ȥ����˿��޸ĵ��ˣ�Ȩ�޷Ŵ���
//	//func(a + x);�ᱨ��a+x�ǲ����޸ģ�����ȥ����˿��޸ĵ��ˣ�Ȩ�޷Ŵ���
//
//	func1(10);//������ʹ�ã�ԭ���ǳ��������޸ģ�����ȥҲ�ǲ����޸ģ�Ȩ��û�зŴ�
//	func1(a + x);//������ʹ��
//
//}


//int main()
//{
//	double d = 1.1;
//	int i = d;//����ת�����м�����һ����ʱ��������ʱ�����ٸ�ֵ��i
//	
//	//int& ri = d;//�ᱨ��
//	const int& ri = d;
//	//d���ȿ�����һ��int�͵���ʱ������Ȼ����ʱ��������ri
//	//��ʱ�������г��ԣ�����Ҫ��riҲ�ǲ����޸ĵ�
//
//	return 0;
//}


class Date
{
public:
	Date(int year = 1, int month = 1,int day=1)
	{
		_Year = year;
		_Month = month;
		_Day = day;
	}
	
	Date(const Date& d)//�������죬���������Ҫ�����ã���ֹ���֡�����ݹ顱�����
	{//��const��Ϊ�˱���d���ܱ��޸�
		_Year = d._Year;
		_Month = d._Month;
		_Day = d._Day;
	}
	
	void print()
	{
		cout << _Year << "-" << _Month << "-" << _Day<<endl;
	}
	
	
	bool operator==( const Date& y)
	{
		return this->_Year == y._Year
			&& this->_Month == y._Month
			&& this->_Day == y._Day;
	}

	bool operator<( const Date& y)
	{
		if (this->_Year < y._Year)
		{
			return true;
		}
		else if (this->_Year == y._Year)
		{
			if (this->_Month < y._Month)
			{
				return true;
			}
			else if (this->_Month == y._Month)
			{
				if (this->_Day < y._Day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	

private:
	int _Year;
	int _Month;
	int _Day;

};

int main()
{
	Date d1(2023, 3, 1);
	Date d2(2023, 1, 9);
	
	cout<<d1.operator<(d2)<<endl;

	cout << (d1< d2) << endl;//�����м��һ�����ţ�<<���ȼ�����<

	cout << (d1 == d2) << endl;

}