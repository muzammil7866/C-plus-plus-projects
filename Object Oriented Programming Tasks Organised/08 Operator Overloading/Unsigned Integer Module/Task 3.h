#ifndef _UINT_H
#define _UINT_H
#include<iostream>
using namespace std;


enum OP_STATUS
{
	SUCCESS = 0, FAILURE = 1
};

class UInt
{
private:
	
		unsigned int* value;
		static OP_STATUS status;

public:

		UInt();
		UInt(unsigned int a);
		UInt(UInt& a);
		void set(unsigned int a);
		void setStatus(OP_STATUS a);
		unsigned int get() const;
		const char* checkStatus() const;
		unsigned int size() const;		
		UInt operator +( UInt& rhs) const;
		UInt operator -( UInt& rhs) const;
		UInt operator *( UInt& rhs) const;
		UInt operator /( UInt& rhs) const;
		UInt& operator =(const UInt& rhs);
		
};

#endif
#ifndef _UINT8_H
#define _UINT8_H

class UInt8 : public UInt 
{

public:
	UInt8();
	UInt8(unsigned int a);
	UInt8(UInt8& a);
	unsigned int size() const;
	UInt8 operator +( UInt8& rhs) const;
	UInt8 operator -( UInt8& rhs) const;
	UInt8 operator *( UInt8& rhs) const;
	UInt8 operator /( UInt8& rhs) const;
	UInt8& operator =(const UInt8& rhs);
};

#endif
#ifndef _UINT16_H
#define _UINT16_H

class UInt16 : public UInt 
{

public:
	UInt16();
	UInt16(unsigned int a);
	UInt16(UInt16& a);
	unsigned int size() const;
	UInt16 operator +( UInt16& rhs) const;
	UInt16 operator -( UInt16& rhs) const;
	UInt16 operator *( UInt16& rhs) const;
	UInt16 operator /( UInt16& rhs) const;
	UInt16& operator =(const UInt16& rhs);
};

#endif
#ifndef _UINT24_H
#define _UINT24_H

class UInt24 : public UInt 
{

public:
	UInt24();
	UInt24(unsigned int a);
	UInt24(UInt24& a);
	unsigned int size() const;
	UInt24 operator +( UInt24& rhs) const;
	UInt24 operator -( UInt24& rhs) const;
	UInt24 operator *( UInt24& rhs) const;
	UInt24 operator /( UInt24& rhs) const;
	UInt24& operator =(const UInt24& rhs);
};

#endif
#ifndef _UINT32_H
#define _UINT32_H

class UInt32 : public UInt 
{

public:
	UInt32();
	UInt32(unsigned int a);
	UInt32(UInt32& a);
	unsigned int size() const;
	UInt32 operator +( UInt32& rhs) const;
	UInt32 operator -( UInt32& rhs) const;
	UInt32 operator *( UInt32& rhs) const;
	UInt32 operator /( UInt32& rhs) const;
	UInt32& operator =(const UInt32& rhs);
};

#endif
