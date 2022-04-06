#pragma once

const int STR_DIM = 51;

struct elem {
       char inf[STR_DIM] ;
       elem* pun ;
       elem* prev;
};

typedef elem* lista ;
char* head(lista);
elem* search(lista, char*);
elem* new_elem(char *);
lista cancella(lista, char*);