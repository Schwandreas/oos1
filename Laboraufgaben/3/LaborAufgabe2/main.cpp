#include <iostream>

#include "../../../OOS1Lib/MyString.cpp"
using namespace std;
int main() {
	const MyString cs("Ein konstanter String");
	MyString s(cs);
	s.assign(cs);
	s.append(cs);
	std::cout << cs.c_str() << endl;
	cout << cs.size() << endl;
	cout << cs.capacity() << endl;
	cout << boolalpha << cs.empty() << endl;
	s = cs + cs;
	cout << (cs == cs) << endl;
	s = cs;
	cout << cs << endl;
	s.at(1) = 'X';
	s[2] = 'Y';
	cout << s << endl;
	return 0;
}
