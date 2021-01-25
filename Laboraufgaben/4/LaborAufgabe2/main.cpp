#include <iostream>
#include <string>
using namespace std;

class A {
public:
	void f() {
		cout << "A::f()" << endl;
	}
	void g(double d) {
		cout << "A::g(double)" << endl;
	}
	void g(string s) {
		cout << "A::g(string)" << endl;
	}
	void h(char c) {
		cout << "A::h(char)" << endl;
	}
	void h(string s) {
		cout << "A::h(string)" << endl;
	}
};

class B : public A {
public:
	void g(int i) {
		cout << "B::g(int)" << endl;
	}
	void h(int i) {
		cout << "B::h(int)" << endl;
	}
	void h(string s) {
		cout << "B::h(string)" << endl;
	}
};

int main() {
	A a;
	B b;
	cout << "a.f() ";
	a.f();
	cout << "b.f() ";
	b.f();
	cout << "a.g(1.2) ";
	a.g(1.2);
	cout << "b.g(1.2) ";
	b.g(1.2); // Überdeckt A::g(double d) 'double' to 'int' conversion
	cout << "a.g(1) ";
	a.g(1);
	cout << "b.g(1) ";
	b.g(1);   //Überdeckt A::g(double d)
	cout << "a.g('a') ";
	a.g('a');
	cout << "b.g('a') ";
	b.g('a'); //Überdeckt A::g(double d) 'char' to 'int' conversion ( a = 97 )
	cout << "a.g(\"a\") ";
	a.g("a"); //Überdeckt A::g(string) not assignable
	//cout << "b.g(\"a\") ";
	// b.g("a");
	cout << "a.h(1) ";
	a.h(1);
	cout << "b.h(1) ";
	b.h(1);   //Redefiniert A::h(string)
	cout << "a.h('a') ";
	a.h('a'); //
	cout << "b.h('a') ";
	b.h('a'); //Überdeckt A::h(char)
	cout << "a.h(\"a\") ";
	a.h("a"); //
	cout << "b.h(\"a\") ";
	b.h("a"); //Redefiniert A::h(string)
	return 0;
}

