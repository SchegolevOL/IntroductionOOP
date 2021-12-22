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
std::istream& getline(std::istream& is, String& obj);

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
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		/*this->size = size;
		this->str = new char[size] {};*/ //Память обезательно нужно занулить
		cout << "SizeConstructor: " << this << endl;
	}
	String(const char str[]):
		size(strlen(str) + 1),
		str(new char[size]{})
	{
		/*this->size = strlen(str) + 1;
		this->str = new char[size] {};*/
		for (size_t i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor: " << this << endl;
	}
	String(const String& other): size(other.size), str(new char[size] {})
	{
		/*this->size = other.size;
		this->str = new char[size];*/
		for (size_t i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor: " << this << endl;
	}
	//------------MoveConstructor--------------

	String(String&& other)noexcept//никогда не бросает исключения
	{
		this->size = other.size;
		this->str = other.str;//копируем адресс памяти пренадлежащей другому обекту
		//Зануляем другой объект
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor" << this << endl;
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
	String& operator = (String&& other)noexcept
	{
		if (this == &other)
		{
			return *this;
		}
		delete this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		/*this->str = nullptr;
		*this = std::move(other);
		cout << "MoveAssigment:\t\t" << this << endl;*/
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
#define OPERATORS_CHEK
//#define INPUT_CHEK
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
	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;
	/*cin >> str1;
	cout << str1 << endl;
	str2 += str1;;
	cout << str2 << endl;*/
#endif // OPERATORS_CHEK
#ifdef INPUT_CHEK
	String str;
	cout << "Введите строку : ";
	//cin >> str;
	str.print();
	getline(cin, str);
	cout << str << endl;
#endif // INPUT_CHEK
	//String str1;//конструктор по умолчанию
	//str1.print();
	//String str4(); /*невызывается ни какой конструктор поскольку не создается 
	//				обект, ф объявляется фукция которая ничего не принимает, 
	//				а возвращает значение типа String*/
	//String str5{};//конструктор по умолчанию
	//str5.print();
	//String str6("World");//конструктор с одним параметром
	//String str7{ "Planet" };//конструктор с одним параметром
	







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
