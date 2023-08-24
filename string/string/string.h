#pragma once
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
namespace CC
{
	class string
	{
	public:
		/*string()
			:_str(new char[1])
			, _size(0)
			, _capicity(0)
		{
			_str[0] = '\0';
		}
		string(const char* str)
			:_size(strlen(str))
		{
			_capicity = _size;
			_str = new char[_capicity + 1];
			strcpy(_str, str);
		}*/
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const iterator begin() const
		{
			return _str;
		}
		const iterator end() const
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capicity = _size == 0 ? 4 : _size;
			_str = new char[_capicity + 1];
			strcpy(_str, str);
		}
		//拷贝构造 string s2(s1)
		string(const string& s)
			:_size(s._size)
			,_capicity(s._capicity)
		{
			_str= new char[_capicity + 1];
			strcpy(_str, s._str);
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char* c_str() const
		{
			return _str;
		}
		size_t size() const
		{
			return _size;
		}
		size_t capicity() const
		{
			return _capicity;
		}
		//拷贝复制 运算符重载 s3 = s2
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capicity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				//_str = new char[s._capicity + 1];
				_str = tmp;
				_size = s._size;
				_capicity = s._capicity;
			}
			return *this;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}
		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}
		bool operator<(const string& s) const
		{
			return strcmp(_str, s._str) < 0;
		}
		bool operator!=(const string& s) const
		{
			return !(operator==(s));
		}
		bool operator>=(const string& s) const
		{
			return !(operator<(s));
		}
		bool operator<=(const string& s) const
		{
			return !(operator>(s));
		}
		void rsize(size_t n, char ch = '\0')
		{
			if (n <= _capicity)
			{
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
					_size++;
				}
				_str[_size] = '\0';
			}
			else
			{
				reserve(_capicity * 2);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
					_size++;
				}
				_str[_size] = '\0';
			}
		}
		void reserve(size_t  n)
		{
			//考虑缩容问题 不能缩容
			if (n > _capicity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capicity = n + 1;
			}
		}
		void push_back(char ch)
		{
			if (_size + 1 > _capicity)
			{
				reserve(_capicity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capicity)
			{
				reserve(_capicity + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void insert(size_t pos, const char ch)
		{
			assert(pos <= _size);
			if (_size + 1 > +_capicity)
			{
				reserve(_capicity * 2);
			}
			char* tmp = new char[_size - pos + 1];
			strcpy(tmp, _str + pos);
			strcpy(_str + pos + 1, tmp);
			_str[pos] = ch;
			_size++;
			//_str[_size] = '\0';
		}
		//void insert(size_t pos, const char* str)
		//{
		//	assert(pos <= _size);
		//	size_t len = strlen(str);
		//	if (_size + len > _capicity)
		//	{
		//		reserve(_capicity + len);
		//	}
		//	//hello world
		//	//helloxxxx_world\0
		//	//xxxx
		//	char* tmp = new char[_size - pos + 1];
		//	strcpy(tmp, _str + pos);//tmp="_world\0"
		//	size_t end = 0;
		//	while (end < len)
		//	{
		//		_str[pos + end] = str[end];
		//		end++;
		//	}
		//	strcpy(_str + pos + len, tmp);
		//	_size += len;
		//}
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capicity)
			{
				reserve(_capicity + len);
			}
			//hello world\0    
			//hello    _world\0
			//helloxxxx_world\0
			//xxxx
			size_t end = _size + len;
			while (end <= pos)
			{
				_str[end--] = _str[_size--];
			}
			char* tmp = new char[_size - pos];
			strcpy(tmp, _str + pos);
			strcpy(_str + pos, str);
			strcpy(_str + pos + len, tmp);
			_size += len;
		}
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos <= _size);
			assert(pos != npos);
			//hello world 
			if (pos + len >= _size || len == npos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size)
				{
					_str[pos] = _str[end];
					end++;
					pos++;
				}
				_size -= len;
			}
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capicity, s._capicity);
			std::swap(_size, s._size);
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		//析构
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capicity = 0;
		}
		friend istream& operator>>(istream& in, string& s);
		
	private:
		char* _str;//0 1 2 3 
		int _size;// 4 5 6 7 0 1 2 3
		int _capicity;//8 9 10 11 
		static size_t npos;
	};
	size_t string::npos = -1;
	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch = in.get();
		char buff[128];
		int i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			
			ch = in.get();
		}
		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
	    }
		return in;
	}
	void Print(const string& s)
	{
		
		for (size_t i = 0; i < s.size(); i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
		string::const_iterator cit = s.begin();
		while (cit != s.end())
		{
			cout << *cit << " ";
			cit++;
		}
		cout << endl;
		for (auto ch : s)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
	void test_string1()
	{
		string s1;
		string s2("hello world");
	}
	void test_string2()
	{
		string s1("hello world");
		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;
		}
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
		cout << s1.c_str() << endl;
		Print(s1);
	}
	void test_string3()
	{
		string s1("hello world");
		string s2(s1);
		//cout << s1.c_str() << endl;
		cout << s1.c_str() << endl;
		string s3;
		s3 = s2;
		cout << s3.c_str() << endl;
	}
	void test_string4()
	{
		string s1("hello world");
		
		string::iterator it = s1.begin();
		/*for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;*/
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
		Print(s1);
	}
	void test_string5()
	{
		string s1("hello world");
		string s2("hello world");
		string s3("xx");
		cout << (s1 == s2) << endl;//1
		cout << (s1 > s2) << endl;//0
		cout << (s1 < s3) << endl;//1
		cout << (s1 <= s3) << endl;//1
		cout << (s1 > s3) << endl;//0
		cout << (s1 >= s3) << endl;//0
	}
	void test_string6()
	{
		/*string s1("hello world");
		cout << s1.c_str() << endl;
		s1.push_back('x');
		s1.push_back('x');
		s1.push_back('x');
		s1.push_back('x');
		s1.push_back('x');
		cout << s1.c_str() << endl;*/
		/*string s1;
		cout << s1.c_str() << endl;
		s1.push_back('x');
		s1.push_back('x');
		s1.push_back('x');
		s1.push_back('x');
		s1.push_back('x');
		cout << s1.c_str() << endl;*/
	} 
	void test_string7()
	{
		//string s1("hello world");
		//s1.insert(5, 'x');
		//s1.insert(5, 'x');
		//s1.insert(5, 'x');
		//s1.insert(5, 'x');

		//cout << s1.c_str() << endl;
		//s1.insert(s1.size(), 'c');
		//s1.insert(0, 'x');
		//s1.insert(5, 'x');
		//s1.insert(s1.size(), 'c');
		//s1.insert(s1.size(), 'c');
		//s1.insert(s1.size(), 'c');
		//s1.insert(s1.size(), 'c');
		//s1.insert(s1.size(), 'c');
		//s1.insert(0, 'w');
		//s1.insert(0, 'w');
		//s1.insert(0, 'w');
		//s1.insert(0, 'w');
		//s1.insert(0, 'w');
		////s1.insert(5, 'c');
		//cout << s1.c_str() << endl;
		string s1("hello world");
		cout << s1.c_str() << endl;
		//s1.insert(5, "xxxx");
		//s1.insert(0, "cc");
		s1.erase(5);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		s1.erase(0);
		cout << s1.c_str() << endl;
	}
	void test_string8()
	{
		/*string s1("hello world");
		s1.insert(0, 'c');
		cout << s1.c_str() << endl;

		s1.insert(5, "yyy");
		cout << s1.c_str() << endl;

		s1.insert(0, "yyy");
		cout << s1.c_str() << endl;*/
		string s1("0123456789");
		cout << s1.c_str() << endl;

		s1.erase(4, 3);
		cout << s1.c_str() << endl;

		s1.erase(4, 30);
		cout << s1.c_str() << endl;

		s1.erase(2);
		cout << s1.c_str() << endl;

		/*cout << s1.size() << endl;
		cout << s1.c_str() << endl;
		s1.erase(5,3);
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;*/
	}
	void test_string9()
	{
		string s1("hello world");
		string s2("world hello");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		s1.swap(s2);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}
	void test_string10()
	{
		string s1("hello world");
		s1 += ' ';
		s1 += "ccccc";
		cout << s1 << endl;

		//std::string s2;
		//std::operator>>(cin, s2);
		////cin >> s2;
		//std::cout << s2 << std::endl;
		string s2;
		operator>>(cin, s2);
		//cin >> s2;
		cout << s2 << endl;
	}
}