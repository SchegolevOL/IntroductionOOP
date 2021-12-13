

//#pragma warning (diseble:4326) // отключаем предупреждение по коду

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

bool operator==(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator!=(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);
int digit_number_part(double value);
int fractional_part(double value);


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
	void set_integer(int integer)
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
	explicit Fraction(int integer)
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

	Fraction(double value)
	{	
		/*this->integer = int(value);
		value = (value - int(value)) * 100000000;
		int i = 9;
		while (int(value) % 10 == 0)
		{
			value /= 10;
			i--;
		}		
		this->numerator = int(value);
		this->denomenator = pow(10, i);
		os << "1agrConstructor:\t" << this << endl;*/
		
		/*this->integer = int(value);
		this->numerator = fabs(fractional_part(value));
		this->denomenator = pow(10, digit_number_part(value));*/
		value += 1e-11;
		integer = value;
		denomenator = 1e+9;
		numerator = ((value)-integer) * denomenator;
		reduce();
	}


	//--------------Destructor-------------------
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//---------------Type-cast operators:---------

	explicit operator int()const
	{
		return integer;
	}

	explicit operator double()const
	{
		return integer < 0 ? integer - double(numerator) / denomenator : fabs(integer) + double(numerator) / denomenator;
	}

	//----------------Methods:--------------------
	std::ostream& print(std::ostream& os = cout)const
	{
		if (integer) os << integer;
		if (numerator)
		{
			if (integer)os << "(";
			os << numerator << "/" << denomenator;
			if (integer)os << ")";
		}
		else if (integer == 0)os << 0;
		return os;
	}
	Fraction& to_impropert()//Перевод дроби в неправельную дробь
	{
		int minus = 0;
		if (integer < 0)
		{
			minus = 1;
			integer *= -1;
		}
		numerator += integer * denomenator;
		integer = 0;
		if (minus == 1)numerator *= -1;
		return *this;
	}
	Fraction& to_proper()//Перевод дроби в правельную дробь
	{
		int minus = 0;
		if (numerator < 0)
		{
			minus = 1;
			numerator *= -1;
		}
		integer += numerator / denomenator;
		numerator %= denomenator;
		if (minus == 1)integer *= -1;
		return *this;
	}
	
	Fraction& reduce()// алгоритм Эвклида
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
		int minus = 0;
		to_impropert();
		if (numerator < 0)
		{
			minus = 1;
			numerator *= -1;
			denomenator *= -1;
		}
		return Fraction(this->denomenator, this->numerator);
	}
	Fraction& multiple(Fraction other)
	{

		if (denomenator == 0)return *this;
		int more, less;
		int rest;
		if (denomenator > other.get_denomenator())
		{
			more = denomenator;
			less = other.get_denomenator();
		}
		else
		{
			less = other.get_denomenator();
			more = denomenator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;

		} while (rest);
		int GCD = more;
		int nok = denomenator * other.denomenator / GCD;

		this->numerator = this->numerator * nok / this->denomenator;
		this->denomenator = nok;
		return *this;
	}

	//----------------Operators---------------------

	Fraction& operator = (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denomenator = other.denomenator;
		cout << "CopyAssignment : " << this << endl;
		return *this;
	}
	Fraction operator *=(const Fraction other)
	{
		return *this = *this * other;
	}
	Fraction operator /=(const Fraction other)
	{
		return *this = *this / other;
	}
	Fraction operator +=(const Fraction other)
	{
		return *this = *this + other;
	}
	Fraction operator -=(const Fraction other)
	{
		return *this = *this - other;
	}
	/*friend bool operator==(Fraction left, Fraction right);
	friend bool operator<(Fraction left, Fraction right);
	friend bool operator>( Fraction left,  Fraction right);
	friend bool operator!=(Fraction left, Fraction right);
	friend bool operator>=(Fraction left, Fraction right);
	friend bool operator<=(Fraction left, Fraction right);*/

};

//#define CONSRUCTOR_CHECK
//#define OERATORS_CHECK
//#define TYPE_CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_CLASS_TO_OTHER
//#define HOME_WORK

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& in, Fraction& obj);
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
#ifdef OPERATORS_CHECK



	Fraction A(-5, 1, 100);
	Fraction B(-3, 2, 10);
	Fraction C = A * B;
	os << "\t\t\t\t\t\t\tПроверка оператора * : "; A.print(); os << " * "; B.print(); os << " = "; C.print(); os << endl;
	A=Fraction( 5, 1, 100);
	B=Fraction(3, 2, 10);
	C = A * B;
	os << "\t\t\t\t\t\t\tПроверка оператора * : "; A.print(); os << " * "; B.print(); os << " = "; C.print(); os << endl;
	A = Fraction(-5, 9, 100);
	B = Fraction(3, 2, 10);
	C = A * B;
	os << "\t\t\t\t\t\t\tПроверка оператора * : "; A.print(); os << " * "; B.print(); os << " = "; C.print(); os << endl;

	A = Fraction(-5, 9, 100);
	B = Fraction(3, 2, 10);
	C = A + B;
	os << "\t\t\t\t\t\t\tПроверка оператора + : "; A.print(); os << " + "; B.print(); os << " = "; C.print(); os << endl;
	A = Fraction(5, 1, 100);
	B = Fraction(3, 2, 10);
	C = A + B;
	os << "\t\t\t\t\t\t\tПроверка оператора + : "; A.print(); os << " + "; B.print(); os << " = "; C.print(); os << endl;
	A = Fraction(-5, 1, 100);
	B = Fraction(-3, 2, 10);
	C = A + B;
	os << "\t\t\t\t\t\t\tПроверка оператора + : "; A.print(); os << " + "; B.print(); os << " = "; C.print(); os << endl;

	A = Fraction(-5, 9, 100);
	B = Fraction(3, 2, 10);
	C = A / B;
	os << "\t\t\t\t\t\t\tПроверка оператора / : "; A.print(); os << " / "; B.print(); os << " = "; C.print(); os << endl;
	A = Fraction(5, 1, 100);
	B = Fraction(3, 2, 10);
	C = A / B;
	os << "\t\t\t\t\t\t\tПроверка оператора / : "; A.print(); os << " / "; B.print(); os << " = "; C.print(); os << endl;
	A = Fraction(-5, 1, 100);
	B = Fraction(-3, 2, 10);
	C = A / B;
	os << "\t\t\t\t\t\t\tПроверка оператора / : "; A.print(); os << " / "; B.print(); os << " = "; C.print(); os << endl;

	A = Fraction(-5, 9, 100);
	B = Fraction(3, 2, 10);
	C = A - B;
	os << "\t\t\t\t\t\t\tПроверка оператора - : "; A.print(); os << " - "; B.print(); os << " = "; C.print(); os << endl;
	A = Fraction(5, 1, 100);
	B = Fraction(3, 2, 10);
	C = A - B;
	os << "\t\t\t\t\t\t\tПроверка оператора - : "; A.print(); os << " - "; B.print(); os << " = "; C.print(); os << endl;
	A = Fraction(-5, 1, 100);
	B = Fraction(-3, 2, 10);
	C = A - B;
	os << "\t\t\t\t\t\t\tПроверка оператора - : "; A.print(); os << " - "; B.print(); os << " = "; C.print(); os << endl;

	A = Fraction(-5, 9, 100);
	B = Fraction(3, 2, 10);	
	os << "\t\t\t\t\t\t\tПроверка оператора *= : "; A.print(); os << " *= "; B.print(); os << " = " << endl;
	A *= B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;
	A = Fraction(5, 1, 100);
	B = Fraction(3, 2, 10);	
	os << "\t\t\t\t\t\t\tПроверка оператора *= : "; A.print(); os << " *= "; B.print(); os << " = "<<endl; 
	A *= B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;
	A = Fraction(-5, 1, 100);
	B = Fraction(-3, 2, 10);	
	os << "\t\t\t\t\t\t\tПроверка оператора *= : "; A.print(); os << " *= "; B.print(); os << " = " << endl;
	A*= B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;

	A = Fraction(-5, 9, 100);
	B = Fraction(3, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора /= : "; A.print(); os << " /= "; B.print(); os << " = " << endl;
	A /= B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;
	A = Fraction(5, 1, 100);
	B = Fraction(3, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора /= : "; A.print(); os << " /= "; B.print(); os << " = " << endl;
	A /= B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;
	A = Fraction(-5, 1, 100);
	B = Fraction(-3, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора /= : "; A.print(); os << " /= "; B.print(); os << " = " << endl;
	A /= B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;

	A = Fraction(-5, 9, 100);
	B = Fraction(3, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора += : "; A.print(); os << " += "; B.print(); os << " = " << endl;
	A += B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;
	A = Fraction(5, 1, 100);
	B = Fraction(3, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора += : "; A.print(); os << " += "; B.print(); os << " = " << endl;
	A += B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;
	A = Fraction(-5, 1, 100);
	B = Fraction(-3, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора += : "; A.print(); os << " += "; B.print(); os << " = " << endl;
	A += B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;

	A = Fraction(-5, 9, 100);
	B = Fraction(3, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора -= : "; A.print(); os << " -= "; B.print(); os << " = " << endl;
	A -= B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;
	A = Fraction(5, 1, 100);
	B = Fraction(3, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора -= : "; A.print(); os << " -= "; B.print(); os << " = " << endl;
	A -= B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;
	A = Fraction(-5, 1, 100);
	B = Fraction(-3, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора -= : "; A.print(); os << " -= "; B.print(); os << " = " << endl;
	A -= B;
	os << "\t\t\t\t\t\t\t\t\t"; A.print(); os << endl;

	A = Fraction(-5, 2, 10);
	B = Fraction(5, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора == : "; A.print(); os << " == "; B.print(); os << endl;
	if (A==B) os << "\t\t\t\t\t\t\t\t\t\t\tyes" << endl;
	else os << "\t\t\t\t\t\t\t\t\t no" << endl;

	A = Fraction(-5, 2, 10);
	B = Fraction(5, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора != : "; A.print(); os << " != "; B.print(); os << endl;
	if (A != B) os << "\t\t\t\t\t\t\t\t\t\t\tyes" << endl;
	else os << "\t\t\t\t\t\t\t\t\t no" << endl;

	A = Fraction(5, 2, 10);
	B = Fraction(-6, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора < : "; A.print(); os << " < "; B.print(); os << endl;
	if (A < B) os << "\t\t\t\t\t\t\t\t\t\t\tyes" << endl;
	else os << "\t\t\t\t\t\t\t\t\tno" << endl;

	A = Fraction(-6, 2, 10);
	B = Fraction(5, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора > : "; A.print(); os << " > "; B.print(); os << endl;
	if (A > B) os << "\t\t\t\t\t\t\t\t\t\t\tyes" << endl;
	else os << "\t\t\t\t\t\t\t\t\t no" << endl;

	A = Fraction(-5, 2, 10);
	B = Fraction(5, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора <= : "; A.print(); os << " <= "; B.print(); os << endl;
	if (A <= B) os << "\t\t\t\t\t\t\t\t\t\t\tyes" << endl;
	else os << "\t\t\t\t\t\t\t\t\t no" << endl;

	A = Fraction(-6, 2, 10);
	B = Fraction(5, 2, 10);
	os << "\t\t\t\t\t\t\tПроверка оператора >= : "; A.print(); os << " >= "; B.print(); os << endl;
	if (A >= B) os << "\t\t\t\t\t\t\t\t\t\t\tyes" << endl;
	else os << "\t\t\t\t\t\t\t\t\t no" << endl;
#endif // OPERATORS_CHECK	
#ifdef TYPE_CONVERSION_BASICS
	int a = 2;		//no converion (нет приобразования)
	double b = 3;	//from less to more (от меньшего к большему)
	int c = b;		//from more to less without data loss(от большего к меньшему без потери данных)
	int d = 4.5;	//from more to less with data loss(от большего к меньшему с потери данных)

#endif // TYPE_CONVERSION_BASICS
#ifdef CONVERSION_FROM_OTHER_TO_CLASS



	double a = 2;	//from 'int' to 'double'
	Fraction A = (Fraction)5;	//from 'int' to 'Fraction'
								//1agrConstructor
	A.print();
	Fraction B;
	B = Fraction(8);			//CopyAssignment
	//Fraction C = 12;
	Fraction C(12);
	Fraction D{ 12 };
#endif // CONVERSION_FROM_OTHER_TO_CLASS
#ifdef CONVERSION_CLASS_TO_OTHER
	Fraction A(2);
	int a = int(A);
	int b(A);
	int c = (int)A;
	os << a << endl;
#endif // CONVERSION_CLASS_TO_OTHER
#ifdef HOME_WORK
	Fraction A(2, 3, 4);
	double a = A;
	os << a << endl;
	double b = 2.00003;
	Fraction B = b;
	B.print();

#endif // HOME_WORK
	
	Fraction A(2,3,4);
	cout << A << endl;
	A.print();	
	cin >> A;
	cout << A << endl;
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
	left.to_impropert();
	right.to_impropert();
	return Fraction
	(
		left.multiple(right).get_numerator() + right.multiple(left).get_numerator(),
		left.multiple(right).get_denomenator()
	).to_proper().reduce();
}

Fraction& operator-(Fraction left, Fraction right)
{
	left.to_impropert();
	right.to_impropert();
	return Fraction
	(
		left.to_impropert().multiple(right).get_numerator() - right.to_impropert().multiple(left).get_numerator(),
		left.multiple(right).get_denomenator()
	).to_proper().reduce();
}

bool operator==(Fraction left, Fraction right)
{	
	left.to_impropert().multiple(right);
	right.to_impropert().multiple(left);
	return (left.get_numerator()== right.get_numerator()&&
		 left.get_denomenator() == right.get_denomenator()
		 );
}

bool operator<(Fraction left, Fraction right)
{
	left.to_impropert().multiple(right);
	right.to_impropert().multiple(left);
	return (left.get_numerator() < right.get_numerator());
}

bool operator>(Fraction left, Fraction right)
{
	left.to_impropert().multiple(right);
	right.to_impropert().multiple(left);
	return (left.get_numerator() > right.get_numerator());
}

bool operator!=(Fraction left, Fraction right)
{
	return !(left == right);
}

bool operator>=(Fraction left, Fraction right)
{
	left.to_impropert().multiple(right);
	right.to_impropert().multiple(left);
	return (left.get_numerator() >= right.get_numerator());
}

bool operator<=(Fraction left, Fraction right)
{
	left.to_impropert().multiple(right);
	right.to_impropert().multiple(left);
	return (left.get_numerator() <= right.get_numerator());
}

int digit_number_part(double value)//функция подсчета разрядов
{
	int diget = 0;//колличество разрядов знаменателя
	int part = (int)value;
	value = value - part;
	if (value == 0) return 0;	
	while (diget < 9)
	{
		value *= 10;
		part = int(value);
		diget++;//подсчет разрядов
		if (part % 10 != 0)part += 1;//устронение погрешности double
	}
	while (part % 10 == 0)
	{
		part /= 10;//убираем 0 с права числа
		diget--;//уменьшаем разрядность числа 
	}
	return diget;
}

int fractional_part(double value)//функция перевода дробной части double в int-овое значение 2,36->36
{
	int part=0;
	value = value - (int)value;
	if (value==0) return 0;
	int i = 0;//колличество разрядов знаменателя
	while (i < 9)
	{
		value *= 10;
		part = int(value);
		i++;
		if (part % 10 != 0)part += 1;//устронение погрешности double
		
	}
	while (part % 10 == 0)//убираем 0 с права числа
	{
		part /= 10;
	}
	return part;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	/*if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denomenator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;*/

	return obj.print(os);
}

std::istream& operator>>(std::istream& in, Fraction& obj)
{
	/*int a, b, c;
	in >> a >> b >> c;
	obj.set_integer(a);
	obj.set_numerator(b);
	obj.set_denomenator(c);*/

	int integer=0, numerator=0, denomenator=0;
	int z = 1;
	int f=0;
	char ch[30];
	in >> ch;
	for (size_t i = 0; i < 30 || ch[i]==')'; i++)
	{
		if (ch[0] == '-')z = -1;
		if (ch[i] == '(')f = 1;
		if (ch[i] == '/')f = 2;
		if (ch[i] >= '0' && ch[i] <= '9' && f == 0)integer = (integer * 10 + (ch[i] - '0')); 
		if (ch[i] >= '0' && ch[i] <= '9' && f == 1)numerator = (numerator * 10 + (ch[i] - '0'));
		if (ch[i] >= '0' && ch[i] <= '9' && f == 2)denomenator = (denomenator*10 + (ch[i] - '0'));
	}
	if (z == -1)integer = integer* (-1);
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denomenator(denomenator);

	return in;
}
