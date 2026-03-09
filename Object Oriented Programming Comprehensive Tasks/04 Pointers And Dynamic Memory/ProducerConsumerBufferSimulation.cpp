#include <iostream>
using namespace std;
const int BUFSIZE = 10;
const int ITERATIONS = 50;
double getProb();
int* generateData(int*& inbuf, int& count);
void processData(int*& outbuf, int& count, int& total);
int main()
{
//	srand(time(0));
	int* fillbuffer = new int[BUFSIZE];
	int fillcnt = 0; 
	int* processbuffer = NULL;
	int	processcnt = 0;
	int tcount = 0;
	for (int i = 0; i < ITERATIONS; i++)
	{
		int* temp;
		if (getProb() <= 0.40)
		{
			temp = generateData(fillbuffer, fillcnt);
			if (temp != NULL) 
				processbuffer =	temp;
		}
		if (getProb() <= 0.60)
//				processData(processbuffer, processcnt, tcount);
//				
		cout << fillcnt << endl;
		cout<< processcnt << endl;
		cout << "Total value: " << tcount << endl;
//		
	}
//
	return 0;
}
//
double getProb()
{
double num = ((rand() % 1+1)-0.27)/(rand()%5+1);
return num;
}
//
int* generateData(int*& inbuf, int& count)
{
inbuf[count] = -1+ rand() % 10;
//	count++;
//
if (count >  BUFSIZE-1)
{
	count = 0;
	int* newBuffer = new int[BUFSIZE];
	inbuf = newBuffer;
//
	return inbuf;
}
//
else
	return NULL;
//
}
void processData(int*& outbuf, int& count, int& total) 
{
if (outbuf == NULL)
	return;
else
{
	total = total + *(outbuf + count);
//		count++;
}
//
if (count == BUFSIZE-1)
{
	count = 0;
//		delete[] outbuf;
	outbuf = NULL;
}
//
//
//
}
