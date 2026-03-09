#ifndef _UINT16_H
#define _UINT16_H
#include<iostream>
using namespace std;
//
enum OP_STATUS
{
SUCCESS = 0 , FAILURE = 1
};
//
class UInt16
{
//
private:
//	unsigned int *value;
static OP_STATUS status;
//
public:
//	
//	UInt16(); //default constructor
//	UInt16(unsigned int a); //parameterised constructor
//	UInt16(UInt16& a); //copy constructor
UInt16 assignment (UInt16& a); //assignment operator overloaded
void set(unsigned int a); //setter of value
const char* checkStatus() const; //returns the status of last arithematic operation char by char
unsigned int size() const; //returns size of the operations
UInt16 add(UInt16 a) const; //addition
UInt16 sub(UInt16 a) const; //subtraction
UInt16 mup(UInt16 a) const;	//multiplication
UInt16 div(UInt16 a) const; //division
unsigned int get() const; //getter of value
//
//
//	
//
};
#endif
