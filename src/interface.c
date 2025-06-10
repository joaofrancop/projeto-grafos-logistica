#include <stdio.h>
#include "grafo.h"
#include "producao.h"
#include "confianca.h"

void exibirMenu(Grafo* g) {
    int opcao;

    do {
        printf("\n== MENU PRINCIPAL ==\n");
        printf("1. Mostrar ordem de montagem\n");
        printf("2. Escolher fornecedor mais confiável\n");
        printf("3. Buscar menor caminho com A*\n");
        printf("0. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Grafo* grafoMontagem = criarGrafo(6);
                adicionarAresta(grafoMontagem, 0, 1, 1);
                adicionarAresta(grafoMontagem, 1, 2, 1);
                adicionarAresta(grafoMontagem, 0, 3, 1);
                adicionarAresta(grafoMontagem, 2, 4, 1);
                adicionarAresta(grafoMontagem, 3, 4, 1);
                adicionarAresta(grafoMontagem, 4, 5, 1);

                printf("\n== ORDEM DE MONTAGEM - MONTADORA DE CARROS ==\n");
                ordenacaoTopologica(grafoMontagem);
                liberarGrafo(grafoMontagem);
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
            case 3: {
                printf("\nGrafo:\n");
                imprimirGrafo(g);  // <-- Aqui!
                
                int origem, destino;
                printf("Digite o vértice de origem: ");
                scanf("%d", &origem);
                printf("Digite o vértice de destino: ");
                scanf("%d", &destino);
                a_estrela(g, origem, destino);
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
