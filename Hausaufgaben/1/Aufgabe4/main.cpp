// Vergleich von Deklaration, Enumeration und Typumwandlung 
// in C und C++

// Fehler                                               C    |  C++
//enum enumeration { 1st, 2nd, 3rd, 4th };				// Z1      n     | n 
//enum marks { '1', '2', '3', '4', '5', '6' };			// Z2      n     | n
enum class1 { DIETER, HANS, PETER, KAI };				// Z3          y |y
//enum class2 { ANDREA, KAI, SABINE, ZOE };				//  n   | n
enum sports { FUSSBALL, BASKETBALL, HOCKEY };			// Z5           y|y

int main(void)											// Z7           |
{
	int i;												// Z8           y|y
sports mysport;											// Z9           y| n
//enum sports mysport;									// Z10         y |y 
	mysport = FUSSBALL;									// Z11          y|y
	// mysport = FUSSBALL + 1;							// Z12          n|y
	// mysport = 1;										// Z13          n|y
// mysport = 10;										// Z14         n |y
	// mysport = mysport + 1;							// Z15         n |y
	mysport = sports(mysport + 1);           // Z16          y| n
	float f;                                 // Z17          y| y
	for (i = FUSSBALL; i <= HOCKEY; i++)     // Z18        y  |y
		mysport = sports(i);                 // Z19         y | n
	for (int k = FUSSBALL; k <= HOCKEY; k++) // Z20          y| y
		mysport = sports(k);                 // Z21          y| n
	return 0;                                // Z22          y|y
}

