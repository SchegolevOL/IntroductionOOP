#include"Matrix.h"




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	
	size_t row, colum;
	int a, b;
	cout << "������� ������ ������ : ";
	cin >> row;
	cin >> colum;
	Matrix matrix1(row, colum);
	cout << "������� �������� �����, ��� ���������� ������� : ";
	cin >> a;
	cin >> b;
	matrix1.rnd(a, b);
	cout << "������� �1"<<endl;
	matrix1.print();
	cout << "������������ ������� �1 = " << determinant(matrix1) << endl;
	cout << "\n\n";
	Matrix matrix2(row, colum);
	matrix2.rnd(a, b);
	cout << "������� �2" << endl;
	matrix2.print();
	cout << "������������ ������� �2 = " << determinant(matrix2) << endl;

	cout << "\n\n";
	Matrix matrix3;
	cout << "������� �3 = ������� �1 + ������� �2" << endl;
	try
	{
		matrix3 = matrix1 + matrix2;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	matrix3.print();

	cout << "������� �3 = ������� �1 - ������� �2" << endl;
	try
	{
		matrix3 = matrix1 - matrix2;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	matrix3.print();

	cout << "������� �3 = ������� �1 - ������� �2" << endl;
	try
	{
		matrix3 = matrix1 - matrix2;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	matrix3.print();

	cout << "������� �3 = ������� �1 * ������� �2" << endl;
	try
	{
		matrix3 = matrix1 * matrix2;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	matrix3.print();

	cout << "������� �3 = ������� �1 / ������� �2" << endl;
	try
	{
		matrix3 = matrix1 / matrix2;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	matrix3.print();

	cout << "�������� ������� ������� �1 = " << endl;
	matrix3 = Inverse(matrix1);
	matrix3.print();
	cout << "�������� �������� �������" << endl;
	matrix2 = matrix1 * matrix3;
	matrix2.print();

	return 0;
}




