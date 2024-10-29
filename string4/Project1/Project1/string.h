#define _CRT_SECURE_NO_DEPRECATE

#pragma once
#include <iostream>
#include<assert.h>
#include <cstring>
using namespace std;
namespace wxy
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		/*string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}*/

		//��������ȫȱʡ�ģ��ȿ��Դ��Σ��п��Բ�����
		string(const char* str="")//����Ҫ��""��ʾһ�����ַ�����������'\0'����char���ͣ�û�취����char*����
			:_size(strlen(str))//����const char* str�����nullptr��ʼ��������û�취strlen
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy_s(_str, _capacity+1,str);
		}

		//��������
		string(const string& s)
		{
			_str = new char[s._capacity + 5];
			strcpy_s(_str,s._size+1,s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		//��������
		~string()
		{
			delete[] _str;//c++�и��Ƽ�new��delete
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		const char* c_str()
		{
			return _str;
		}

		//����
		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);//���ԣ���ֹԽ��
			return _str[pos];//_str��new�����ģ������ڶ��ϣ�������������Ȼ���ڣ����������÷���
		}

		const char& operator[](size_t pos) const
		{
			//��������ǰ��const����ʾ����һ�������ã�Ҳ����ͨ��������������ص����ò��������޸��ַ����е��ַ�
			//eg��
			//const wxy::string s("hello");
			//char ch = s[0];       // ���Զ�ȡ
			//s[0] = 'H';           // ���������Ϊ���ص��� const char&�������޸��ַ�

			//�������ͺ��const����ʾ�����Ա����Ϊ������Ա����������������ڲ������޸���ĳ�Ա����������ζ�Ÿú������Ա�const�������
			//eg��
			//const wxy::string s("hello");
			//char ch = s[0];  // ���Ե��ã���Ϊ operator[] �� const ��Ա����




			assert(pos < _size);//���ԣ���ֹԽ��
			return _str[pos];//_str��new�����ģ������ڶ��ϣ�������������Ȼ���ڣ����������÷���
		}

		void reserve(size_t n)//��ǰ_capacity���ݵ�n���ռ�
		{
			if (n > _capacity)
			{
				char* tmp = new char[n];//���¿ռ�
				strcpy_s(tmp, _capacity+1,_str);//��������
				//strcpy_s��char *strDestination, size_t numberOfElements, const char *strSource��:
				//��һ��������Ŀ���ַ�����ָ��
				//�ڶ�����������Ҫ������Ԫ�ظ���
				//������������Դ�ַ�����ָ��
				delete[] _str;//�ͷžɿռ�
				_str = tmp;//ָ��ָ���¿ռ�

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			//����
			if (_size == _capacity-1|| _size == _capacity)
			{
				reserve(_capacity==0 ? 4 : 2 * _capacity);
			}

			_str[_size] = ch;//���ַ��Ž�ȥ
			_size++;
			_str[_size] = '\0';//��־�ַ�����β

		}

		void append(const char* str)
		{
			// ����Ҫ׷�ӵ��ַ�������
			size_t len = strlen(str);

			// ����Ƿ���Ҫ����
			if (_size + len > _capacity)
			{
				// ���ݵ��������������ַ����������ַ����ĳ���
				reserve(_size + len+1);//�������ݲ�����2*capacity����Ϊ�㲻֪���ӹ������ַ����ж೤��������Ⱥܳ����������ݾ�ʧЧ��
			}

			// �������ַ����������ַ���ĩβ
			// ע������� _capacity - _size + 1 ΪĿ�껺����ʣ��ռ�
			strcpy_s(_str + _size, len+1 , str);

			// ���� _size��ʹ�������׷�ӵ��ַ�������
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, char ch)//size_t>=0
		{
			assert(pos <= _size);//pos=_sizeʱ��β��
			//����
			if (_size == _capacity - 1 || _size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			int end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				end--;
				if (end == -1)//����������if������end=-1��pos=0�ȵ�ʱ��,-1�����0����Ϊ����������������Ͳ�ͬ���ᷢ����������������޷��������бȽ�
				{//����һ�ְ취������while����Ƚϵ�ʱ���һ��ǿת��ǿת������Int�Ƚ�
					break;
				}
			}

			_str[pos] = ch;
			_size++;

		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);//pos=_sizeʱ��β��
			int len=strlen(str);//��ȡҪ�����ַ����ĳ���
			if (_size+len>=_capacity)
			{
				reserve(_size + 2*len);//���ݵ�_size + len + 1
			}

			int end = _size;
			while (end >= (int)pos)//����λ�ú��ԭ�ַ������ֺ���len��
			{
				int posnew = end + len;
				_str[posnew] = _str[end];
				end--;
			}

			memcpy(_str + pos,str, len);//�¼����ַ����Ŀ�����ԭ�ַ���
			//memcpy ֻ�ᰴ��ָ�����ֽ������и��ƣ������Զ����� \0��
			//���������strcpy_s,���str����\0Ҳ���ƽ�ȥ���������ǵ��߼����

			//�����ַ�����С
			_size = _size + len;

		}

		void erase(size_t pos, size_t len = npos)//��posλ��ɾlen���ַ�
		{
			assert(pos < _size);//����ɾ��������Ҫ����\0����\0����Ҫ��ɾ��

			//���len����npos������ζ�Ŵ�posλ�ÿ�ʼ���ַ�����βȫ��ɾ��
			if (len == npos||len>= _size-pos)
			{
				_str[pos] = '\0';//����ɨ��str,ɨ��\0��Ĭ�Ͻ�����
				_size = pos;
			}
			else
			{
				strcpy_s(_str + pos, _size-pos-len+1, _str + pos + len);
				_size -= len;
			}
		}


		void resize(size_t n, char ch = '\0')//���»���С�������ԭ��С��ɾ����ԭ��������ַ�ch���
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n+1);//���n��capacityС��ɶҲ��������n��capacity���������
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}

		string& operator=(const string& s)
		{
			char* tmp = new char[s._capacity + 1];
			strcpy_s(tmp, s._size + 1, s._str);
			delete[] _str;//ɾs1ԭ�ȵĿռ�
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
		static const int npos;
	};

	const int string::npos = -1;//��̬��Ա���������������࣬����ÿ������

	void test1()
	{
		string s1("hello world");//����
		string s2;//������

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i]++ << " ";//s1[i]��д
		}

		
		cout << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";//s1[i]�ɶ�
		}

		cout << endl;
		//s1[100];//����Խ�磬����Ա���


		const string s3("xxx");
		for (size_t i = 0; i < s3.size(); i++)
		{
			cout << s3[i] << " ";//const����ֻ�ܵ���const��Ա����
			//const����ֻ�ɶ�������д
		}
	}

	void test2()
	{
		string s1("hello");
		string::iterator it = s1.begin();//������
		while (it != s1.end())
		{
			cout << *it << " ";//�ɶ�
			it++;
		}

		cout << endl;
		it = s1.begin();
		while (it != s1.end())
		{
			*it -= 1;//��д
			cout << *it << " ";//�ɶ�
			it++;
		}

		cout << endl;

		for (auto ch : s1)//��Χfor,����iterator begin()��iterator end()
		{
			cout << ch << " ";
		}

		cout << endl;

		const string s2("xxxx");
		for (auto ch : s2)//�����const_iterator begin() const��const_iterator end() const
		{
			cout << ch << " ";
		}

	}


	void test3()
	{
		string s1("hello world");
		s1.push_back('w');
		s1.push_back('x');
		s1.push_back('y');
		cout << s1.c_str() << endl;

		cout << "-----" << endl;

		s1.append("hhhh");
		cout << s1.c_str() << endl;
	}


	void test4()
	{
		string s1("hello");

		s1 += "world";
		cout << s1.c_str() << endl;

		s1 += 'w';
		cout << s1.c_str() << endl;

		s1 += "xy";
		cout << s1.c_str() << endl;

		s1 += "1234567890";
		cout << s1.c_str() << endl;
	}


	void test5()
	{
		string s1 = "abcdefg";
		s1.insert(3, 'x');//3���±����x
		cout << s1.c_str() << endl;//helxlo

		s1.insert(6, 'y');//β�壨pos==size�����
		cout << s1.c_str() << endl;//helxloy

		s1.insert(0, 'w');//ͷ��

		s1.insert(2, "wxy");
		cout << s1.c_str() << endl;
	}

	void test6()
	{
		string s1 = "hello world";
		s1.erase(2, 3);
		cout << s1.c_str() << endl;

		string s2 = "hello world";
		s2.erase(2);
		cout << s2.c_str() << endl;

		string s3 = "hello world";
		s3.erase(2, 30);
		cout << s3.c_str() << endl;
	}
	
	void test7()
	{
		string s1 = "hello world";
		s1.resize(3);
		cout << s1.c_str() << endl;//hel

		string s2 = "hello world";
		s2.resize(7,'x');//��ԭ����С����ɾ������ַ�ֻ����resize��ԭ���ַ�������ʹ��
		cout << s2.c_str() << endl;

		string s3 = "hello world";
		s3.resize(20, 'x');//��ԭ����С����ɾ������ַ�ֻ����resize��ԭ���ַ�������ʹ��
		cout << s3.c_str() << endl;
	}

	void test8()
	{
		string s1 = "hhhhwxy";
		string s2(s1);
		cout << s2.c_str() << endl;

		s1[2] = 'x';
		cout << s1.c_str() << endl;//�޸�s1����Ӱ��s2
		cout << s2.c_str() << endl;

		cout << "--------" << endl;
		string s3 = s1;
		cout << s3.c_str() << endl;
		
	}
}
