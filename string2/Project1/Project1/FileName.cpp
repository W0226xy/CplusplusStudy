#include<iostream>
using namespace std;
//迭代器简单使用
//int main()
//{
//	string s1("abcdefg");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//
//	cout <<endl<< "------" << endl;
//
//	//反向迭代器
//	string s2("abc");
//	string::reverse_iterator rit = s2.rbegin();
//	while (rit != s2.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//
//	cout << endl << "------" << endl;
//
//	//const修饰的对象要用const的迭代器const_iterator
//	const string s3("abcdefgh");
//	string::const_iterator cit = s3.begin();
//	while (cit != s3.end())
//	{
//		cout << *cit << " ";
//		cit++;
//	}
//	//普通迭代器：可读可写
//	//const迭代器：可读不可写
//
//	cout << endl << "------" << endl;
//
//	string s4("hello world");
//	cout << s4.length() << endl;//11
//	cout << s4.size() << endl;//11
//	//都打印字符串长度11，一般是用size
//
//	cout << s4.max_size() << endl;//9223372036854775807
//	cout << s4.capacity() << endl;//15
//	//在字符串每次插入新元素时，如果容量不够会触发扩容机制
//
//	//清除数据
//	s4.clear();
//	cout <<"s4="<< s4 << endl;//s4=
//	cout << "s4 size=" << s4.size() << endl;//size=0
//	cout << "s4 capacity=" << s4.capacity() << endl; //s4 capacity = 15
//	//清数据的时候，size也会变0，但是原先扩大的容量不会变
//	cout << endl << "------" << endl;
//
//
//	//reserve改变capacity
//	string s;
//	s.reserve(100);
//	cout << s.capacity();//这里reserve100，实际开了111
//	
//	cout << endl << "------" << endl;
//	
//	//如果resever比当前的capacity小
//	s.reserve(10);
//	cout << s.capacity();//这里reserve10，capacity变成了15，也缩小了
//	
//	cout << endl << "------" << endl;
//	//resize改变size
//	string s5("xxxxxxxxxxxxx");
//	cout << s5.size() << endl;
//
//	s5.resize(20);//比原先size大，会用空字符填充
//	cout << s5.size() << endl;
//
//	s5.resize(3);//比原先的size小，会删除字符
//	cout << s5.size() << endl;
//	cout << s5 << endl;
//	return 0;
//}


//int main()
//{
//	string s = "abcdef";
//	cout << s[3] << endl;//d
//	cout << s.at(3) << endl;//d
//
//	try
//	{
//		s.at(10);
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;//invalid string position
//	}
//}

//int main()
//{
//	string s("abc");
//
//	//尾插字符
//	s.push_back('d');
//	cout << s << endl; //abcd
//
//	//尾插字符串
//	s.append("efg");
//	cout << s << endl;//abcdefg
//
//	s.append(10, 'x');
//	cout << s << endl;//abcdefgxxxxxxxxxx
//
//	string s1(" apple ");
//	s.append(s1.begin(), s1.end());
//	cout << s << endl;//abcdefgxxxxxxxxxx apple
//
//	//也可以直接用operator+=
//	s +="hhh";
//	cout << s << endl;//abcdefgxxxxxxxxxx apple hhh
//
//	s.assign("xxxx");
//	cout << s << endl;//把s的空间进行覆盖，重新赋值为xxxx
//
//	s.assign("hello world");
//
//	string ssub = s.substr(2, 5);//从2号下标打印到5号下标
//	cout << ssub << endl;//llo w
//	
//	s.assign("hello world wxy hhh world");
//	int i = s.find("world");//返回找到的第一个world下标
//	cout << i << endl;//6
//
//	s.insert(2, "wxyhhh");//从2号下标开始，插入wxyhhh
//	cout << s << endl;//hewxyhhhllo world wxy hhh world
//
//	s.erase(2, 6);//从第二个位置，删6个字符
//	cout << s << endl;
//	//ps:如果要删的比实际的多，就会删到字符串结尾结束
//	
//	s.replace(2, 1, "abc");//从第二个位置开始，替换1个字符为abc
//	cout << s << endl;
//
//}

//多次替换写法
//int main()
//{
//	string s("hello wxy abc wxy asdf wxy 111 wxy");
//	int pos = s.find("wxy");
//	while (pos != string::npos)//string::npos表示到字符串的结尾
//	{
//		s.replace(pos, 3, "world");//替换pos位置起的3个字符为world
//		pos = s.find("wxy");
//	}
//	cout << s << endl;
//}

//删除字符串中的空格
//int main()
//{
//	string s("hello world");
//	string tmp;
//	for (auto c : s)
//	{
//		if (c != ' ')
//		{
//			tmp += c;
//		}
//	}
//	s = tmp;
//	cout << s << endl;
//}

//替换字符串中的空格（不用replace）
//int main()
//{
//	string s = "hello world";
//	string tmp;
//	//这里替换空格为wxy
//	for (auto c : s)
//	{
//		if (c != ' ')
//		{
//			tmp += c;
//		}
//		else
//		{
//			tmp += "wxy";
//		}
//	}
//	//s = tmp;//这里除了赋值，也可以调swap函数
//	s.swap(tmp);
//	cout << s << endl;
//}

//给你一个字符串 s ，根据下述规则反转字符串：
//所有非英文字母保留在原有位置。
//所有英文字母（小写或大写）位置反转。
//返回反转后的 s 

//示例：
//输入：s = "Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"

//int main()
//{
//	string s("Test1ng-Leet=code-Q!");
//	
//
//	string tmp;
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		if((*it > 65 && *it < 90)||(*it > 97 && *it < 122))//*it是（大小写）字母
//		tmp += *it;
//		it++;
//	}
//	
//	string::iterator it1 = s.begin();
//	string::reverse_iterator it2 = tmp.rbegin();//反向遍历迭代器
//	while (it1 != s.end())
//	{
//		if ((*it1 > 65 && *it1 < 90) || (*it1 > 97 && *it1 < 122))//遇到字母，把tmp里对应字母赋过去
//		{
//			*it1 = *it2;
//			it1++;
//			it2++;
//		}
//		else
//		{
//			it1++;
//		}
//	}
//	cout << s << endl;
//}

//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
//法一：暴力求解
//bool oneTime(string tmp,char c)
//{
//	int i = 0;
//	string::iterator it = tmp.begin();
//	while (it != tmp.end())
//	{
//		if (*it != c)
//		{
//			it++;
//		}
//		else
//		{
//			i++;
//			it++;
//		}
//	}
//	if (i != 1)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//	
//}
//int main()
//{
//	string s;
//	cin >> s;
//
//	string tmp=s;//存已经出现过的字母
//	
//	
//	int i = 0;
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		if (oneTime(tmp, *it))
//		{
//			cout << i<<endl;
//			return 0;
//		}
//		else
//		{
//			it++;
//			i++;
//		}
//	}
//	cout << -1 << endl;
//}

//法二：哈希表

#include <unordered_map>
//int main()
//{
//	string s;
//	cin >> s;
//	unordered_map<char, int> HashMap;
//
//	string::iterator it = s.begin();
//
//	int i = 0;//标记元素下标
//
//	while (it != s.end())//初始化哈希表
//	{
//		if (HashMap.count(*it) > 0)//原先hash表中存在字符*it
//		{
//			HashMap[*it]++;//value++
//			it++;
//		}
//		else//原先不存在，则插入键值对
//		{
//			HashMap.insert(make_pair(*it, 1));
//			it++;
//		}
//
//	}
//
//	
//	for (auto c : s)
//	{
//		if (HashMap[c]==1)
//		{
//			cout << i << endl;
//			return 0;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	//前面还没return出去，说明都有重复
//	cout << -1;
//
//	return 0;
//}

//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
//示例 1：
//输入：num1 = "11", num2 = "123"
//输出："134"
//
//示例 2：
//输入：num1 = "456", num2 = "77"
//输出："533"
//
//示例 3：
//输入：num1 = "0", num2 = "0"
//输出："0"
//ps：这里输出的也是字符串




//法一：暴力法（部分特别大的无法通过）
//long long myStringLong(string s)//string->int
//{
//	long long i = 0;
//	string::iterator it = s.begin();//反向迭代器
//	while (it != s.end())
//	{
//		i *= 10;
//		i += *it-48;//数字0-9对应的ascii码48-57
//		it++;
//	}
//	return i;
//}
//
//string mylongString(long long i)//int->string
//{
//	//123
//	string s1;
//	while (i != 0)
//	{
//		int x = i % 10;
//		char c = 48 + x;
//		s1 += c;
//		i /= 10;
//	}
//	//到这里得到321
//
//	//再反向遍历回去
//	string::reverse_iterator rit = s1.rbegin();
//	string s2;
//	while (rit != s1.rend())
//	{
//		s2 += *rit;
//		rit++;
//	}
//	return s2;
//}
//
//
//int main()
//{
//	string num1;
//	string num2;
//	
//	cout << "请输入num1：";
//	cin >> num1;
//	cout << "请输入num2：";
//	cin >> num2;
//	
//	long long Num1 = myStringLong(num1);
//	long long Num2 = myStringLong(num2);
//	long long x=Num1 + Num2;//先获取int
//
//	if (x == 0)
//	{
//		cout << "" << endl;
//		return 0;
//	}
//
//	//最终需要把int转成string返回
//	string y = mylongString(x);
//	cout << y << endl;
//	return 0;
//}
#include<string>
//法二：按位相加

string String1(string num1, string num2, int flag)//不等长情况，子串处理
{//num1长度大于num2
    if (flag == 1)//需要进位
    {
        int k = num1.size() - num2.size();//获取长度之差
        string s = num1.substr(0, k);//取子串
        //substr（i,j）从第i个位置取j个长度的子串

        if (s[k - 1] - '0' < 9)//不需要进位
        {
            s[k - 1]++;
        }
        else//需要进位
        {
            while (s[k - 1] - '0' == 9)
            {
                s[k - 1] = '0';
                k--;
                if (k == 0)
                {
                    string tmp = "1";
                    s = tmp + s;
                    break;
                }
                if (s[k-1]-'0' != 9)//防止是9+1
                {
                    s[k - 1]++;
                    break;
                }
            }
        }
        return s;
    }
    else//不需要进位，直接取剩余子串相加即可
    {
        int k = num1.size() - num2.size();
        string s = num1.substr(0, k);
        return s;
    }
}
string addStrings(string num1, string num2) {
    //从最后一位开始遍历
    string num;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    int flag = 0;//用于标记后面是否需要进位

    for (i, j; i >= 0, j >= 0; i--, j--)
    {
        if (i < 0 || j < 0)
        {
            break;
        }
        int c1 = num1[i] - '0';//获得对应位的数字
        int c2 = num2[j] - '0';
        int c3;
        if (flag == 0)//前面遍历的一位相加没有超过10
        {
            c3 = c1 + c2;
        }
        else
        {
            c3 = c1 + c2 + 1;
        }
        string tmp = to_string(c3);
        if (c3 >= 10)
        {
            //个位数最大就是9+9+1
            //相加最大是两位数
            num.insert(num.begin(), tmp[1]);//头插
            flag = 1;
        }
        else
        {
            num.insert(num.begin(), tmp[0]);
            flag = 0;
        }
    }
    if (num1.size() == num2.size())
    {
        if (flag == 0)//等长无进位
        {
            return num;
        }
        else//等长有进位
        {
            //等长进位最多进1位
            //比如91+92
            //1+2=3 个位取3
            //9+9=18 十位取8
            num.insert(0, 1,'1');
            return num;
        }
    }
    //防止两字符串不等长
    if (num1.size() > num2.size())
    {
        string s = String1(num1, num2, flag);
        s += num;
        num = s;
    }
    else
    {
        string s = String1(num2, num1, flag);
        s += num;
        num = s;
    }
    
    return num;
}

int main()
{
    string s1 = "71";
    string s2 = "168899993";
    
    string s=addStrings(s1, s2);
    cout << s << endl;
    return 0;
   
}

//验证回文串
// 
//如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 
//字母和数字都属于字母数字字符。
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

//示例 1：
//输入 : s = "A man, a plan, a canal: Panama"
//输出：true
//解释："amanaplanacanalpanama" 是回文串。
//
//示例 2：
//输入：s = "race a car"
//输出：false
//解释："raceacar" 不是回文串。
//
//示例 3：
//输入：s = " "
//输出：true
//解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。

//string func(string s)//先将大写转换成小写，并且去除空格等，只保留小写字母
//{
//	string tmp;
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		//大写字母
//		if (*it <= 90 && *it>=65)//A-Z的ASCII码为65-90
//		{
//			tmp += *it + 32;//a-z的ASCII码为97-122
//		}
//		//小写字母
//		else if(*it <= 122 && *it>=97)
//		{
//			tmp += *it;
//		}
//		else if (*it <= 57 && *it >= 48)//数字0-9
//		{
//			tmp += *it;
//		}
//		it++;
//	}
//	return tmp;
//}
//
//bool isPalindrome(string s) {
//
//	string s1 = func(s);//去除非字母元素，并将大写转换为小写
//	string::iterator it = s1.begin();
//	string::reverse_iterator rit = s1.rbegin();
//
//	while (it!=s1.end())
//	{
//		if (*it != *rit)
//		{
//			return false;
//		}
//		else
//		{
//			it++;
//			rit++;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	string s = " ";
//	bool fl = isPalindrome(s);
//	cout << fl << endl;
//}


//int main()
//{
//	char c1 = 'a';//ascii码97
//	char c2 = 98;
//	cout << c1 << endl;//a
//	cout << c2 << endl;//b
//}

//int main()
//{
//	//下面是utf-8编码（中文编码）
//	char buff[] = "吃饭睡觉";
//	cout << buff<< endl; //吃饭睡觉
//	buff[3]++;
//	buff[3]++;
//	cout << buff<< endl;//吃坊睡觉
//
//	buff[1]++;
//	buff[1]++;
//	cout << buff<< endl;//持坊睡觉
//	
//}


//toString:将其他类型转成string
//stod:将其他类型从string转回去
//#include<string>
//int main()
//{
//	//将其他类型转成string
//	int i = 1234;
//	double d = 3.14;
//	string s1 = to_string(i);
//	string s2 = to_string(d);
//	cout << s1 << endl;//1234
//	cout << s2 << endl;//3.140000
//
//	//如果要转回去
//	double d1 = stod(s2);
//	cout << d1 << endl;//3.14
//}