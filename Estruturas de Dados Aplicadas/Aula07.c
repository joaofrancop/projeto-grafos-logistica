#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#define TAM 10

int tamanho = 0, lista[TAM];

void insere(int valor) {
    int i;

    if (tamanho == TAM) { // Verifica se a lista não está cheia
        printf("\n\tERRO: A lista está cheia\n");
        return;
    }

    for (i = tamanho; i > 0 && valor < lista[i - 1]; i--) { // Faz com que os elementos deem um passo para trás
        lista[i] = lista[i - 1];
    }

    lista[i] = valor; // O elemento é inserido na posição que o loop parou
    tamanho++;
    printf("\nElemento inserido com sucesso!\n\n");
}

void remover(int valor) {
    int i, j, cont = 0;

    if (tamanho == 0) { // Verifica se a lista está vazia
        printf("\n\tErro: Lista vazia!");
        return;
    }

    for (i = 0; i < tamanho && valor >= lista[i]; i++) {
        if (valor == lista[i]) {
            for (j = i; j < tamanho - 1; j++) {
                lista[j] = lista[j + 1]; // Faz os elementos darem um passo para frente
            }
            tamanho--;
            i--; // Faz o i voltar para o caso de haver número repetidos
            cont++;
        }
    }
    if (cont != 0)
        printf("\nElemento removido com sucesso!");
    else
        printf("\n\tERRO: valor não está na lista");
}

void exibir() {
    int i;

    if (tamanho == 0) {
        printf("\n\tErro: Lista vazia!");
        return;
    }

    for (i = 0; i < tamanho; i++) {
        printf("\nElemento[ %d ] - posição na lista %d", lista[i], i + 1);
    }
}

void buscar(int valor) {
    int i, aux = 0;

    if (tamanho == 0) {
        printf("\n\tERRO: Lista vazia");
        return;
    }

    for (i = 0; i < tamanho && valor >= lista[i]; i++) {
        if (valor == lista[i]) {
            printf("\nValor [ %d ] está na posição [%d]", valor, i + 1);
            aux++;
        }
    }
    if (aux == 0)
        printf("\n\tERRO: valor não está na lista");
}

void menu() {
    printf("EXEMPLO DE LISTA SEQUENCIAL ESTÁTICA\n\n");
    printf("\n##############################################");
    printf("\n#           MENU - Lista Ordenada            #");
    printf("\n#                                            #");
    printf("\n#   Digite a desejada                       #");
    printf("\n#                                            #");
    printf("\n#   1 = Inserir elemento                    #");
    printf("\n#   2 = Remover elemento                    #");
    printf("\n#   3 = Buscar elemento                     #");
    printf("\n#   4 = Exibir lista                        #");
    printf("\n#   5 = Sair                                #");
    printf("\n#                                            #");
    printf("\n##############################################");
    printf("\n\n");
}

int main() {
    int opcao, valor;
    bool i = true;

    menu();
    do {
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);  // Mudança aqui, agora usando scanf para ler a opção

        switch (opcao) {
            case 1:
                system("cls");
                menu();
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                insere(valor);
                printf("\n\nEscolha outra opção para continuar...\n\n");
                break;
            case 2:
                system("cls");
                menu();
                printf("\nDigite o valor a ser removido: ");
                scanf("%d", &valor);
                remover(valor);
                printf("\n\nEscolha outra opção para continuar...\n\n");
                break;
            case 3:
                system("cls");
                menu();
                printf("\nDigite o valor a ser buscado: ");
                scanf("%d", &valor);
                buscar(valor);
                printf("\n\nEscolha outra opção para continuar...\n\n");
                break;
            case 4:
                system("cls");
                menu();
                exibir();
                printf("\n\nEscolha outra opção para continuar...\n\n");
                break;
            case 5:
                system("cls");
                printf("\n\n\t\tAté logo !!\n\n\n\n\n\n\n\n\n\n");
                i = false;
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    } while (i == true);

    system("pause");
    return 0;
}
