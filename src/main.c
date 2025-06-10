#include <stdio.h>
#include "interface.h"
#include "grafo.h"
#include <windows.h>

int main() {
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

    // Imprime a estrutura do grafo
    printf("Grafo:\n");
    imprimirGrafo(g);

    // Executa busca A* do vértice 0 até o 5
    printf("\nBusca A* de V0 até V5:\n");
    a_estrela(g, 0, 5);

    // Libera memória
    liberarGrafo(g);
    

    SetConsoleOutputCP(65001);  // saída (printf)
    SetConsoleCP(65001);        // entrada (scanf)

    exibirMenu();


    return 0;
}
