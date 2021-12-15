#include <iostream>
#include<Windows.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;

class String
{
	//------------Parameters----------------------

	size_t length;
	char* str;

public:
	//-----------Metods---------------------------
	//--Geter-------------------------------------

	int get_length()const
	{
		return length;
	}

	char* get_str()const
	{
		return str;
	}

	//--Setor-------------------------------------

	int set_length(int length)
	{
		this->length = length;
	}
	char set_str(char* str)
	{
		this->str = str;
	}

	//-----------Constructors---------------------

	String(size_t length = 80)//---DefautConstructor
	{
		this->length = length;
		this->str = new char[length] {};
		cout << "DefautConstructor: " << this << endl;
	}
	String(const char* str)
	{
		this->length = strlen(str) + 1;
		this->str = new char[length] {};
		for (size_t i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor: " << this << endl;
	}
	String (String& other)//---CopyConstructor
	{
		this->length = other.length;
		this-> str = new char [length] {};
		for (size_t i = 0; i < length; i++)
		{
			str[i] = other.str[i];
		}
		cout << "CopyConstructor: " << this << endl;
	}



	//--------------Destructor-------------------
	~String()
	{
		delete[] this->str;
		cout << "Destructor:" << this << endl;
	}
	//----------------Methods:--------------------
	void print()const
	{
		for (size_t i = 0; i < length; i++)
		{
			cout<<str[i];
		}
	}

	//---------------Operators--------------------
	String& operator = (String& other)
	{
		this->length = other.length;
		this->str = other.str;
		return *this;
	}
	




};
String& operator+(const String left, const String right);
ostream& operator<<(ostream& os, const String& obj);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	String str;
	String str1 = "Hello";
	str1.print(); cout << endl;
	String str2 = "World";
	str2.print(); cout << endl;
	String str3 = str2 + str1;
	str3.print(); cout << endl;
	cout << str3 << endl;




	return 0;
}
ostream& operator<<(ostream& os, const String& obj)
{
	for (size_t i = 0; i < obj.get_length(); i++)
	{
		os << obj.get_str()[i];
	}
	return os;
}


String& operator+(const String left, const String right)
{
	
	char* arr = new char[left.get_length() + right.get_length() - 1];
	
	for (size_t i = 0; i < left.get_length(); i++)
	{
		arr[i] = left.get_str()[i];
	}
	for (size_t i = 0; i < right.get_length(); i++)
	{
		arr[i+ left.get_length()-1] = right.get_str()[i];
	}

	String tmp(arr);
	delete[]arr;
	return tmp;
} 