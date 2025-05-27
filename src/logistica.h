#ifndef LOGISTICA_H
#define LOGISTICA_H

#include "grafo.h"

int* dijkstra(Grafo* grafo, int origem);
int* a_star(Grafo* grafo, int origem, int destino, int (*heuristica)(int, int));

#endif
