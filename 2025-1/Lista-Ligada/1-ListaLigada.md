
# 🧠  Lista Ligada em C (Implementações Estática e Dinâmica)

## 📌 Objetivo

Vamos aprender  o conceito de **Lista Ligada** e como implementá-la na linguagem C de duas maneiras:

- 🧱 **Estática** (usando vetores e índices);
- 🔗 **Dinâmica** (usando ponteiros e alocação de memória).

Além disso, discutiremos as **vantagens, desvantagens** e **diferenças principais** entre essas abordagens.

---

### 🔗 Estrutura de uma Lista Ligada

A figura a seguir representa o funcionamento de uma **lista ligada simples**, uma estrutura de dados dinâmica amplamente utilizada em algoritmos e sistemas que requerem flexibilidade na manipulação de elementos.

![Lista Ligada](https://github.com/ICTIN-UFLA/AED-Johnatan-2024-1/blob/main/2025-1/Lista-Ligada/img/listaencadeada.png)

#### 🧠 Explicação da estrutura:

- **P**: Ponteiro que indica o **início da lista**, ou seja, o primeiro nó.
- Cada **nó** da lista possui duas partes:
  - Um campo para o **dado armazenado** (representado por `x`);
  - Um ponteiro para o **próximo nó** da lista (por exemplo, o nó A aponta para o nó B).
- Os nós são conectados sequencialmente, formando uma cadeia.
- O último elemento, indicado por **F**, possui um ponteiro que aponta para `NULL`, indicando o fim da lista.

#### 🧾 Considerações técnicas:

- Essa estrutura permite **inserções e remoções eficientes**, especialmente em cenários onde o custo de deslocamento de elementos (como em vetores) é indesejado.
- O acesso aos elementos é feito **sequencialmente**, seguindo os ponteiros, o que implica em custo linear para buscas em geral.
- É uma estrutura fundamental para o entendimento de outras abstrações, como pilhas, filas e árvores.

## 📖 O que é uma Lista Ligada?

Uma **lista ligada** é uma estrutura de dados linear que armazena elementos (nós) de forma encadeada, ou seja, cada elemento aponta para o próximo.

Diferente dos vetores tradicionais, as listas ligadas não precisam de um tamanho fixo definido previamente, o que oferece flexibilidade.

### 🔍 Componentes de um nó:
- **Informação/dado**: o valor armazenado.
- **Ponteiro (ou índice)**: referência ao próximo nó.

---

## 📘 Parte 1: Lista Ligada Estática (com vetores)

### 🧱 Como funciona?

Na implementação estática, usamos **vetores de structs** e um campo de índice para simular os "ponteiros".

### 📦 Estrutura do nó:

```c
#define MAX 100

typedef struct {
    int valor;
    int proximo; // Índice do próximo nó
} NoEstatico;

typedef struct {
    NoEstatico nos[MAX];
    int inicio;
    int disponivel;
} ListaEstatica;
```

### 🚧 Inicialização:

```c
void inicializarLista(ListaEstatica *lista) {
    lista->inicio = -1;
    lista->disponivel = 0;
    for (int i = 0; i < MAX - 1; i++) {
        lista->nos[i].proximo = i + 1;
    }
    lista->nos[MAX - 1].proximo = -1; // Fim da lista de disponíveis
}
```

### ➕ Inserção no início:

```c
void inserirInicio(ListaEstatica *lista, int valor) {
    if (lista->disponivel == -1) {
        printf("Lista cheia.\n");
        return;
    }
    int novo = lista->disponivel;
    lista->disponivel = lista->nos[novo].proximo;

    lista->nos[novo].valor = valor;
    lista->nos[novo].proximo = lista->inicio;

    lista->inicio = novo;
}
```

### 📤 Impressão:

```c
void imprimirLista(ListaEstatica *lista) {
    int atual = lista->inicio;
    while (atual != -1) {
        printf("%d -> ", lista->nos[atual].valor);
        atual = lista->nos[atual].proximo;
    }
    printf("NULL\n");
}
```

---

## 📗 Parte 2: Lista Ligada Dinâmica (com ponteiros)

### 🔗 Como funciona?

Na abordagem dinâmica, usamos ponteiros e alocação de memória com `malloc()`.

### 📦 Estrutura do nó:

```c
typedef struct NoDinamico {
    int valor;
    struct NoDinamico *proximo;
} NoDinamico;
```

### ➕ Inserção no início:

```c
void inserirInicio(NoDinamico **inicio, int valor) {
    NoDinamico *novo = (NoDinamico*) malloc(sizeof(NoDinamico));
    if (novo == NULL) {
        printf("Erro de alocação.\n");
        return;
    }
    novo->valor = valor;
    novo->proximo = *inicio;
    *inicio = novo;
}
```

### 📤 Impressão:

```c
void imprimirLista(NoDinamico *inicio) {
    NoDinamico *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}
```

### 🧹 Liberação de memória:

```c
void liberarLista(NoDinamico *inicio) {
    NoDinamico *atual = inicio;
    while (atual != NULL) {
        NoDinamico *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
```

---

## ⚖️ Comparação: Estática vs Dinâmica

| Aspecto                     | Estática                           | Dinâmica                           |
|----------------------------|------------------------------------|------------------------------------|
| Crescimento                | Limitado (tamanho fixo)            | Flexível (depende da memória)      |
| Alocação                   | Feita uma vez                      | Sob demanda (`malloc`)             |
| Liberação de memória       | Implícita (fim do programa)        | Explícita (`free`) necessária      |
| Velocidade de acesso       | Rápida (índice direto)             | Mais lenta (ponteiros)             |
| Complexidade de implementação | Mais simples                      | Mais complexa                      |
| Indicado para              | Listas com tamanho conhecido       | Listas de tamanho variável         |

---

## 🧪 Exemplo de uso completo

### 🌐 Estático

```c
int main() {
    ListaEstatica lista;
    inicializarLista(&lista);
    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);
    imprimirLista(&lista);
    return 0;
}
```

### 🌐 Dinâmico

```c
int main() {
    NoDinamico *lista = NULL;
    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);
    imprimirLista(lista);
    liberarLista(lista);
    return 0;
}
```

---

## ✅ Conclusão

Você aprendeu:

- O que é uma lista ligada;
- Como implementar de forma **estática e dinâmica** em C;
- Quais as **vantagens e desvantagens** de cada abordagem.

Se este conteúdo te ajudou, ⭐ dê uma estrela no repositório!

---

## 🧠 Desafios

1. Implemente a função `removerInicio()` nas duas versões.
2. Implemente inserção no **final** da lista.
3. Implemente busca de um elemento.

---

## 📎 Licença

Este conteúdo está sob a Licença MIT. Sinta-se à vontade para copiar, usar, e contribuir!
