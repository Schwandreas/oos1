#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

const double pi = acos(-1);

void trapezFlaeche(double sideA, double sideB, double sideC, double deg) {
    double rad = deg * 2 * pi / 360;
    double height = sideB * sin(rad);
    double flaeche = .5 * (sideA + sideC) * height;
    cout << "Flaeche: " << flaeche << endl;
}

//Quadrat
void trapezFlaeche(double sideA) {
    trapezFlaeche(sideA, sideA, sideA, 90);
}

//Rechteck
void trapezFlaeche(double sideA, double sideB) {
    trapezFlaeche(sideA, sideB, sideA, 90);
}


void trapezFlaeche(double sideA, double sideB, double deg) {
    trapezFlaeche(sideA, sideB, sideA, deg);
}

int main() {
    trapezFlaeche(2, 3.5, 4, 45);
    trapezFlaeche(3., 4., 45.);
    trapezFlaeche(4., 5.);
    trapezFlaeche(2.);

    getchar();
}

