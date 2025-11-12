#include<iostream>
using namespace std;
#include<string>

#include<atlfile.h>
//int main()
//{
//	string s("hello world");
//	string filename("test.cpp");
//	FILE* f = fopen(filename.c_str(),"r");
//	//fopen是c语言的一个函数，不支持对象
//	//filename是一个string对象，要把它变成普通的字符串可以用一下c_str
//}


//find使用示例1
//int main()
//{
//	//查找对应字符串
//	string s1("file.txt");
//	int x = s1.find('.');
//	cout << x << endl;//打印'.'的下标4
//
//	int y = s1.find('a');
//	cout << y << endl;//如果没找到打印-1
//
//	//取子串
//	string s2("hello world i love china");
//	size_t pos1 = s2.find(' ');//查找到第一个空格下标
//	if (pos1 != string::npos)
//	{
//		string suffix = s2.substr(pos1);//从空格下标处往后取子串（包括空格）
//		cout << suffix << endl;// world i love china
//	}
//	else
//	{
//		cout << "未找到对应子串" << endl;
//	}
//	
//}

//find使用示例2
//int main()
//{
//	string url("https://wenku.baidu.com/tfview/752bcc13f41fb7360b4c2e3f5727a5e9846a2782.html?fr=launch_ad&SS-bdtg161&utm_source=bdss-WD&utm_medium=cpc&keyword=%C5%B5%B1%B4%B6%FB%CE%EF%C0%ED%D1%A7%BD%B1&utm_account=SS-bdtg161&e_creative=67005177916&e_keywordid=518892501073&bd_vid=17227497446310251758");
//	
//	string protocol, domain, uri;//协议，域名，资源
//
//	size_t i1 = url.find(':');
//	if (i1 != string::npos)//string::npos表示到字符串的结尾
//	{
//		protocol = url.substr(0, i1);
//		cout << protocol << endl;//打印https
//	}
//
//	size_t i2 = url.find('/',i1+3);//23
//	//从i1+3处开始找，找出现第一个/的位置
//	//左闭右开
//
//	if (i2 != string::npos)
//	{
//		domain = url.substr(i1 + 3, i2 - (i1 + 3));//从i1+3位置开始，取i2 - (i1 + 3)的长度
//		cout << domain << endl;//wenku.baidu.com
//	}
//}

//int main()
//{
//	string s1 = "hello";
//	string s2 = "world";
//	cout << s1 + s2 << endl;//helloworld
//}

//给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//示例 1：
//输入：s = "abcdefg", k = 2
//输出："bacdfeg"
//
//示例 2：
//输入：s = "abcd", k = 2
//输出："bacd"

string reverse(string s1)
{
	string s2;
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		s2 += *rit;
		rit++;
	}
	return s2;
}
int main()
{
	string s="abcdefg";
	int k=2;
	
	string s1;

	int i = 0;//标记字符串下标
	int j = 0;
	int length =s.length();

	for (i = 0; i < length; i += 2 * k)
	{
		if (i + 2 * k < length)
		{
			string tmp = s.substr(i, k);//字符串s从i号下标位置取k个字符
			tmp = reverse(tmp);
			s1 += tmp;
			s1 += s.substr(i + k,  k);
		}
		else if (i + 2 * k >= length && i + k < length)
		{
			string tmp = s.substr(i, k);//字符串s从i号下标位置取k个字符
			tmp = reverse(tmp);
			s1 += tmp;
			s1 += s.substr(i + k, length - (i + k));
		}
		else//i+k>length
		{
			string tmp = s.substr(i, length);//字符串s从i号下标位置取k个字符
			tmp = reverse(tmp);
			s1 += tmp;
		}
	}
		
	
	
	cout << s1;
	return 0;
}



//给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//示例 1：
//输入：s = "Let's take LeetCode contest"
//输出："s'teL ekat edoCteeL tsetnoc"
//
//示例 2:
//输入： s = "Mr Ding"
//输出："rM gniD"

//string reverse(string s1)
//{
//	string s2;
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		s2 += *rit;
//		rit++;
//	}
//	return s2;
//}
//int main()
//{
//	string s="Let's take LeetCode contest";
//	string s1;
//	int i = 0;
//	int j = 0;
//	int length = s.length();
//	for (i = 0; i < length; )//因为不知道具体单词长度，这里不做++处理
//	{
//		while (s[j] != ' ')//找到下一个空格
//		{
//			j++;
//			if (j >= length)
//			{
//				break;
//			}
//		}
//		int k = j - i;//所需反转的单词长度
//		string tmp = s.substr(i, k);
//		tmp = reverse(tmp);
//		s1 += tmp;
//
//		int m = s.find(' ');
//		s1 += ' ';
//
//		i += k+1;
//		j = i+1;
//		
//	}
//	//最后得出的s1末尾会多一个空格，把它截断
//	s1 = s1.substr(0, s1.length() - 1);
//	cout << s1 << endl;
//
//}

