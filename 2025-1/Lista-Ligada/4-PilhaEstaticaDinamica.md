
# 📚  Pilha em C (Implementações Estática e Dinâmica)

## 📌 Objetivo

Você vai aprender a  implementar a estrutura de dados **Pilha (Stack)** na linguagem C, tanto na forma:

- 🧱 **Estática** (usando vetor);
- 🔗 **Dinâmica** (usando ponteiros e alocação de memória).

---

## 📚 O que é uma Pilha?

Uma **pilha (stack)** é uma estrutura de dados do tipo **LIFO** (_Last In, First Out_), onde o **último elemento inserido é o primeiro a ser removido**.

### 📥 Operações principais:

- `push`: inserir elemento no topo;
- `pop`: remover elemento do topo;
- `top` ou `peek`: acessar o topo sem remover.

---

## 📘 Parte 1: Implementação Estática

### 🧱 Estrutura

```c
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} PilhaEstatica;
```

---

### 🚀 Inicializar

```c
void inicializar(PilhaEstatica *p) {
    p->topo = -1;
}
```

---

### ➕ Push

```c
void push(PilhaEstatica *p, int valor) {
    if (p->topo == MAX - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = valor;
}
```

---

### ➖ Pop

```c
int pop(PilhaEstatica *p) {
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[(p->topo)--];
}
```

---

### 🔍 Topo

```c
int topo(PilhaEstatica *p) {
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo];
}
```

---

## 📗 Parte 2: Implementação Dinâmica

### 📦 Estrutura

```c
typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} PilhaDinamica;
```

---

### 🚀 Inicializar

```c
void inicializarDinamica(PilhaDinamica *p) {
    p->topo = NULL;
}
```

---

### ➕ Push

```c
void pushDinamico(PilhaDinamica *p, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação!\n");
        return;
    }
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}
```

---

### ➖ Pop

```c
int popDinamico(PilhaDinamica *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    No *temp = p->topo;
    int valor = temp->valor;
    p->topo = temp->proximo;
    free(temp);
    return valor;
}
```

---

### 🔍 Topo

```c
int topoDinamico(PilhaDinamica *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->topo->valor;
}
```

---

### 🧹 Liberação

```c
void liberarPilha(PilhaDinamica *p) {
    No *atual = p->topo;
    while (atual) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
```

---

## ⚖️ Comparação: Estática vs Dinâmica

| Aspecto             | Estática                         | Dinâmica                      |
|---------------------|----------------------------------|-------------------------------|
| Tamanho             | Fixo (limite pré-definido)       | Flexível (aloca sob demanda) |
| Uso de memória      | Pode desperdiçar espaço          | Usa só o necessário           |
| Velocidade          | Mais rápida                      | Pode ser mais lenta           |
| Complexidade        | Mais simples                     | Exige gerenciamento de memória |

---

## 🧪 Exemplo de Uso

### 🌐 Estática

```c
int main() {
    PilhaEstatica p;
    inicializar(&p);
    push(&p, 10);
    push(&p, 20);
    printf("Topo: %d\n", topo(&p));
    printf("Pop: %d\n", pop(&p));
    return 0;
}
```

### 🌐 Dinâmica

```c
int main() {
    PilhaDinamica p;
    inicializarDinamica(&p);
    pushDinamico(&p, 10);
    pushDinamico(&p, 20);
    printf("Topo: %d\n", topoDinamico(&p));
    printf("Pop: %d\n", popDinamico(&p));
    liberarPilha(&p);
    return 0;
}
```

---

## 🧠 Desafios

1. Implemente a função `imprimirPilha()` nas duas versões.
2. Adicione verificação de tamanho na pilha dinâmica.
3. Crie uma pilha genérica usando `void*` e ponteiros para função.

---

## ✅ Conclusão

Você aprendeu:

- O conceito de pilha (LIFO);
- Como implementar pilha de forma estática e dinâmica;
- Vantagens, desvantagens e aplicação prática.

---

## 📎 Licença

Este conteúdo está sob a Licença MIT. Sinta-se à vontade para compartilhar e contribuir!
