# Atividade Prática -- Tabelas Hash em C


## Exercício : Catálogo de Produtos por Código Numérico

**Cenário**\
Você está ajudando um pequeno comércio que precisa guardar os preços de
seus produtos usando um **código numérico (inteiro)**.\
O sistema precisa ser rápido para **inserir, buscar e listar** os
produtos.

### Requisitos

-   Chave: código do produto (inteiro positivo);
-   Valor: preço (double);
-   Hash: `codigo % M`, com `M = 11`;
-   Colisões: encadeamento.

### Operações

-   `inserir(codigo, preco)` (atualiza se já existir);
-   `buscar(codigo)` (retorna preço ou -1);
-   `remover(codigo)` (excluir produto);
-   `imprimir()` (mostrar tabela).

### Esqueleto

``` c
#include <stdio.h>
#include <stdlib.h>

#define M 11

typedef struct No {
    int codigo;
    double preco;
    struct No* prox;
} No;

No* tabela[M];

int hash(int codigo) { return codigo % M; }
void inicializar() { for (int i = 0; i < M; i++) tabela[i] = NULL; }

No* novo_no(int codigo, double preco) {
    No* n = (No*) malloc(sizeof(No));
    n->codigo = codigo; n->preco = preco; n->prox = NULL;
    return n;
}

void inserir(int codigo, double preco) {
    int idx = hash(codigo);
    No* atual = tabela[idx];
    while (atual) {
        if (atual->codigo == codigo) { atual->preco = preco; return; }
        atual = atual->prox;
    }
    No* n = novo_no(codigo, preco);
    n->prox = tabela[idx];
    tabela[idx] = n;
}

double buscar(int codigo) {
    int idx = hash(codigo);
    No* atual = tabela[idx];
    while (atual) {
        if (atual->codigo == codigo) return atual->preco;
        atual = atual->prox;
    }
    return -1;
}

int remover(int codigo) {
    int idx = hash(codigo);
    No* atual = tabela[idx]; No* ant = NULL;
    while (atual) {
        if (atual->codigo == codigo) {
            if (ant) ant->prox = atual->prox;
            else tabela[idx] = atual->prox;
            free(atual); return 1;
        }
        ant = atual; atual = atual->prox;
    }
    return 0;
}

void imprimir() {
    printf("\n--- TABELA HASH (Produtos) ---\n");
    for (int i = 0; i < M; i++) {
        printf("[%2d]: ", i);
        No* a = tabela[i];
        if (!a) printf("(vazio)");
        while (a) { printf(" -> {Codigo:%d, Preco:%.2f}", a->codigo, a->preco); a = a->prox; }
        printf("\n");
    }
}

int main() {
    inicializar();
    inserir(101, 9.99);
    inserir(202, 19.99);
    inserir(303, 5.50);
    inserir(414, 7.75);
    inserir(525, 2.25);
    inserir(636, 15.00);
    imprimir();

    printf("\nPreco do codigo 202: %.2f\n", buscar(202));
    printf("Preco do codigo 999: %.2f\n", buscar(999));

    printf("\nRemovendo codigo 303...\n");
    remover(303);
    imprimir();
    return 0;
}
```

------------------------------------------------------------------------

## Perguntas de Reflexão

1.  Por que `M` primo ajuda?
2.  O que acontece quando o **fator de carga** cresce?
3.  Compare hash de inteiros vs hash de strings.
4.  Quando sondagem linear seria melhor que encadeamento?
