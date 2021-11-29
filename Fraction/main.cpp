#include <iostream>
#include<Windows.h>
#include<math.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;





class Fraction
{
	int x;// числитель
	int y;// знаменатель
	int z;// целое
public:
	int get_x()const
	{
		return x;
	}
	int get_y()const
	{
		return y;
	}
	int get_z()const
	{
		return z;
	}

	void set_x(int x)
	{
		this->x = x;
	}
	void set_y(int y)
	{
		this->y = y;
	}
	void set_z(int z)
	{
		this->z = z;
	}

	//				Constructors
	
	Fraction(int z = 0, int x = 0, int y = 1)
	{
		this->z = z;
		this->x = x;
		this->y = y;
		
	}
	
	Fraction(const Fraction& other)// конструктор копирования
	{
		
		this->z = other.z;
		this->x = other.x;
		this->y = other.y;
		
	}

	/*Fraction(int z, int x, int y)
	{	
		this->z = z;
		this->x = x;
		this->y = y;
	}*/


	~Fraction()
	{
		
	}


	//				Operators


	Fraction& operator=(const Fraction& other)
	{
		this->z = other.z;
		this->x = other.x;
		this->y = other.y;
		
		return *this;
	}



	Fraction& operator++()//Prefix increment
	{
		this->z++;
		

		return *this;
	}
	Fraction operator++(int)//Posfix increment
	{
		Fraction old = *this;
		this->z++;
		return old;
	}

	//				Methods:
	void print()const
	{
		cout << z << "  " << x << "/" << y << endl;
	}

	
};


Fraction operator +(const Fraction& left, const Fraction& right);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction A(1, 1, 2);
	A.print();
	A++;
	Fraction B(1, 0, 1);
	B.print();
	Fraction C = A + B;
	C.print();
	return 0;
}


Fraction operator +(const Fraction& left, const Fraction& right)
{
	Fraction result;
	int _x;
	int _y;
	int _z;
	_x = left.get_x() * right.get_y() + right.get_x() * left.get_y();
	_y = left.get_y() * right.get_y();
	_z = left.get_z() + right.get_z();

	result.set_x(_x);
	result.set_y(_y);
	result.set_z(_z);
	return result;
}