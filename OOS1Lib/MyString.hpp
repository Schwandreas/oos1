#ifndef OOS1LIB_MYSTRING
#define OOS1LIB_MYSTRING
#include <string>

class MyString
{
private:
	char*        strPtr;
	unsigned int strSize;
	unsigned int strCapacity;
	void initStrPtrWithNullSym() const;
public:
	MyString();

	MyString(const char* val);

	MyString(const MyString& source);

	MyString(MyString&& source);

	~MyString();
	MyString  operator+(const MyString& mys) const;
	char&     operator[](int i);
	bool      operator==(const MyString& rhs) const;
	MyString& operator=(const MyString& mys);
	friend std::ostream& operator<<(std::ostream& os, const MyString& string);
	
	void         reserve(unsigned int c);
	MyString&    append(MyString& str);
	MyString&    append(const MyString& str);
	MyString&    assign(const MyString& str);
	const char*  c_str() const;
	unsigned int size();
	unsigned int capacity();
	void         clear();
	bool         empty();
	char&        at(unsigned i);
};
#endif
