    #include <stdio.h>
    #include <stdlib.h>

    // Estrutura de um nó da lista encadeada
    typedef struct elemento {
        int valor;
        struct elemento *proximo;
    } No;

    // Estrutura da lista com ponteiros para o início, fim e tamanho
    typedef struct {
        No *inicio;
        No *fim;
        int tamanho;
    } Lista;

    // Inicializa a lista como vazia
    void inicializa(Lista *lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    // Insere um novo elemento no início da lista
    int inserirInicio(Lista *lista, int valor) {
        No *novo = (No*) malloc(sizeof(No));
        if (novo == NULL)
            return -1;

        novo->valor = valor;

        if (lista->inicio == NULL) { // lista vazia
            novo->proximo = NULL;
            lista->inicio = novo;
            lista->fim = novo;
        } else {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }

        lista->tamanho++;
        return 0;
    }

    // Insere um novo elemento no fim da lista
    int inserirFim(Lista *lista, int valor) {
        No *novo = (No*) malloc(sizeof(No));
        if (novo == NULL)
            return -1;

        novo->valor = valor;
        novo->proximo = NULL;

        if (lista->inicio == NULL) { 
            // lista vazia
            lista->inicio = novo;
            lista->fim = novo;
        } else {
            lista->fim->proximo = novo;
            lista->fim = novo;
        }

        lista->tamanho++;
        return 0;
    }

    // Insere um elemento em uma posição específica (meio da lista)
    int inserirMeio(Lista *lista, int valor, int posicao) {
        if (posicao < 0 || posicao > lista->tamanho) {
            printf("Posição inválida!\n");
            return -1;
        }

        No *novo = (No*) malloc(sizeof(No));
        if (novo == NULL)
            return -1;

        novo->valor = valor;

        if (posicao == 0) { // inserção no início
            novo->proximo = lista->inicio;
            lista->inicio = novo;
            if (lista->tamanho == 0)
                lista->fim = novo;
        } else {
            No *atual = lista->inicio;
            for (int i = 0; i < posicao - 1; i++) {
                atual = atual->proximo;
            }
            novo->proximo = atual->proximo;
            atual->proximo = novo;
            if (novo->proximo == NULL)
                lista->fim = novo;
        }

        lista->tamanho++;
        return 0;
    }

    // Remove o primeiro elemento da lista
    void removeInicio(Lista *lista) {
        if (lista->inicio != NULL) {
            No *no = lista->inicio;
            lista->inicio = no->proximo;
            free(no);
            lista->tamanho--;
            if (lista->inicio == NULL)
                lista->fim = NULL; // a lista ficou vazia
        }
    }

    // Remove o primeiro nó que contém o valor especificado
    void removeQualquer(Lista *lista, int valor) {
        No *atual = lista->inicio;
        No *anterior = NULL;

        while (atual != NULL && atual->valor != valor) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == NULL) {
            printf("Valor não encontrado na lista.\n");
            return;
        }

        if (anterior == NULL) { // valor está no início
            lista->inicio = atual->proximo;
            if (lista->inicio == NULL)
                lista->fim = NULL; // lista ficou vazia
        } else {
            anterior->proximo = atual->proximo;
            if (atual == lista->fim)
                lista->fim = anterior; // atualizarmos o fim se for o último nó
        }

        free(atual);
        lista->tamanho--;
    }

    // Imprime todos os elementos da lista
    void imprime(Lista *lista) {
        No *atual = lista->inicio;
        printf("Tamanho atual da lista = %d\n", lista->tamanho);
        while (atual != NULL) {
            printf("%d\n", atual->valor);
            atual = atual->proximo;
        }
    }

    // Função principal com menu de interação
    int main() {
        Lista *lista;
        int valor;
        char op = '\0'; // inicializa para evitar lixo de memória

        lista = (Lista*)malloc(sizeof(Lista));
        if (lista == NULL)
            return 1;

        inicializa(lista);

        while (op != 'X') {
            printf("\nDigite a letra da função desejada:\n");
            printf("A - Adicionar elemento no início da lista\n");
            printf("B - Adicionar elemento no fim da lista\n");
            printf("M - Adicionar elemento no meio da lista\n");
            printf("R - Remover elemento do início da lista\n");
            printf("V - Remover um elemento da lista\n");
            printf("L - Imprimir os elementos da lista\n");
            printf("X - Sair do programa\n");

            // limpa o buffer e lê a opção
            while ((getchar()) != '\n'); // substitui fflush(stdin)
            scanf("%c", &op);

            if (op == 'A'||op == 'a') {
                printf("Digite o valor a ser inserido:\n");
                scanf("%d", &valor);
                if (inserirInicio(lista, valor) == 0)
                    printf("Elemento inserido com sucesso\n");
                else
                    printf("Falha ao inserir elemento\n");
            } else if (op == 'B'||op == 'b') {
                printf("Digite o valor a ser inserido:\n");
                scanf("%d", &valor);
                if (inserirFim(lista, valor) == 0)
                    printf("Elemento inserido com sucesso\n");
                else
                    printf("Falha ao inserir elemento\n");
            } else if (op == 'M'||op == 'm') {
                int posicao;
                printf("Digite o valor a ser inserido:\n");
                scanf("%d", &valor);
                printf("Digite a posição onde deseja inserir (0 até %d):\n", lista->tamanho);
                scanf("%d", &posicao);
                if (inserirMeio(lista, valor, posicao) == 0)
                    printf("Elemento inserido com sucesso no meio da lista\n");
                else
                    printf("Falha ao inserir elemento\n");
            } else if (op == 'R'||op == 'r') {
                removeInicio(lista);
            } else if (op == 'V'||op == 'v') {
                printf("Digite o valor a ser removido:\n");
                scanf("%d", &valor);
                removeQualquer(lista, valor);
            } else if (op == 'L'||op == 'l') {
                printf("\nValores dentro da lista:\n");
                imprime(lista);
            } else if (op == 'X'||op == 'x') {
                printf("Tchau querido(a)! :) \n");
            } else {
                printf("Função inválida\n");
            }
        }

        // libera memória da lista ao final
        while (lista->inicio != NULL) {
            removeInicio(lista);
        }
        free(lista);

        return 0;
    }
