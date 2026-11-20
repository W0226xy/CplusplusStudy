#include<iostream>
#include <memory>
using namespace std;

// int div()
// {
//     int a, b;
//     cin >> a >> b;
//     if (b == 0)
//     throw invalid_argument("除0错误");
//     return a / b;
// }
// void Func()
// {
//     // 1、如果p1这里new 抛异常会如何？
//     //如果内存分配失败，`new` 会抛出 std::bad_alloc。
//     // 此时 p1 还没有成功分配，`p2` 和 div() 都不会执行；异常直接传到 main 的 catch 中输出异常信息。
//     // 结论：不会内存泄漏。

//     // 2、如果p2这里new 抛异常会如何？
//     //此时 p1 已经申请成功，但后面的：delete不会执行，p1指向的内存会泄漏


//     // 3、如果div调用这里又会抛异常会如何？
//     //p1和p2指向的内存都会泄漏
//     int* p1 = new int;
//     int* p2 = new int;
//     cout << div() << endl;
//     delete p1;
//     delete p2;
// }


// int main()
// {
//     try
//     {
//         Func();
//     }
//     catch (exception& e)
//     {
//         cout << e.what() << endl;
//     }
//     return 0;
// }



// 使用RAII思想设计的SmartPtr类
//RAII（Resource Acquisition Is Initialization）是一种利用对象生命周期来控制程序资源（如内存、文件句柄、网络连接、互斥量等等）的简单技术。
//在对象构造时获取资源，接着控制对资源的访问使之在对象的生命周期内始终保持有效，最后在对象析构的时候释放资源。
//借此，我们实际上把管理一份资源的责任托管给了一个对象。这种做法有两大好处：
// 1.不需要显式地释放资源。
// 2.采用这种方式，对象所需的资源在其生命期内始终保持有效
// template<class T>
// class SmartPtr {
// public:
//     SmartPtr(T* ptr = nullptr)
//     : _ptr(ptr)
//     {}
    
//     ~SmartPtr()
//     {
//         if(_ptr)
//         delete _ptr;
//         cout<<"已析构"<<endl;
//     }

// private:
//     T* _ptr;
// };

// int div()
// {
//     int a, b;
//     cin >> a >> b;
//     if (b == 0)
//     throw invalid_argument("除0错误");
//     return a / b;
// }

// void Func()
// {
//     SmartPtr<int> sp1(new int);
//     SmartPtr<int> sp2(new int);
//     cout << div() << endl;//此时即使 div() 因为除零抛异常，`Func()` 发生栈展开时：
//     //先析构 sp2，释放第二块 int 内存；
//     //再析构 sp1，释放第一块 int 内存；
//     //然后异常传到 main()，被 catch 捕获。
// }

// int main()
// {
//     try {
//         Func();
//     }
//     catch(const exception& e)
//     {
//         cout<<e.what()<<endl;
//     }
//     return 0;
// }


// C++11库才更新智能指针实现
// C++11出来之前，boost搞除了更好用的scoped_ptr/shared_ptr/weak_ptr
// C++11将boost库中智能指针精华部分吸收了过来
// C++11->unique_ptr/shared_ptr/weak_ptr
// unique_ptr/scoped_ptr
// 原理：简单粗暴 -- 防拷贝
// namespace bit
// {
// template<class T>
//  class unique_ptr
//  {
//     public:
//     unique_ptr(T* ptr)
//     :_ptr(ptr)
//     {}
   
//     ~unique_ptr()
//     {
//         if (_ptr)
//         {
//             cout << "delete:" << _ptr << endl;
//             delete _ptr;
//         }
//     }

//     // 像指针一样使用
//     T& operator*()
//     {
//         return *_ptr;
//     }

//     T* operator->()
//     {
//         return _ptr;
//     }
//     unique_ptr(const unique_ptr<T>& sp) = delete;//不允许拷贝
//     unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;//不允许赋值重载
//  private:
//     T* _ptr;
// };

// }
// int main()
// {
// bit::unique_ptr<int> sp1(new int);
// //bit::unique_ptr<int> sp2(sp1);//不允许拷贝构造
// //原因是：如果允许拷贝，`sp1` 和 sp2 会同时保存同一个地址。函数结束时二者析构，都会执行：delete _ptr;
// //同一块内存被释放两次，产生“双重释放”错误。

// //`unique_ptr` 是“独占管理一块资源的智能指针”
// //同一时间只能有一个 unique_ptr 拥有这块内存；
// //p 离开作用域时，自动 delete 这块内存。
// std::unique_ptr<int> sp3(new int);
// //std::unique_ptr<int> sp2(sp1); 不允许拷贝构造
// std::unique_ptr<int> sp4(move(sp3));//可以移动赋值，把sp3的资源转移给sp4，最后只有 sp4 会释放内存。

// return 0;
// }


//shared_ptr：支持拷贝
// int main()
// {
//     // 两个 shared_ptr 共同管理同一块 int 内存
//     shared_ptr<int> sp1 = make_shared<int>(10);

//     cout << *sp1 << endl;              // 10
//     cout << sp1.use_count() << endl;   // 引用计数：1

//     {
//         shared_ptr<int> sp2 = sp1;     // 允许拷贝，共享所有权

//         cout << *sp2 << endl;              // 10
//         cout << sp1.use_count() << endl;   // 引用计数：2
//         cout << sp2.use_count() << endl;   // 引用计数：2
//     } // sp2 离开作用域，引用计数减为 1

//     cout << sp1.use_count() << endl;   // 1
// } // sp1 离开作用域，引用计数减为 0，自动释放 int 内存


// #include "shared_ptr.h"
// int main()
// {
//     wxy::shared_ptr<int> sp1(new int(1));
//     wxy::shared_ptr<int> sp2(sp1);

//     cout<<"============="<<endl;
    
//     wxy::shared_ptr<int> sp3(new int(2));
//     sp3=sp1;//这里会先把sp3的资源释放掉，然后sp3再去共同管理sp1的资源
//     return 0;

    
// }

// #include <iostream>
// #include "shared_ptr.h"

// int main()
// {
//     wxy::shared_ptr<int> sp1(new int(10));
//     std::cout << *sp1 << std::endl;             // 10
//     std::cout << sp1.use_count() << std::endl;  // 1

//     wxy::shared_ptr<int> sp2(sp1);
//     std::cout << sp1.use_count() << std::endl;  // 2

//     wxy::shared_ptr<int> sp3;
//     sp3 = sp2;
//     std::cout << sp1.use_count() << std::endl;  // 3

//     wxy::shared_ptr<int> sp4(std::move(sp3));
//     std::cout << sp4.use_count() << std::endl;  // 3
//     std::cout << sp3.use_count() << std::endl;  // 0

//     return 0;
// }

//shared_ptr循环引用问题
// struct Node
// {
//     std::shared_ptr<Node> _next;
//     std::shared_ptr<Node> _prev;
//     int _val;

//     ~Node()
//     {
//         cout<<"析构"<<endl;
//     }
// };

// int main()
// {
//    std::shared_ptr<Node> p1(new Node);
//    std::shared_ptr<Node> p2(new Node);
//    cout<<p1.use_count()<<endl;//1
//    cout<<p2.use_count()<<endl;//1
//    p1->_next=p2;// Node2 的引用计数变为 2
//    p2->_prev=p1;//Node1 的引用计数变为 2
//    cout<<p1.use_count()<<endl;//2
//    cout<<p2.use_count()<<endl;//2

//    //当 main 结束时，`p1`、`p2` 两个外部指针销毁，各自计数只减到 1。
//    //两个 Node 仍通过成员变量互相持有，计数永远不会到 0，所以析构函数不会输出“析构”。
//    //程序进程退出后，操作系统会回收这个进程申请的内存。问题在于，如果这是一个长期运行的程序或循环中持续创建这种节点，内存会不断增长。
// }

//weak_ptr解决循环引用问题
//weak_ptr 是“弱引用智能指针”：它可以观察一个由 shared_ptr 管理的对象，但不拥有该对象，因此不会增加强引用计数。
// struct Node
// {
//     std::weak_ptr<Node> _next;// 弱引用：仅观察后驱节点
//     std::weak_ptr<Node> _prev;// 弱引用：仅观察前驱节点
//     int _val;

//     ~Node()
//     {
//         cout<<"析构"<<endl;
//     }
// };

// int main()
// {
//    std::shared_ptr<Node> p1(new Node);
//    std::shared_ptr<Node> p2(new Node);
//    cout<<p1.use_count()<<endl;//1
//    cout<<p2.use_count()<<endl;//1
//    p1->_next=p2;//`p2` 的强引用计数不变。
//    p2->_prev=p1;//`p1` 的强引用计数不变。
   
//    cout<<p1.use_count()<<endl;//1
//    cout<<p2.use_count()<<endl;//1

//    //所以 main 结束后，外部的 p1、`p2` 释放，两个节点都能正常析构。
// }

//shared_ptr 的删除器用于：资源不是通过普通 new 获得，或释放方式不是普通 delete 时。
//有些资源必须用专门的方法释放。最典型的是文件指针 FILE*
//删除器就是“资源怎么申请，就用匹配的方式释放”。`new` 对应 delete，`new[]` 对应 delete[]，`fopen` 对应 fclose，系统句柄或第三方库资源也要用它们提供的释放函数。
#include <cstdio>
#include <memory>
#include <iostream>

int main()
{
    //std::shared_ptr<FILE> file(rawFile, 删除器);第二个参数“删除器”规定：最后一个 shared_ptr 销毁时，这个资源到底应该如何释放。
    std::shared_ptr<FILE> file(
        std::fopen("test.txt", "w"),//"w"：写入模式打开test.txt；文件不存在则创建，存在则清空原内容；返回一个 FILE*；打开失败时返回 nullptr.
        [](FILE* f)
        {
            if (f != nullptr)
            {
                std::fclose(f); // 不能用 delete，必须 fclose
                std::cout << "文件已关闭\n";
            }
        }//因为 FILE* 是由 fopen() 获取的，它不属于 new 出来的 C++ 对象；若用 delete file.get()，行为错误。
    );

    if (!file)
    {
        std::cout << "文件打开失败\n";
        return 1;
    }

    std::fputs("hello\n", file.get());

} // file 最后一个 shared_ptr 析构时，自动调用 fclose