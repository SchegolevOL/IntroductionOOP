#include <iostream>
#include<Windows.h>
#include<math.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Fraction;//обявление класса

Fraction& operator *(Fraction left, Fraction right);
Fraction& operator /(Fraction left, Fraction right);
Fraction& operator +(Fraction left, Fraction right);
Fraction& operator -(Fraction left, Fraction right);

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
		if (denomenator == 0) denomenator = 1;
		this->denomenator = denomenator;
	}
	//------------Constructors:--------------------
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
	Fraction(int numerator, int denomenator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denomenator(denomenator);
		cout << "2agrsConstructor:\t" << this << endl;
	}



	//--------------Destructor-------------------
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}


	//----------------Methods:--------------------
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
	Fraction& to_impropert()//Перевод дроби в неправельную дробь
	{
		numerator += integer * denomenator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()//Перевод дроби в правельную дробь
	{
		integer += numerator / denomenator;
		numerator %= denomenator;
		return *this;
	}
	Fraction& reduce()// 
	{
		int nod = 1;
		for (size_t i = numerator; i > 0; i--)
		{
			if (numerator % i == 0 && denomenator % i == 0)
			{
				nod = i;
				break;
			}
		}
		numerator /= nod;
		denomenator /= nod;
		return *this;
	}
	Fraction& _reduce()// алгоритм Эвклида
	{
		if (numerator == 0)return *this;
		int more, less;
		int rest;
		if (numerator > denomenator)
		{
			more = numerator;
			less = denomenator;
		}
		else
		{
			less = numerator;
			more = denomenator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;

		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denomenator /= GCD;
		return *this;
	}

	Fraction inverted()// обращенная дробь
	{
		to_impropert();
		return Fraction(this->denomenator, this->numerator);
	}
	Fraction& multiple(Fraction other)
	{
		int nod = 1;
		
		for (size_t i = this->denomenator; i > 0; i--)
		{
			if (this->denomenator % i == 0 && other.denomenator % i == 0)
			{
				nod = i;
				break;
			}
		}
		int nok = denomenator * other.denomenator / nod;
		
		this->numerator *= nok / this->denomenator;
		this->denomenator = nok;
		return *this;
	}

	//----------------Operators---------------------
	Fraction operator *=(const Fraction other)
	{
		return *this = *this * other;
	}
	Fraction operator /=(const Fraction other)
	{
		return *this = *this / other;
	}

};






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

	Fraction A(5, 1, 5);
	Fraction B(3, 2, 5);
	/*Fraction C = A * B;

	C.print();

	C.print();
	Fraction F;


	F = A / B;
	F.print();*/

	A *= B;
	A.print();
	A /= B;
	A.print();
	Fraction D;
	/*D = A + B;
	D.print();*/
	D = A - B;
	D.print();

	return 0;
}

Fraction& operator *(Fraction left, Fraction right)
{
	left.to_impropert();
	right.to_impropert();

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denomenator() * right.get_denomenator()
	).to_proper().reduce();
}

Fraction& operator /(Fraction left, Fraction right)
{
	return left * right.inverted();
}

Fraction& operator+(Fraction left, Fraction right)
{
	
	return Fraction
	(
		left.multiple(right).get_numerator() + right.multiple(left).get_numerator(), 
		left.multiple(right).get_denomenator()
	).reduce();
}

Fraction& operator-(Fraction left, Fraction right)
{
	left.to_impropert();
	right.to_impropert();
	return Fraction
	(
		left.multiple(right).get_numerator() - right.multiple(left).get_numerator(),
		left.multiple(right).get_denomenator()
	).to_proper().reduce();
}
