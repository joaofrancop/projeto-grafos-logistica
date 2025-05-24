#include<stdio.h>
#include<locale.h>

int busca_sequencial(int*lista,int chave,int n){

    int i;
    for(i=0;i<n;i++){
        if(lista[i]==chave){
            return i;
        }
    }
    return -1;
}

int main(){

 setlocale(LC_ALL,"PORTUGUES");

int vetor[]={23,29,59,79,85,17,11,63,52};

 
 int chave,resultado;

 printf("Digite o valor a ser buscado:");
 scanf("%d",&chave);


 resultado= busca_sequencial(vetor,chave,10);
 

 // Resultado

        if(resultado !=-1){

            printf("o valor%d  encontrado  na posiçao %d\n",chave,resultado);
        }else{
            printf("o valor %d nao encotrado no vetor.\n",chave);
        }

    
    return 0;
}