# Atividade Prática -- Tabelas Hash em C

## Contexto

Você foi convidado(a) a apoiar o time de TI de uma escola. Eles precisam
guardar e buscar informações **muito rápido** (em tempo quase constante)
a partir de uma **chave**. Para isso, você vai usar **tabelas hash**.

Nesta atividade: - você verá um **exercício resolvido** (com código C
completo e comentado); - depois fará um **exercício proposto** (com
esqueleto de código e orientações).

------------------------------------------------------------------------

## Objetivos de Aprendizagem

-   Entender o papel de uma **função de dispersão (hash)**.
-   Implementar uma **tabela hash** com **tratamento de colisões**
    (encadeamento).
-   Inserir, buscar e listar elementos.
-   Medir noções básicas de **fator de carga** e o efeito de colisões.

------------------------------------------------------------------------

## Revisão Rápida (em 2 minutos)

-   **Tabela hash**: vetor (`table[M]`) de "baldes".
-   **Hash**: função `h(chave) -> [0..M-1]`.
-   **Colisão**: quando duas chaves caem no mesmo índice.
-   **Tratamento de colisões**:
    -   **Encadeamento** (lista ligada em cada posição do vetor);
    -   (Outras: *linear probing*, *quadrática*, *duplo hash* ---
        veremos depois).
-   **Boas práticas**:
    -   Escolha `M` (tamanho da tabela) preferencialmente **primo**.
    -   Mantenha **fator de carga** `α = n/M` sob controle (quanto
        maior, mais colisões).

------------------------------------------------------------------------

## Exercício 1 (RESOLVIDO): Cadastro de Alunos pelo RA (inteiro)

**Tarefa**\
Implemente uma tabela hash para armazenar pares **(RA → nome)** com: -
`inserir(RA, nome)` - `buscar(RA)` (retorna o nome ou "não
encontrado") - `imprimir()` (mostra a tabela por índices)

**Escolhas de projeto** - Chave: `RA` (inteiro). - Hash: **método da
divisão** `h(RA) = RA % M`, com `M = 13`. - Colisões: **encadeamento**
com lista ligada.

### Código Completo (compile e rode)

> Compile: `gcc hash_alunos.c -o hash_alunos`\
> Execute: `./hash_alunos`

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 13               // tamanho da tabela (primo ajuda a dispersar melhor)
#define MAX_NOME 64

// Nó da lista (encadeamento separado)
typedef struct No {
    int ra;                 // chave
    char nome[MAX_NOME];    // valor
    struct No* prox;
} No;

// A tabela é um vetor de ponteiros para No
No* tabela[M];

// Função de hash (método da divisão)
int hash(int ra) {
    return ra % M;
}

// Inicializa todos os "baldes" com NULL
void inicializar() {
    for (int i = 0; i < M; i++) {
        tabela[i] = NULL;
    }
}

// Cria e retorna um novo nó
No* novo_no(int ra, const char* nome) {
    No* n = (No*) malloc(sizeof(No));
    n->ra = ra;
    strncpy(n->nome, nome, MAX_NOME - 1);
    n->nome[MAX_NOME - 1] = '\0';
    n->prox = NULL;
    return n;
}

// Insere (se RA já existir, atualiza o nome)
void inserir(int ra, const char* nome) {
    int idx = hash(ra);
    No* atual = tabela[idx];

    while (atual != NULL) {
        if (atual->ra == ra) {
            strncpy(atual->nome, nome, MAX_NOME - 1);
            atual->nome[MAX_NOME - 1] = '\0';
            return;
        }
        atual = atual->prox;
    }

    No* n = novo_no(ra, nome);
    n->prox = tabela[idx];
    tabela[idx] = n;
}

// Busca por RA; retorna ponteiro para nome ou NULL
const char* buscar(int ra) {
    int idx = hash(ra);
    No* atual = tabela[idx];

    while (atual != NULL) {
        if (atual->ra == ra) {
            return atual->nome;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Imprime a tabela hash
void imprimir() {
    printf("\n--- ESTADO DA TABELA HASH ---\n");
    for (int i = 0; i < M; i++) {
        printf("[%2d]: ", i);
        No* atual = tabela[i];
        if (!atual) {
            printf("(vazio)");
        }
        while (atual) {
            printf(" -> (RA:%d, Nome:%s)", atual->ra, atual->nome);
            atual = atual->prox;
        }
        printf("\n");
    }
}

// Libera memória
void destruir() {
    for (int i = 0; i < M; i++) {
        No* atual = tabela[i];
        while (atual) {
            No* prox = atual->prox;
            free(atual);
            atual = prox;
        }
        tabela[i] = NULL;
    }
}

// Calcula fator de carga
double fator_de_carga() {
    int n = 0;
    for (int i = 0; i < M; i++) {
        No* atual = tabela[i];
        while (atual) {
            n++;
            atual = atual->prox;
        }
    }
    return (double)n / (double)M;
}

int main() {
    inicializar();

    inserir(12345, "Ana");
    inserir(67890, "Bruno");
    inserir(11113, "Carla");
    inserir(22226, "Daniel");
    inserir(33339, "Ellen");
    inserir(44442, "Felipe");
    inserir(26, "Gabi");
    inserir(39, "Heitor");

    imprimir();

    int consultas[] = {12345, 39, 77777};
    for (int i = 0; i < 3; i++) {
        const char* achou = buscar(consultas[i]);
        if (achou) {
            printf("BUSCA: RA %d -> %s\n", consultas[i], achou);
        } else {
            printf("BUSCA: RA %d -> NAO ENCONTRADO\n", consultas[i]);
        }
    }

    printf("\nFator de carga aproximado: %.2f\n", fator_de_carga());

    destruir();
    return 0;
}
```

