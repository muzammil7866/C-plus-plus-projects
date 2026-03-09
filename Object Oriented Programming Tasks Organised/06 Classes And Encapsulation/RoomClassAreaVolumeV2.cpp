#include <iostream>
using namespace std;
enum week{monday, tuesday, wednesday, thursday, friday, saturday, sunday}; //defines the data for enum
int main()
{
//	week today, yesterday, tomorrow; //declares the objects of enum
today = thursday;
yesterday = wednesday;
tomorrow = friday;
cout << "Tomorrow: "<<today + 1 << endl; //displays 1 added to today as tomorrow
cout << "Yesterday: "<<today - 1; //displays 1 subracted to today as yesterday
//
return 0;
}
