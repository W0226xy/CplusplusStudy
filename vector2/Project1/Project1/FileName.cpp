//vectorӦ��
//�����������https://leetcode.cn/problems/pascals-triangle/
#include<vector>
#include<iostream>
#include<assert.h>
#include"vector.h"
using namespace std;
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv(numRows);//����һ������Ϊ5��Ԫ��Ϊvector<int>��˳���
//        for (int i = 0; i < numRows; i++)//�����ɵ�˳����ʼ������С����ֵ��
//        {
//            vv[i].resize(i + 1, 1);//��1��ʼ����i��˳����е����ݣ���СΪi+1
//        }
//
//        if (numRows >= 3)//�����������2������Ҫ�������ÿ��˳�����������1��
//        {
//            for (int j = 2; j < numRows; j++)//����ÿ��˳��������ֵ����
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

