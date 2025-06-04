#ifndef CONFIANCA_H
#define CONFIANCA_H

typedef struct Fornecedor {
    int id;
    const char* nome;
    float confianca;  // de 0.0 a 1.0
    float preco;      // valor cobrado pelo item
} Fornecedor;

Fornecedor escolherFornecedorConfiavel(Fornecedor lista[], int tamanho);

#endif
