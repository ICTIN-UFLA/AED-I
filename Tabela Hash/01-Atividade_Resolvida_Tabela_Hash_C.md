
# Atividade Prática Resolvida: Aplicação de Tabela Hash em C

## Contexto do Problema
Você está desenvolvendo um sistema de gerenciamento de estoque para uma pequena loja. A loja vende vários produtos e precisa de uma forma eficiente de armazenar e buscar informações sobre os produtos, como o nome, a quantidade em estoque e o preço. A solução deve permitir adicionar novos produtos, buscar informações sobre um produto específico e remover produtos do estoque.

## Objetivo
Implementar uma tabela hash em C para gerenciar o estoque de produtos da loja, permitindo as operações de inserção, busca e remoção de produtos.

## Estrutura da Tabela Hash
Cada produto terá um identificador único (código do produto) que será usado como chave na tabela hash. A tabela armazenará informações sobre o produto, como nome, quantidade e preço.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Product {
    char *code;
    char *name;
    int quantity;
    float price;
    struct Product *next;
} Product;

typedef struct {
    Product *products[TABLE_SIZE];
} HashTable;
```

## Função de Hash
A função de hash será baseada na soma dos valores ASCII dos caracteres do código do produto.

```c
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash += *key++;
    }
    return hash;
}
```

## Funções para Manipulação da Tabela Hash

### Inicialização
```c
HashTable* create_table() {
    HashTable *table = malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->products[i] = NULL;
    }
    return table;
}
```

### Inserção
```c
void insert_product(HashTable *table, const char *code, const char *name, int quantity, float price) {
    unsigned int index = hash(code) % TABLE_SIZE;
    Product *product = malloc(sizeof(Product));
    product->code = strdup(code);
    product->name = strdup(name);
    product->quantity = quantity;
    product->price = price;
    product->next = table->products[index];
    table->products[index] = product;
}
```

### Busca
```c
Product* search_product(HashTable *table, const char *code) {
    unsigned int index = hash(code) % TABLE_SIZE;
    Product *product = table->products[index];
    while (product != NULL) {
        if (strcmp(product->code, code) == 0) {
            return product;
        }
        product = product->next;
    }
    return NULL; // Produto não encontrado
}
```

### Remoção
```c
void delete_product(HashTable *table, const char *code) {
    unsigned int index = hash(code) % TABLE_SIZE;
    Product *product = table->products[index];
    Product *prev = NULL;
    while (product != NULL && strcmp(product->code, code) != 0) {
        prev = product;
        product = product->next;
    }
    if (product == NULL) {
        return; // Produto não encontrado
    }
    if (prev == NULL) {
        table->products[index] = product->next;
    } else {
        prev->next = product->next;
    }
    free(product->code);
    free(product->name);
    free(product);
}
```

## Função Principal para Teste
```c
int main() {
    HashTable *table = create_table();

    insert_product(table, "P001", "Produto 1", 10, 19.99);
    insert_product(table, "P002", "Produto 2", 20, 29.99);
    insert_product(table, "P003", "Produto 3", 15, 39.99);

    Product *p = search_product(table, "P002");
    if (p != NULL) {
        printf("Produto encontrado: %s, Quantidade: %d, Preço: %.2f\n", p->name, p->quantity, p->price);
    } else {
        printf("Produto não encontrado\n");
    }

    delete_product(table, "P002");
    p = search_product(table, "P002");
    if (p != NULL) {
        printf("Produto encontrado: %s, Quantidade: %d, Preço: %.2f\n", p->name, p->quantity, p->price);
    } else {
        printf("Produto não encontrado\n");
    }

    return 0;
}
```

## Conclusão
Nesta atividade prática, você implementou uma tabela hash para gerenciar o estoque de produtos de uma loja. A tabela hash permite adicionar, buscar e remover produtos de maneira eficiente. Essa abordagem é útil para sistemas onde operações rápidas de busca e atualização são essenciais.
