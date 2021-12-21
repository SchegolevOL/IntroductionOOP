#include<iostream>
#include"String.h"

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
	is.getline(buffer, SIZE);
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