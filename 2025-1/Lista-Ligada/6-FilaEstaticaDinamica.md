
# 🚦 Fila em C (Implementações Estática e Dinâmica)

## 📌 Objetivo

Você aprenderá a implementar a estrutura de dados **Fila (Queue)** em C, utilizando:

- 🧱 Implementação **Estática** (com vetores);
- 🔗 Implementação **Dinâmica** (com ponteiros e alocação de memória).

---

## 📚 O que é uma Fila?

Uma **fila** é uma estrutura de dados baseada na regra **FIFO** (_First In, First Out_). O primeiro elemento inserido é o primeiro a sair.

### 🧭 Operações principais:

- `enqueue`: inserir elemento no final;
- `dequeue`: remover elemento do início;
- `peek`: visualizar o primeiro elemento sem removê-lo.

---

## 📘 Parte 1: Fila Estática

### 🧱 Estrutura

```c
#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaEstatica;
```

---

### 🚀 Inicialização

```c
void inicializar(FilaEstatica *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}
```

---

### ➕ Enqueue

```c
void enqueue(FilaEstatica *f, int valor) {
    if (f->tamanho == MAX) {
        printf("Fila cheia!\n");
        return;
    }
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = valor;
    f->tamanho++;
}
```

---

### ➖ Dequeue

```c
int dequeue(FilaEstatica *f) {
    if (f->tamanho == 0) {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return valor;
}
```

---

### 🔍 Peek

```c
int peek(FilaEstatica *f) {
    if (f->tamanho == 0) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->dados[f->inicio];
}
```

---

## 📗 Parte 2: Fila Dinâmica

### 📦 Estrutura

```c
typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} FilaDinamica;
```

---

### 🚀 Inicializar

```c
void inicializarDinamica(FilaDinamica *f) {
    f->inicio = NULL;
    f->fim = NULL;
}
```

---

### ➕ Enqueue

```c
void enqueueDinamico(FilaDinamica *f, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (f->fim != NULL)
        f->fim->proximo = novo;
    else
        f->inicio = novo;

    f->fim = novo;
}
```

---

### ➖ Dequeue

```c
int dequeueDinamico(FilaDinamica *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }

    No *temp = f->inicio;
    int valor = temp->valor;
    f->inicio = temp->proximo;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);
    return valor;
}
```

---

### 🔍 Peek

```c
int peekDinamico(FilaDinamica *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->inicio->valor;
}
```

---

### 🧹 Liberação

```c
void liberarFila(FilaDinamica *f) {
    No *atual = f->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
```

---

## ⚖️ Comparação: Estática vs Dinâmica

| Característica       | Fila Estática                   | Fila Dinâmica                   |
|----------------------|----------------------------------|----------------------------------|
| Crescimento          | Limitado (tamanho fixo)          | Flexível (alocação sob demanda) |
| Uso de memória       | Pré-alocado                      | Aloca apenas o necessário       |
| Complexidade         | Simples                          | Requer ponteiros                |
| Velocidade           | Alta (sem alocação)              | Levemente menor (malloc/free)   |

---

## 🧪 Exemplo de Uso

### 🌐 Estática

```c
int main() {
    FilaEstatica f;
    inicializar(&f);
    enqueue(&f, 10);
    enqueue(&f, 20);
    printf("Primeiro: %d\n", peek(&f));
    printf("Removido: %d\n", dequeue(&f));
    return 0;
}
```

### 🌐 Dinâmica

```c
int main() {
    FilaDinamica f;
    inicializarDinamica(&f);
    enqueueDinamico(&f, 10);
    enqueueDinamico(&f, 20);
    printf("Primeiro: %d\n", peekDinamico(&f));
    printf("Removido: %d\n", dequeueDinamico(&f));
    liberarFila(&f);
    return 0;
}
```

---

## 🧠 Desafios

1. Implemente uma fila de strings (char*).
2. Adicione contagem de elementos na fila dinâmica.
3. Implemente `imprimirFila()` em ambas as versões.

---

## ✅ Conclusão

Você aprendeu:

- O conceito de fila e seu funcionamento;
- Como implementar com vetores e com ponteiros;
- As vantagens e desvantagens de cada abordagem.

---

## 📎 Licença

Este conteúdo está sob a Licença MIT. Sinta-se à vontade para usar, modificar e compartilhar!
