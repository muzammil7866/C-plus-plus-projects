#include <iostream>
using namespace std;
struct MovieData //defines a structure
{
//	//block of code shoes the attributes of the structure 'MovieData' and their data types
string title;
int year;
float minutes;
};
int main()
{
MovieData bollywood; //creates an object 'bollywood' of type 'MovieData'
//	
//	//block of code initialises the attributes of object bollywood
bollywood.title = "Koi Mil Gya";
bollywood.year = 2002;
bollywood.minutes = 90.3;
//
MovieData hollywood; //creates an object 'hollywood' of type 'MovieData'
//	
//	//block of code initialises the attributes of object hollywood
hollywood.title = "Avatar";
hollywood.year = 2016;
hollywood.minutes = 87.6;
//
//
//	//this block of code outputs the attributes of object 'bollywood' using concatenation
cout << "MOVIE 1:" << endl << endl;
//
cout << "Movie Name: "<<bollywood.title<<endl;
cout << "Movie Year of Release: " << bollywood.year << endl;
cout << "Movie duration in Minutes: " << bollywood.minutes << endl;
//
//
//	//this block of code outputs the attributes of object 'hollywood' using concatenation
cout <<endl<<endl<< "MOVIE 2:" << endl<<endl;
//
cout << "Movie Name: " << hollywood.title << endl;
cout << "Movie Year of Release: " << hollywood.year << endl;
cout << "Movie duration in Minutes: " << hollywood.minutes << endl;
//	
return 0;
}
