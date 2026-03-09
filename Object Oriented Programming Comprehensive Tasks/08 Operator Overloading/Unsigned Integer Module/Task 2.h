#ifndef _UINT_H
#define _UINT_H
#include<iostream>
using namespace std;
//
//
enum OP_STATUS
{
SUCCESS = 0, FAILURE = 1
};
//
class UInt
{
private:
//	
	unsigned int* value;
	static OP_STATUS status;
//
public:
//
//		UInt();
//		UInt(unsigned int a);
//		UInt(UInt& a);
	UInt assignment (UInt& a);
	void set(unsigned int a);
	void setStatus(OP_STATUS a);
	unsigned int get() const;
	const char* checkStatus() const;
	unsigned int size() const;		
	UInt add(UInt a) const;
	UInt sub(UInt a) const;
	UInt mup(UInt a) const;
	UInt div(UInt a) const;
//		
};
//
#endif
#ifndef _UINT8_H
#define _UINT8_H
//
class UInt8 : public UInt 
{
//
public:
//	UInt8();
//	UInt8(unsigned int a);
//	UInt8(UInt8& a);
UInt8 assignment (UInt8& a);
unsigned int size() const;
UInt8 add(UInt8& a) const;
UInt8 sub(UInt8& a) const;
UInt8 mup(UInt8& a) const;
UInt8 div(UInt8& a) const;
};
//
#endif
#ifndef _UINT16_H
#define _UINT16_H
//
class UInt16 : public UInt 
{
//
public:
//	UInt16();
//	UInt16(unsigned int a);
//	UInt16(UInt16& a);
UInt16 assignment (UInt16& a);
unsigned int size() const;
UInt16 add(UInt16& a) const;
UInt16 sub(UInt16& a) const;
UInt16 mup(UInt16& a) const;
UInt16 div(UInt16& a) const;
};
//
#endif
#ifndef _UINT24_H
#define _UINT24_H
//
class UInt24 : public UInt 
{
//
public:
//	UInt24();
//	UInt24(unsigned int a);
//	UInt24(UInt24& a);
UInt24 assignment (UInt24& a);
unsigned int size() const;
UInt24 add(UInt24& a) const;
UInt24 sub(UInt24& a) const;
UInt24 mup(UInt24& a) const;
UInt24 div(UInt24& a) const;
};
//
#endif
#ifndef _UINT32_H
#define _UINT32_H
//
class UInt32 : public UInt 
{
//
public:
//	UInt32();
//	UInt32(unsigned int a);
//	UInt32(UInt32& a);
UInt32 assignment (UInt32& a);
unsigned int size() const;
UInt32 add(UInt32& a) const;
UInt32 sub(UInt32& a) const;
UInt32 mup(UInt32& a) const;
UInt32 div(UInt32& a) const;
};
//
#endif
