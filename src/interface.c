#include <stdio.h>
#include "grafo.h"
#include "producao.h"
#include "confianca.h"

void exibirMenu() {
    int opcao;

    do {
        printf("\n== MENU PRINCIPAL ==\n");
        printf("1. Mostrar ordem de montagem\n");
        printf("2. Escolher fornecedor mais confiável\n");
        printf("0. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Grafo* grafo = criarGrafo(6);
                adicionarAresta(grafo, 0, 1, 1);
                adicionarAresta(grafo, 1, 2, 1);
                adicionarAresta(grafo, 0, 3, 1);
                adicionarAresta(grafo, 2, 4, 1);
                adicionarAresta(grafo, 3, 4, 1);
                adicionarAresta(grafo, 4, 5, 1);

                printf("\n== ORDEM DE MONTAGEM - MONTADORA DE CARROS ==\n");
                ordenacaoTopologica(grafo);
                liberarGrafo(grafo);
                break;
            }
            case 2: {
                Fornecedor fornecedores[] = {
                    {0, "Fornecedor A", 0.65, 120.0},
                    {1, "Fornecedor B", 0.82, 140.0},
                    {2, "Fornecedor C", 0.91, 160.0},
                    {3, "Fornecedor D", 0.60, 100.0}
                };
                int qtd = sizeof(fornecedores) / sizeof(Fornecedor);
                Fornecedor escolhido = escolherFornecedorConfiavel(fornecedores, qtd);
                printf("\nFornecedor escolhido: %s\n", escolhido.nome);
                printf("Confiança: %.2f | Preço: R$ %.2f\n", escolhido.confianca, escolhido.preco);
                break;
            }
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);
}
