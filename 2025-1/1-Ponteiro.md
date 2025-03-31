
# Aula: Ponteiros e Lista Linear Sequencial em Linguagem C

## 🎯 Objetivos da Aula
- Entender o conceito de ponteiros em C
- Compreender o que é uma lista linear sequencial (vetor dinâmico)
- Implementar uma lista linear sequencial em C usando ponteiros
- Resolver um exercício prático

---

## ✅ Ponteiros em C

### O que é um Ponteiro?

Um ponteiro é uma variável que armazena o **endereço de memória** de outra variável.

### Exemplo básico:

```c
#include <stdio.h>

int main() {
    int x = 10;
    int* p = &x; // ponteiro p aponta para x

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Valor de p (endereço de x): %p\n", p);
    printf("Conteúdo apontado por p: %d\n", *p); // desreferenciação

    return 0;
}
```

---

## ✅ Lista Linear Sequencial

### Definição

A lista linear sequencial é uma estrutura baseada em **vetor**. Seus elementos estão armazenados em posições sequenciais da memória.

### Estrutura da Lista

```c
#define MAX 100

typedef struct {
    int dados[MAX];
    int n; // quantidade de elementos armazenados
} Lista;
```

- `dados[MAX]` é o vetor que armazena os dados.
- `n` indica o número de elementos da lista.

---

## 📌 Funções Básicas

### Criar Lista (inicializar)

```c
void inicializar(Lista* l) {
    l->n = 0;
}
```

### Inserir Elemento no Final

```c
int inserirFinal(Lista* l, int valor) {
    if (l->n == MAX) return 0;
    l->dados[l->n++] = valor;
    return 1;
}
```

### Remover Último Elemento

```c
int removerFinal(Lista* l) {
    if (l->n == 0) return 0;
    l->n--;
    return 1;
}
```

### Imprimir Lista

```c
void imprimir(Lista* l) {
    for(int i = 0; i < l->n; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}
```

---

## Exemplo Completo

```c
#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int n;
} Lista;

void inicializar(Lista* l) {
    l->n = 0;
}

int inserirFinal(Lista* l, int valor) {
    if (l->n == MAX) return 0;
    l->dados[l->n++] = valor;
    return 1;
}

int removerFinal(Lista* l) {
    if (l->n == 0) return 0;
    l->n--;
    return 1;
}

void imprimir(Lista* l) {
    for(int i = 0; i < l->n; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

int main() {
    Lista l;
    inicializar(&l);

    inserirFinal(&l, 10);
    inserirFinal(&l, 20);
    inserirFinal(&l, 30);

    printf("Lista após inserções:\n");
    imprimir(&l);

    removerFinal(&l);
    printf("Lista após remoção do último elemento:\n");
    imprimir(&l);

    return 0;
}
```

---

## ✅ Exercício Resolvido

> Implemente uma função que insere um valor na **posição específica** da lista.

### Solução:

```c
int inserirPosicao(Lista* l, int valor, int pos) {
    if (l->n == MAX || pos < 0 || pos > l->n) return 0;
    
    for(int i = l->n; i > pos; i--) {
        l->dados[i] = l->dados[i-1];
    }
    
    l->dados[pos] = valor;
    l->n++;
    return 1;
}
```

### Testando no `main`

```c
inserirPosicao(&l, 15, 1); // Insere 15 na posição 1
printf("Lista após inserção na posição 1:\n");
imprimir(&l);
```

---

## Comparação: Lista Sequencial x Lista Ligada

| Característica         | Lista Sequencial | Lista Ligada |
|------------------------|-----------------|--------------|
| Crescimento            | Limitado (MAX)  | Ilimitado (memória disponível) |
| Inserção/Remoção        | Pode ter custo de deslocamento | Simples (com ponteiros) |
| Acesso direto (índices) | Sim             | Não          |
