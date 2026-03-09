#include<iostream>
#include "UInt16.h"
using namespace std;
//
//	UInt16::UInt16()
{
	value = new unsigned int;
//		*value = 0;
}
//
//	UInt16::UInt16(unsigned int a)
{
	value = new unsigned int;
//		*value = a;
}
//
//	UInt16::UInt16(UInt16& a)
{
	value = new unsigned int;
//		*value = *a.value;
}
//
//	UInt16 UInt16::assignment (UInt16& a)
{
	UInt16 temp;
//		*temp.value = *a.value;
//
	return temp;
}
//
//	void UInt16::set(unsigned int a)
{
//		*value = a;
//
}
//
//
//	unsigned int UInt16::get()const
{
	return *value;
}
//
const char* UInt16::checkStatus() const
{
	const char temp[8] = "SUCCESS";
//
	if (status == 1)
	{
		const char temp[8] = "FAILURE";
	}
//
	return temp;
}
//
//	unsigned int UInt16::size() const
{
	return 16;
}
//
//	UInt16 UInt16::add(UInt16 a) const
{
	UInt16 temp;
//		*temp.value = 0;
//		*temp.value = *value + *a.value;
	status = SUCCESS;
//
//		//checks overflow of addition
	if (sizeof(*value + *a.value) > sizeof(unsigned int))
		status = FAILURE;
//
	return temp;
}
//	UInt16 UInt16::sub(UInt16 a) const
{
	UInt16 temp;
//		*temp.value = 0;
//		*temp.value = *value - *a.value;
	status = SUCCESS;
//
	return temp;
}
//	UInt16 UInt16::mup(UInt16 a) const
{
	UInt16 temp;
//		*temp.value = 0;
//		*temp.value = *value * *a.value;
	status = SUCCESS;
// 
//		//checks overflow of multiplication
if (sizeof(*value * *a.value) > sizeof(unsigned int))
		status = FAILURE;
//
	return temp;
}
//	UInt16 UInt16::div(UInt16 a) const
{
	UInt16 temp;
//		*temp.value = 0;
//
	if (*a.value == 0)
		status = FAILURE;
	else
//
//			//checks failure of status due to denominator = 0
	{
//			*temp.value = *value / *a.value;
		status = SUCCESS;
		return temp;
	}
//
//		
}
