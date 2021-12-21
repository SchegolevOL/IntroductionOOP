#pragma once
#include<iostream>
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
