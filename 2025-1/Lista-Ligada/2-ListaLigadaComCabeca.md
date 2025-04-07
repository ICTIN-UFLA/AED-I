
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


### 🧩 Exemplo: Lista Ligada Simples com Nó Cabeça


A figura abaixo ilustra a estrutura de uma **lista ligada simples** que utiliza um **nó cabeça**. Esse tipo de lista é composto por uma sequência de nós, onde cada nó armazena um dado e uma referência (ponteiro) para o próximo nó da lista.

![Lista Ligada com Nó Cabeça](https://github.com/ICTIN-UFLA/AED-Johnatan-2024-1/blob/main/2025-1/Lista-Ligada/img/cabeca.png)

## 🟥 Nó Cabeça (Head)

Representado na extremidade esquerda da figura com destaque em vermelho, o **nó cabeça** não armazena dados úteis da aplicação. Sua principal função é servir como ponto de partida da lista e facilitar operações como inserção e remoção no início da estrutura. Ele sempre aponta para o primeiro nó que contém dados válidos.

## 🟫 Nós de Dados

Os nós seguintes, com cor bege, armazenam os dados da lista. Cada nó possui dois campos:

- **Dado**: O valor armazenado no nó (pode ser um número, caractere, estrutura, etc.).
- **Próximo**: Um ponteiro que indica o próximo nó da lista.

## 🔚 Fim da Lista

O último nó da lista possui o campo "próximo" apontando para `NULL`, o que indica que não há mais elementos após ele.

---

Essa organização permite a **inserção e remoção dinâmica de elementos**, sem a necessidade de realocação de memória, sendo especialmente útil em cenários onde o número de elementos varia constantemente.




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
