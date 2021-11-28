#include <iostream>
#include<Windows.h>
//#include<math.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;


#define tab "\t"
//#define STRUCT_POINT
//#define CONSRTUCTOR CHECK
//#define DISTANCE
//#define ASSIGNMENT_CHECK




class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	

	//				Constructors
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	/*Point(double x)
	{
		this->x = x;
		this->y = double();
		cout << "1argConstructor:\t" << this << endl;
	}*/
	Point(const Point& other)// конструктор копирования
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor" << this << endl;
	}
	
	

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}


//				Operators

	
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment :\t" << this << endl;
		return *this;
	}



	Point& operator++()//Prefix increment
	{
		this->x ++;
		this->y ++;
		
		return *this;//Возвращается измененное значение
	}
	Point operator++(int)//Posfix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		
		return old;//Спарое (НЕ измененное) значение
	}

	//				Methods:
	void print()const
	{
		cout << "x= " << x << "\ty= " << y << endl;
	}

	double distance(const double& x, const double& y)const
	{
		return sqrt(pow((this->x - x), 2) + pow((this->y - y), 2));
	}

	double distance(const Point& other)const
	{
		return sqrt(pow((this->x - other.x), 2) + pow((this->y - other.y), 2));
	}
};

double distance(const Point& A, const Point& B);

Point operator +(const Point& left, const Point& right);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#ifdef STRUCT_POINT	
	Point A;//создание экземпляра структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;//Обявляем указатель
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT
#ifdef CONSRTUCTOR CHECK
	Point A(3,5);
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;
	A.print();
	Point B(4, -5);
	B.print();
	Point C(5);//Singl-argumen constructor
	C.print();
	Point D;
	D.print();
	
	Point E = A;
	Point F(A);

	E.print();
	Point G;
	G = E;

	
#endif // CONSRTUCTOR CHECK
#ifdef DISTANCE
	Point A(2, 5);
	Point B(3, 6);
	cout << "-----------------------------------------------------------------"<<endl;
	cout << "Растояние от точки А до точки В : " << B.distance(A) << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Растояние между точкой B и точкой A : " << distance(B, A) << endl;
	cout << "-----------------------------------------------------------------" << endl;
#endif // DISTANCE

#ifdef ASSIGNMENT_CHECK
		int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;
	
	Point A, B, C;
	cout << "-----------------------------------------------------------------" << endl;
	A = B = C = Point(2, 3);//Point(2, 3) - явно вызваный временный безымянный обект

	cout << "-----------------------------------------------------------------" << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK
	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();	
	C++;
	C.print();
	B = A++;
	A.print();
	B.print();
	B = ++A;
	A.print();
	B.print();
	return 0;
}

double distance(const Point& A, const Point& B)
{
	return sqrt(pow((A.get_x() - B.get_x()), 2) + pow((A.get_y() - B.get_y()), 2));
}

Point operator +(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}