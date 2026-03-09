#include<iostream>
using namespace std;
template <class T>
class myIncrement
{
T value;
public:
//	myIncrement(T arg) { value = arg; }
T toTncrement() { return ++value; }
};
template<>
class myIncrement<char> {
char value;
public:
//	myIncrement(char arg) { value = arg; }
char uppercase()
{
	if ((value >= 'a') && (value <= 'z'))
//			value += 'A' - 'a';
	return value;
}
};
int main() {
//	myIncrement<int>myint(7);
//	myIncrement<char>mychar('s');
//	myIncrement<double>mydouble(11.0);
cout << "incremented int value:" << myint.toTncrement()<< endl;
cout << "Uppercase value:" << mychar.uppercase() << endl;
cout << "incremented double value:" << mydouble.toTncrement() << endl;
return 0;
}
