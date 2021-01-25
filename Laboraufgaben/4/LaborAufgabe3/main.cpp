#include <iostream>
#include <string>
using namespace std;

// Name s und Wert val einer Instanzvariable ausgeben
void speicherzelle(string s, int val) {
	cout << "---------------------" << endl;
	cout << s << "= " << val << endl;
}

// Die Instanzvariablen raussuchen und ausgeben,
// die wegen virtuellen Basisklassen zusammenfallen
void suche(string s[], int* vptr[], int n) {
	// Zustand von cout zwischenspeichern
	ios::fmtflags cflags = cout.flags();
	// Hilfsvariablen initialisieren
	int i = 0;
	int k = 0;
	string str = "";
	// cout für Ausgabe der Instanzvariablen konfigurieren
	cout << hex << uppercase;
	// Schauen, ob Instanzvariable i (vptr[i])
	// evtl. mit Variable k (vptr[k]) zusammenfällt
	while (i < n) {
		// Wenn Variable i+k und i+k+1 identisch ...
		if ((i + k < n - 1) && (vptr[i + k] == vptr[i + k + 1])) {
			// erhöhe k
			k++;
		}
		else {
			// andernfalls gib die zusammengefallenen Variablen
			// auf einer Zeile aus
				// Text für Ausgabe zusammenstellen
			for (int m = i; m <= i + k; m++) {
				str += s[m] + " ";
			}
			// Text und Wert ausgeben
			speicherzelle(str, *vptr[i]);
			// Hilfsvariablen für nächste Prüfung zurücksetzen
			str = "";
			i += k + 1;
			k = 0;
		}
	}
	cout << "---------------------" << endl << endl;
	// Ursprünglicher Zustand von cout wieder herstellen
	cout.flags(cflags);
}

// Klassenhierarchie
class A {
public:
	int a;
	A(int a = 0xA) : a(a) {}
};

class B : public virtual A {
public:
	int b;
	B(int a = 0xBA, int b = 0xB) : A(a), b(b) {}
};

class C1 : public virtual B {
public:
	C1(int a = 0xC1A, int b = 0xC1B)
		: A(a), B(a, b) {}
};

class C2 : public virtual B {
public:
	C2(int a = 0xC2A, int b = 0xC2B)
		: A(a), B(a, b) {}
};

class C3 : public B {
public:
	C3(int a = 0xC2A, int b = 0xC2B)
		:B(a, b) {}
};

class D1 : public C1, public C2 {
public:
	D1(int C1_a = 0xD1C1A, int C2_a = 0xD1C2A,
		int C1_b = 0xD1C1B, int C2_b = 0xD1C2B)
		: A(0xD1A), B(b), C1(C1_a, C1_b), C2(C2_a, C2_b) {}
	void print() {
		cout << "D1::print() ..." << endl;
		string strArr[] =
		{ "C1::a", "C2::a", "C1::b", "C2::b" };
		int* intPtrArr[] = { &(C1::a), &(C2::a),
							  &(C1::b), &(C2::b) };
		suche(strArr, intPtrArr, 4);
	}
};

class D2 : public C1, public C2, public C3 {
public:
	D2(int C1_a = 0xD2C1A, int C2_a = 0xD2C2A, int C3_a = 0xD2C3A,
		int C1_b = 0xD2C1B, int C2_b = 0xD2C2B, int C3_b = 0xD2C3B)
		: B(a, 0xD2B), C1(C1_a, C1_b), C2(C2_a, C2_b), C3(C3_a, C3_b) {}
	void print() {
		cout << "D2::print() ..." << endl;
		string strArr[] = { "C1::a", "C2::a", "C3::a",
							"C1::b", "C2::b", "C3::b" };
		int* intPtrArr[] = { &(C1::a), &(C2::a), &(C3::a),
							  &(C1::b), &(C2::b), &(C3::b) };
		suche(strArr, intPtrArr, 6);
	}
};

// does not work on my machine or in visual studio idk why...  https://tio.run/##lVXbjuJGEH3GX1Ei0sgMHjY2UR64rIThIVGkaKVcVtoIRW27gQ6msbptZsSIv9lvyNO@8WGTqm5fuEXsjsR0d3XVqcupasdZ9rSM47e374SM0yLhMBJbnSvONu@dRoYSIZfvnULjApJtuM5YzEHnydBx3r2DX1EEGgqZwEeuctixFLiQXMHPUudM7ndMCRalHFihlzzi0tltRQI64yJecbXnacpd6wa0B0IajA68Oq14W@QwGkH76dZfm664TNJho6mN@hjMHYVSqxxMtDPBL@OSoDAyXWAw0qRRxemRQYIGz3yJVzuh8oKClRAyLfQ6ZVrjYV9ottlwuWB0VyZHaHVSf81NWo@wy3JVHkCaDNHDp4LCSWC3lWDS2D8LTcFUFZJOC5kZDBabfJGypYbYLmOj3jMHtzM0YD@JdKGbzIQUuWCp0IIrTjjoWKDh90O7X5f7KtJcoaDdtlgmmMXxi4IJVoRFHJJrViWst3IhloUqXVRMrPgLLUWWcRUzzS3mb/GKFVha2EZX/SHANQUS847R5bs87cFG5PBnpbIuVdbzTlP34@c0zZ3W80qghitgVNaWMD5yKRtz0V0bhnHt@iASLnMqNfR6PVQXC3DRvIteEAKewO/Aw0MVFMnnMB5Dc8SfP@9YXyZgtTr@u8Io6bzudjHl1gF/PNW8VkKqkVJqFg1LEZkGq1JZcttEvIlZVmbFohyrT1zYYaIbuvqdv1zwVOHp3PQrKS62CmuDlG@QYTHEZYQrZYH7brdMghoBumNs2c0c79pArWCTqD3Vk17PM9ldTrMHjxWZw9L6ojdNxPL4OV5hmPBBHb8sCuzBfYG7eK15vi@hm6ZEjig6U3hzrPqXIjx89Xtx8m5gWH8onaFLuUxNBtfz@Cw4NT7e1fU8GTw7jJ3qgfnFvgornAamYlycmCQwwQJnRYQ@Bnb0GHqfGEYYJfEy6cAAmMuQiYNzwLfV2oUotXb2AcIn7QoqQqjwBCqc2CcmsicCniCwB5EbXcBP/Wv88BR/6p8AT/0z5Kkf4qS2KvTQZeji0kFwz0Fw6iA4dxB8hYN@4@AcuH8f@Cbi7KQmU9@rt8Ep@szWZer/bR3M/Lo406CRoVt6WaxmVGuGtWYta1Kl48SkG@F/JICceAaAzoFLDjxjbCJvmU9Ohi947to5rudg5g8G1QU@cqdfzJM3f6LwqwRjlL1Ce4omrO3hJqg2KIkqSdSGw9Cm9Eg5fKjN4RUeXGONUeIuMDvzquAflJdRfYnBG6T6W4k4XgPpwQ/0cpwRE/wPMc22f8ZRcMFRcIOjoG6Nab@R9W/wFtzgDa3D2rqW9UsuTXuRJLxLJC59lyLwDNJdYoNvIBZu09o3m4qgS5pLjW/lm3b9u8xXand74MemB8zHiwlpS4FDmvjb6J8h0QxJYLdG1CsLQ@fg/Kx4XihJn4yD8/b2Hw
int main() {
	D1 d1obj;
	D2 d2obj;
	d1obj.print();
	d2obj.print();
	return 0;
}
