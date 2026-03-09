#include<iostream>
using namespace std;
#include "Task 2.h"

UInt::UInt()
{
value = new unsigned int;
	*value = 0;
}

UInt::UInt(unsigned int a)
{
value = new unsigned int;
	*value = a;
}

UInt::UInt(UInt& a)
{
value = new unsigned int;
	*value = *a.value;
}

void UInt::set(unsigned int a)
{
	*value = a;

}

void UInt::setStatus(OP_STATUS a)
{
status = a;
}


unsigned int UInt::get()const
{
return *value;
}

const char* UInt::checkStatus() const
{
const char temp[8] = "SUCCESS";
			
if (status == 1)
	{
		const char temp[8] = "FAILURE";
	}
	
return temp;

}

unsigned int UInt::size() const
{
return 4; //the original size of the unsigned integer is 4 thus returning 4 here
}


UInt UInt::add(UInt a) const
{
UInt temp;
	*temp.value = 0;
	*temp.value = *value + *a.value;
status = SUCCESS;

if (sizeof(*value + *a.value) > sizeof(unsigned int))
	status = FAILURE;

return temp;
}

UInt UInt::sub(UInt a) const
{
UInt temp;
	*temp.value = 0;
	*temp.value = *value - *a.value;
status = SUCCESS;

return temp;
}

UInt UInt::mup(UInt a) const
{
UInt temp;
	*temp.value = 0;
	*temp.value = *value * *a.value;
status = SUCCESS;

if (sizeof(*value * *a.value) > sizeof(unsigned int))
	status = FAILURE;

return temp;
}

UInt UInt::div(UInt a) const
{
UInt temp;
	*temp.value = 0;

if (*a.value == 0)
{
	status = FAILURE;
	cout << "DENOMINATOR COULD NOT BE ZERO!";

}
else
{
		*temp.value = *value / *a.value;
	status = SUCCESS;
	return temp;
}


}

unsigned int UInt8::size() const
{
return 8;
}

unsigned int UInt16::size() const
{
return 16;
}

unsigned int UInt24::size() const
{
return 24;
}

unsigned int UInt32::size() const
{
return 32;
}

UInt8::UInt8() : UInt::UInt() {}

UInt8::UInt8(unsigned int a) : UInt::UInt(a) {}

UInt8::UInt8(UInt8& a) 
{
UInt temp;
	temp.set(a.get());

	this->set(temp.get());
}

UInt16::UInt16() : UInt::UInt() {}

UInt16::UInt16(unsigned int a) : UInt::UInt(a) {}

UInt16::UInt16(UInt16& a)
{
UInt temp;
	temp.set(a.get());

	this->set(temp.get());
}

UInt24::UInt24() : UInt::UInt() {}

UInt24::UInt24(unsigned int a) : UInt::UInt(a) {}

UInt24::UInt24(UInt24& a)
{
UInt temp;
	temp.set(a.get());

	this->set(temp.get());
}

UInt32::UInt32() : UInt::UInt() {}

UInt32::UInt32(unsigned int a) : UInt::UInt(a) {}

UInt32::UInt32(UInt32& a)
{
UInt temp;
	temp.set(a.get());

	this->set(temp.get());
}

UInt8 UInt8::add(UInt8& a) const
{
UInt8 temp;
	temp.set(this->get() + a.get());
	a.setStatus(SUCCESS);

if (sizeof(this->get() + a.get()) > sizeof(unsigned int))
		a.setStatus(FAILURE);

return temp;
}

UInt8 UInt8::sub(UInt8& a) const
{
UInt8 temp;
	temp.set(this->get() - a.get());
	a.setStatus(SUCCESS);

return temp;
}

UInt8 UInt8::mup(UInt8& a) const
{
UInt8 temp;
	temp.set(this->get() * a.get());
	a.setStatus(SUCCESS);

if (sizeof(this->get() * a.get()) > sizeof(unsigned int))
		a.setStatus(FAILURE);

return temp;
}

UInt8 UInt8::div(UInt8& a) const
{

if (a.get() == 0)
{
		a.setStatus(FAILURE);
	cout << "DENOMINATOR COULD NOT BE ZERO!";
}
		
else
{
	UInt8 temp;
		temp.set(this->get() / a.get());
		a.setStatus(SUCCESS);

	return temp;
}


}

UInt16 UInt16::add(UInt16& a) const
{
UInt16 temp;
	temp.set(this->get() + a.get());
	a.setStatus(SUCCESS);

if (sizeof(this->get() + a.get()) > sizeof(unsigned int))
		a.setStatus(FAILURE);

return temp;
}

UInt16 UInt16::sub(UInt16& a) const
{
UInt16 temp;
	temp.set(this->get() - a.get());
	a.setStatus(SUCCESS);

return temp;
}

UInt16 UInt16::mup(UInt16& a) const
{
UInt16 temp;
	temp.set(this->get() * a.get());
	a.setStatus(SUCCESS);

if (sizeof(this->get() * a.get()) > sizeof(unsigned int))
		a.setStatus(FAILURE);

return temp;
}

UInt16 UInt16::div(UInt16& a) const
{

if (a.get() == 0)
{
		a.setStatus(FAILURE);
	cout << "DENOMINATOR COULD NOT BE ZERO!";
}

else
{
	UInt16 temp;
		temp.set(this->get() / a.get());
		a.setStatus(SUCCESS);

	return temp;
}


}

UInt24 UInt24::add(UInt24& a) const
{
UInt24 temp;
	temp.set(this->get() + a.get());
	a.setStatus(SUCCESS);

if (sizeof(this->get() + a.get()) > sizeof(unsigned int))
		a.setStatus(FAILURE);

return temp;
}

UInt24 UInt24::sub(UInt24& a) const
{
UInt24 temp;
	temp.set(this->get() - a.get());
	a.setStatus(SUCCESS);

return temp;
}

UInt24 UInt24::mup(UInt24& a) const
{
UInt24 temp;
	temp.set(this->get() * a.get());
	a.setStatus(SUCCESS);

if (sizeof(this->get() * a.get()) > sizeof(unsigned int))
		a.setStatus(FAILURE);

return temp;
}

UInt24 UInt24::div(UInt24& a) const
{

if (a.get() == 0)
{
		a.setStatus(FAILURE);
	cout << "DENOMINATOR COULD NOT BE ZERO!";
}

else
{
	UInt24 temp;
		temp.set(this->get() / a.get());
		a.setStatus(SUCCESS);

	return temp;
}


}

UInt32 UInt32::add(UInt32& a) const
{
UInt32 temp;
	temp.set(this->get() + a.get());
	a.setStatus(SUCCESS);

if (sizeof(this->get() + a.get()) > sizeof(unsigned int))
		a.setStatus(FAILURE);

return temp;
}

UInt32 UInt32::sub(UInt32& a) const
{
UInt32 temp;
	temp.set(this->get() - a.get());
	a.setStatus(SUCCESS);

return temp;
}

UInt32 UInt32::mup(UInt32& a) const
{
UInt32 temp;
	temp.set(this->get() * a.get());
	a.setStatus(SUCCESS);

if (sizeof(this->get() * a.get()) > sizeof(unsigned int))
			a.setStatus(FAILURE);

return temp;
}

UInt32 UInt32::div(UInt32& a) const
{

if (a.get() == 0)
{
		a.setStatus(FAILURE);
	cout << "DENOMINATOR COULD NOT BE ZERO!";
}

else
{
	UInt32 temp;
		temp.set(this->get() / a.get());
		a.setStatus(SUCCESS);

	return temp;
}


}

UInt UInt::assignment (UInt& a)
{
	UInt temp;
		temp.set(a.get());

	return temp;
}

UInt8 UInt8::assignment (UInt8& a)
{
	UInt8 temp;
		temp.set(a.get());

	return temp;
}

UInt16 UInt16::assignment (UInt16& a)
{
	UInt16 temp;
		temp.set(a.get());

	return temp;
}

UInt24 UInt24::assignment (UInt24& a)
{
	UInt24 temp;
		temp.set(a.get());

	return temp;
}

UInt32 UInt32::assignment (UInt32& a)
{
	UInt32 temp;
		temp.set(a.get());

	return temp;
}
