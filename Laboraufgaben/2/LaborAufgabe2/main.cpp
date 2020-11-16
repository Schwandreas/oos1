#include <iostream>
using namespace std;

class fifoMem {
	int maxSize;
	int number,wPos,rPos;
	char cArr[];
	unique_ptr<char> ptr = cArr;
public:
	fifoMem(int maxSize = 20) {
		this->maxSize = maxSize;
		this->number = 0;
		this->wPos = 0;
		this->rPos = 0;
		this->cArr[maxSize];
	};
	int push(char c) {
		ptr[wPos] = c;	//char in cArr mit index wPos speichern
		wPos++;
		number++;		//+1 gespeichertes Element
	};

	int pop() {
		cout << fifoMem->cArr[rPos]<< endl;		//ausgegebenes char an des cArr an der Stelle rPos
		cArr[rPos] = clear;						//speicher freigeben
		rPos++;
		number--;								//bei erfolgreicher Ausgabe Anzahl -1 gespeicherter Elem.
	};

	void isEmpty() {
		//(wPos == rPos) ? return 1; : return 0;
		if (wPos == rPos) return 1; : return 0;
	};

	void isFull() {
		if (wPos + 1 == rPos || rPos == 0 && wPos + 1 == maxSize) return 1; : return 0;
	};

	void getWPos() {
		cout << "Die aktuell schreibende Position ist " << fifoMem.wPos << "." << endl;
	};
	void getRPos() {
		cout << "Die aktuell lesende Position ist " << fifoMem.rPos << "." << endl;
	};
};

unique_ptr<fifoMem> builder(int size = 20) {
	fifoMem->maxSize = size;
	fifoMem->cArr[maxSize];
	fifoMem->number = 0;
	fifoMem->wPos = 0;
	fifoMem->rPos = wPos;
	return make_unique<fifoMem> cArr;
}



int main() {
	fifoMem();
}