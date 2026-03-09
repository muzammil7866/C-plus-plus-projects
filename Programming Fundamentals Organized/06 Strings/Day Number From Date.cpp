#include <iostream>
#include <string>
using namespace std;
void dayNumber(int days, int month, int year);
int main()
{
string date, day, month, year;
int size = 0;
int intDay = 0, intMonth = 0, intYear = 0;
int dashindex = 0;
cout << "Enter the date in the format (month-day-year): ";
getline(cin, date);
cout << date;
size = date.length();
//
int i = 0;
while (date[i] != '-')
{
	month = month + date[i];
	i++;
}
cout <<endl<< month;
dashindex = i;
i++;
while (date[i] != '-')
{
	day = day + date[i];
	i++;
}
//
cout << endl << day;
dashindex = i;
i++;
//
while (date[i] != '\0')
{
	year = year + date[i];
	i++;
}
//
cout << endl<<year;
//
intDay = stoi(day);
intMonth = stoi(month);
intYear = stoi(year);
	cout << intMonth << " " << intDay << " " << intYear;
dayNumber(intDay, intMonth, intYear);
return 0;
}
//
void dayNumber(int intDay, int intMonth, int intYear)
{
int totalDays = 0;
totalDays = intDay;
//
if (intDay < 1 || intDay >31)
	cout << "Entered day is invalid as it should be from (1 - 31)";
//
for (int count = 1; count <= intMonth - 1; count++)
{
	switch (count)
	{
	case 1:
		totalDays = totalDays + 31;
		break;
	case 2:
		if (intYear % 4 == 0 && intYear % 100 != 0)
			totalDays = totalDays + 29;
		else if (intYear % 100 == 0 && intYear % 400 == 0)
			totalDays = totalDays + 29;
		else
			totalDays = totalDays + 28;
		break;
	case 3:
		totalDays = totalDays + 31;
		break;
	case 4:
		totalDays = totalDays + 30;
		break;
	case 5:
		totalDays = totalDays + 31;
		break;
	case 6:
		totalDays = totalDays + 30;
		break;
	case 7:
		totalDays = totalDays + 31;
		break;
	case 8:
		totalDays = totalDays + 31;
		break;
	case 9:
		totalDays = totalDays + 30;
		break;
	case 10:
		totalDays = totalDays + 31;
		break;
	case 11:
		totalDays = totalDays + 30;
		break;
	case 12:
		totalDays = totalDays + 31;
		break;
//
	default:
		cout << "Entered month is not a valid month";
	}
}
cout << "The day number is: " << totalDays;
}
