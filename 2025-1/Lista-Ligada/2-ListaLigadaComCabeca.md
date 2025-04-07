
# 🧠 Lista Ligada Simples com Nó Cabeça em C

## 📌 Objetivo

Você vai aprender a implementar uma **Lista Ligada Simples com Nó Cabeça** na linguagem C, mesmo sem ser circular.

---

## 🧩 O que é um Nó Cabeça?

Um **nó cabeça** é um nó especial usado no início da lista. Ele:

- Não armazena dados relevantes (valor simbólico);
- Serve como ponto fixo de entrada;
- Facilita operações de inserção e remoção.

---

## 🆚 Com ou Sem Nó Cabeça?

| Característica             | Com Nó Cabeça             | Sem Nó Cabeça             |
|---------------------------|---------------------------|---------------------------|
| Estrutura inicial         | Sempre tem um nó fixo     | Pode ser `NULL` no início |
| Inserção no início        | Mais simples              | Requer tratamento especial |
| Remoção                   | Não precisa tratar o primeiro nó como caso especial | Precisa de código adicional |
| Código                    | Mais uniforme             | Mais verboso              |

---

## 🔧 Estrutura da Lista

```c
typedef struct No {
    int valor;
    struct No *proximo;
} No;
```

---

## 🚀 Criar Lista

```c
No* criarLista() {
    No *cabeca = (No*) malloc(sizeof(No));
    if (cabeca == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    cabeca->proximo = NULL;
    cabeca->valor = -1; // valor simbólico
    return cabeca;
}
```

---

## ➕ Inserção no Início

```c
void inserirInicio(No *cabeca, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação.\n");
        return;
    }
    novo->valor = valor;
    novo->proximo = cabeca->proximo;
    cabeca->proximo = novo;
}
```

---

## ➖ Remoção de um Elemento

```c
void removerElemento(No *cabeca, int valor) {
    No *anterior = cabeca;
    No *atual = cabeca->proximo;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Elemento %d não encontrado.\n", valor);
        return;
    }

    anterior->proximo = atual->proximo;
    free(atual);
}
```

---

## 📤 Impressão da Lista

```c
void imprimirLista(No *cabeca) {
    No *atual = cabeca->proximo;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}
```

---

## 🧹 Liberação de Memória

```c
void liberarLista(No *cabeca) {
    No *atual = cabeca;
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
    No *lista = criarLista();

    inserirInicio(lista, 10);
    inserirInicio(lista, 20);
    inserirInicio(lista, 30);

    imprimirLista(lista);

    removerElemento(lista, 20);
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}
```

---

## ✅ Conclusão

Você aprendeu:

- O que é uma lista ligada simples com nó cabeça;
- Como implementar inserção, remoção e impressão;
- As vantagens de usar nó cabeça mesmo sem lista circular.

---

## 🧠 Desafios

1. Implemente inserção ordenada.
2. Adicione contagem de elementos na lista.
3. Adapte para usar tipo `float` ao invés de `int`.

---

## 📎 Licença

Este conteúdo está sob a Licença MIT. Sinta-se à vontade para usar e compartilhar!
