#include <iostream>
using namespace std;
class student
{
public: 
	int age;
	string name;
	int roll_no;

};

class player: public student
{
	int score;
	string sports_type;
	
public:
	void init(int a, string b, int c, int d, string e)
	{
		age = a;
		name = b;
		roll_no = c;
		score = d;
		sports_type = e;
	
	}

	void display()
	{
		cout << "THIS PLAYER DETAILS : "<<endl;
		cout << "AGE:" << age << " NAME: " << name << " ROLL NO: " << roll_no << " SCORE: " << score << " SPORTS TYPE: " << sports_type;
		cout << endl;
		cout << endl;
	}
};
int main()
{

	player man1[10];
	man1[0].init(19, "Olympus", 3148, 75, "Boxer");
	man1[1].init(20, "Augustus", 3182, 65, "Cricket");
	man1[2].init(21, "Veruca", 3122, 71, "Football");
	man1[3].init(22, "Saman", 3135, 19, "Wrestling");
	man1[4].init(23, "Charlie", 3162, 45, "Golf");
	man1[5].init(24, "Roshi", 3189, 53, "Snooker");
	man1[6].init(25, "Chapelien", 3131, 21, "Billiards");
	man1[7].init(26, "Ronnie", 3153, 53, "Archery");
	man1[8].init(27, "Saad", 3232, 11, "Judo");
	man1[9].init(28, "Drake", 3642, 53, "Rock Climbing");

	man1[0].display();
	man1[1].display();
	man1[2].display();
	man1[3].display();
	man1[4].display();
	man1[5].display();
	man1[6].display();
	man1[7].display();
	man1[8].display();
	man1[9].display();


	return 0;
}
