#include <iostream>
using namespace std;
int main()
{
	int array[7], thisindex, count=0, max, max2=0, count2=0;
	
	for(int i=0; i<7; i++)
	{
		cout<<"Enter element of array at index ["<<i<<"]: ";
		cin>>array[i];
	}
	
	max = array[0];
	max2 = array[0];
			
	for(int j =0; j<=6; j++)
	{
		
			if(max < array[j])
			{
				max = array[j];
				
			}		
	}
	
	for(int j =0; j<=6; j++)
	{
		
			if(max2 < array[j] && array[j] != max)
			{
				max2 = array[j];				
			}		
	}
	cout<<"The maximum number in the array is: "<<max<<endl;
	cout<<"The second maximum number in the array is: "<<max2;
	return 0;	
}
