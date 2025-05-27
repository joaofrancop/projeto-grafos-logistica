#ifndef GRAFO_H
#define GRAFO_H

typedef struct Aresta {
    int destino;
    int peso;
    struct Aresta* prox;
} Aresta;

typedef struct Vertice {
    int id;
    Aresta* listaArestas;
} Vertice;

typedef struct Grafo {
    int numVertices;
    Vertice* vertices;
    int** matrizAdjacencia;
} Grafo;

Grafo* criarGrafo(int numVertices);
void adicionarAresta(Grafo* grafo, int origem, int destino, int peso);
void imprimirGrafo(Grafo* grafo);
void liberarGrafo(Grafo* grafo);

#endif
