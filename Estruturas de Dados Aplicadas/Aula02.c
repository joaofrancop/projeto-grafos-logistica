#include<stdio.h>
#include<stdlib.h>

void bubleSort(float *v, int n) {
    int i, continua, fim = n;
    float aux;
    do {
        continua = 0;
        for (i = 0; i < fim - 1; i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = 1;  // Indicate that a swap happened
            }
        }
        fim--;
    } while (continua != 0);  // Continue if any swap happened
}

int main() {
    float vet[10];
    int i;

    // Correct loop condition to iterate 10 times
    for (i = 0; i < 10; i++) {
        printf("Informe a nota do aluno: ");
        scanf("%f", &vet[i]);  // Corrected the scanf to take the address
    }

    int n = 10;
    
    // Call the bubble sort function
    bubleSort(vet, n);

    // Print the sorted grades
    printf("\nNotas ordenadas: ");
    for (i = 0; i < 10; i++) {
        printf("%.2f ", vet[i]);
    }

    return 0;
}
