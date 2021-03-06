#include "MyString.hpp"


#include <iostream>

using namespace std;

void MyString::initStrPtrWithNullSym() const
{
	for (unsigned i = strSize; i < strCapacity + 1; ++i)
	{
		strPtr[i] = '\0';
	}
}

MyString::MyString()
	: strPtr{nullptr}
{
	strCapacity = 10;
	strPtr      = new char[strCapacity + 1];
	strSize     = 0;
	initStrPtrWithNullSym();
}

MyString::MyString(const char* val)
{
	if (val == nullptr)
	{
		strCapacity = 10;
		strPtr      = new char[strCapacity + 1];
		strSize     = 0;
		initStrPtrWithNullSym();
	}

	else
	{
		strSize     = strlen(val);
		strCapacity = strSize;
		strPtr      = new char[strCapacity + 1];

		strcpy_s(strPtr, strCapacity + 1, val);
	}
}

MyString::MyString(const MyString& source)
{
	const unsigned size = source.strSize + 1;
	strPtr              = new char[size];
	strcpy_s(strPtr, size, source.strPtr);

	strCapacity = source.strCapacity;
	strSize     = source.strSize;
}

MyString::MyString(MyString&& source)
{
	strPtr         = source.strPtr;
	strCapacity    = source.strCapacity;
	strSize        = source.strSize;
	source.strPtr  = nullptr;
	source.strSize = 0;
}

void MyString::reserve(unsigned int c)
{
	if (strCapacity >= c)
	{
		return;
	}

	const auto ptr = static_cast<char*>(realloc(strPtr, c + 1));
	if (!strPtr)
	{
		cout << "realloc failed, the original pointer needs to be freed - bye, bye";
		free(strPtr);
	}
	strPtr = ptr;
	strCapacity = c;
}

MyString& MyString::append(MyString& str)
{
	const unsigned oldSize = this->strSize;
	const unsigned newSize = str.size() + this->strSize;
	if (newSize > this->strCapacity)
	{
		this->reserve(newSize);
	}

	for (unsigned i = oldSize; i < newSize; ++i)
	{
		char x    = str.at(i - oldSize);
		strPtr[i] = x;
	}
	strPtr[newSize] = '\0';
	strSize         = newSize;
	return *this;
}

MyString& MyString::append(const MyString& str)
{
	const unsigned oldSize = this->strSize;
	const unsigned newSize = str.strSize + this->strSize;
	if (newSize > this->strCapacity)
	{
		this->reserve(newSize);
	}

	for (unsigned i = oldSize; i < newSize; ++i)
	{
		strPtr[i] = str.strPtr[i - oldSize];
	}
	strPtr[newSize] = '\0';
	strSize         = newSize;
	return *this;
}

MyString& MyString::assign(const MyString& str)
{
	delete strPtr;

	const unsigned size = str.strSize + 1;
	strPtr              = new char[size];
	strcpy_s(strPtr, size, str.strPtr);

	strCapacity = str.strCapacity;
	strSize     = str.strSize;

	return *this;
}

const char* MyString::c_str() const
{
	return strPtr;
}

unsigned MyString::size() const
{
	return strSize;
}

unsigned MyString::capacity() const
{
	return strCapacity;
}

void MyString::clear()
{
	delete strPtr;
	strPtr    = new char[11];
	strSize   = 0;
	strPtr[0] = '\0';
}

bool MyString::empty() const
{
	if (strSize == 0)
	{
		return true;
	}

	bool onlyNull = true;
	for (unsigned i = 0; i < strSize; ++i)
	{
		onlyNull &= strPtr[i] == '\0';
		if (!onlyNull)
		{
			break;
		}
	}
	return onlyNull;
}


char& MyString::at(unsigned i)
{
	if (strCapacity == 0 || i > strCapacity)
	{
		return strPtr[strSize];
	}
	return strPtr[i];
}

MyString::~MyString()
{
	delete[] strPtr;
}


MyString MyString::operator+(const MyString& mys) const {
	MyString str(*this);
	str.append(mys);
	return str;
}

char& MyString::operator[](int i) {
	return at((unsigned int)i);
}

bool MyString::operator==(const MyString& rhs) const {
	return strcmp(c_str(), rhs.c_str()) == 0;
}

MyString& MyString::operator=(const MyString& mys) {
	if(this != & mys)
	{
		assign(mys);
	}
	return *this;
}

ostream& operator<<(std::ostream& os, const MyString& string) {
	return os << string.c_str();
}