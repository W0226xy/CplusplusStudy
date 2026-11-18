#include<iostream>
using namespace std;
double Division(int a, int b)
{
    if(b==0)
    {
        throw "Division by zero condition";
    }
    return ((double)a / (double)b);
}
void Func()
{
    int len, time;
    cin >> len >> time;
    cout << Division(len, time) << endl;
}
int main()
{
    try {
        Func();//这里输入5 0测试
    }
    catch (const int* errmsg)//这里类型不匹配，捕获不到
    {
        cout<<"1捕获到了异常"<<endl;
        cout << errmsg << endl;
    }
    catch (const char* errmsg) {//这里捕获的异常类型要匹配
        cout<<"2捕获到了异常"<<endl;//2捕获到了异常
        cout << errmsg << endl;//Division by zero condition
    }
    catch(...){//这里捕获任意类型
        cout<<"unkown exception"<<endl; 
    } 
    return 0;
}