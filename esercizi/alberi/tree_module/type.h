#ifndef TYPE_H
#define TYPE_H

typedef char* tipo_inf;

void copy(tipo_inf dst, const tipo_inf src);
int compare(const tipo_inf first, const tipo_inf second);
void print(const tipo_inf data);

#endif  // TYPE_H