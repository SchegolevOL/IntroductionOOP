#include <iostream>
#include<Windows.h>
//#include<math.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;


#define tab "\t"
//#define STRUCT_POINT

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(fabs(pow((x1 - x2), 2)) + fabs(pow((y1 - y2), 2)));
}

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

	

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		cout << "x= " << x << "\ty= " << y << endl;
	}

	double distance(double x, double y)
	{
		return sqrt(fabs(pow((this->x - x), 2)) + fabs(pow((this->y - y), 2)));
	}

};


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
	Point A(3,-6);
	/*A.set_x(2);
	A.set_y(3);*/
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();
	Point B(4, -5);
	B.print();
	Point C(5);//Singl-argumen constructor
	C.print();
	Point D;
	D.print();
	
	cout << A.distance(B.get_x(), B.get_y()) << endl;
	cout << distance(A.get_x(), A.get_y(), B.get_x(), B.get_y()) << endl;




	return 0;
}
