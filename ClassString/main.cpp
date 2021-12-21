#include"String.h"

//#define CONSTRACTOR_CHEK
#define OPERATORS_CHEK
//#define INPUT_CHECK
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#ifdef CONSTRACTOR_CHEK
	String str;//Default constructor
	cout << str << endl;
	String str2(25);//Single-argument constructor
	String str3 = "Heloo";
	str3 = str3;
	cout << str3 << endl;
	String str4 = str3;
	cout << str4 << endl;//Copy constructor
	String str5;
	str5 = str4;//CopyAssigment
	cout << str5 << endl;
#endif // CONSTRACTOR_CHEK
#ifdef OPERATORS_CHEK
	String str1 = "Heloo";
	String str2 = "World";

	String str3 = str1 + str2;
	cout << str3 << endl;
	cin >> str1;
	cout << str1 << endl;
	str2 += str1;
	cout << str2 << endl;
#endif // OPERATORS_CHEK
#ifdef INPUT_CHECK
	String str;
	cout << "Введите строку : ";
	//cin >> str;
	str.print();
	getline(cin, str);
	cout << str << endl;
#endif // INPUT_CHECK
	return 0;
}

