#include<iostream>
using namespace std;
//��������ʹ��
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
//	//���������
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
//	//const���εĶ���Ҫ��const�ĵ�����const_iterator
//	const string s3("abcdefgh");
//	string::const_iterator cit = s3.begin();
//	while (cit != s3.end())
//	{
//		cout << *cit << " ";
//		cit++;
//	}
//	//��ͨ���������ɶ���д
//	//const���������ɶ�����д
//
//	cout << endl << "------" << endl;
//
//	string s4("hello world");
//	cout << s4.length() << endl;//11
//	cout << s4.size() << endl;//11
//	//����ӡ�ַ�������11��һ������size
//
//	cout << s4.max_size() << endl;//9223372036854775807
//	cout << s4.capacity() << endl;//15
//	//���ַ���ÿ�β�����Ԫ��ʱ��������������ᴥ�����ݻ���
//
//	//�������
//	s4.clear();
//	cout <<"s4="<< s4 << endl;//s4=
//	cout << "s4 size=" << s4.size() << endl;//size=0
//	cout << "s4 capacity=" << s4.capacity() << endl; //s4 capacity = 15
//	//�����ݵ�ʱ��sizeҲ���0������ԭ����������������
//	cout << endl << "------" << endl;
//
//
//	//reserve�ı�capacity
//	string s;
//	s.reserve(100);
//	cout << s.capacity();//����reserve100��ʵ�ʿ���111
//	
//	cout << endl << "------" << endl;
//	
//	//���resever�ȵ�ǰ��capacityС
//	s.reserve(10);
//	cout << s.capacity();//����reserve10��capacity�����15��Ҳ��С��
//	
//	cout << endl << "------" << endl;
//	//resize�ı�size
//	string s5("xxxxxxxxxxxxx");
//	cout << s5.size() << endl;
//
//	s5.resize(20);//��ԭ��size�󣬻��ÿ��ַ����
//	cout << s5.size() << endl;
//
//	s5.resize(3);//��ԭ�ȵ�sizeС����ɾ���ַ�
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
//	//β���ַ�
//	s.push_back('d');
//	cout << s << endl; //abcd
//
//	//β���ַ���
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
//	//Ҳ����ֱ����operator+=
//	s +="hhh";
//	cout << s << endl;//abcdefgxxxxxxxxxx apple hhh
//
//	s.assign("xxxx");
//	cout << s << endl;//��s�Ŀռ���и��ǣ����¸�ֵΪxxxx
//
//	s.assign("hello world");
//
//	string ssub = s.substr(2, 5);//��2���±��ӡ��5���±�
//	cout << ssub << endl;//llo w
//	
//	s.assign("hello world wxy hhh world");
//	int i = s.find("world");//�����ҵ��ĵ�һ��world�±�
//	cout << i << endl;//6
//
//	s.insert(2, "wxyhhh");//��2���±꿪ʼ������wxyhhh
//	cout << s << endl;//hewxyhhhllo world wxy hhh world
//
//	s.erase(2, 6);//�ӵڶ���λ�ã�ɾ6���ַ�
//	cout << s << endl;
//	//ps:���Ҫɾ�ı�ʵ�ʵĶ࣬�ͻ�ɾ���ַ�����β����
//	
//	s.replace(2, 1, "abc");//�ӵڶ���λ�ÿ�ʼ���滻1���ַ�Ϊabc
//	cout << s << endl;
//
//}

//����滻д��
//int main()
//{
//	string s("hello wxy abc wxy asdf wxy 111 wxy");
//	int pos = s.find("wxy");
//	while (pos != string::npos)//string::npos��ʾ���ַ����Ľ�β
//	{
//		s.replace(pos, 3, "world");//�滻posλ�����3���ַ�Ϊworld
//		pos = s.find("wxy");
//	}
//	cout << s << endl;
//}

//ɾ���ַ����еĿո�
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

//�滻�ַ����еĿո񣨲���replace��
//int main()
//{
//	string s = "hello world";
//	string tmp;
//	//�����滻�ո�Ϊwxy
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
//	//s = tmp;//������˸�ֵ��Ҳ���Ե�swap����
//	s.swap(tmp);
//	cout << s << endl;
//}

//����һ���ַ��� s ��������������ת�ַ�����
//���з�Ӣ����ĸ������ԭ��λ�á�
//����Ӣ����ĸ��Сд���д��λ�÷�ת��
//���ط�ת��� s 

//ʾ����
//���룺s = "Test1ng-Leet=code-Q!"
//�����"Qedo1ct-eeLg=ntse-T!"

//int main()
//{
//	string s("Test1ng-Leet=code-Q!");
//	
//
//	string tmp;
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		if((*it > 65 && *it < 90)||(*it > 97 && *it < 122))//*it�ǣ���Сд����ĸ
//		tmp += *it;
//		it++;
//	}
//	
//	string::iterator it1 = s.begin();
//	string::reverse_iterator it2 = tmp.rbegin();//�������������
//	while (it1 != s.end())
//	{
//		if ((*it1 > 65 && *it1 < 90) || (*it1 > 97 && *it1 < 122))//������ĸ����tmp���Ӧ��ĸ����ȥ
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

//����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� -1 ��
//��һ���������
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
//	string tmp=s;//���Ѿ����ֹ�����ĸ
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

//��������ϣ��

#include <unordered_map>
//int main()
//{
//	string s;
//	cin >> s;
//	unordered_map<char, int> HashMap;
//
//	string::iterator it = s.begin();
//
//	int i = 0;//���Ԫ���±�
//
//	while (it != s.end())//��ʼ����ϣ��
//	{
//		if (HashMap.count(*it) > 0)//ԭ��hash���д����ַ�*it
//		{
//			HashMap[*it]++;//value++
//			it++;
//		}
//		else//ԭ�Ȳ����ڣ�������ֵ��
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
//	//ǰ�滹ûreturn��ȥ��˵�������ظ�
//	cout << -1;
//
//	return 0;
//}

//���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺͲ�ͬ�����ַ�����ʽ���ء�
//�㲻��ʹ���κ΃Ƚ������ڴ���������Ŀ⣨���� BigInteger���� Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��
//ʾ�� 1��
//���룺num1 = "11", num2 = "123"
//�����"134"
//
//ʾ�� 2��
//���룺num1 = "456", num2 = "77"
//�����"533"
//
//ʾ�� 3��
//���룺num1 = "0", num2 = "0"
//�����"0"
//ps�����������Ҳ���ַ���




//��һ���������������ر����޷�ͨ����
//long long myStringLong(string s)//string->int
//{
//	long long i = 0;
//	string::iterator it = s.begin();//���������
//	while (it != s.end())
//	{
//		i *= 10;
//		i += *it-48;//����0-9��Ӧ��ascii��48-57
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
//	//������õ�321
//
//	//�ٷ��������ȥ
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
//	cout << "������num1��";
//	cin >> num1;
//	cout << "������num2��";
//	cin >> num2;
//	
//	long long Num1 = myStringLong(num1);
//	long long Num2 = myStringLong(num2);
//	long long x=Num1 + Num2;//�Ȼ�ȡint
//
//	if (x == 0)
//	{
//		cout << "" << endl;
//		return 0;
//	}
//
//	//������Ҫ��intת��string����
//	string y = mylongString(x);
//	cout << y << endl;
//	return 0;
//}
#include<string>
//��������λ���

string String1(string num1, string num2, int flag)//���ȳ�������Ӵ�����
{//num1���ȴ���num2
    if (flag == 1)//��Ҫ��λ
    {
        int k = num1.size() - num2.size();//��ȡ����֮��
        string s = num1.substr(0, k);//ȡ�Ӵ�
        //substr��i,j���ӵ�i��λ��ȡj�����ȵ��Ӵ�

        if (s[k - 1] - '0' < 9)//����Ҫ��λ
        {
            s[k - 1]++;
        }
        else//��Ҫ��λ
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
                if (s[k-1]-'0' != 9)//��ֹ��9+1
                {
                    s[k - 1]++;
                    break;
                }
            }
        }
        return s;
    }
    else//����Ҫ��λ��ֱ��ȡʣ���Ӵ���Ӽ���
    {
        int k = num1.size() - num2.size();
        string s = num1.substr(0, k);
        return s;
    }
}
string addStrings(string num1, string num2) {
    //�����һλ��ʼ����
    string num;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    int flag = 0;//���ڱ�Ǻ����Ƿ���Ҫ��λ

    for (i, j; i >= 0, j >= 0; i--, j--)
    {
        if (i < 0 || j < 0)
        {
            break;
        }
        int c1 = num1[i] - '0';//��ö�Ӧλ������
        int c2 = num2[j] - '0';
        int c3;
        if (flag == 0)//ǰ�������һλ���û�г���10
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
            //��λ��������9+9+1
            //����������λ��
            num.insert(num.begin(), tmp[1]);//ͷ��
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
        if (flag == 0)//�ȳ��޽�λ
        {
            return num;
        }
        else//�ȳ��н�λ
        {
            //�ȳ���λ����1λ
            //����91+92
            //1+2=3 ��λȡ3
            //9+9=18 ʮλȡ8
            num.insert(0, 1,'1');
            return num;
        }
    }
    //��ֹ���ַ������ȳ�
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

//��֤���Ĵ�
// 
//����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� 
//��ĸ�����ֶ�������ĸ�����ַ���
//����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��

//ʾ�� 1��
//���� : s = "A man, a plan, a canal: Panama"
//�����true
//���ͣ�"amanaplanacanalpanama" �ǻ��Ĵ���
//
//ʾ�� 2��
//���룺s = "race a car"
//�����false
//���ͣ�"raceacar" ���ǻ��Ĵ���
//
//ʾ�� 3��
//���룺s = " "
//�����true
//���ͣ����Ƴ�����ĸ�����ַ�֮��s ��һ�����ַ��� "" ��

//string func(string s)//�Ƚ���дת����Сд������ȥ���ո�ȣ�ֻ����Сд��ĸ
//{
//	string tmp;
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		//��д��ĸ
//		if (*it <= 90 && *it>=65)//A-Z��ASCII��Ϊ65-90
//		{
//			tmp += *it + 32;//a-z��ASCII��Ϊ97-122
//		}
//		//Сд��ĸ
//		else if(*it <= 122 && *it>=97)
//		{
//			tmp += *it;
//		}
//		else if (*it <= 57 && *it >= 48)//����0-9
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
//	string s1 = func(s);//ȥ������ĸԪ�أ�������дת��ΪСд
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
//	char c1 = 'a';//ascii��97
//	char c2 = 98;
//	cout << c1 << endl;//a
//	cout << c2 << endl;//b
//}

//int main()
//{
//	//������utf-8���루���ı��룩
//	char buff[] = "�Է�˯��";
//	cout << buff<< endl; //�Է�˯��
//	buff[3]++;
//	buff[3]++;
//	cout << buff<< endl;//�Է�˯��
//
//	buff[1]++;
//	buff[1]++;
//	cout << buff<< endl;//�ַ�˯��
//	
//}


//toString:����������ת��string
//stod:���������ʹ�stringת��ȥ
//#include<string>
//int main()
//{
//	//����������ת��string
//	int i = 1234;
//	double d = 3.14;
//	string s1 = to_string(i);
//	string s2 = to_string(d);
//	cout << s1 << endl;//1234
//	cout << s2 << endl;//3.140000
//
//	//���Ҫת��ȥ
//	double d1 = stod(s2);
//	cout << d1 << endl;//3.14
//}