#include <stdio.h>
#include "interface.h"
#include "grafo.h"
#include <windows.h>

int main() {
    // Configura console para UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Cria o grafo com 6 vértices (0 a 5)
    Grafo* g = criarGrafo(6);

    // Adiciona arestas com pesos
    adicionarAresta(g, 0, 1, 2);
    adicionarAresta(g, 0, 2, 4);
    adicionarAresta(g, 1, 2, 1);
    adicionarAresta(g, 1, 3, 7);
    adicionarAresta(g, 2, 4, 3);
    adicionarAresta(g, 4, 3, 2);
    adicionarAresta(g, 3, 5, 1);

    // Inicia o menu interativo, passando o grafo
    exibirMenu(g);

    // Libera memória
    liberarGrafo(g);

    return 0;
}
