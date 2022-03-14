//============================================================================
// Name        : calcola_meta.cpp
// Author      : Luca Bedogni
// Version     :
// Copyright   : Luca Bedogni
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// int calcolaMeta(double valore) {
// 	return valore / 2;
// }

// int main() {
// 	double valore;
// 	cout << "Inserisci un valore: ";
// 	cin >> valore;
// 	double resto = calcolaMeta(valore);
// 	cout << "La meta del numero e': " << resto << endl;
// 	return 0;
// }

// SOLUZIONE
double calcolaMeta(double valore) {
	return valore / 2;
}

int main() {
	double valore;
	cout << "Inserisci un valore: ";
	cin >> valore;
	double resto = calcolaMeta(valore);
	cout << "La meta del numero e': " << resto << endl;
	return 0;
}