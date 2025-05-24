#include <stdio.h>
#include <locale.h>

int buscaBin(int *lista, int chave, int inicio, int fim) {
   
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2; // objetivo achar o meio do vetorint main() {
	 

        if (lista[meio] == chave) {
            return meio;
        }
        else if (lista[meio] > chave) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }
    return -1;
}

int main()
{

	setlocale(LC_ALL,"PORTUGUESE");
    int vetor[]={7,9,11,17,23,25,29,33,45,51};
    int chave, resultado;

    

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &chave);

    
    resultado = buscaBin(vetor, chave, 0, 9);

    // Resultado da busca
    
    if (resultado != -1) {
        printf("Valor %d encontrado na posição %d.\n", chave, resultado + 1);
    } else {
        printf("Valor %d não encontrado no vetor.\n", chave);
    }

    return 0;
}