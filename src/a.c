#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "grafo.h"

#define INFINITO INT_MAX

// Função heurística simples (pode ser substituída por algo mais realista)
int heuristica(int atual, int destino) {
    return abs(destino - atual); // Exemplo simples
}

void a_estrela(Grafo* grafo, int inicio, int fim) {
    int n = grafo->numVertices;
    int* g = malloc(n * sizeof(int));
    int* f = malloc(n * sizeof(int));
    bool* visitado = calloc(n, sizeof(bool));
    int* pai = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        g[i] = INFINITO;
        f[i] = INFINITO;
        pai[i] = -1;
    }

    g[inicio] = 0;
    f[inicio] = heuristica(inicio, fim);

    while (1) {
        int atual = -1;
        int menorF = INFINITO;

        for (int i = 0; i < n; i++) {
            if (!visitado[i] && f[i] < menorF) {
                menorF = f[i];
                atual = i;
            }
        }

        if (atual == -1) break;
        if (atual == fim) break;

        visitado[atual] = true;

        Aresta* a = grafo->vertices[atual].listaArestas;
        while (a != NULL) {
            int vizinho = a->destino;
            int novoG = g[atual] + a->peso;

            if (novoG < g[vizinho]) {
                g[vizinho] = novoG;
                f[vizinho] = novoG + heuristica(vizinho, fim);
                pai[vizinho] = atual;
            }

            a = a->prox;
        }
    }

    // Reconstrução do caminho
    if (pai[fim] == -1) {
        printf("Caminho não encontrado.\n");
    } else {
        printf("Caminho de %d até %d:\n", inicio, fim);
        int atual = fim;
        int caminho[grafo->numVertices];
        int tam = 0;
        while (atual != -1) {
            caminho[tam++] = atual;
            atual = pai[atual];
        }
        for (int i = tam - 1; i >= 0; i--) {
            printf("V%d", caminho[i]);
            if (i > 0) printf(" -> ");
        }
        printf("\nCusto total: %d\n", g[fim]);
    }

    free(g);
    free(f);
    free(visitado);
    free(pai);
}
