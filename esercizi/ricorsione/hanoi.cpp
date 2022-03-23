#include <iostream>

using namespace std;

int mosse_count = 0;  // ~2^n mosse

/**
 * @brief sposta l'unico disco che si trova sul piolo_s sul piolo_d
 */
void sposta_disco(char piolo_s, char piolo_d) {
    mosse_count++;
    cout << "Sposta disco da " << piolo_s << " a " << piolo_d << endl;
}

/**
 * @brief soluzione ricorsiva al problema della torre di Hanoi
 * 
 * @param n numero pioli
 * @param piolo_s piolo sorgente
 * @param piolo_d piolo destinazione
 * @param piolo_a piolo appoggio
 */
void hanoi(int n, char piolo_s, char piolo_d, char piolo_a) {
    if (n == 1) {  // caso base
        sposta_disco(piolo_s, piolo_d);
        return;
    }

    hanoi(n-1, piolo_s, piolo_a, piolo_d);
    sposta_disco(piolo_s, piolo_d);
    hanoi(n-1, piolo_a, piolo_d, piolo_s);
}

int main() {
    int num;
    cout << "Numero dischi: "; cin >> num;
    hanoi(num, 'A', 'B', 'C');
    cout << "Contatore di mosse: " << mosse_count << endl;
    return 0;
}