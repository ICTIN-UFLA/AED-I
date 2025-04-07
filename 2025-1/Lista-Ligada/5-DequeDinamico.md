
# 🌀  Deque Dinâmico em C

## 📌 Objetivo

Você vai aprender a implementar um **Deque (Double Ended Queue)** de forma **dinâmica** usando ponteiros na linguagem C.

---

## 🧩 O que é um Deque?

Um **Deque** (fila dupla) é uma estrutura de dados que permite:

- Inserção e remoção **no início** (frente);
- Inserção e remoção **no final** (fundo).

### ✨ Vantagens:
- Flexibilidade de operações em ambas as extremidades;
- Combina características de pilha e fila.

---

## 🔧 Estrutura de Dados

```c
typedef struct No {
    int valor;
    struct No *anterior;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Deque;
```

---

## 🚀 Inicializar Deque

```c
void inicializarDeque(Deque *d) {
    d->inicio = NULL;
    d->fim = NULL;
}
```

---

## ➕ Inserção no Início

```c
void inserirInicio(Deque *d, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = d->inicio;

    if (d->inicio != NULL)
        d->inicio->anterior = novo;
    else
        d->fim = novo;

    d->inicio = novo;
}
```

---

## ➕ Inserção no Final

```c
void inserirFim(Deque *d, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = d->fim;

    if (d->fim != NULL)
        d->fim->proximo = novo;
    else
        d->inicio = novo;

    d->fim = novo;
}
```

---

## ➖ Remoção do Início

```c
int removerInicio(Deque *d) {
    if (d->inicio == NULL) {
        printf("Deque vazio!\n");
        return -1;
    }

    No *temp = d->inicio;
    int valor = temp->valor;
    d->inicio = temp->proximo;

    if (d->inicio != NULL)
        d->inicio->anterior = NULL;
    else
        d->fim = NULL;

    free(temp);
    return valor;
}
```

---

## ➖ Remoção do Final

```c
int removerFim(Deque *d) {
    if (d->fim == NULL) {
        printf("Deque vazio!\n");
        return -1;
    }

    No *temp = d->fim;
    int valor = temp->valor;
    d->fim = temp->anterior;

    if (d->fim != NULL)
        d->fim->proximo = NULL;
    else
        d->inicio = NULL;

    free(temp);
    return valor;
}
```

---

## 📤 Impressão do Deque

```c
void imprimirDeque(Deque *d) {
    No *atual = d->inicio;
    printf("Deque: ");
    while (atual != NULL) {
        printf("%d <-> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}
```

---

## 🧹 Liberação de Memória

```c
void liberarDeque(Deque *d) {
    No *atual = d->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
```

---

## 🧪 Exemplo de Uso

```c
int main() {
    Deque d;
    inicializarDeque(&d);

    inserirInicio(&d, 10);
    inserirFim(&d, 20);
    inserirInicio(&d, 5);

    imprimirDeque(&d);

    printf("Removido do início: %d\n", removerInicio(&d));
    printf("Removido do fim: %d\n", removerFim(&d));

    imprimirDeque(&d);

    liberarDeque(&d);
    return 0;
}
```

---

## 🧠 Desafios

1. Implemente `buscarElemento()` no deque.
2. Crie uma versão circular do deque.
3. Adicione contagem de elementos.

---

## ✅ Conclusão

Você aprendeu:

- O que é um deque e como ele funciona;
- Como implementar com alocação dinâmica;
- Como fazer inserção e remoção em ambas as extremidades.

---

## 📎 Licença

Este conteúdo está sob a Licença MIT. Sinta-se à vontade para usar e compartilhar!
