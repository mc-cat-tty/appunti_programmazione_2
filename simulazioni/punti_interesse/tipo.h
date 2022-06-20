#pragma once

const int NOME_MAX_DIM = 21;

struct place {
	int id;
	char nome[NOME_MAX_DIM];
	char tipo;
};

typedef place tipo_inf;

int compare(tipo_inf x, tipo_inf y);
void copy(tipo_inf &dst, tipo_inf src);
void print(tipo_inf x);
