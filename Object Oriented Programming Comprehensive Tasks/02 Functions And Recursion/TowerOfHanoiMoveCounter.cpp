#include<iostream>
using namespace std;
int count1 = 0;
void TowerofHanoi(int start, int end, char source, char aux, char destination);
int main()
{
	int disks; 
	cout << "Enter the number of disk you want to start from: "; //enter the number of disks need to be transferred
	cin >> disks;
	TowerofHanoi(1, disks, 'A', 'B', 'C'); //this line passes the argument list
	cout <<endl<< "Total moves are: "<<count1;



	return 0;
}
void TowerofHanoi(int start, int end, char source, char aux, char destination)
{
	
	if (start > end) //checks if there are remaining disks to be moved
		return;	//ends the recursive function call

	TowerofHanoi(start, end - 1, source, destination, aux); //decrements in the end so n-1 disks could be moved first 
	cout << "move disk " << end << " from " << source << " to " << destination << endl; 
	count1 += 1; //counts the turns
	TowerofHanoi(start, end - 1, aux, source, destination); //makes another call and copy is made which is solved first
}
