/*
 * stampaNumeriPari.cpp
 *
 *  Created on: 26 Feb 2020
 *      Author: lbedogni
 */

#include <iostream>
#include <math.h>
using namespace std;

// double pow(double numero, int esponente) { // @suppress("No return")
// 	while (esponente > 0) {
// 		numero = numero * numero;
// 		esponente--;
// 	}
// 	// SOL: return numero;
// }

// int main() {
// 	double numeroDiPartenza;
// 	cout << "Inserisci il numero di partenza: ";
// 	cin >> numeroDiPartenza;

// 	while (numeroDiPartenza != 1) {  // SOL: numeroDiPartenza <= 1
// 		double potenza = pow(numeroDiPartenza,3);
// 		cout << numeroDiPartenza << " : " << potenza << endl;
// 		numeroDiPartenza--;
// 	}
// }

// SOLUZIONE
double pow(double numero, int esponente) { // @suppress("No return")
	int res = 1;
	while (esponente > 0) {
		res *= numero;
		esponente--;
	}
	return res;
}

int main() {
	double numeroDiPartenza;
	cout << "Inserisci il numero di partenza: ";
	cin >> numeroDiPartenza;

	while (numeroDiPartenza >= 1) {
		double potenza = pow(numeroDiPartenza, 3);
		cout << numeroDiPartenza << " : " << potenza << endl;
		numeroDiPartenza--;
	}
}
