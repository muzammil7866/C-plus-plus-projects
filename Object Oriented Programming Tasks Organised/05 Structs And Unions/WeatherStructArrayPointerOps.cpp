#include<iostream>
using namespace std;
struct month
{
float total_rainfall;
float high_temp;
float low_temp;
float avg_temp;
string name;
};
int main()
{
month months[12];
month* ptr = new month;
ptr = months;
for (int i = 0;i < 12; i++)
{
	cout << "Enter the total rainfall of month "<<i+1<<": ";
	cin >> (*(ptr + i)).total_rainfall;
	cout << "Enter the highest temp of month " << i + 1 << ": ";
	cin >> (*(ptr + i)).high_temp;
	cout << "Enter the lowest temp of month " << i + 1 << ": ";
	cin >> (*(ptr + i)).low_temp;
//		(*(ptr + i)).avg_temp = ((*(ptr + i)).low_temp + (*(ptr + i)).high_temp) / 2;
}
//	
for (int i = 0;i < 12; i++)
{
	cout << "Details of Month-> " << i + 1<<endl;
	cout << "Total Rainfall: "<<(*(ptr + i)).total_rainfall << endl;
	cout << "Highest Temperature: " << (*(ptr + i)).high_temp<<endl;
	cout << "Lowest Temperature: " << (*(ptr + i)).low_temp<<endl;
	cout << "Average Temperature: " << (*(ptr + i)).avg_temp << endl << endl;
}
//
float total = 0;
//
for (int i = 0;i < 12; i++)
{
//		total += (*(ptr + i)).total_rainfall;
}
//
cout << "Average rainfall for the entire year is: "<<total / 12;
//
//
return 0;
}
