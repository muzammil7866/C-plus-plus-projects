#include <iostream>
using namespace std;
int main ()
{
	long int totalcookies, noofcontainers, cookieboxestot,  totalcookiesinbox, noofcookieboxes, remnoofcookieboxes, noofcookieboxesincont, remnoofcontainers;
	cout<<"Enter your total cookies: ";
	cin>>totalcookies; 
	cout<<"Enter your total cookies in a box: ";
	cin>>totalcookiesinbox;
	cout<<"Enter your total boxes in a container: ";
	cin>>noofcookieboxesincont;
	if(totalcookiesinbox< 25 && noofcookieboxesincont< 76)
	{ 
	
	cookieboxestot= totalcookies/totalcookiesinbox;
	
	noofcontainers= cookieboxestot/noofcookieboxesincont;
	
	remnoofcookieboxes= totalcookies%totalcookiesinbox;
	remnoofcontainers= cookieboxestot%noofcookieboxesincont;
	
	cout<<"Number of cookie boxes: "<<noofcookieboxes<<endl;
	cout<<"Number of containers: "<<noofcontainers<<endl;
	cout<<"Number of remaining cookies: "<<remnoofcookieboxes<<endl;
	cout<<"Number of remaining cookie boxes: "<<remnoofcontainers<<endl;
	}
	
	else
	{
		cout<<"Cookies in a box cannot exceed 24 and Boxes in a containes cannot exceed 75";
	}
	
	
	return 0;
}
