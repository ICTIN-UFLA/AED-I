
  

#  Árvores em Programação C

  

## Introdução

  

Uma árvore é uma estrutura de dados hierárquica que consiste em nós, onde cada nó possui um valor e uma lista de referências (ou ponteiros) para outros nós (seus filhos). Em uma árvore, o primeiro nó é chamado de raiz, e cada nó pode ter zero ou mais filhos.

  

As árvores são amplamente utilizadas em algoritmos e estruturas de dados devido à sua eficiência em operações como inserção, busca e deleção.

  

## Estrutura de uma Árvore em C

  

Em C, uma árvore pode ser representada usando estruturas (`structs`). Vamos criar uma estrutura básica para representar um nó de uma árvore.

  

```c

#include  <stdio.h>

#include  <stdlib.h>

  

// Estrutura para um nó da árvore

struct Node {

int data;

struct Node* left;

struct Node* right;

};

  

// Função para criar um novo nó

struct Node* newNode(int  data) {

struct Node* node = (struct Node*)malloc(sizeof(struct Node));

node->data = data;

node->left = NULL;

node->right = NULL;

return node;

}

```

  

## Inserção em uma Árvore Binária

  

Vamos criar uma função para inserir um novo nó em uma árvore binária de busca (Binary Search Tree - BST). Em uma BST, para cada nó, os valores dos nós no sub-árvore esquerda são menores e os valores dos nós no sub-árvore direita são maiores.

  

```c

// Função para inserir um novo nó na árvore binária de busca

struct Node* insert(struct Node* node, int  data) {

// Se a árvore estiver vazia, retorna um novo nó

if (node == NULL) {

return  newNode(data);

}

// Caso contrário, recursivamente percorre a árvore

if (data < node->data) {

node->left = insert(node->left, data);

} else  if (data > node->data) {

node->right = insert(node->right, data);

}

return node;

}

```

  

## Percorrendo a Árvore

  

Existem várias maneiras de percorrer uma árvore: em ordem (in-order), pré-ordem (pre-order) e pós-ordem (post-order). Vamos implementar a travessia em ordem.

  

```c

// Função para percorrer a árvore em ordem

void  inorderTraversal(struct Node* root) {

if (root != NULL) {

inorderTraversal(root->left);

printf("%d ", root->data);

inorderTraversal(root->right);

}

}

```

  

## Exemplo Completo

  

Aqui está um exemplo completo que cria uma árvore binária de busca, insere alguns nós e percorre a árvore em ordem.

  

```c

#include  <stdio.h>

#include  <stdlib.h>

  

// Estrutura para um nó da árvore

struct Node {

int data;

struct Node* left;

struct Node* right;

};

  

// Função para criar um novo nó

struct Node* newNode(int  data) {

struct Node* node = (struct Node*)malloc(sizeof(struct Node));

node->data = data;

node->left = NULL;

node->right = NULL;

return node;

}

  

// Função para inserir um novo nó na árvore binária de busca

struct Node* insert(struct Node* node, int  data) {

// Se a árvore estiver vazia, retorna um novo nó

if (node == NULL) {

return  newNode(data);

}

// Caso contrário, recursivamente percorre a árvore

if (data < node->data) {

node->left = insert(node->left, data);

} else  if (data > node->data) {

node->right = insert(node->right, data);

}

return node;

}

  

// Função para percorrer a árvore em ordem

void  inorderTraversal(struct Node* root) {

if (root != NULL) {

inorderTraversal(root->left);

printf("%d ", root->data);

inorderTraversal(root->right);

}

}

  

int  main() {

struct Node* root = NULL;

root = insert(root, 50);

insert(root, 30);

insert(root, 20);

insert(root, 40);

insert(root, 70);

insert(root, 60);

insert(root, 80);

  

printf("Traversal in order:\n");

inorderTraversal(root);

  

return  0;

}

```

  

## Considerações Finais

  

As árvores binárias de busca são uma estrutura fundamental que pode ser expandida para incluir operações como busca e deleção, além de outras variações de árvores como árvores AVL e árvores Red-Black. Estude esses conceitos para aprofundar seu conhecimento sobre estruturas de dados.
