#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<math.h>
#include <cstring>
using namespace std;
class Data;
//std::istream& operator>>(std::istream& is, Data& obj);
int search_week(int d, int m, int y);



class Data
{
	int week;
	int day;
	int month;
	int year;
public:
	//--------gets----------

	const int get_day()
	{
		return day;
	}
	const int get_week()
	{
		return week;
	}
	const int get_month()
	{
		return month;
	}
	const int get_year()
	{
		return year;
	}

	//--------sets----------

	void set_year(int year)
	{
		this->year=year;
		this->week= search_week(this->day, this->month, this->year);
	}
	void set_day(int day)
	{
		this->day = day;
		this->week = search_week(this->day, this->month, this->year);
	}
	void set_month(int month)
	{
		this->month = month;
		this->week = search_week(this->day, this->month, this->year);
	}
	//------Constructor-----

	Data()
	{
		this->day = 1;
		this->month = 1;
		this->week = 1;
		this->year = 1;
	}

	Data(int day,int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;		
		this-> week = search_week(day, month, year);
	}

	Data(const char* str)
	{
		const int size = strlen(str) + 1;
		char buffer[20] = {};
		for (size_t i = 0; i < 10; i++)
		{
			buffer[i] = str[i];
		}
		const char delimites[] = "/. ";
		char* number[3] = {};
		int n = 0;
		for (char* pch = strtok(buffer, delimites); pch; pch = strtok(NULL, delimites))
		{
			number[n++] = pch;
		}
		int d = atoi(number[0]);
		int m = atoi(number[1]);
		int y = atoi(number[2]);
		Data(d, m, y);
	}

	Data(const Data& other)
	{
		this->day = other.day;
		this->month = other.month;
		this->week = other.week;
		this->year = other.year;
	}


	void print()const
	{
		cout << "День:\t" << day << endl;
		cout << "Месяц:\t" << month << endl;
		cout << "Год:\t" << year << endl;
		cout << "Неделя:\t";
			switch (week)
			{			
			case 1:
				cout << "Понедельник";
				break;
			case 2:
				cout << "Вторник";
				break;
			case 3:
				cout << "Среда";
				break;
			case 4:
				cout << "Четверг";
				break;
			case 5:
				cout << "Пятница";
				break;
			case 6:
				cout << "Субота";
				break;
			case 7:
				cout << "Воскресенье";
				break;
			}
			cout << endl;

	}



	//-----------Destructor---------------------
	~Data()
	{
		cout << "Destructor: " << this << endl;
	}

	Data& operator = (const Data& other)
	{
		if (this == &other)
		{
			return *this;
		}
		this->day = other.day;
		this->month = other.month;
		this->week = other.week;
		this->year = other.year;
		cout << "CopyAssignment : " << this << endl;
		return *this;
	}

};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Data d(26,12,2021);
	d.set_year(2022);
	d.set_month(1);
	d.print();
	Data a = d;
	a.print();


	return 0;
}
int search_week(int d, int m, int y)
{
	if (m <= 2)
	{
		y -= 1;
		d += 3;
	}
	int w = 1 + (d + y + y / 4 - y / 100 + y / 400 + (31 * m + 10) / 12) % 7;
	return w;
}
//std::istream& operator>>(std::istream& is, Data& obj)
//{
//	const int SIZE = 32;
//	char buffer[SIZE] = {};
//	is >> buffer;
//	obj = buffer;
//	return is;
//}

