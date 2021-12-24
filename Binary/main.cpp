#include<iostream>
#include<Windows.h>

using namespace std;
class Binary;


class Binary
{
	size_t size;
	char* bin;
	


public:
	//-----geter------------------------
	const size_t get_size()const
	{
		return size;
	}

	//------Constructors-----------------

	Binary(size_t size) : size(size), bin(new char[size] {})
	{
		cout << "SizeConstructor: " << this << endl;
	}
	Binary(char*bin):Binary(strlen(bin)+1)
	{
		for (size_t i = 0; i < size; i++)
		{
			this->bin[i] = bin[i];
		}
		cout << "Constructor: " << this << endl;
	}
	



};




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a = 0b1010100;
	cout << a;




	return 0;
}