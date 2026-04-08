#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include"stack.h"
#include"queue.h"
#include<concurrent_priority_queue.h>
using namespace std;

//void test1()
//{
//	stack<int> st;//栈后进先出，只能在一端进和出
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";//获取栈顶元素
//		st.pop();//出栈（删除栈顶元素）
//	}
//}
//
//int main()
//{
//	test1();//4 3 2 1
//}



//题目链接
//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        int p1 = 0;//标记入栈元素位置
        int p2 = 0;//标记出栈元素位置
        stack<int> s1;
        while (p1 < pushV.size())
        {
            if (!s1.empty() && popV[p2] == s1.top())//看当前元素是否可以直接出栈
            {
                s1.pop();
                p2++;
                continue;
            }
            if (pushV[p1] != popV[p2])
            {
                s1.push(pushV[p1]);
                p1++;
            }
            else
            {//相等的情况要入栈再出栈，这里直接省略这个步骤是一样的
                p1++;
                p2++;
            }
        }
        //到这里入栈就走完了
        if (s1.empty())
        {
            return true;
        }
        else
        {
            while (!s1.empty())
            {
                int tmp = s1.top();
                if (tmp != popV[p2])
                {
                    return false;
                }
                s1.pop();
                p2++;
            }
            return true;
        }
    }
};

//int main()       
// {
//    vector<int> v1 ;
//    v1.push_back(-6);
//    v1.push_back(15);
//    v1.push_back(4);
//    v1.push_back(17);
//    v1.push_back(7);
//    v1.push_back(14);
//
//    vector<int> v2;
//    v2.push_back(-6);
//    v2.push_back(17);
//    v2.push_back(4);
//    v2.push_back(15);
//    v2.push_back(14);
//    v2.push_back(7);
//    
//    Solution s1;
//    bool b = s1.IsPopOrder(v1, v2);
//    cout << b << endl;
//    return 0;
//}

//int main()
//{
//    wxy::stack<int, vector<int>> st;
//    st.push(1);
//    st.push(2);
//    st.push(3);
//    st.push(4);
//    while (!st.empty())
//    {
//        cout << st.top() << " ";//4 3 2 1
//        st.pop();
//    }
//}


void test_priority_queue()
{
    priority_queue<int> pq;
    pq.push(11);
    pq.push(22);
    pq.push(13);
    pq.push(14);
    pq.push(5);
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}


void test_priority_queue1()
{
    priority_queue<int,vector<int>,greater<int>> pq;//vector<int> 是用作 priority_queue 的底层容器
    //greater<int> 是一个比较函数对象，用于定义元素的排序方式。
    // 默认情况下，priority_queue 是最大堆（最大元素排在队头），而通过传入 greater<int>，我们可以将优先队列改为最小堆（最小元素排在队头）。
    // greater<int> 是一个模板类，它表示“较小的元素具有更高的优先级”。
    pq.push(11);
    pq.push(22);
    pq.push(13);
    pq.push(14);
    pq.push(5);
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void test1()
{
    vector<int> v = { 3,1,54,32,7,4 };
    sort(v.begin(), v.end());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(),greater<int>());
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

//ps:所有数据都是public直接用struct即可
//有些数据公有，有些数据私有，用class


//仿函数
template<class T>
class Less
{
public:
    bool operator()(const T& x, const T& y)
    {
        return x < y;
    }
};

int main()
{
    test_priority_queue();//22 14 13 11 5
    //优先级队列出队会按照从大到小顺序排列，底层是“大堆”，这样的数据结构

    test_priority_queue1();//5 11 13 14 22
    //加参数greater<int>是小堆

    test1();//1 3 4 7 32 54调用sort函数默认是升序
    //加参数greater<int>()则是降序54 32 7 4 3 1

    //ps:greater<int>()传的是对象
    //greater<int>传的是类型

    Less<int> lessfunc;
    cout << lessfunc(1, 2) << endl;//打印1
    //lessfunc(1,2)一眼看过去以为是个函数，其实是个对象
    cout << lessfunc.operator()(1, 2) << endl;//1 和上一句效果一样
    cout << Less<int>()(1, 2) << endl;//1 匿名对象调用operator()
}