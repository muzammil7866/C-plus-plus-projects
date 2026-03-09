#include <iostream>
using namespace std;
// 
class COUNTING
{
public:
// 
int count;
//
//	COUNTING()
{
	count = 3;
}
//
//	void operator ++()
{
	count = count * 3;
}
//
};
// 
int main()
{
COUNTING obj;
 cout<<"BEFORE: ";
cout << obj.count<<" ";
//	++obj;
cout<<endl;
 cout<<"AFTER: ";
cout << obj.count << " ";
//
return 0;
}
