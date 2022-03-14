#include <iostream>

using namespace std ;

void fun(int& b) {
	/* DOMANDA: quali variabili vedi ora? */
    int c = 3, a = 5 ;
	b=c+a;
}

int main()
{
    int a;
/* DOMANDA: qual è il valore di a */
    cin>>a ;

/* Osserva l'evoluzione dei valori di b */
    int b[3] = {1, 5, 2} ;

    int i;
    for(i=0;i<3;i++)
    	cout<<b[i]<<endl;


    fun(b[1]);

 /* DOMANDA: quali variabili del main sono cambiate e perché?*/

    return 0 ;
}
