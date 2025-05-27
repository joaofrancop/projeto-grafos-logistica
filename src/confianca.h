#ifndef CONFIANCA_H
#define CONFIANCA_H

typedef struct Fornecedor {
    int id;
    float confianca; // 0.0 a 1.0
} Fornecedor;

float getConfiancaFornecedor(int id);

#endif
