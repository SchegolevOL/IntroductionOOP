#include"Matrix.h"

//-------functions-----------
Matrix operator+(const Matrix(left), const Matrix(right))
{
	if (left.get_row() != right.get_row() || left.get_colum() != right.get_colum())throw std::exception("Error: The sizes of the matrices do not match");
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
	if (left.get_row() != right.get_row() || left.get_colum() != right.get_colum())throw std::exception("Error: The sizes of the matrices do not match");
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
	if (left.get_colum() != right.get_row())throw std::exception("Error: The dimensions of the matrices are incorrect");
	Matrix result(left.get_row(), right.get_colum());

	for (size_t i = 0; i < result.get_row(); i++)
	{
		for (size_t j = 0; j < result.get_colum(); j++)
		{
			result[i][j] = 0;
			for (size_t k = 0; k < left.get_colum(); k++)
			{
				result[i][j] += left[i][k] * right[k][j];
			}
		}
	}
	return result;
}
Matrix operator/(const Matrix(left), const Matrix(right))
{
	if (left.get_row() != left.get_colum() && right.get_row() != right.get_colum())throw std::exception("Error: The matrix is not square");
	if (left.get_row() != right.get_row() || left.get_colum() != right.get_colum())throw std::exception("Error: The sizes of the matrices do not match");
	return left* Inverse(right);
}
int Determinant(Matrix matrix)
{
	if (matrix.get_row() != matrix.get_colum())throw std::exception("Error:  Are not the same the number of rows and columns the matrix.");
	if (matrix.get_row() == 1)return matrix[0][0];
	if (matrix.get_row() == 2)return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	if (matrix.get_row() >= 3)
	{
		Matrix tmp(matrix.get_row() - 1, matrix.get_row() - 1);
		double det = 0;
		int a, b;
		for (size_t i = 0; i < matrix.get_row(); i++)
		{
			a = 0;
			for (size_t j = 1; j < matrix.get_row(); j++)
			{
				b = 0;
				for (size_t k = 0; k < matrix.get_row(); k++)
				{
					if (k != i)
					{
						tmp[a][b] = matrix[j][k];
						b++;
					}
				}
				a++;
			}
			det += pow(-1, (double)i + 1 + 1) * matrix[0][i] * Determinant(tmp);
		}
		return det;
	}
}
Matrix Inverse(const Matrix matrix)
{
	Matrix InvMatrix(matrix);
	double det = Determinant(matrix);
	for (size_t i = 0; i < matrix.get_row(); i++)
	{
		for (size_t j = 0; j < matrix.get_colum(); j++)
		{			
			InvMatrix[i][j] = pow(-1, i + j) * Determinant(Matrix(matrix, j, i)) / det;
		}
	}
	return InvMatrix;
}




//---get---------------------
const size_t Matrix::get_row()const
{
	return row;
}
const size_t Matrix::get_colum()const
{
	return colum;
}
//-------Constructors--------
Matrix::Matrix(size_t row , size_t colum )
{
	this->row = row;
	this->colum = colum;
	this->matrix = new double* [row];
	for (size_t i = 0; i < row; i++)
	{
		this->matrix[i] = new double[colum] {};
	}
	//cout << "Constructor_2Arg: \t" << this << endl;
}
Matrix::Matrix(const Matrix& (other)) : Matrix(other.row, other.colum)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < colum; j++)
		{
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
	//cout << "CopyConstructor:\t" << this << endl;
}
Matrix::Matrix(const Matrix& (other), size_t k, size_t z): Matrix(other.row-1,other.colum-1)
{
	int a = 0, b = 0;
	for (size_t i = 0; i < other.row; i++)
	{
		b = 0;
		for (size_t j = 0; j < other.colum; j++)
		{			
			if (i != k && j != z)
			{
				matrix[a][b] = other.matrix[i][j];
				b++;
			}			
		}
		if (i != k)a++;
	}
}
//-------Destructor----------
Matrix::~Matrix()
{
	for (size_t i = 0; i < row; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
	//cout << "Destructor: \t\t" << this << endl;
}
//--------Methods------------

//------Operators------------
void Matrix::print()const
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
void Matrix::rnd(int begin, int end)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < colum; j++)
		{
			matrix[i][j] = rand() % (end - begin + 1) + begin;
		}
	}
}
double* Matrix::operator[](int i)
{
	return matrix[i];
}
const double* Matrix::operator[](int i)const
{
	return matrix[i];
}

Matrix& Matrix::operator=(const Matrix(other))
{
	this->row = other.row;
	this->colum = other.colum;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < colum; j++)
		{
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
	return *this;
}
