#include "grafo.h"
#include "producao.h"
#include "logistica.h"
#include "interface.h"

int main() {
    Grafo* grafoProducao = criarGrafo(10);
    Grafo* grafoLogistica = criarGrafo(10);

    mostrarMenu();
    executarSimulacao(grafoProducao, grafoLogistica);

    liberarGrafo(grafoProducao);
    liberarGrafo(grafoLogistica);
    return 0;
}
