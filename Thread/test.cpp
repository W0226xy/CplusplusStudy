#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<atomic>
#include <condition_variable>
using namespace std;

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Thread ID: "<<this_thread::get_id()<<" Value: "<<i<<endl;
    }
}

// int main()
// {
//     thread t1(print, 5);//创建一个名为 t1 的新线程，让它执行：print(5);
//     thread t2(print, 5);
//     t1.get_id(); //获取线程 t1 的 ID
//     t2.get_id(); //获取线程 t2 的 ID
//     printf("t1 thread id: %d\n", t1.get_id());// t1 thread id: 2
//     printf("t2 thread id: %d\n", t2.get_id());// t2 thread id: 3


//     t1.join();//等待 t1 线程完成
//     t2.join();

//     //主线程等待 t1 和 t2 都执行完再退出。否则如果 main() 先结束，程序会直接结束，两个打印线程也无法正常完成。
//     return 0;

// }

int x=0;
void addtest(int n)
{
    for(int i=0;i<n;i++)
    {
        x++;
    }
}

void addtest_mutex(int n, mutex &m)
{
    m.lock();
    for(int i=0;i<n;i++)
    {
        x++;
    }
     m.unlock();
}
// int main()
// {
//     thread t1(addtest, 10000);
//     thread t2(addtest, 10000);
//     t1.join();
//     t2.join();
//     cout<<"Final value of x: "<<x<<endl;//输出结果可能不是20000，因为两个线程同时对x进行修改，导致数据竞争
//     //可以用互斥锁(mutex)来解决这个问题，保证同一时间只有一个线程可以修改x的值，从而避免数据竞争。

//     x=0;

//     mutex m;
//     thread t3(addtest_mutex, 10000, ref(m));//使用互斥锁来保护对x的修改，保证线程安全。ref(m) 是 std::ref(m)，作用是：把 m 以“引用方式”传给新线程。
//     //如果直接传m，会调用mutex的拷贝构造函数，导致编译错误，因为mutex是不可拷贝的。
//     //因为 mutex 代表的是“一把具体的锁”，它内部关联了操作系统提供的同步资源和状态，不能安全地复制。

//     thread t4(addtest_mutex, 10000, ref(m));
//     t3.join();
//     t4.join();
//     cout<<"Final value of x with mutex: "<<x<<endl;//输出结果应该是20000，因为使用了互斥锁，保证了线程安全。
// }

// int main()
// {
//     int a=0;
//     mutex m;
//     //用 Lambda 表达式作为线程函数
//     //[&] 表示：Lambda 中用到的外部局部变量都按引用捕获。因此，线程内部访问的 a 和 m，就是 main 中那两个对象，不是副本。
//     thread t1([&](){
//         for(int i=0;i<10000;i++)
//         {
//             m.lock();
//             a++;
//             m.unlock();
//         }
//     });

//     thread t2([&](){
//         for(int i=0;i<10000;i++)
//         {
//             m.lock();
//             a++;
//             m.unlock();
//         }
//     });

//     t1.join();
//     t2.join();

//     cout<<"Final value of a with mutex: "<<a<<endl;//输出结果应该是20000，因为使用了互斥锁，保证了线程安全。
// }

// int main()
// {
//     vector<thread> threads;
//     int n;
//     cin>>n;
//     threads.resize(n);//创建一个大小为 n 的线程数组
//     int x=0;
//     mutex m;
//     auto func=[&](int n){
//         for(int i=0;i<n;i++)
//         {
//             m.lock();
//             x++;
//             m.unlock();
//         }
//     };

//     for(auto &t:threads)
//     {
//         t=thread(func, 10000);
//     }
//     for(auto &t:threads)
//     {
//         t.join();
//     }
//     cout<<"Final value of x with mutex: "<<x<<endl;
//     return 0;
// }

class LockGuard
{
public:
    LockGuard(mutex& mtx)
        :_mtx(mtx)
    {
        _mtx.lock();
    }
    ~LockGuard()
    {
        _mtx.unlock();
    }

private:
    mutex& _mtx;
};
// int main()
// {
//     vector<thread> threads;
//     int n;
//     cin>>n;
//     threads.resize(n);//创建一个大小为 n 的线程数组
//     int x=0;
//     mutex m;
//     auto func=[&](int n){
//         for(int i=0;i<n;i++)
//         {
//             LockGuard lock(m);//创建一个 LockGuard 对象，自动加锁
//             x++;
//         }//LockGuard 对象在这里被销毁，自动解锁
//     };

//     for(auto &t:threads)
//     {
//         t=thread(func, 10000);
//     }
//     for(auto &t:threads)
//     {
//         t.join();
//     }
//     cout<<"Final value of x with LockGuard: "<<x<<endl;
//     return 0;
// }


// int main()
// {
//     vector<thread> threads;
//     int n;
//     cin>>n;
//     threads.resize(n);//创建一个大小为 n 的线程数组
//     //这次不用互斥锁，而使用了原子变量 atomic<int>
//     //x 初始值为 0，但它不是普通 int，而是“原子整数”。多个线程同时对它加一时，`atomic` 能保证每次加一都完整执行，不会发生数据竞争。2
//     atomic<int> x(0);//使用 atomic<int> 类型的变量 x，保证对 x 的操作是原子性的
//     auto func=[&](int n){
//         for(int i=0;i<n;i++)
//         {
//             x++;//对 atomic<int> 类型的变量 x 进行自增操作，是线程安全的
//         }
//     };

//     for(auto &t:threads)
//     {
//         t=thread(func, 10000);
//     }
//     for(auto &t:threads)
//     {
//         t.join();
//     }
//     cout<<"Final value of x with atomic: "<<x<<endl;//输出结果应该是 n*10000，因为使用了 atomic<int>，保证了线程安全。
//     return 0;
// }

//两个程序交替打印奇数偶数
int main()
{
    int n;
    cin>>n;
    mutex m;//保护共享变量 odd_turn，避免两个线程同时修改它
    condition_variable cv;//条件变量，用来让线程“等待自己的回合”。
    bool odd_turn=true;//表示当前是否轮到奇数线程打印
    auto print_odd=[&](){
        for(int i=1;i<=n;i+=2)
        {
            unique_lock<mutex> lock(m);//unique_lock 是一个互斥锁的智能指针，构造时自动加锁，析构时自动解锁
            cv.wait(lock, [&](){return odd_turn;});//如果 odd_turn 为 false，则当前线程阻塞，直到 odd_turn 为 true
           //实际逻辑类似于：
            //while (!odd_turn)
            // {
            //     lock.unlock();  // 暂时放开 m，不能一直占着锁等待
            //     cv.wait();      // 进入等待状态
            //     lock.lock();    // 被通知唤醒后，重新竞争并获得 m
            // }
           
            cout<<i<<endl;
            odd_turn=false;
            cv.notify_all();//唤醒所有等待的线程，让偶数线程打印
        }
    };

    auto print_even=[&](){
        for(int i=2;i<=n;i+=2)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return !odd_turn;});
            cout<<i<<endl;
            odd_turn=true;
            cv.notify_all();
        }
    };

    thread t1(print_odd);
    thread t2(print_even);
    t1.join();
    t2.join();
    return 0;
}

//lambda表达式
// int main()
// {
//     //基本格式
//     //[捕获列表](参数列表) -> 返回类型 {
//     //     函数体
//     // };
    
//     //捕获列表：指定 lambda 表达式中使用的外部变量的访问方式。可以是按值捕获（[=]）或按引用捕获（[&]）。
//     //捕获列表是因为函数体可能用到了外部的局部变量，而 lambda 表达式是一个匿名函数，它没有自己的参数列表，所以需要通过捕获列表来获取外部变量的值或引用。
//     //参数列表：指定 lambda 表达式的参数类型和名称。可以为空。

//     auto add = [](int a, int b) -> int {
//         return a + b;
//     };

//     cout << add(3, 5);  // 8

//     int x = 10;
//     auto print = [x]() {
//         cout << x;
//     };
//     print();//10
// }