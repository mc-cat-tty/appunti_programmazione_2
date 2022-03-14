/*
 * memoria.cpp
 *
 *  Created on: 28 Feb 2020
 *      Author: lbedogni
 */

#include <iostream>

using namespace std;

// Esercizio
/* Non si puo cambiare il tipo di ritorno di miafunzione
 * Occorre visualizzare il valore 5 nella stampa finale
 */
// void miafunzione(int var) {
// 	var = 5;
// }

// int main() {
// 	int miaVariabile;
// 	miafunzione(miaVariabile);
// 	cout << miaVariabile << endl;
// }



// SOLUZIONE
void miafunzione(int& var) {
	var = 5;
}

int main() {
	int miaVariabile;
	miafunzione(miaVariabile);
	cout << miaVariabile << endl;
}

