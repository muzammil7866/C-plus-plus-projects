#include <iostream>
using namespace std;
int main()
{	int x, y, z;
	bool answer1, answer2, answer3, answer4, answer5;
	x=10;
	y=15;
	z=20;
	
	answer1 = !(x>10);
	cout<<"Answer 1: "<<answer1<<endl;
	
	answer2 = x<=5 || y<15;
	cout<<"Answer 2: "<<answer2<<endl;
	
	answer3 = (x!=5) && (y!=z);
	cout<<"Answer 3: "<<answer3<<endl;
	
	answer4 = x>=z || (x+y>=z);
	cout<<"Answer 4: "<<answer4<<endl;
	
	answer5 = (x<=y-2) && (y>=z) || (z-2!=20);
	cout<<"Answer 5: "<<answer5<<endl;
	
	
return 0;
}




