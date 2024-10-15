#include<stdio.h>
#include<stdlib.h>

typedef struct cel celula;
struct cel {
    int dado;
    celula *prox;
};
celula *lista, *p, *nova;

void insere (int x)
{
    nova = (celula *) malloc (sizeof(celula));
    nova->dado = x;
    nova->prox = lista->prox;
    lista->prox = nova;
}

void imprime()
{
    p = lista->prox;
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

    lista = (celula *) malloc (sizeof(celula));
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
                imprime();
                break;
            case 2:
                printf("\nEntre valor a ser inserido na lista: ");
                scanf("%d", &valor);
                insere(valor);
                break;
            default:
                printf("\n\nOPCAO INVALIDA!\n");
            }
    }
    return 0;
}
