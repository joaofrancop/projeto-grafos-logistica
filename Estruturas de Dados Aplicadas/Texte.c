// Implementar uma pilha de inteiros com 10 posições

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO 10


int topo = 0;

int pilha[TAMANHO];

int Size_Pilha() {
    return topo;
}

void Push(int valor) {
    if (topo < TAMANHO) {
        pilha[topo] = valor;
        topo++;
        printf("Inserção realizada com sucesso!\n\n");
    } else {
        printf("ERRO: A pilha já está cheia\n");
    }
}

int Pop() {
    if (topo == 0) {
        printf("ERRO: Pilha encontra-se vazia\n");
        return -1; // Indicador de erro
    } else {
        topo--;
        return pilha[topo];
    }
}

void Lista_Pilha() {
    int i;
    printf("\n\nOs valores da pilha são:\n");
    for (i = 0; i < topo; i++) {
        printf("O valor na posição %i é: %i\n", i + 1, pilha[i]);
    }
}

int Peek_Pilha() {
    if (topo == 0) {
        printf("ERRO: Pilha vazia\n");
        return -1;
    }
    return pilha[topo - 1];
}

int main() {
    setlocale(LC_ALL, "portuguese");

    char op;
    int aux;

    printf("\n###### Bem-vindo ao nosso Sistema de Pilhas ######\n\n");

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf(" A - Adicionar um Elemento na Pilha\n");
        printf(" R - Remover um Elemento na Pilha\n");
        printf(" T - Tamanho atual da Pilha\n");
        printf(" L - Listar os elementos da pilha\n");
        printf(" U - Mostrar o último elemento da pilha\n");
        printf(" S - Sair\n");

        printf("\nOpção: ");
        while ((getchar()) != '\n'); // Limpar buffer do teclado
        scanf("%c", &op);

        if (op == 'A' || op == 'a') {
            printf("\nInforme o valor que deseja inserir: ");
            scanf("%i", &aux);
            Push(aux);
        } else if (op == 'R' || op == 'r') {
            int removido = Pop();
            if (removido != -1)
                printf("O valor %i foi removido com sucesso\n", removido);
        } else if (op == 'T' || op == 't') {
            printf("O tamanho da pilha é %i\n\n", Size_Pilha());
        } else if (op == 'L' || op == 'l') {
            Lista_Pilha();
        } else if (op == 'U' || op == 'u') {
            int topoValor = Peek_Pilha();
            if (topoValor != -1)
                printf("\nO elemento do topo é: %i\n\n", topoValor);
        } else if (op == 'S' || op == 's') {
            printf("\nSaindo do programa...\n");
            break;
        } else {
            printf("\nATENÇÃO: Operação Inválida\n");
        }
    }

    return 0;
}
       