#include <clocale>  // für setlocale
#include <ctime>    // für time_t, struct tm, time, 
// strftime, localtime
#include <iostream>
using namespace std;

int main()
{
	// define rawtime
	time_t rawtime;
	// define timeinfo pointer
	struct tm* timeinfo;
	// set rawtime to cur time
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	char buffer[80] = {0};

	// Derzeitige Lokalitätseinstellungen augeben
	cout << "Locale ist: " << setlocale(LC_ALL,NULL) << endl;
	strftime(buffer, 80, "%c", timeinfo);
	cout << "Zeit: " << buffer;
	cout << " Dies ist ein Test: üäöÜÖÄß. Ok?" << endl;

	// Lokalitätseinstellungen der installierten Umgebung aktivieren
	setlocale(LC_ALL, "");
	cout << "Locale ist: " << setlocale(LC_ALL,NULL) << endl;
	strftime(buffer, 80, "%c", timeinfo);
	cout << "Zeit: " << buffer;
	cout << " Dies ist ein Test: üäöÜÖÄß. Ok?" << endl;

	// Einzelne Lokalitätseinstellungen ändern
	setlocale(LC_TIME, "kor");
	setlocale(LC_CTYPE, "jpn");
	cout << "Locale ist: " << setlocale(LC_ALL,NULL) << endl;
	strftime(buffer, 80, "%c", timeinfo);
	cout << "Zeit: " << buffer;
	cout << " Dies ist ein Test: üäöÜÖÄß. Ok?" << endl;

	return 0;
}
