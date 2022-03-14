#include <iostream>

using namespace std ;

void f(int i, int *p, int &ri, int *&rp) {

	int *q = new int ;
	
	i = 10 ;	// nuovo valore dell'argomento i
	p = q ;	 	// nuovo valore dell'argomento p
	*p = 10 ;	// nuovo valore dell'oggetto puntato da p
	ri = 10 ; 	// nuovo valore dell'oggetto di nome (sinonimo) ri
	rp = q ;    // nuovo valore dell'oggetto di nome (sinonimo) rp
	*rp = 30;	// nuovo valore dell'oggetto puntato dal puntatore
		        // di nome (sinonimo) rp
}

int main()
{
	int a = 20, b=15, c=12, d=8;

	int *punt;
	punt = &b;

	int *prp;
	prp = &d;

	f(a, punt, c, prp);
	cout << a << " " << *punt << " " << c << " " << *prp << " " << endl;
    // 20 15 10 30
}