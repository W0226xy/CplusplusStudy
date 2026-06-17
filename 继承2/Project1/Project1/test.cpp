#include<iostream>
using namespace std;
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//
//
//int main()
//{
//	Student s1;//1
//	Student s2;//2
//	Student s3;//3
//	Graduate s4;//4(这里Graduate向上构造student，student向上构造person)
//	//基类定义了static静态成员，则整个继承体系里面只有一个这样的成员。无论派生出多少个子类，都只有一个static成员实例
//	cout << " 人数 :" << Person::_count << endl;//4
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;//0
//
//	cout << &Person::_count << endl;//00007FF7430524C0
//	cout << &Student::_count << endl;//00007FF7430524C0
//	//父类创建的static成员和子类共用
//}

//多继承中的菱形继承，比如一个人既是老师又是博士，这个_name可能就会有问题，比如叫刘老师，刘博士
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";//直接用a._name这里会报错
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//虚拟继承可以解决菱形继承的二义性和数据冗余的问题。
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person//虚继承
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	Assistant a;
//	a._name = "peter";
//}

//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;//把地址0x000000D46C4FF820改为1
//	d.C::_a = 2;//把地址0x000000D46C4FF820改为1
//	//这里由于是虚继承，实际上B::_a和C::_a是一个位置的值
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}

//虚继承的核心作用可以总结成一句话：在菱形继承中，让最顶层的基类只保留一份。
//普通继承：Assistant 中有两份 Person
//虚继承：Assistant 中只有一份 Person


//关于继承和对象组合
//继承表示“is-a”，是什么关系。
//组合表示“has - a”，有什么关系。


//1.继承：表示“是一个”
//eg：学生是一个人
class Person
{
public:
    void eat()
    {
        cout << "吃饭" << endl;
    }
};
class Student : public Person
{
public:
    void study()
    {
        cout << "学习" << endl;
    }
};


//2. 对象组合：表示“有一个”
//eg：汽车有一个发动机（一般不能说汽车是一个发动机）
class Engine
{
public:
    void start()
    {
        cout << "发动机启动" << endl;
    }
};

class Car
{
public:
    void run()
    {
        engine.start();
        cout << "汽车行驶" << endl;
    }

private:
    Engine engine; // Car 里面包含一个 Engine 对象
};

//一般优先使用对象组合而不是继承