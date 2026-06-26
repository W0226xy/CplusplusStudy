#include<iostream>
using namespace std;


//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
//	为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
//	这样使用*/
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}

//多态的条件：
//1.虚函数重写（父子类虚函数：函数名、参数、返回值相同）
//2.父类指针或引用去调用
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }//这里析构虽然名字与父类不同，但是编译器会对析构做统一处理（统一为destructor()，让子类析构能够重写）
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函
////数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;//p2是Person，但是指向的是student
//	//指向父类调用父类析构，指向子类调用子类析构
//	delete p1;
//	delete p2;
//	//~Person()
//	//~Student()
//	//~Person()
//	//子类析构会先子后父（构造是先父后子）
//	return 0;
//	//建议析构函数写成虚函数，防止发生内存泄露
//}

//例题：以下程序输出结果是什么（）
//A: A->0 B: B->1 C: A->1 D: B->0 E: 编译出错 F: 以上都不正确
//class A
//{
//public:
//	virtual void func(int val = 1) 
//	{ 
//		std::cout << "A->" << val << std::endl; 
//	}
//	virtual void test() //这里隐藏了A*this的参数
//	{ 
//		func(); 
//	}
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) //构成重写（派生类不加virtual也是虚函数）
//	{ 
//		std::cout << "B->" << val << std::endl; 
//	}
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	//调用父类A的test，test调用func，
//	//这里func用的是子类对象p，构成多态，调用子类对象的func
//	//但是多态这里重写的是函数体的实现，也就是{...}的内容，前面声明还是void func(int val = 1)
//
//	return 0;
//}//一般没人这样写代码，注意一下即可

//例题：
//A：p1 == p2 == p3 B：p1 < p2 < p3 C：p1 == p3 != p2 D：p1 != p2 != p3
//class Base1
//{
//public:
//    int _b1;
//};
//
//class Base2
//{
//public:
//    int _b2;
//};
//
//class Derive : public Base1, public Base2
//{
//public:
//    int _d;
//};
//
//int main()
//{
//    Derive d;//Derive继承了两个类，Derive中有3个成员：_b1,_b2,_d Derive的指针会先指向_b1的位置
//
//    Base1* p1 = &d;//派生类对象转换成不同父类指针。
//    //p1 指向 d 对象中的 Base1 部分,也就是_b1位置，因为 p1 的类型是 Base1*，它只认识 Base1 里面的成员。
//    Base2* p2 = &d;
//    //p2 指向的是 Base2 那一部分，也就是 _b2 的位置。
//    Derive* p3 = &d;
//    //p3 是派生类指针，指向派生类对象 d。
//
//    return 0;
//}//选C

//1. final：修饰虚函数，表示该虚函数不能再被重写
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	//virtual void Drive() { cout << "Benz-舒适" << endl; }//这里会报错无法重写final函数
//};

//2. override: 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。
//class Car {
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }//如果没完成重写，会报错
//};

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "func1()" << endl;
//	}
//private:
//	int _b = 1;
//	char _ch = 'x';
//};
//int main()
//{
//	cout << sizeof(Base) << endl;//16
//	//Base中有虚表指针（虚函数表指针，只要有虚函数就会有）,_b,_ch
//	//无论这个类中有多少个虚函数，都只有一个虚表指针
//  //每个类都有自己的虚表，同类型的对象共用一张虚表
// 
//	//成员	大小
//	//虚表指针 vptr	8 字节
//	//int _b	4 字节
//	//char _ch	1 字节
//	//补齐字节	3 字节
//	//总大小	16 字节
//
//
//	//内存对齐规则
//	//规则一：每个成员要放在自己对齐数的整数倍地址处
//	//规则二：整个对象大小要是最大对齐数的整数倍
//
//		//虚表指针 vptr：8 字节
//		//int _b：4 字节
//		//char _ch：1 字节
//
//		//偏移量
//		//0~7      vptr，8 字节
//		//8~11     int _b，4 字节
//		//12       char _ch，1 字节
//		//13~15    补齐 3 字节
//	return 0;
//}

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//private:
//	int _i = 1;
//};
//
//class Student:public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//private:
//	int _j = 2;
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;//父类对象
//	Func(Mike);//买票-全价
//	//P指向父类对象，调用父类对象的BuyTicket
//
//	Student John;
//	Func(John);//买票-半价
//	//p指向子类对象，子类对象重写了父类对象虚函数，调用子类对象的BuyTicket
//	return 0;
//}




// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	d.Func1();//Derive::Func1()
//	d.Func2();//Base::Func2()
//	d.Func3();//Base::Func3()
//	return 0;
//}
//这段代码主要考察 继承 + 虚函数 + 虚函数表（vtable）+ 重写。
//Base类中Func1()和Func2()是虚函数，这个类的对象内部会有一个虚函数表指针_vfptr(它指向一张虚函数表，虚函数表中存放虚函数的地址。)
//Base对象内部为：虚函数表指针和int _b
//由于Func3不是虚函数，不会进入虚函数表

//Derive类继承Base,
//所以会继承Base::_b
//Base::Func1()
//Base::Func2()
//Base::Func3()

//Derive类又重新实现了Func1()，会重写（覆盖override）父类虚函数
//Derive 的虚函数表中，Func1() 的位置会被替换成子类版本。
//Derive对象内部：虚函数表指针、int _b、int _d
//Derive对象的虚函数表为：Derive::Func1()  和Base::Func2()
// 注意：Func3() 虽然被继承了，但它是普通成员函数，不会进入虚函数表，也不直接存放在对象内部。 
//因为成员函数的代码不存放在每个对象里，而是存放在代码区，所有对象共用一份函数代码
//因为 Func1() 和 Func2() 是虚函数，所以对象里面有一个虚函数表指针 vfptr，它指向虚函数表。（这两个函数也是不直接放对象里面的）
//虚函数本质是一个函数指针数组，存放函数指针的数组

//注意
//虚表存的是虚函数指针，不是虚函数，虚函数和普通函数一样的，都是存在代码段的，只是
//他的指针又存到了虚表中。另外对象中存的不是虚表，存的是虚表指针。


//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//	//父类引用 Person& p 可以接收父类对象，也可以接收子类对象；
//	//当调用虚函数 BuyTicket() 时，会根据 p 实际引用的对象类型决定调用 Person 版本还是 Student 版本，这就是多态。
//}

//class car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//	//在虚函数的后面写上 = 0 ，则这个函数为纯虚函数。
//	//包含纯虚函数的类叫做抽象类（也叫接口类），抽象类不能实例化出对象。
//};
//
////派生类继承后也不能实例化出对象，
////只有重写纯虚函数，派生类才能实例化出对象。
////纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承。
//class Benz :public car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//class BMW :public car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//int main()
//{
//	//car c;//这里会报错
//	Benz benz;
//	benz.Drive();//Benz-舒适
//
//	BMW bmw;
//	bmw.Drive();//BMW-操控
//}
//多态调用：运行时，到指向对象的虚表中找虚函数调用。指向父类，调用父类虚函数。指向子类，调用子类虚函数
//普通调用：编译时，调用对象是哪个类型，就调用他的函数 

//class Base1 {
//public:
//    virtual void func1() { cout << "Base1::func1" << endl; }
//    virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//    int b1;
//};
//
//class Base2 {
//public:
//    virtual void func1() { cout << "Base2::func1" << endl; }
//    virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//    int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//    virtual void func1() { cout << "Derive::func1" << endl; }
//    virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//    int d1;
//};
//
//typedef void(*VFPTR)();
//
//void PrintVTable(VFPTR vTable[], int size)
//{
//    cout << "虚表地址: " << vTable << endl;
//
//    for (int i = 0; i < size; ++i)
//    {
//        cout << "第" << i << "个虚函数地址: " << (void*)vTable[i] << " -> ";
//        VFPTR f = vTable[i];
//        f();
//    }
//
//    cout << endl;
//}
//
//int main()
//{
//    Derive d;
//
//    // 取 Base1 部分的虚表
//    VFPTR* vTableb1 = *(VFPTR**)&d;
//    PrintVTable(vTableb1, 3);
//    //虚表地址: 00007FF6D99DBF08
//    //第0个虚函数地址 : 00007FF6D99D161D->Derive::func1
//    //第1个虚函数地址 : 00007FF6D99D1618->Base1::func2
//    //第2个虚函数地址 : 00007FF6D99D15F0->Derive::func3
//
//
//    // 取 Base2 部分的虚表
//    Base2* pBase2 = &d;
//    VFPTR* vTableb2 = *(VFPTR**)pBase2;
//    PrintVTable(vTableb2, 2);
//    //虚表地址: 00007FF6D99DC058
//    //第0个虚函数地址 : 00007FF6D99D1609->Derive::func1
//    //第1个虚函数地址 : 00007FF6D99D15FA->Base2::func2
//
//    //在多继承下，如果多个父类都有虚函数，子类对象中通常会有多个虚表指针，也就对应多张虚表。
//    return 0;
//}


#include <iostream>
using namespace std;

class A {
public:
    A(const char* s)
    {
        cout << s << endl;
    }

    ~A() {}
};

class B : virtual public A//BC虚继承A，然后D继承BC，这样 D 对象中只会有 一份 A
{//虚继承就是让菱形继承中的公共父类只保留一份，避免数据冗余和访问二义性。
public:
    B(const char* s1, const char* s2)
        : A(s1)
    {
        cout << s2 << endl;
    }
};

class C : virtual public A
{
public:
    C(const char* s1, const char* s2)
        : A(s1)
    {
        cout << s2 << endl;
    }
};

class D : public B, public C
{
public:
    D(const char* s1, const char* s2, const char* s3, const char* s4)
        : A(s1), B(s1, s2), C(s1, s3)
    {
        cout << s4 << endl;
    }
};

int main()
{
    D* p = new D("class A", "class B", "class C", "class D");
    delete p;
    return 0;
}