#pragma once


const int DATA_MAX_LEN = 7;
const int ORA_I_MAX_LEN = 5;
const int ORA_F_MAX_LEN = 5;
const int DESCR_MAX_LEN = 51;

struct appuntamento {
	char data[DATA_MAX_LEN];
	char ora_i[ORA_I_MAX_LEN];
	char ora_f[ORA_F_MAX_LEN];
	char descr[DESCR_MAX_LEN];
};

typedef appuntamento tipo_inf;

/**
 * @brief compare two appointments
 * 
 * @return int zero x and t have the same date and staring hour; x.ora_i - y.ora_i (lexicographically) otherwise
 */
int compare(tipo_inf x, tipo_inf y);

/**
 * @brief copy the entire 'appuntamento' structure from src to dst
 * 
 */
void copy(tipo_inf &src, tipo_inf dst);

/**
 * @brief print appointment x
 * 
 */
void print(tipo_inf x);
