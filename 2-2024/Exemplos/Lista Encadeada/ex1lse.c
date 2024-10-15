#include<stdio.h>
#include<stdlib.h>

typedef struct cel celula;
struct cel {
    int dado;
    celula *prox;
};

void insere (int x, celula *p)
{
    celula *nova;

    nova = (celula *) malloc (sizeof(celula));
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
}

void imprime(celula *ini)
{
    celula *p;

    p = ini->prox;
    if (p == NULL){
        printf("\nLista vazia\n");
        return;
    }
    else{
        printf("\nValores na lista:\n");
        while (p != NULL) {
            printf ("%d\t", p->dado);
            p = p->prox;
        }
    }

    printf ("\n\n");
}

int main()
{
    int op = -1, valor;
    celula *lista;

    lista = (celula *) malloc(sizeof(celula));
    lista->prox = NULL;
    while (op != 0)
    {
        printf("\nOpc¸˜oes dispon´ıveis:\n");
        printf("\t1 p/ imprimir lista.\n");
        printf("\t2 p/ inserir novo elemento na lista.\n");
        printf("\t0 p/ encerrar.\n");
        printf("Entre opc¸˜ao desejada: ");
        scanf("%d", &op);
        switch(op) {
            case 0:
                printf("\n\nTCHAU!\n");
                break;
            case 1:
                imprime(lista);
                break;
            case 2:
                printf("\nEntre valor a ser inserido na lista: ");
                scanf("%d", &valor);
                insere(valor, lista);
                break;
            default:
                printf("\n\nOPCAO INVALIDA!\n");
            }
    }
    return 0;
}
