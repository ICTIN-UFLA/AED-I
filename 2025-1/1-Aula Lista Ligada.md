
# Aula: Lista Ligada com e sem Cabeça em Linguagem C

## 📌 Objetivos da Aula
- Compreender o conceito de lista ligada
- Diferenciar lista ligada **com cabeça** e **sem cabeça**
- Implementar as duas versões em linguagem C
- Resolver um exercício prático

---

## O que é uma Lista Ligada?

Uma **lista ligada** (ou **lista encadeada**) é uma estrutura de dados dinâmica, composta por **nós** (ou **nodes**) conectados entre si, onde cada nó armazena:
1. Um dado/informação
2. Um ponteiro para o próximo nó da lista

> 💡 Ao contrário de vetores, listas ligadas não possuem tamanho fixo e podem crescer ou diminuir de acordo com a necessidade.

---

## 📄 Estrutura de um Nó em C

```c
typedef struct No {
    int valor;
    struct No* proximo;
} No;
```

---

## Lista Ligada **Sem Cabeça**

A lista **sem cabeça** é aquela cuja variável que armazena o início da lista já é o ponteiro para o primeiro elemento.

### Exemplo Gráfico

```
[10] -> [20] -> [30] -> NULL
```

Aqui `inicio` aponta direto para o primeiro nó que contém `10`.

### Exemplo de Código

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Inserção no início da lista sem cabeça
void inserir(No** inicio, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = *inicio;
    *inicio = novo;
}

// Impressão
void imprimir(No* inicio) {
    No* atual = inicio;
    while(atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    No* inicio = NULL;

    inserir(&inicio, 30);
    inserir(&inicio, 20);
    inserir(&inicio, 10);

    imprimir(inicio);

    return 0;
}
```

---

## Lista Ligada **Com Cabeça**

A lista **com cabeça** utiliza um nó especial no início da lista, chamado de **cabeça** (ou nó sentinela), que **não armazena dados úteis** e serve apenas para facilitar operações (inserção, remoção, etc.).

### Exemplo Gráfico

```
[CABEÇA] -> [10] -> [20] -> [30] -> NULL
```

A cabeça não guarda valores reais, mas sempre aponta para o primeiro elemento real da lista.

### Exemplo de Código

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Criação da cabeça
No* criarCabeca() {
    No* cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = NULL;
    return cabeca;
}

// Inserção no início (depois da cabeça)
void inserir(No* cabeca, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = cabeca->proximo;
    cabeca->proximo = novo;
}

// Impressão
void imprimir(No* cabeca) {
    No* atual = cabeca->proximo;
    while(atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    No* cabeca = criarCabeca();

    inserir(cabeca, 30);
    inserir(cabeca, 20);
    inserir(cabeca, 10);

    imprimir(cabeca);

    return 0;
}
```

---

## ✅ Comparativo Rápido

| Característica            | Lista sem cabeça | Lista com cabeça |
|---------------------------|-----------------|-----------------|
| Primeira posição           | Já é o primeiro nó | Nó especial antes do primeiro |
| Facilita inserção/remoção? | Não tanto        | Sim             |
| Ocupa memória extra?       | Não              | Sim (nó cabeça) |

---

## 🟣 Exercício Resolvido

> Crie uma função para remover o primeiro elemento de uma lista **com cabeça**.

### Solução

```c
void removerPrimeiro(No* cabeca) {
    if(cabeca->proximo == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    No* temp = cabeca->proximo;
    cabeca->proximo = temp->proximo;
    free(temp);
}
```

### Exemplo de uso:

```c
int main() {
    No* cabeca = criarCabeca();

    inserir(cabeca, 30);
    inserir(cabeca, 20);
    inserir(cabeca, 10);

    printf("Lista antes da remoção:\n");
    imprimir(cabeca);

    removerPrimeiro(cabeca);

    printf("Lista após remover o primeiro elemento:\n");
    imprimir(cabeca);

    return 0;
}
```
