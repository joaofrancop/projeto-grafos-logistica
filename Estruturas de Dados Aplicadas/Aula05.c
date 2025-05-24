#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicialmente criamos o elemento dentro da nossa pilha
typedef struct ElementoPrimitivo {
    char *dado; // dado que quero colocar dentro da pilha
    struct ElementoPrimitivo *seguinte; // armazeno o dado e a próxima posição da pilha
} Elemento;

// Pilha propriamente dita
typedef struct ListaPilha {
    Elemento *inicio; // ponteiro para o início da pilha, podem chamar de topo se quiserem
    int tamanho; // tamanho da pilha
} Pilha;

// Inicializo a pilha
void Init_Pilha(Pilha *pilha) {
    pilha->inicio = NULL;
    pilha->tamanho = 0;
}

// Empilho um novo elemento
int Push_Pilha(Pilha *pilha, char *texto) {
    Elemento *novo_elemento;
    if ((novo_elemento = (Elemento *)malloc(sizeof(Elemento))) == NULL) // alocação e verificação se deu certo
        return -1; // se eu não conseguir alocar, retorno -1

    if ((novo_elemento->dado = (char *)malloc((strlen(texto) + 1) * sizeof(char))) == NULL) // alocando para o dado que vou inserir no elemento
        return -1;

    strcpy(novo_elemento->dado, texto);
    novo_elemento->seguinte = pilha->inicio; // mudo o ponteiro para o início
    pilha->inicio = novo_elemento;
    pilha->tamanho++; // trabalhando com o topo
    return 0;
}

// Desempilho um elemento
int Pop_Pilha(Pilha *pilha) {
    Elemento *remove_elemento;
    if (pilha->tamanho == 0)
        return -1;

    remove_elemento = pilha->inicio; // copiando para um auxiliar
    pilha->inicio = pilha->inicio->seguinte;
    free(remove_elemento->dado); // liberação da memória do dado
    free(remove_elemento); // liberação da memória do elemento
    pilha->tamanho--; // de dentro para fora
    return 0;
}

// Listo os elementos da pilha
void List_Pilha(Pilha *pilha) {
    Elemento *atual = pilha->inicio;
    printf("------- TOPO DA PILHA ----------\n");

    while (atual != NULL) {
        printf("  %s\n", atual->dado);
        atual = atual->seguinte;
    }

    printf("------- FUNDO DA PILHA ----------\n");
}

// Função para verificar e imprimir números pares
void Par_Pilha(Pilha *pilha) {
    Elemento *atual = pilha->inicio;
    printf("------- Números Pares ----------\n");

    while (atual != NULL) {
        int num = atoi(atual->dado); // Converte a string para número inteiro
        if (num % 2 == 0) { // Verifica se o número é par
            printf("%d\n", num);
        }
        atual = atual->seguinte;
    }

    printf("------- FIM Números Pares -------\n");
}

int main() {
    Pilha *teste1;
    char aux[11];
    int i;

    if ((teste1 = (Pilha *)malloc(sizeof(Pilha))) == NULL)
        return -1;

    Init_Pilha(teste1);

    // Inserção de 3 elementos na pilha
    for (i = 0; i < 5; i++) {
        printf("Digite alguma coisa com até 10 caracteres: ");
        scanf("%10s", aux); // Limita a entrada a 10 caracteres
        Push_Pilha(teste1, aux);
        printf("A pilha tem %i elementos.\n", teste1->tamanho);
        List_Pilha(teste1);
    }

    // Chama a função para listar os números pares
    Par_Pilha(teste1);

    // Remove o topo da pilha
    Pop_Pilha(teste1);
    printf("Agora a pilha tem %i elementos.\n", teste1->tamanho);
    List_Pilha(teste1);

    return 0;
}
