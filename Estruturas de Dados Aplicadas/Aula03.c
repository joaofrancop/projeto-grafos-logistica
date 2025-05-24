    #include<stdio.h>   
    #include<stdlib.h>
    #include<locale.h>

    #define tamanho 10

    int topo = 0;

    int pilha [tamanho];

    int Size_Pilha()
    {
        return topo;
    }

    void push(int valor)
    {
    
        if(topo<tamanho){
            pilha[topo]= valor;
            topo++;
            printf("Interserção realizda com sucesso!\n\n\n");
        }
        else{printf("Erro: Pilha esta cheia\n");
        return 0;
        }
    }

    void pop(){   if(topo==0){
        printf("Erro: Pilha encontra-se vazia ");
        return 0 ;
    }else{
        topo -- ;
        return 0;

    }}


    int main(){
    setlocale(LC_ALL,"Portugues");

    char op;
    int aux;


    printf("------------- Bem vindo ao nosso Sistema de Pilhas -------------\n\n");

    //While ()antes de gerar as opções 
    while (op != 'S'|| op!='s'){

        printf(" A - Adicone um Elemento na pilha\n");
        printf(" R - Remove um elemento da pilha \n");
        printf(" T - Tamanho atual da pilha \n");
        printf(" L - Para listar os elemento da pilha  \n");
        printf(" U - Para listar o último  elemento da pilha  \n");
        printf(" S - Para sair   \n");
        
        fflush(stdin);
        scanf("%c",&op);
    }if (op != 'A'|| op!='a')
    {
    printf("\n Informe o valor que desaj inserir:" );

    scanf("%i",&aux);
    push(aux);
    }
else if (op != 'R'|| op!='r')
{
    //printf("O valor %i foi Removido com sucesso\n", Pop());
//Pop();
  //  
scanf("%i",&aux);
push(aux);
}

        return 0 ;
    }