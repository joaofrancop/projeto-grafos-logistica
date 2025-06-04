#include "confianca.h"

Fornecedor escolherFornecedorConfiavel(Fornecedor lista[], int tamanho) {
    int i;
    int melhorIndice = -1;

    // 1. Buscar o mais confiável com menor preço
    for (i = 0; i < tamanho; i++) {
        if (lista[i].confianca >= 0.7) {
            if (melhorIndice == -1 || lista[i].preco < lista[melhorIndice].preco) {
                melhorIndice = i;
            }
        }
    }

    // 2. Se não encontrar confiável, escolher o mais barato mesmo
    if (melhorIndice == -1) {
        for (i = 0; i < tamanho; i++) {
            if (melhorIndice == -1 || lista[i].preco < lista[melhorIndice].preco) {
                melhorIndice = i;
            }
        }
    }

    return lista[melhorIndice];
}
