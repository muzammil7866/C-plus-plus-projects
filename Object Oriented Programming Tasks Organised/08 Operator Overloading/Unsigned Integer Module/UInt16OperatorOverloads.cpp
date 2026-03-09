#include<iostream>
using namespace std;
#include "Task 3.h"

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


UInt UInt::operator +( UInt& rhs) const
{
	UInt temp;
	*temp.value = 0;
	*temp.value = *value + *rhs.value;
	status = SUCCESS;


	return temp;
}

UInt UInt::operator -( UInt& rhs) const
{
	UInt temp;
	*temp.value = 0;
	*temp.value = *value - *rhs.value;
	status = SUCCESS;

	return temp;
}

UInt UInt::operator *( UInt& rhs) const
{
	UInt temp;
	*temp.value = 0;
	*temp.value = *value * *rhs.value;
	status = SUCCESS;

	return temp;
}

UInt UInt::operator /( UInt& rhs) const
{
	UInt temp;
	*temp.value = 0;

	if (*rhs.value == 0)
	{
		status = FAILURE;
		cout << "DENOMINATOR COULD NOT BE ZERO!";

	}
	else
	{
		*temp.value = *value / *rhs.value;
		status = SUCCESS;
		return temp;
	}


}

UInt& UInt::operator = (const UInt& a)
{
	if (this != &a)
	{
		this->set(a.get());
	}
	return *this;
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

UInt8 UInt8::operator +( UInt8& rhs) const
{
	UInt8 temp;
	temp.set(this->get() + rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt8 UInt8::operator -( UInt8& rhs) const
{
	UInt8 temp;
	temp.set(this->get() - rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt8 UInt8::operator *( UInt8& rhs) const
{
	UInt8 temp;
	temp.set(this->get() * rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt8 UInt8::operator /( UInt8& rhs) const
{

	if (rhs.get() == 0)
	{
		rhs.setStatus(FAILURE);
		cout << "DENOMINATOR COULD NOT BE ZERO!";
	}
		
	else
	{
		UInt8 temp;
		temp.set(this->get() / rhs.get());
		rhs.setStatus(SUCCESS);

		return temp;
	}


}

UInt8& UInt8::operator = (const UInt8& a)
{
	if (this != &a)
	{
		this->set(a.get());
	}
	return *this;
}

UInt16 UInt16::operator +( UInt16& rhs) const
{
	UInt16 temp;
	temp.set(this->get() + rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt16 UInt16::operator -( UInt16& rhs) const
{
	UInt16 temp;
	temp.set(this->get() - rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt16 UInt16::operator *( UInt16& rhs) const
{
	UInt16 temp;
	temp.set(this->get() * rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt16 UInt16::operator /( UInt16& rhs) const
{

	if (rhs.get() == 0)
	{
		rhs.setStatus(FAILURE);
		cout << "DENOMINATOR COULD NOT BE ZERO!";
	}

	else
	{
		UInt16 temp;
		temp.set(this->get() / rhs.get());
		rhs.setStatus(SUCCESS);

		return temp;
	}


}

UInt16& UInt16::operator = (const UInt16& a)
{
	if (this != &a)
	{
		this->set(a.get());
	}
	return *this;
}

UInt24 UInt24::operator +( UInt24& rhs) const
{
	UInt24 temp;
	temp.set(this->get() + rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt24 UInt24::operator -( UInt24& rhs) const
{
	UInt24 temp;
	temp.set(this->get() - rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt24 UInt24::operator *( UInt24& rhs) const
{
	UInt24 temp;
	temp.set(this->get() * rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt24 UInt24::operator /( UInt24& rhs) const
{

	if (rhs.get() == 0)
	{
		rhs.setStatus(FAILURE);
		cout << "DENOMINATOR COULD NOT BE ZERO!";
	}

	else
	{
		UInt24 temp;
		temp.set(this->get() / rhs.get());
		rhs.setStatus(SUCCESS);

		return temp;
	}


}

UInt24& UInt24::operator = (const UInt24& a)
{
	if (this != &a)
	{
		this->set(a.get());
	}
	return *this;
}

UInt32 UInt32::operator +( UInt32& rhs) const
{
	UInt32 temp;
	temp.set(this->get() + rhs.get());
	rhs.setStatus(SUCCESS);



	return temp;
}

UInt32 UInt32::operator -( UInt32& rhs) const
{
	UInt32 temp;
	temp.set(this->get() - rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt32 UInt32::operator *( UInt32& rhs) const
{
	UInt32 temp;
	temp.set(this->get() * rhs.get());
	rhs.setStatus(SUCCESS);

	return temp;
}

UInt32 UInt32::operator /( UInt32& rhs) const
{

	if (rhs.get() == 0)
	{
		rhs.setStatus(FAILURE);
		cout << "DENOMINATOR COULD NOT BE ZERO!";
	}

	else
	{
		UInt32 temp;
		temp.set(this->get() / rhs.get());
		rhs.setStatus(SUCCESS);

		return temp;
	}

}

UInt32& UInt32::operator = (const UInt32& a)
{
	if (this != &a)
	{
		this->set(a.get());
	}
	return *this;
}

