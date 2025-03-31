
# Aula: Pilha em C — Implementação Estática e Dinâmica

## 🎯 Objetivos da Aula
- Compreender o conceito de Pilha (Stack)
- Entender o funcionamento do comportamento LIFO (Last In, First Out)
- Implementar uma pilha de forma:
    - Estática (com vetor)
    - Dinâmica (com lista ligada)
- Praticar com exemplos e visualizar o funcionamento passo a passo

---

## 📢 O que é uma Pilha?

Uma **Pilha** é uma estrutura de dados baseada no princípio **LIFO**:

> O último elemento a entrar é o primeiro a sair. (Last In, First Out)

### Exemplo do mundo real:

Imagine uma pilha de pratos:
- Você só consegue colocar ou retirar um prato pelo topo.
- Não dá para tirar o prato do meio sem antes tirar os de cima.

### Operações básicas de uma pilha:

| Operação | Descrição |
|----------|-----------|
| `push`   | Inserir um elemento no topo |
| `pop`    | Remover o elemento do topo |
| `top` ou `peek` | Ver o elemento que está no topo (sem remover) |
| `isEmpty` | Verificar se a pilha está vazia |

---

# 🟣 Parte 1 — Pilha Estática (usando vetor)

## 💡 Estrutura da pilha estática

```c
#define MAX 100

typedef struct {
    int dados[MAX]; // vetor que armazena os dados
    int topo;       // posição do topo
} Pilha;
```

## 🔄 Inicialização

```c
void inicializar(Pilha* p) {
    p->topo = -1; // indica que a pilha está vazia
}
```

## ✅ Inserção (push)

```c
int push(Pilha* p, int valor) {
    if (p->topo == MAX - 1) return 0; // pilha cheia
    p->topo++;
    p->dados[p->topo] = valor;
    return 1; // sucesso
}
```

## ✅ Remoção (pop)

```c
int pop(Pilha* p, int* valor) {
    if (p->topo == -1) return 0; // pilha vazia
    *valor = p->dados[p->topo];
    p->topo--;
    return 1; // sucesso
}
```

## ✅ Visualizar o topo (peek)

```c
int peek(Pilha* p, int* valor) {
    if (p->topo == -1) return 0; // pilha vazia
    *valor = p->dados[p->topo];
    return 1;
}
```

## Exemplo completo — Pilha Estática

```c
#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int push(Pilha* p, int valor) {
    if (p->topo == MAX - 1) return 0;
    p->topo++;
    p->dados[p->topo] = valor;
    return 1;
}

int pop(Pilha* p, int* valor) {
    if (p->topo == -1) return 0;
    *valor = p->dados[p->topo];
    p->topo--;
    return 1;
}

int peek(Pilha* p, int* valor) {
    if (p->topo == -1) return 0;
    *valor = p->dados[p->topo];
    return 1;
}

int main() {
    Pilha p;
    int valor;
    inicializar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    peek(&p, &valor);
    printf("Topo da pilha: %d\n", valor);

    pop(&p, &valor);
    printf("Elemento removido: %d\n", valor);

    peek(&p, &valor);
    printf("Topo atual da pilha: %d\n", valor);

    return 0;
}
```

---

# 🟣 Parte 2 — Pilha Dinâmica (usando lista ligada)

## 💡 Estrutura do Nó

```c
typedef struct No {
    int valor;
    struct No* proximo;
} No;
```

## 💡 Estrutura da Pilha Dinâmica

```c
typedef struct {
    No* topo;
} Pilha;
```

## 🔄 Inicialização

```c
void inicializar(Pilha* p) {
    p->topo = NULL;
}
```

## ✅ Inserção (push)

```c
void push(Pilha* p, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}
```

## ✅ Remoção (pop)

```c
int pop(Pilha* p, int* valor) {
    if (p->topo == NULL) return 0; // pilha vazia
    No* temp = p->topo;
    *valor = temp->valor;
    p->topo = temp->proximo;
    free(temp);
    return 1;
}
```

## ✅ Ver o topo (peek)

```c
int peek(Pilha* p, int* valor) {
    if (p->topo == NULL) return 0;
    *valor = p->topo->valor;
    return 1;
}
```

## Exemplo Completo — Pilha Dinâmica

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
}

void push(Pilha* p, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

int pop(Pilha* p, int* valor) {
    if (p->topo == NULL) return 0;
    No* temp = p->topo;
    *valor = temp->valor;
    p->topo = temp->proximo;
    free(temp);
    return 1;
}

int peek(Pilha* p, int* valor) {
    if (p->topo == NULL) return 0;
    *valor = p->topo->valor;
    return 1;
}

int main() {
    Pilha p;
    int valor;
    inicializar(&p);

    push(&p, 100);
    push(&p, 200);
    push(&p, 300);

    peek(&p, &valor);
    printf("Topo da pilha: %d\n", valor);

    pop(&p, &valor);
    printf("Elemento removido: %d\n", valor);

    peek(&p, &valor);
    printf("Topo atual da pilha: %d\n", valor);

    return 0;
}
```

---

## ✅ Comparando Estática vs Dinâmica

| Característica | Pilha Estática | Pilha Dinâmica |
|----------------|----------------|----------------|
| Tamanho        | Fixo (MAX)      | Ilimitado (depende da memória) |
| Uso de ponteiros | Não            | Sim |
| Uso de memória  | Pré-alocado    | Aloca sob demanda |
| Facilidade de uso | Mais simples | Mais flexível |
