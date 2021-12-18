#include <iostream>
#include<Windows.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator +(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& in, String& obj);

class String
{
	int size;
	char* str;
public:

	//--Geter-------------------------------------

	const int get_size()const
	{
		return size;
	}

	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//-----------Constructors---------------------
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};//Память обезательно нужно занулить
		cout << "SizeConstructor: " << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (size_t i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor: " << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size];
		for (size_t i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor: " << this << endl;
	}

	//-----------Destructor---------------------
	~String()
	{
		delete[]str;
		cout << "Destructor: " << this << endl;
	}

	//-------------Operators---------------------
	String& operator = (const String& other)
	{
		if (this==&other)
		{
			return *this;
		}
		delete[]this->str;
		this->size = other.size;
		this->str = new char[size];
		for (size_t i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}

		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	char& operator[](int i)
	{
		return str[i];
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	//----------------Methods:--------------------

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};




//#define CONSTRACTOR_CHEK
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#ifdef CONSTRACTOR_CHEK
	String str;//Default constructor
	cout << str << endl;
	String str2(25);//Single-argument constructor
	String str3 = "Heloo";
	str3 = str3;
	cout << str3 << endl;
	String str4 = str3;
	cout << str4 << endl;//Copy constructor
	String str5;
	str5 = str4;//CopyAssigment
	cout << str5 << endl;
#endif // CONSTRACTOR_CHEK

	String str1 = "Heloo";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
	cin >> str1;
	cout << str1 << endl;
	str2 += str1;;
	cout << str2 << endl;
	return 0;
}


std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& in, String& obj)
{
	char tmp[256] = {};
	in >> tmp;
	int size = strlen(tmp) + 1;
	String Tmp(size);
	for (size_t i = 0; i < size; i++)Tmp[i] = tmp[i];
	obj = Tmp;


	return in;
}

String operator +(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (size_t i = 0; i < left.get_size(); i++)
	{
		result[i] = left[i];
	}
	for (size_t i = 0; i < right.get_size(); i++)
	{
		result[i + left.get_size() - 1] = right[i];
	}
	return result;
}
