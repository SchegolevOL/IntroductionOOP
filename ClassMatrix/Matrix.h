#pragma once
#include<iostream>
#include<Windows.h>
#include<time.h>
#include <stdlib.h>



using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Matrix;
Matrix operator+(const Matrix(left), const Matrix(right));
Matrix operator-(const Matrix(left), const Matrix(right));
Matrix operator*(const Matrix(left), const Matrix(right));
Matrix operator/(const Matrix(left), const Matrix(right));
int determinant(Matrix matrix);
Matrix Inverse(Matrix matrix);




class Matrix
{
	//---------Parameters--------
	size_t row;
	size_t colum;
	double** matrix;
public:
	//---------Metods------------
	//---get---------------------
	const size_t get_row()const;

	const size_t get_colum()const;


	//---set---------------------


	//-------Constructors--------
	Matrix(size_t row = 3, size_t colum = 3);

	Matrix(const Matrix& (other));

	Matrix(const Matrix& (other), size_t k, size_t z);


	//-------Destructor----------
	~Matrix();


	//--------Methods------------
	

	//------Operators------------
	void print()const;

	void rnd(int begin, int end);

	double* operator[](int i);

	const double* operator[](int i)const;

	Matrix& operator=(const Matrix(other));

};