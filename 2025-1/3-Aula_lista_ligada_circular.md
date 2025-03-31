
# Aula Didática: Lista Ligada Circular com Nó Cabeça

## ✅ O que você vai aprender?
- O que é uma lista ligada circular
- O que é o nó cabeça e por que ele é útil
- Como construir, inserir, remover e imprimir uma lista ligada circular em C
- Um exemplo completo com passo a passo

---

## 🟣 O que é uma Lista Ligada Circular?

Uma **lista ligada** normal é uma sequência de nós onde cada nó aponta para o próximo e o último nó aponta para `NULL`.

Já uma **lista ligada circular** tem a seguinte diferença:
- O último nó **não aponta para NULL**, ele aponta de volta para o primeiro nó (ou para o nó cabeça).
- Isso cria um **ciclo**: é possível percorrer a lista indefinidamente.

---

## 🟣 O que é o Nó Cabeça?

O **nó cabeça** é um nó especial que:
- Não armazena valores úteis (geralmente).
- Serve como um marcador fixo de onde a lista começa e termina.
- Facilita muito operações como inserção e remoção, principalmente em listas circulares.

---

## 🔔 Exemplo Visual

### Lista Circular **com cabeça**:

```
+---------+
| CABEÇA  | --> +----+    +----+    +----+ 
+---------+     | 10 | -> | 20 | -> | 30 | 
    ^           +----+    +----+    +----+
    |                                   |
    +-----------------------------------+
```

- O `CABEÇA` sempre aponta para o primeiro nó.
- O último nó sempre aponta de volta para o `CABEÇA`.
- Isso cria um "anel" ou "círculo".

---

## 📄 Estrutura em C

```c
typedef struct No {
    int valor;
    struct No* proximo;
} No;
```

---

## 💡 Criando a Cabeça

```c
No* criarCabeca() {
    No* cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = cabeca; // aponta para si mesma (lista vazia)
    return cabeca;
}
```

Quando a lista está vazia:
- `cabeca->proximo == cabeca`

---

## 🟣 Inserção Sempre Após a Cabeça

```c
void inserir(No* cabeca, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = cabeca->proximo;
    cabeca->proximo = novo;
}
```

Isso insere o novo nó logo após a cabeça e o ciclo permanece intacto.

---

## 🟣 Impressão da Lista Circular

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

### Observação:
- Usamos `do...while` porque sempre queremos visitar ao menos o primeiro elemento.

---

## 🟣 Remoção do Primeiro Nó da Lista

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

A cabeça facilita a remoção pois:
- Não precisamos verificar caso especial para quando o elemento removido seja o único da lista.
- Basta `cabeca->proximo` saltar o nó a ser removido.

---

## Exemplo Completo e Comentado

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

    printf("Inserindo 10, 20 e 30\n");
    inserir(cabeca, 30);
    inserir(cabeca, 20);
    inserir(cabeca, 10);

    printf("Lista atual:\n");
    imprimir(cabeca);

    printf("Removendo o primeiro elemento...\n");
    removerPrimeiro(cabeca);
    imprimir(cabeca);

    return 0;
}
```

---

## 🟣 Vantagens da Lista Circular com Cabeça
| Vantagem | Por quê? |
| -------- | -------- |
| Evita NULL | Nunca precisamos checar se `proximo == NULL` |
| Facilita inserção | Sempre podemos inserir logo após a cabeça |
| Facilita remoção | Remover o primeiro elemento é simples |
| Estrutura circular | Útil para problemas que precisam "voltar ao início" automaticamente |
