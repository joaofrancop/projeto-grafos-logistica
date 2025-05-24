#include <stdio.h>
#include <locale.h>

// Funcao de ordenacao Bubble Sort
void BubbleSort(int vetor[], int n) {
    int aux, i, j;
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

// Funcao de busca sequencial
int busca_sequencial(int lista[], int chave, int n) {
    for (int i = 0; i < n; i++) {
        if (lista[i] == chave) {
            return i;
        }
    }
    return -1;
}

// Funcao de busca binaria
int buscaBin(int lista[], int chave, int inicio, int fim) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (lista[meio] == chave) {
            return meio;
        } else if (lista[meio] > chave) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;
}

int main() {Install Aduional Languages
    setlocale(LC_ALL, "PORTUGUES");

    int vetor[] = {23, 29, 59, 79, 85, 17, 11, 63, 52};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int busca, resultado, chave;

    // Menu de escolha de busca
    printf("Escolha busca sequencial ou binaria:\n");
    printf("1 - Busca sequencial\n");
    printf("2 - Busca binaria\n");
    scanf("%d", &busca);

    switch (busca) {
    case 1:
        printf("Digite o valor a ser buscado: ");
        scanf("%d", &chave);
        resultado = busca_sequencial(vetor, chave, n);
        break;

    case 2:
        // Ordenando o vetor antes da busca binaria
        BubbleSort(vetor, n);
        printf("Digite o valor a ser buscado: ");
        scanf("%d", &chave);
        resultado = buscaBin(vetor, chave, 0, n - 1);
        break;

    default:
        printf("Opcao invalida!\n");
        return 1;
    }

    // Resultado
    if (resultado != -1) {
        printf("O valor %d foi encontrado na posicao %d\n", chave, resultado);
    } else {
        printf("O valor %d nao foi encontrado no vetor.\n", chave);
    }

    return 0;
}
