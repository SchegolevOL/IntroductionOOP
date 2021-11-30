#include <iostream>
#include<Windows.h>
#include<math.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;



class Fraction
{
	int numerator;
	int denomenator;
	int integer;

public:
	//			Metods
	//----------get--------------чтение
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const

	{
		return numerator;
	}
	int get_denomenator()const
	{
		return denomenator;
	}
	//-----------set--------------запись
	void set_integer(int x)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denomenator(int denomenator)
	{
		if (denomenator==0) denomenator = 1;
		this->denomenator = denomenator;
	}
	//				Constructors:
	Fraction(int integer, int numerator, int denomenator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denomenator = denomenator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denomenator = 1;
		cout << "DefautConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denomenator = 1;
		cout << "1agrConstructor:\t" << this << endl;
	}
	Fraction( int numerator, int denomenator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denomenator(denomenator);
		cout << "2agrsConstructor:\t" << this << endl;
	}
	


	//				Destructor
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}


	//				Methods:
	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denomenator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	void to_impropert()//Перевод дроби в неправельную дробь
	{
		numerator += integer * denomenator;
		integer = 0;
	}
	void to_proper()//Перевод дроби в правельную дробь
	{
		integer += numerator / denomenator;
		numerator %= denomenator;
	}
	void reduce()
	{
		int nod = 1;
		for (size_t i = numerator; i > 0; i--)
		{
			if (numerator%i==0 && denomenator%i==0)
			{
				nod = i;
				break;
			}
		}
		numerator /= nod;
		denomenator /= nod;
	}
};

Fraction operator *(Fraction left, Fraction right)
{
	
	left.to_impropert();
	right.to_impropert();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denomenator(left.get_denomenator() * right.get_denomenator());
	result.to_proper();
	result.reduce();
	return result;
}

//#define CONSRUCTOR_CHECK

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#ifdef CONSRUCTOR_CHECK
	Fraction A;
	A.print();
	Fraction B = 5;
	B.print();
	Fraction D(1, 2, 3);
	D.print();
	Fraction C(3, 2);
	C.print();
#endif // CONSRUCTOR_CHECK
	Fraction A(2, 1, 2);
	Fraction B(3, 2, 5);
	Fraction C = A * B;
	C.print();
	C.reduce();
	C.print();

	return 0;
}