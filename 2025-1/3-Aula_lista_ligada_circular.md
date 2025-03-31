
# Aula: Lista Ligada Circular com Nó Cabeça

## 🎯 Objetivos da Aula
- Compreender o conceito de **lista ligada circular**
- Entender o papel do **nó cabeça**
- Implementar a estrutura em C
- Realizar operações básicas: inserção, remoção e impressão

---

## ✅ O que é uma Lista Ligada Circular?

A **lista ligada circular** é uma variação da lista ligada tradicional onde o último nó aponta de volta para o primeiro, formando um "ciclo" ou "anel".

## ✅ O que é um Nó Cabeça?

O **nó cabeça** (ou nó sentinela) é um nó especial que **não armazena dados úteis**, servindo apenas como um ponto de referência fixo para facilitar as operações.

---

## ✅ Estrutura da Lista Ligada Circular com Cabeça

### Representação Gráfica:

```
[cabeça] -> [10] -> [20] -> [30] -> [cabeça]
```

Perceba que:
- A lista nunca termina em `NULL`.
- O ponteiro `proximo` do último nó aponta de volta para a cabeça.

---

## 📄 Definição do Nó

```c
typedef struct No {
    int valor;
    struct No* proximo;
} No;
```

---

## ✅ Criando a Cabeça da Lista

```c
No* criarCabeca() {
    No* cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = cabeca; // aponta para si mesma inicialmente
    return cabeca;
}
```

---

## ✅ Inserção Após a Cabeça

```c
void inserir(No* cabeca, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;

    novo->proximo = cabeca->proximo;
    cabeca->proximo = novo;
}
```

---

## ✅ Impressão da Lista

```c
void imprimir(No* cabeca) {
    No* atual = cabeca->proximo;
    
    if (atual == cabeca) {
        printf("Lista vazia!\n");
        return;
    }

    do {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    } while (atual != cabeca);
    
    printf("(volta para cabeça)\n");
}
```

---

## ✅ Remoção do Primeiro Elemento

```c
void removerPrimeiro(No* cabeca) {
    if (cabeca->proximo == cabeca) {
        printf("Lista vazia!\n");
        return;
    }

    No* temp = cabeca->proximo;
    cabeca->proximo = temp->proximo;
    free(temp);
}
```

---

## ✅ Exemplo Completo

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* criarCabeca() {
    No* cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = cabeca;
    return cabeca;
}

void inserir(No* cabeca, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = cabeca->proximo;
    cabeca->proximo = novo;
}

void imprimir(No* cabeca) {
    No* atual = cabeca->proximo;
    if (atual == cabeca) {
        printf("Lista vazia!\n");
        return;
    }
    do {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    } while (atual != cabeca);
    printf("(volta para cabeça)\n");
}

void removerPrimeiro(No* cabeca) {
    if (cabeca->proximo == cabeca) {
        printf("Lista vazia!\n");
        return;
    }
    No* temp = cabeca->proximo;
    cabeca->proximo = temp->proximo;
    free(temp);
}

int main() {
    No* cabeca = criarCabeca();

    inserir(cabeca, 30);
    inserir(cabeca, 20);
    inserir(cabeca, 10);

    printf("Lista após inserções:\n");
    imprimir(cabeca);

    removerPrimeiro(cabeca);
    printf("Lista após remover o primeiro elemento:\n");
    imprimir(cabeca);

    return 0;
}
```

---

## ✅ Observações Importantes:
- Evita problemas de `NULL` pois sempre retorna para a cabeça.
- A cabeça facilita tanto inserções quanto remoções.
- Ideal para algoritmos que precisam "circular" pela lista.
