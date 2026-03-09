#include <iostream>
using namespace std;
class student
{
public: 
int age;
string name;
int roll_no;
//
};
//
class player: public student
{
int score;
string sports_type;
//	
public:
void init(int a, string b, int c, int d, string e)
{
	age = a;
	name = b;
	roll_no = c;
	score = d;
	sports_type = e;
//	
}
//
void display()
{
	cout << "AGE:" << age << " NAME: " << name << " ROLL NO: " << roll_no << " SCORE: " << score << " SPORTS TYPE: " << sports_type;
}
};
int main()
{
//
player man1;
//	man1.init(19, "Olympus", 3182, 75, "Boxer");
//	man1.display();
return 0;
}
