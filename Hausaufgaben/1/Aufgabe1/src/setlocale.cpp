#include <clocale>  // für setlocale
#include <ctime>    // für time_t, struct tm, time, 
// strftime, localtime
#include <iostream>
using namespace std;

int main()
{
	// define rawtime and intit with cur time
	time_t rawtime = time(0);
	// define timeinfo tm struct 
	struct tm timeinfo;
	// fill tm struct with current time expressed for the local timezone
	localtime_s(&timeinfo, &rawtime);
	// init buffer
	char buffer[80] = {0};

	// Derzeitige Lokalitätseinstellungen augeben
	// print locale // minimal === c
	cout << "Locale ist: " << setlocale(LC_ALL,NULL) << endl;
	// format timeinfo into buffer via 	"Preferred date and time stamp based on locale" convention
	strftime(buffer, 80, "%c", &timeinfo);
	// print time
	cout << "Zeit: " << buffer;
	// print char test => not working since minimal
	cout << " Dies ist ein Test: üäöÜÖÄß. Ok?" << endl;

	// Lokalitätseinstellungen der installierten Umgebung aktivieren
	setlocale(LC_ALL, "");
	// print cur locale
	cout << "Locale ist: " << setlocale(LC_ALL,NULL) << endl;
	// format time via "Preferred date and time stamp based on locale" convention with current locale from env
	strftime(buffer, 80, "%c", &timeinfo);
	// print
	cout << "Zeit: " << buffer;
	// print test wortking since locale ===  English_United States.1252
	cout << " Dies ist ein Test: üäöÜÖÄß. Ok?" << endl;

	// Einzelne Lokalitätseinstellungen ändern
	// applies to time
	setlocale(LC_TIME, "kor");
	// This category applies to classification and conversion of characters, and to multibyte and wide characters
	setlocale(LC_CTYPE, "jpn");
	// print locale config kind of messed up now
	cout << "Locale ist: " << setlocale(LC_ALL,NULL) << endl;
	// put jpn time with kor char config into buffer
	strftime(buffer, 80, "%c", &timeinfo);
	// print buffer
	cout << "Zeit: " << buffer;
	// print not working text since kor 
	cout << " Dies ist ein Test: üäöÜÖÄß. Ok?" << endl;

	return 0;
}
