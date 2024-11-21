//vector应用
//杨辉三角例题https://leetcode.cn/problems/pascals-triangle/
#include<vector>
#include<iostream>
#include<assert.h>
#include"vector.h"
using namespace std;
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv(numRows);//生成一个长度为5，元素为vector<int>的顺序表
//        for (int i = 0; i < numRows; i++)//对生成的顺序表初始化（大小、数值）
//        {
//            vv[i].resize(i + 1, 1);//用1初始化第i个顺序表中的内容，大小为i+1
//        }
//
//        if (numRows >= 3)//如果行数少于2，则不需要多操作（每个顺序表中数都是1）
//        {
//            for (int j = 2; j < numRows; j++)//对于每个顺序表进行数值更新
//            {
//                for (int k = 1; k < vv[j].size() - 1 - 1; k++)
//                {
//                    vv[j][k] = vv[j - 1][k - 1] + vv[j - 1][k];
//                }
//            }
//        }
//
//        return vv;
//
//    }
//};


int main()
{
	//wxy::test1();
	//wxy::test2();
	//wxy::test3();
	// wxy::test4();
	//wxy::test5();
	//wxy::test6();
	//wxy::test7();

	//wxy::test8();
	wxy::test9();
}

