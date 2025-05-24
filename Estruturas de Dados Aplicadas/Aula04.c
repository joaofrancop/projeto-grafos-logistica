    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>

    #define TAMANHO 10

    // Definicao da estrutura para os elementos da pilha
    typedef struct {
        int idade;
        int data;
        int matricula;
    } Estrutura_pilha;

    int topo = 0;
    Estrutura_pilha pilha[TAMANHO];

    // Funcao que retorna o tamanho atual da pilha
    int Size_Pilha() {
        return topo;
    }

    // Funcao para adicionar um elemento a pilha
    void Push(int idade, int data, int matricula) {
        if (topo < TAMANHO) {
            pilha[topo].idade = idade;
            pilha[topo].data = data;
            pilha[topo].matricula = matricula;
            topo++;
            printf("Insercao realizada com sucesso!\n\n");
        } else {
            printf("ERRO: A pilha ja esta cheia\n");
        }
    }

    // Funcao para remover o topo da pilha
    Estrutura_pilha Pop() {
        if (topo == 0) {
            printf("ERRO: Pilha encontra-se vazia\n");
            Estrutura_pilha erro = {-1, -1, -1}; // Retorna uma estrutura de erro
            return erro;
        } else {
            topo--;
            return pilha[topo];
        }
    }

    // Funcao para listar os elementos da pilha
    void Lista_Pilha() {
        int i;
        printf("\n\nOs valores da pilha sao:\n");
        for (i = 0; i < topo; i++) {
            printf("Elemento %d -> Idade: %d, Data: %d, Matricula: %d\n", i + 1, pilha[i].idade, pilha[i].data, pilha[i].matricula);
        }
    }

    // Funcao para mostrar o topo da pilha
    Estrutura_pilha Peek_Pilha() {
        if (topo == 0) {
            printf("ERRO: Pilha vazia\n");
            Estrutura_pilha erro = {-1, -1, -1}; // Retorna uma estrutura de erro
            return erro;
        }
        return pilha[topo - 1];
    }

    int main() {
        setlocale(LC_ALL, "portugues");

        char op;
        Estrutura_pilha aux;

        printf("\n###### Bem-vindo ao nosso Sistema de Pilhas ######\n\n");

        while (1) {
            printf("\nEscolha uma opcao:\n");
            printf(" A - Adicionar um Elemento na Pilha\n");
            printf(" R - Remover um Elemento na Pilha\n");
            printf(" T - Tamanho atual da Pilha\n");
            printf(" L - Listar os elementos da pilha\n");
            printf(" U - Mostrar o ultimo elemento da pilha\n");
            printf(" S - Sair\n");

            printf("\nOpcao: ");
            while ((getchar()) != '\n'); // Limpar buffer do teclado
            scanf("%c", &op);

            if (op == 'A' || op == 'a') {
                printf("\n Informe a idade:");
                scanf("%i", &aux.idade);
                printf("\nInforme a data:");
                scanf("%i", &aux.data);
                printf("\nInforme a matricula:");
                scanf("%i", &aux.matricula);
                
                // Chama a funcao Push para adicionar a pilha
                Push(aux.idade, aux.data, aux.matricula);

            } else if (op == 'R' || op == 'r') {
                Estrutura_pilha removido = Pop();
                if (removido.idade != -1) {
                    printf("O elemento com Idade: %d, Data: %d, Matricula: %d foi removido com sucesso\n", removido.idade, removido.data, removido.matricula);
                }
            } else if (op == 'T' || op == 't') {
                printf("O tamanho da pilha e %i\n\n", Size_Pilha());
            } else if (op == 'L' || op == 'l') {
                Lista_Pilha();
            } else if (op == 'U' || op == 'u') {
                Estrutura_pilha topoValor = Peek_Pilha();
                if (topoValor.idade != -1) {
                    printf("\nO elemento do topo e: Idade: %d, Data: %d, Matricula: %d\n\n", topoValor.idade, topoValor.data, topoValor.matricula);
                }
            } else if (op == 'S' || op == 's') {
                printf("\nSaindo do programa...\n");
                break;
            } else {
                printf("\nATENCAO: Operacao Invalida\n");
            }
        }

        return 0;
    }
