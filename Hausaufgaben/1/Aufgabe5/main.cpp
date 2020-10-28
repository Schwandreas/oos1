// Vergleich von Deklaration, Enumeration und Typumwandlung 
// in C und C++

// Fehler                                               C    |  C++
//enum class enumeration { 1st, 2nd, 3rd, 4th };				// Z1      n     | n 
//enum class marks { '1', '2', '3', '4', '5', '6' };			// Z2      n     | n
#include <type_traits>

enum class class1 { DIETER, HANS, PETER, KAI };				// Z3          y |y
enum class class2 { ANDREA, KAI, SABINE, ZOE };				//  n   | n
enum class sports { FUSSBALL, BASKETBALL, HOCKEY };			// Z5           y|y


sports operator++(sports& x) {
	return x = static_cast<sports>(static_cast<std::underlying_type<sports>::type>(x) + 1);
}

sports operator+(const sports& x, const int& i) {
	return static_cast<sports>(static_cast<std::underlying_type<sports>::type>(x) + i);
}

sports operator*(sports c) {
	return c;
}

sports begin(sports r) {
	return sports::FUSSBALL;
}

sports end(sports r) {
	sports l = sports::HOCKEY;
	return ++l;
}


int main(void) // Z7           |
{
	sports i;       // Z8           y|y
	sports mysport; // Z9           y| n
	//enum sports mysport;
	mysport = sports::FUSSBALL; // Z11          y|y
	mysport = sports(4);										// Z13          n|y
	// Z10         y |y 
	mysport = sports::FUSSBALL; // Z11          y|y
	mysport = sports::FUSSBALL + 1;							// Z12          n|y
	mysport = sports(1);										// Z13          n|y
	mysport = sports(10);										// Z14         n |y
	mysport = mysport + 1;							// Z15         n |y
	mysport = sports(mysport + 1);           // Z16          y| n
	float f;
	sports mysport2; // Z9           y| n
	// Z17          y| y
	for (const auto& c : sports())		// Z18        y  |y
		mysport2 = c;                          // Z19         y | n
	return 0;                                // Z22          y|y
}

