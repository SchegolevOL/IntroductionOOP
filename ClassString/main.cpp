﻿#include <iostream>
#include<Windows.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator +(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& in, String& obj);
std::istream& getline(std::istream& is, String& obj);

class String
{

	int size;
	char* str;
public:

	//--Geter-------------------------------------

	const int get_size()const;	
	const char* get_str()const;	
	char* get_str();
	

	//-----------Constructors---------------------
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	//-----------Destructor---------------------
	~String();
	//-------------Operators---------------------
	String& operator = (const String& other);
	char& operator[](int i);
	const char& operator[](int i)const;
	String& operator+=(const String& other);
	//----------------Methods:--------------------
	void print()const;
};




//#define CONSTRACTOR_CHEK
#define OPERATORS_CHEK
//#define INPUT_CHECK
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
#ifdef OPERATORS_CHEK
	String str1 = "Heloo";
	String str2 = "World";

	String str3 = str1 + str2;
	cout << str3 << endl;
	cin >> str1;
	cout << str1 << endl;
	str2 += str1;
	cout << str2 << endl;
#endif // OPERATORS_CHEK
#ifdef INPUT_CHECK
	String str;
	cout << "Введите строку : ";
	//cin >> str;
	str.print();
	getline(cin, str);
	cout << str << endl;
#endif // INPUT_CHECK



	return 0;
}


std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	const int SIZE = 1024;
	char buffer[SIZE] = {};
	is >> buffer;
	obj = buffer;
	return is;
}
std::istream& getline(std::istream& is, String& obj)
{
	const int SIZE = 1024;
	char buffer[SIZE] = {};
	is.getline(buffer,SIZE);
	obj = buffer;
	return is;
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
const int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//-----------Constructors---------------------
String::String(int size) :
	size(size),
	str(new char[size] {})
{
	/*this->size = size;
	this->str = new char[size] {};*///Память обезательно нужно занулить
	cout << "SizeConstructor: " << this << endl;
}
String::String(const char str[]) :
	String(strlen(str) + 1)
{
	/*this->size = strlen(str) + 1;
	this->str = new char[size] {};*/
	for (size_t i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor: " << this << endl;
}
String::String(const String& other) :
	String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}*/
	cout << "CopyConstructor: " << this << endl;
}
//-----------Destructor---------------------
String::~String()
{
	delete[]str;
	cout << "Destructor: " << this << endl;
}
//-------------Operators---------------------
String& String::operator = (const String& other)
{
	if (this == &other)
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
char& String::operator[](int i)
{
	return str[i];
}
const char& String::operator[](int i)const
{
	return str[i];
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
//----------------Methods:--------------------
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}