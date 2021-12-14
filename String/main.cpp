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

	String(size_t length = 80)
	{
		this->length = length;
		this->str = new char[length] {};
		cout << "DefautConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->length = strlen(str) + 1;
		this->str = new char[length] {};
		for (size_t i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
	}
	String (String& other)//---CopyConstructor
	{
		this->length = other.length;
		this-> str = new char [length] {};
		for (size_t i = 0; i < length; i++)
		{
			str[i] = other.str[i];
		}
	}



	//--------------Destructor-------------------
	~String()
	{
		delete[] this->str;
		//cout << "Destructor:\t\t" << this << endl;
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



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	String str;
	String str1 = "Hello";
	str1.print(); cout << endl;
	String str2 = "World123";
	
	String str3 = str2;

	str3.print();
	//cout << str3 << endl;




	return 0;
}