## Pilha 

A estrutura de dados conhecida como **Pilha (Stack)** é uma das mais fundamentais em Ciência da Computação. Ela segue o princípio **LIFO** (Last In, First Out), ou seja, o último elemento inserido é o primeiro a ser removido. Pilhas são amplamente usadas em vários contextos, como em chamadas de funções recursivas, controle de navegação (voltar) em browsers, e operações com expressões matemáticas.

Vamos aprender como implementar e manipular uma pilha usando a linguagem C. Para isso, criaremos um exemplo prático passo a passo.

### Estrutura de Dados e Operações Básicas

Uma pilha em C pode ser implementada de diversas formas, mas vamos usar um **array** para facilitar a compreensão. As operações básicas que iremos implementar são:

1.  **Push**: Inserir um elemento no topo da pilha.
    
2.  **Pop**: Remover um elemento do topo da pilha.
    
3.  **Peek**: Consultar o elemento do topo sem removê-lo.
    
4.  **isEmpty**: Verificar se a pilha está vazia.
    
5.  **isFull**: Verificar se a pilha está cheia (para implementações com tamanho fixo).
    

### Implementação em C

Vamos definir nossa pilha com um tamanho máximo fixo e implementar as operações descritas.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define o tamanho máximo da pilha

// Definindo a estrutura da pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Pilha *p) {
    return p->topo == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

// Função para inserir um elemento na pilha (push)
void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Erro: a pilha está cheia!\n");
    } else {
        p->itens[++(p->topo)] = valor;
        printf("Valor %d inserido na pilha.\n", valor);
    }
}

// Função para remover um elemento da pilha (pop)
int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: a pilha está vazia!\n");
        return -1;  // Indica que a pilha está vazia
    } else {
        int valor = p->itens[(p->topo)--];
        printf("Valor %d removido da pilha.\n", valor);
        return valor;
    }
}

// Função para consultar o elemento do topo da pilha (peek)
int peek(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: a pilha está vazia!\n");
        return -1;  // Indica que a pilha está vazia
    } else {
        return p->itens[p->topo];
    }
}

int main() {
    Pilha minhaPilha;
    inicializar(&minhaPilha);

    // Testando as operações
    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);

    printf("Elemento no topo: %d\n", peek(&minhaPilha));

    pop(&minhaPilha);
    pop(&minhaPilha);

    printf("Elemento no topo: %d\n", peek(&minhaPilha));

    pop(&minhaPilha);
    pop(&minhaPilha);  // Tentativa de remover de uma pilha vazia

    return 0;
}
```

### Explicação do Código

1.  **Definição da Pilha**: A estrutura `Pilha` contém um array `itens` para armazenar os elementos e um índice `topo` que indica o elemento do topo.
    
2.  **Função** `**inicializar**`: Define o valor inicial do topo como `-1`, indicando que a pilha está vazia.
    
3.  **Função** `**push**`: Insere um elemento no topo da pilha, aumentando o valor do `topo`.
    
4.  **Função** `**pop**`: Remove o elemento do topo e diminui o valor do `topo`.
    
5.  **Função** `**peek**`: Retorna o valor do elemento no topo sem removê-lo.
    
6.  **Funções** `**isEmpty**` **e** `**isFull**`: Verificam respectivamente se a pilha está vazia ou cheia.

### Saída Esperada

Ao executar o programa, você terá uma saída similar a:

```c
Valor 10 inserido na pilha.
Valor 20 inserido na pilha.
Valor 30 inserido na pilha.
Elemento no topo: 30
Valor 30 removido da pilha.
Valor 20 removido da pilha.
Elemento no topo: 10
Valor 10 removido da pilha.
Erro: a pilha está vazia!
```


A pilha é uma estrutura de dados simples, mas muito útil. No exemplo acima, mostramos uma implementação com tamanho fixo, mas também é possível criar uma pilha dinâmica usando ponteiros, o que permitiria um crescimento mais flexível.


#### Agora que sabemos como funciona PILHA, proponho resolvermos o problema a seguir. 

### Histórico de Navegador Web

ocê está desenvolvendo um navegador web simples e deseja implementar a funcionalidade de **histórico de navegação** usando uma pilha. Sempre que o usuário visita um site, ele deve ser armazenado em uma pilha. O objetivo desta atividade é implementar a navegação retroativa (voltar página) de um navegador web usando o conceito de pilha em C.

**Descrição**:

1.  Sempre que o usuário visita um novo site, você deve armazenar o endereço na pilha de histórico.
    
2.  Quando o usuário desejar voltar para a página anterior, você deve utilizar a operação `pop` para remover o site atual da pilha e retornar ao site anterior.
    
3.  Implemente as operações de adicionar um site ao histórico (push) e voltar para o site anterior (pop), além de mostrar o site atual no topo da pilha.
    

**Dicas para Resolver (sou um pai, né)**:

-   Use a estrutura de pilha apresentada no contexto  anterior para armazenar os sites visitados.
    
-   Cada site pode ser representado por uma string que contenha o endereço do site (por exemplo, "www.ufla.br").
    
-   Inicialize a pilha e, sempre que um novo site for visitado, use a função `push` para armazená-lo.
    
-   Para voltar para o site anterior, use a função `pop` e mostre ao usuário qual site está sendo exibido atualmente.
    
-   Verifique se a pilha está vazia antes de tentar voltar, para evitar erros.
    

**Exemplo**:

-   O usuário visita os seguintes sites: "www.google.com", "www.wikipedia.org", "www.github.com". Esses sites são adicionados à pilha.
    
-   Quando o usuário solicita `voltar`, o site "www.github.com" é removido da pilha, e o site "www.wikipedia.org" passa a ser o atual.
    

**Tarefa**: Implemente as funções `push` e `pop` para gerenciar o histórico de navegação e simule um pequeno fluxo de uso do navegador, mostrando como os sites são armazenados e como é possível voltar para páginas anteriores.

Dessa forma, você aplicará o conceito de pilha para resolver um problema prático relacionado ao histórico de navegação, reforçando o aprendizado sobre como a pilha pode ser usada em diversas situações do dia a dia. Boa prática!

