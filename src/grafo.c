#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo* criarGrafo(int numVertices) {
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    grafo->vertices = (Vertice*) malloc(numVertices * sizeof(Vertice));

    for (int i = 0; i < numVertices; i++) {
        grafo->vertices[i].id = i;
        grafo->vertices[i].listaArestas = NULL;
    }

    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino, int peso) {
    Aresta* nova = (Aresta*) malloc(sizeof(Aresta));
    nova->destino = destino;
    nova->peso = peso;
    nova->prox = grafo->vertices[origem].listaArestas;
    grafo->vertices[origem].listaArestas = nova;
}

void imprimirGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        printf("V%d -> ", i);
        Aresta* atual = grafo->vertices[i].listaArestas;
        while (atual != NULL) {
            printf("[V%d | peso %d] -> ", atual->destino, atual->peso);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
}

void liberarGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        Aresta* atual = grafo->vertices[i].listaArestas;
        while (atual != NULL) {
            Aresta* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(grafo->vertices);
    free(grafo);
}
