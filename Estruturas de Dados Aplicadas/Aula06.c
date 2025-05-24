#include<stdio.h>
#include<stdlib.h>

#define tem 5  // Definindo o tamanho da fila

int primeiro = 0;
int ultimo = -1;
int fila[tem];

// Função para inserir um valor na fila
void enqueue(int valor)
{
    if (ultimo < tem - 1)
    {
        ultimo++;
        fila[ultimo] = valor;
        printf("\nValor inserido com sucesso!");
    }
    else
    {
        printf("\nNão foi possível inserir o elemento da fila. A fila está cheia.\n");
    }
}

// Função para remover um valor da fila
int daqueue()
{
    int aux;
    if (primeiro <= ultimo)
    {
        aux = fila[primeiro];
        fila[primeiro] = -1;  // Marca o valor como removido
        primeiro++;
        return aux;
    }
    else
    {
        printf("\nA fila se encontra vazia\n");
        return -1;  // Indica que não foi possível remover
    }
}

// Função para listar os elementos da fila
void lista()
{
    int i;
    printf("\n##### OS ELEMENTOS DA FILA SÃO #### \n");

    for (i = 0; i <= ultimo; i++)  // Exibe apenas os elementos válidos
    {
        printf("\nValor na posição %i: %i", i + 1, fila[i]);
    }
    printf("\n\nO cursor Primeiro é: %i", primeiro);
    printf("\nO cursor Último é: %i\n", ultimo);
}

// Função para visualizar o primeiro elemento sem remover
int peek()
{
    if (primeiro <= ultimo)
    {
        return fila[primeiro];  // Retorna o primeiro valor da fila
    }
    else
    {
        return -1;  // A fila está vazia
    }
}

int main()
{
    char op;
    int aux;
    while (op != 'E' && op != 'e')
    {
        printf("\nEscolha uma opção:\n");
        printf("I - Inserir um elemento na fila\n");
        printf("R - Remover um elemento da fila\n");
        printf("L - Listar elementos da fila\n");
        printf("P - Verificar o primeiro elemento\n");
        printf("E - Sair\n");

        fflush(stdin);
        scanf(" %c", &op);  // Espaço antes de %c para garantir que leia corretamente

        if (op == 'I' || op == 'i')
        {
            printf("\nInforme o valor que deseja inserir: ");
            scanf("%i", &aux);
            enqueue(aux);
        }
        else if (op == 'R' || op == 'r')
        {
            daqueue();  // Não precisa passar valor
        }
        else if (op == 'L' || op == 'l')
        {
            lista();  // Listar os elementos
        }
        else if (op == 'P' || op == 'p')
        {
            int primeiroElemento = peek();
            if (primeiroElemento != -1)
            {
                printf("\nO primeiro elemento é: %i", primeiroElemento);
            }
            else
            {
                printf("\nA fila está vazia");
            }
        }
        else if (op != 'E' && op != 'e')
        {
            printf("\nOpção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
