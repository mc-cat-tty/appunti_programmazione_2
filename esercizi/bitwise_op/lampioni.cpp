#include <iostream>

using namespace std;

typedef uint8_t lampioni_t;

static const int lampioni_size = sizeof(lampioni_t)*8;  // numero di bit della configurazione di lampioni
typedef enum {GUASTA, RIPARA} stato_t;

void stampa_lista(lampioni_t lamp) {
    for (int i=0; i<lampioni_size; i++) {
        if (lamp & (1<<i))
            cout << i << " ";
    }
    cout << endl;
}

void modifica_lampione(lampioni_t &lamp_array, int index, stato_t stato) {
    if (stato == GUASTA) {
        lamp_array &= ~(0x01 << index);
    }
    else if (stato == RIPARA) {
        lamp_array |= (0x01 << index);
    }
}

bool power_saving_check(lampioni_t &lamp_array) {
    lampioni_t even_mask = 0x00;
    for (int i=0; i<lampioni_size; i+=2) {
        even_mask |= (0x01 << i);
    }
    if ((lamp_array & even_mask) != even_mask)  // se alcuni dei lampioni pari sono spenti
        return false;
    lampioni_t odd_mask = ~even_mask;
    if ((lamp_array & odd_mask) != 0x00)  // se alcuni dei lampioni dispari sono accesi
        return false;
    return true;
}

void run_function(char choice, lampioni_t &lamp) {
    int index;
    bool res;
    switch (choice) {
        case 'G':
            cout << "Indice del lampione da guastare: "; cin >> index;
            modifica_lampione(lamp, index, GUASTA);
            break;
        case 'R':
            cout << "Indice del lampione da riparare: "; cin >> index;
            modifica_lampione(lamp, index, RIPARA);
            break;
        case 'L':
            stampa_lista(lamp);
            break;
        case 'K':
            res = power_saving_check(lamp);
            if (res)
                cout << "Risparmio energetico attivo" << endl;
            else
                cout << "Risparmio energetico disattivato" << endl;
            break;
        case 'T':
            exit(0);
            break;
        default:
            cout << "Comando non consentito" << endl;
            break;
    }
}

char menu() {
    char choice;
    cout
        << "G - guasta lampione" << endl
        << "R - ripara lampione" << endl
        << "L - lista lampioni funzionanti" << endl
        << "K - controlla risparmio energetico" << endl
        << "T - termina" << endl
        << ">> ";
    cin >> choice;
    return choice;
}

int main() {
    lampioni_t lampioni = ~0;  // tutti i lampioni sono funzionanti
    while (true) {
        char scelta = menu();
        run_function(scelta, lampioni);
    }
    return 0;
}