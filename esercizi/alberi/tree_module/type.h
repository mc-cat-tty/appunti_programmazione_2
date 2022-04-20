#ifndef TYPE_H
#define TYPE_H

const unsigned int STR_MAX_DIM = 64;

typedef char* tipo_inf;

void copy(tipo_inf dst, const tipo_inf src);
int compare(const tipo_inf first, const tipo_inf second);
void print(const tipo_inf data);
char* to_string(const tipo_inf data);

#endif  // TYPE_H