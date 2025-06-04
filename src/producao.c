#include <stdio.h>
#include <stdlib.h>
#include "producao.h"
#include "grafo.h"

void ordenacaoTopologica(Grafo* grafo) {
    int quantidadeModulos = grafo->numVertices;

    // Nomes reais dos módulos da montadora
    const char* nomesModulos[] = {
        "Chassi",
        "Suspensão",
        "Powertrain",
        "Carroceria",
        "Montagem Final",
        "Controle de Qualidade"
    };

    int* grauEntrada = (int*) calloc(quantidadeModulos, sizeof(int));
    int* fila = (int*) malloc(quantidadeModulos * sizeof(int));
    int inicio = 0, fim = 0;

    // Etapa 1: calcular grau de entrada
    for (int i = 0; i < quantidadeModulos; i++) {
        Aresta* dependencia = grafo->vertices[i].listaArestas;
        while (dependencia != NULL) {
            grauEntrada[dependencia->destino]++;
            dependencia = dependencia->prox;
        }
    }

    // Etapa 2: enfileirar módulos sem dependências
    for (int i = 0; i < quantidadeModulos; i++) {
        if (grauEntrada[i] == 0) {
            fila[fim++] = i;
        }
    }

    printf("\nOrdem de montagem:\n");

    // Etapa 3: processar a fila
    while (inicio < fim) {
        int moduloAtual = fila[inicio++];
        printf("Módulo %d (%s)\n", moduloAtual, nomesModulos[moduloAtual]);

        Aresta* dependente = grafo->vertices[moduloAtual].listaArestas;
        while (dependente != NULL) {
            grauEntrada[dependente->destino]--;
            if (grauEntrada[dependente->destino] == 0) {
                fila[fim++] = dependente->destino;
            }
            dependente = dependente->prox;
        }
    }

    free(grauEntrada);
    free(fila);
}
