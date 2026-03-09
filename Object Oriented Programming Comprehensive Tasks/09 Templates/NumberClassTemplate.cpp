#include <iostream>
using namespace std;

template <class T>

class Number
{

	private:
		T num, num2;

	public:
		Number(T n): num(n), num2(0) {}

		Number(T n, T n2) : num(n), num2(n2) {}

	T getNum()
	{
		return num;
	}

	T getDivNum()
	{
		if (num != 0)
		{
			return num2 / num;
		}

		else
		{
			cout << "ERROR AS THE DENOMINATOR IS ZERO\n";
			system("pause");
		}
		
	}

};
int main()
{
	Number<int> numberInt(7);
	Number<double> numberDouble(7.7);

	cout << "Int Number = " << numberInt.getNum() << endl;
	cout << "Double Number = " << numberDouble.getNum() << endl;

	Number<double> obj(16.8, 64.2);
	cout<<"DIVIDED NUMBER: "<<obj.getDivNum() << endl;

	Number<int> check(0, 17);
	check.getDivNum();

	return 0;
}
