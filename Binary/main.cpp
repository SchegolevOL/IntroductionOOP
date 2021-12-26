#include<iostream>
#include<Windows.h>

using namespace std;
class Binary;
Binary operator+(Binary left, Binary right);
int bin_to_dec(Binary& bin_value);
std::ostream& operator<<(std::ostream& os, const Binary& value);
Binary operator-(Binary left, Binary right);
Binary operator*(Binary left, Binary right);
Binary operator/(Binary left, Binary right);
Binary operator||(Binary left, Binary right);
Binary operator&&(Binary left, Binary right);
Binary operator ^ (Binary left, Binary right);
class Binary
{
	size_t size;
	bool* bin;
public:
	//-----geter------------------------
	const size_t get_size()const
	{
		return size;
	}
	const bool* get_bin()const
	{
		return bin;
	}

	//------Constructors-----------------
	explicit Binary()
	{
		this->size = 32;
		this->bin = new bool[size] {};
		
	}

	Binary(const char*str)
	{
		this->size = strlen(str);
		this->bin = new bool[size];
		for (size_t i = 0; i < size; i++)
		{
			bin[i] = str[i] == '0' ? 0 : 1;
		}
		cout << "Constructor: " << this << endl;
	}
	Binary(const Binary& other)
	{
		this->size = other.size;
		this->bin = new bool[size];
		for (size_t i = 0; i < size; i++)
		{
			bin[i] = other.bin[i];
		}
		cout << "CopyConstructor:\t\t" << this << endl;

	}
	Binary(Binary&& other)noexcept : size(other.size), bin(other.bin)
	{
		this->size = other.size;
		this->bin = other.bin;
		
		other.size = 0;
		other.bin = nullptr;
		cout << "MoveConstructor" << this << endl;
	}
	Binary(int value)
	{
		size_t f = 0;
		int tmp = value;
		do
		{
			tmp /= 2;
			f++;
		} while (tmp != 0);
		tmp = value;
		this->size = f;
		this->bin = new bool[size];
		for (size_t i = 0; i < size; i++)
		{
			bin[size - i - 1] = tmp % 2;
			tmp /= 2;
		}
	}

	~Binary()
	{
		cout << "Destructor: " << this << endl;
		delete[]bin;
	}
	

	bool& operator[](int i)
	{
		return bin[i];
	}

	const bool& operator[](int i)const
	{
		return bin[i];
	}
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "bin :\t";
		for (size_t i = 0; i < size; i++)
		{
			cout <<  bin[i];
		}
		cout << endl;

	}
	std::ostream& print(std::ostream& os = cout)const
	{
		for (size_t i = 0; i < size; i++)
		{
			os << bin[i];
		}	
		return os;
	}
	Binary& operator = (const Binary& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[]this->bin;
		this->size = other.size;
		this->bin = new bool[size];
		for (size_t i = 0; i < size; i++)
		{
			this->bin[i] = other.bin[i];
		}
		cout << "CopyAssignment : " << this << endl;
		return *this;
	}
	Binary& operator = (Binary&& other)noexcept
	{
		if (this == &other)
		{
			return *this;
		}
		delete this->bin;
		this->size = other.size;
		this->bin = other.bin;
		other.size = 0;
		other.bin = nullptr;		
		cout << "MoveAssigment:\t\t" << this << endl;
		return *this;
	}

	Binary& max_bin(const Binary&(other))
	{
		if (this->size >= other.size) return *this;
		Binary tmp(other);
		for (size_t i = 0; i < other.size; i++)
		{
			if (i >= this->size)
			{
				tmp[other.size - i - 1] = 0;
			}
			else 
			{
				tmp[other.size - i - 1] = this->bin[this->size - i - 1];
			}
		}
		*this = tmp;		
		return *this;
	}
	Binary operator !()
	{
		for (size_t i = 0; i < size; i++)
		{
			
			if (bin[i])bin[i] = 0;
			else bin[i] = 1;
		}
		*this = bin_to_dec(*this);
		return *this;
	}
};




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Binary a = "101";
	cout << a << endl;
	
	Binary b=100;
	a.max_bin(b);
	cout << a << endl;
	Binary d;
	d = a || b;
	cout << a << endl;
	cout << b << endl;
	cout << d << endl<<endl;
	d = a && b;
	cout << a << endl;
	cout << b << endl;
	cout << d << endl;
	d = a ^ b;
	cout << a << endl;
	cout << b << endl;
	cout << d << endl;
	cout << d << endl;
	cout << !d << endl;

	//Binary g(11);
	//cout << g << endl;
	//c = bin_to_dec(b);
	//cout << b << endl;
	
	//	d = a + b;
	//	d = b - a;
	//	d = b * a;
	//	//d = b / a;
	//cout << d << "   " << bin_to_dec(d) << endl;

	return 0;
}

Binary operator+(Binary left, Binary right)
{
	int tmp = bin_to_dec(left) + bin_to_dec(right);
	Binary result(tmp);
	return result;
}
Binary operator-(Binary left, Binary right)
{
	int tmp = bin_to_dec(left) - bin_to_dec(right);
	Binary result(tmp);
	return result;
}
Binary operator*(Binary left, Binary right)
{
	int tmp = bin_to_dec(left) * bin_to_dec(right);
	Binary result(tmp);
	return result;
}
Binary operator/(Binary left, Binary right)
{
	int tmp = bin_to_dec(left) / bin_to_dec(right);
	Binary result(tmp);
	return result;
}
Binary operator||(Binary left, Binary right)
{
	left = left.max_bin(right);
	right = right.max_bin(left);
	Binary tmp(left);
	for (size_t i = 0; i < tmp.get_size(); i++)
	{
		tmp[tmp.get_size() - i - 1] = left.get_bin()[tmp.get_size() - i - 1] == 1 || right.get_bin()[tmp.get_size() - i - 1] == 1 ? 1 : 0;
	}
	Binary result(bin_to_dec(tmp));
	return tmp;
}
Binary operator&&(Binary left, Binary right)
{
	left = left.max_bin(right);
	right = right.max_bin(left);
	Binary tmp(left);
	for (size_t i = 0; i < tmp.get_size(); i++)
	{
		tmp[tmp.get_size() - i - 1] = left.get_bin()[tmp.get_size() - i - 1] == 0 || right.get_bin()[tmp.get_size() - i - 1]==0 ? 0 : 1;
	}
	Binary result(bin_to_dec(tmp));
	return result;
}
Binary operator ^ (Binary left, Binary right)
{
	left = left.max_bin(right);
	right = right.max_bin(left);
	Binary tmp(left);
	for (size_t i = 0; i < tmp.get_size(); i++)
	{
		tmp[tmp.get_size() - i - 1] = left.get_bin()[tmp.get_size() - i - 1] ==  right.get_bin()[tmp.get_size() - i - 1] ? 0 : 1;
	}
	Binary result(bin_to_dec(tmp));
	return result;
}



int bin_to_dec(Binary& bin_value)
{
	int value = 0;
	for (size_t i = 0; i < bin_value.get_size(); i++)
	{
		value += bin_value[i] == 0 ? 0 : 1 * pow(2, bin_value.get_size() - i - 1);
	}
	return value;
}


std::ostream& operator<<(std::ostream& os, const Binary& value)
{
	return value.print(os);
}
