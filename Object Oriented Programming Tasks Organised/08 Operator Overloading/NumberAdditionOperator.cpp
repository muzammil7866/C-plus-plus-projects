#include <iostream>
using namespace std;
class A {
public:
//    //constructor
//        A() 
   {
       cout << "A's Constructor called \n";
   }
};
//
class B {
//
   public:
//        //constructor
//        B()
   {
       cout<< "B's Constructor called \n";
   }
};
class C :public B, public A {
public:
//    //constructor
//    C() 
   {
       cout << "C's Constructor called \n";
   }
};
//
//
int main()
{
//    //declaring object
   C  obj1;
//
return 0;
}
