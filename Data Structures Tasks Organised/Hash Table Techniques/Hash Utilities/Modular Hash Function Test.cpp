#include<iostream>
using namespace std;
int hashFun(int key) {
	int x = (key + 7) * (key + 7);
	x = x / 16;
	x = x + key;
	x = x % 11;
	return x;
}
int main()
{
	cout << hashFun(43)<<endl;
	cout << hashFun(23)<<endl;
	cout << hashFun(1)<<endl;
	cout << hashFun(0)<<endl;
	cout << hashFun(15)<<endl;
	cout << hashFun(31)<<endl;
	cout << hashFun(4)<<endl;
	cout << hashFun(7)<<endl;
	cout << hashFun(11)<<endl;
	cout << hashFun(3)<<endl;



	return 0;
}