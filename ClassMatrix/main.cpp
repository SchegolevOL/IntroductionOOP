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




class Matrix
{
	//---------Parameters--------
	size_t row;
	size_t colum;
	int** matrix;
public:
	//---------Metods------------
	//---get---------------------
	const size_t get_row()const
	{
		return row;
	}
	const size_t get_colum()const
	{
		return colum;
	}
	
	//---set---------------------
	

	//-------Constructors--------
	 Matrix(size_t row = 3, size_t colum=3)
	{
		this->row = row;
		this->colum = colum;
		this->matrix = new int* [row];
		for (size_t i = 0; i < row; i++)
		{
			this->matrix[i] = new int[colum] {};
		}
		cout << "Constructor_2Arg: \t" << this << endl;
	}
	/*Matrix(size_t size) 
	 {
		this->row = size;
		this->colum = size;
		this->matrix = new int* [row];
		for (size_t i = 0; i < row; i++)
		{
			this->matrix[i] = new int[colum] {};
		}
		 cout << "Constructor_1Arg: \t" << this << endl;
	 }*/


	 Matrix(const Matrix& (other)) : Matrix(other.row,other.colum)
	 {
		 for (size_t i = 0; i < row; i++)
		 {
			 for (size_t j = 0; j < colum; j++)
			 {
				 this->matrix[i][j] = other.matrix[i][j];
			 }
		 }
		 cout << "CopyConstructor:\t" << this << endl;
	 }
	 


	//-------Destructor----------
	~Matrix()
	{
		for (size_t i = 0; i < row; i++)
		{
			delete[]matrix[i];
		}
		delete[]matrix;
		cout << "Destructor: \t\t" << this << endl;
	}

	//--------Methods------------


	//------Operators------------
	void print()const
	{
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < colum; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void rnd(int begin, int end)
	{
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < colum; j++)
			{
				matrix[i][j] = rand() % (end - begin + 1) + begin;
			}
		}
	}
	int* operator[](int i)
	{
		return matrix[i];
	}

	const int* operator[](int i)const
	{
		return matrix[i];
	}
	

};




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Matrix matrix1(3,3);
	matrix1.rnd(1, 5);
	matrix1.print();
	Matrix matrix2(3,2);
	matrix2.rnd(1, 5);
	matrix2.print();
	/*Matrix matrix4 = matrix1 + matrix2;*/
	/*matrix4.print();*/
	Matrix matrix3 = matrix1 * matrix2;
	matrix3.print();
	


	return 0;
}

Matrix operator+(const Matrix(left), const Matrix(right))
{
	if (left.get_row() != right.get_row() || left.get_colum() != right.get_colum())return -1;//??????????????
	Matrix result(left.get_row(), right.get_row());

	for (size_t i = 0; i < result.get_row(); i++)
	{
		for (size_t j = 0; j < result.get_colum(); j++)
		{
			result[i][j] = left[i][j] + right[i][j];
		}
	}
	return result;
}
Matrix operator-(const Matrix(left), const Matrix(right))
{
	if (left.get_row() != right.get_row() || left.get_colum() != right.get_colum())return -1;//??????????????
	Matrix result(left.get_row(), right.get_row());

	for (size_t i = 0; i < result.get_row(); i++)
	{
		for (size_t j = 0; j < result.get_colum(); j++)
		{
			result[i][j] = left[i][j] - right[i][j];
		}
	}
	return result;
}
Matrix operator*(const Matrix(left), const Matrix(right))
{
	if (left.get_colum() !=  right.get_row())return -1;//??????????????
	Matrix result(left.get_row(), right.get_colum());

	for (size_t i = 0; i < result.get_row(); i++)
	{
		for (size_t j = 0; j < result.get_colum(); j++)
		{
			result[i][j] = 0;
			for (size_t k = 0; k < left.get_colum(); k++)
			{
				result[i][j] = result[i][j] + left[i][k] * right[k][j];
			}			
		}
	}
	return result;
}
Matrix operator/(const Matrix(left), const Matrix(right))
{
	
	return 0;
}




