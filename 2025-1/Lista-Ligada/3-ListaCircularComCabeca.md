
# 🔄  Lista Ligada Circular com Nó Cabeça em C

## 📌 Objetivo

Vamos estudar como implementar uma **Lista Ligada Circular com Nó Cabeça** em C, abordando:

- A estrutura e funcionamento de uma lista circular;
- O papel do nó cabeça;
- Implementação passo a passo;
- Inserção, remoção e impressão de elementos;
- Diferenças em relação à lista ligada simples.

---

## 🔍 O que é uma Lista Ligada Circular?

Uma **lista ligada circular** é uma variação da lista ligada em que o último nó aponta de volta para o primeiro, formando um ciclo.

### 🎯 Vantagens:
- Navegação contínua;
- Útil em sistemas circulares (ex: agendamento, buffers circulares).

---

## 🎩 O que é o Nó Cabeça?

O **nó cabeça** é um nó especial que:
- Não armazena dados válidos do usuário;
- Serve como ponto fixo de acesso à lista;
- Facilita operações como inserção e remoção, evitando verificações adicionais (ex: se a lista está vazia).

---

## 🧱 Estrutura de Dados

```c
typedef struct No {
    int valor;
    struct No *proximo;
} No;
```

---

## ⚙️ Inicialização da Lista

```c
No* criarLista() {
    No *cabeca = (No*) malloc(sizeof(No));
    if (cabeca == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    cabeca->valor = -1; // Valor simbólico
    cabeca->proximo = cabeca; // Lista vazia: aponta para si mesma
    return cabeca;
}
```

---

## ➕ Inserção no Final

```c
void inserirFinal(No *cabeca, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação.\n");
        return;
    }
    novo->valor = valor;

    No *atual = cabeca;
    while (atual->proximo != cabeca) {
        atual = atual->proximo;
    }

    novo->proximo = cabeca;
    atual->proximo = novo;
}
```

---

## ➖ Remoção de um Elemento

```c
void removerElemento(No *cabeca, int valor) {
    No *anterior = cabeca;
    No *atual = cabeca->proximo;

    while (atual != cabeca && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == cabeca) {
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
    if (atual == cabeca) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista: ");
    while (atual != cabeca) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("(volta ao início)\n");
}
```

---

## 🧹 Liberação de Memória

```c
void liberarLista(No *cabeca) {
    No *atual = cabeca->proximo;
    while (atual != cabeca) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(cabeca);
}
```

---

## 🧪 Exemplo de uso

```c
int main() {
    No *lista = criarLista();

    inserirFinal(lista, 10);
    inserirFinal(lista, 20);
    inserirFinal(lista, 30);

    imprimirLista(lista);

    removerElemento(lista, 20);
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}
```

---

## 📊 Comparação com Lista Simples

| Aspecto                 | Lista Simples              | Lista Circular com Nó Cabeça |
|------------------------|----------------------------|-------------------------------|
| Navegação              | Termina em NULL            | Volta ao início               |
| Verificação de fim     | Necessária                 | Opcional                      |
| Nó cabeça              | Opcional                   | Necessário                    |
| Aplicações             | Gerais                     | Cíclicas, jogos, buffers      |

---

## 🧠 Desafios

1. Implemente inserção ordenada na lista circular.
2. Implemente uma função `buscarElemento()`.
3. Modifique a função de remoção para não usar `free()`, mas sim uma lista de nós livres (reciclagem).

---

## ✅ Conclusão

Você aprendeu:

- O que é uma lista circular com nó cabeça;
- Como implementar em C com ponteiros;
- Como manipular elementos dinamicamente;
- Comparações e aplicações.

---

## 📎 Licença

Este conteúdo está sob a Licença MIT. Sinta-se à vontade para usar e contribuir!
