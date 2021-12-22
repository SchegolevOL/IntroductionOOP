#include"Matrix.h"




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	
	size_t row, colum;
	int a, b;
	cout << "Введите размер матриц : ";
	cin >> row;
	cin >> colum;
	Matrix matrix1(row, colum);
	cout << "Введите интервал чисел, для заполнения матрицы : ";
	cin >> a;
	cin >> b;
	matrix1.rnd(a, b);
	cout << "Матрица №1"<<endl;
	matrix1.print();
	//cout << "Определитель матрицы №1 = " << determinant(matrix1) << endl;
	cout << "\n\n";
	Matrix matrix2(row, colum);
	matrix2.rnd(a, b);
	cout << "Матрица №2" << endl;
	matrix2.print();
	//cout << "Определитель матрицы №2 = " << determinant(matrix2) << endl;

	cout << "\n\n";
	Matrix matrix3;
	cout << "Матрица №3 = Матрица №1 + Матрица №2" << endl;
	try
	{
		matrix3 = matrix1 + matrix2;
		matrix3.print();
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	

	cout << "Матрица №3 = Матрица №1 - Матрица №2" << endl;
	try
	{
		matrix3 = matrix1 - matrix2;
		matrix3.print();
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	

	cout << "Матрица №3 = Матрица №1 - Матрица №2" << endl;
	try
	{
		matrix3 = matrix1 - matrix2;
		matrix3.print();
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	

	cout << "Матрица №3 = Матрица №1 * Матрица №2" << endl;
	try
	{
		matrix3 = matrix1 * matrix2;
		matrix3.print();
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	

	cout << "Матрица №3 = Матрица №1 / Матрица №2" << endl;
	try
	{
		matrix3 = matrix1 / matrix2;
		matrix3.print();
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	

	cout << "Обратная матрица Матрицы №1 = " << endl;
	try
	{
	matrix3 = Inverse(matrix1);
	matrix3.print();
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}

	
	cout << "Проверка обратной матрицы" << endl;
	try
	{
	matrix2 = matrix1 * matrix3;
	matrix2.print();
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	

	return 0;
}




