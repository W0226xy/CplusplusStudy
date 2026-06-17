#include<iostream>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//public:
//	string _name = "peter"; // 姓名
//private:
//	int _age = 18; // 年龄
//};
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了
////Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可
////以看到变量的复用。调用Print可以看到成员函数的复用。
//class Student : public Person//这里的继承方式public可以不写，不写默认为private
//{
//public:
//	void Print()
//	{
//		cout << "hello student" << endl;
//	}
//	void func()
//	{
//		//不能直接用父类私有成员，可以间接使用
//		cout << _name << endl;//这里的name默认是优先用子类自己的
//		cout << Person::_name << endl;//如果想用父类的，使用域作用限定符
//		
//		Print();//可以用父类的方法，间接得到父类成员值
//	}
//public:
//	string _name = "luyis";
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};

//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();//子类可以用父类公有的
//	//name:peter
//	//age:18
//	t.Print();
//	//name:peter
//	//age:18
//	cout << "-----" << endl;
//	s.func();
//	//peter
//	//name : peter
//	//age : 18
//
//	
//
//	return 0;
//}

// public：父类公开给所有人的东西，子类能用，外部对象也能用
// protected：父类留给子类内部使用的东西，外部对象不能随便用
// private：父类自己的私房钱，子类不能直接访问，只能通过父类提供的接口间接使用

//int main()
//{
//	Student s;
//	Person p = s;//子类对象可以赋值给父类对象(公有继承才可以)
//	p.Print();
//	//name:peter
//	//age:18
//	//父类可以用和子类同样有的东西，但是子类有父类没有的，父类用不了
//
//	Person& ref = s;//父类用子类对象，中间不会出现临时变量（特殊情况——赋值兼容）
//	Person* ptr = &s;
//	ref._name += "1";
//	ptr->_name += "2";
//	s.Print();
//	//name:peter12
//	//age:18
//}

//int main()
//{
//	Student s;
//	s.func();//父类和子类有同名函数，子类调用时，用子类的函数(如果函数中访问了同名成员变量，也是用子类的),这种技术称为“隐藏”
//	//luyis
//	//peter
//	//hello student
//}

//例题：
//class A
//{
//public:
//	void fun()
//	{
//		cout << "fun()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "fun(int i)->" << i << endl;
//	}
//};
//A.编译报错  B.运行报错 C.两个fun构成重载  D.两个fun构成隐藏
//void fun()和void fun(int i)虽然它们参数不同，但是它们不构成函数重载。因为函数重载要求在同一个作用域中
//这里一个在父类 A 里面，一个在子类 B 里面，属于不同作用域，所以是隐藏。选D

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person & p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)//子类没有写name（继承父类的，这里要用Person(name)）
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);//这里必须多加一个Person:: 否则子类和父类同名的函数会构成隐藏，会一直调用自己的operator=，递归死循环了
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};
int main()
{
	Student s1("jack", 18);//C++ 中子类对象构造时，一定会先调用父类的构造函数
	//先构造父类部分
	//再构造子类自己的成员变量
	//最后执行子类构造函数体
	//输出
	/*Person()
	Student()
	~Student()
	~Person()*/
	//子类析构时，也一定会调用父类析构函数。但是析构顺序和构造顺序相反：
	//构造：先父类，再子类
	//析构：先子类，再父类

	//Student s2(s1);//拷贝构造，也是先拷贝构造父类，然后子类
	//输出
	//Person(const Person& p)
	//Student(const Student & s)
	//~Student()
	//~Person()


	Student s3("rose", 17);
	s1 = s3;
	//构造s3
	//Person()
	//Student()
	//s1=s3是赋值（前面s1已经有了，调用的是 Student 的赋值运算符重载，然后Student赋值重载里面再调用Person赋值重载）
	//Student& operator= (const Student& s)
	//Person operator=(const Person & p)
	//~Student()
	//~Person()
}
//子类调用父类默认构造的时候，如果父类没有默认构造就会直接报错
//拷贝构造：用一个已有对象，创建一个新对象
//赋值运算符：两个对象都已经存在，把一个对象的值赋给另一个对象