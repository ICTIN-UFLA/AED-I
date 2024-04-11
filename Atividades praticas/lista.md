# Lista Encadeada em C
## O que é uma Lista Encadeada?

Uma lista encadeada é uma estrutura de dados linear, onde cada elemento é um objeto separado chamado de nó. Cada nó contém dados e uma referência (ou link) para o próximo nó na sequência.

Uma lista encadeada é uma estrutura de dados que consiste em uma série de elementos chamados nós. Cada nó contém dois componentes:

1.  **Dados**: O valor armazenado no nó. Pode ser qualquer tipo de dado, como um número, caractere ou até mesmo um objeto mais complexo.
    
2.  **Ponteiro para o próximo nó**: Um ponteiro que aponta para o próximo nó na lista. No último nó da lista, este ponteiro geralmente aponta para `NULL`, indicando o fim da lista.
    

### Exemplo:

Suponha que você queira criar uma lista de números inteiros. Um exemplo de lista encadeada pode ser a sequência 3 -> 7 -> 5, onde cada número é um nó na lista.

### Funcionamento:

-   **Inserção**: Você pode inserir um novo nó no início, no final ou em qualquer posição da lista.
-   **Deleção**: Também é possível remover um nó da lista.
-   **Busca**: Você pode percorrer a lista para encontrar um nó ou recuperar dados.

Listas encadeadas são úteis quando você precisa de uma coleção de elementos e deseja inserir ou remover elementos com frequência, especialmente se o número total de elementos não for conhecido antecipadamente.

### Ilustração de uma Lista Encadeada:

Aqui está uma ilustração representando uma lista encadeada:

Cada retângulo representa um nó, com um número representando os dados e uma seta apontando para o próximo nó. O último nó aponta para `NULL`, indicando o fim da lista.



## Estrutura de um Nó

Um nó típico em uma lista encadeada em C tem geralmente a seguinte estrutura:
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;

```
O código define uma estrutura chamada `Node`, usada para criar nós em uma lista encadeada em C. Cada `Node` tem duas partes:

1.  **Data (`int data`)**: Um campo que armazena dados do tipo inteiro. É o valor que cada nó da lista encadeada vai manter.
    
2.  **Next Pointer (`struct Node* next`)**: Um ponteiro para um `Node` seguinte na lista. Esse ponteiro é usado para "conectar" os nós em uma sequência, formando assim a lista encadeada. Se um nó for o último da lista, esse ponteiro apontará para `NULL`, indicando o fim da lista. Essa estrutura permite criar uma série de nós conectados, onde cada nó sabe onde o próximo nó está localizado, criando uma lista linear de elementos.


## Criando um Nó

Vamos começar criando um simples nó.

```c
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```
A função `createNode` cria um novo nó para uma lista encadeada.

-   `Node* createNode(int data)`: Retorna um ponteiro para um `Node`, recebendo um inteiro `data` como entrada.
-   Dentro da função:
    -   `malloc` é usado para alocar memória para um novo `Node`.
    -   O campo `data` do novo nó é definido com o valor fornecido.
    -   O ponteiro `next` do novo nó é inicializado como `NULL`, indicando que é o final da lista.
-   Retorna o ponteiro para o novo nó.

O `*` indica que a função retorna um ponteiro para um `Node`, e também é usado para trabalhar com os dados do nó via ponteiros.

## Inserindo um Nó

Podemos inserir um nó no início da lista:


```c
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
```
  
A função `insertAtBeginning` insere um novo nó no início de uma lista encadeada:

-   **Parâmetros:**
    
    -   `Node** head`: Um ponteiro para o ponteiro do primeiro nó (cabeça) da lista. Usar um ponteiro duplo permite modificar o ponteiro `head` original da função chamadora.
    -   `int data`: O valor de dados a ser armazenado no novo nó.
-   **Corpo da Função:**
    
    1.  `Node* newNode = createNode(data);`: Cria um novo nó com o valor `data`.
    2.  `newNode->next = *head;`: O ponteiro `next` do novo nó é definido para apontar para o atual primeiro nó da lista (o nó que `head` estava apontando).
    3.  `*head = newNode;`: Atualiza o ponteiro `head` para apontar para o novo nó, tornando-o o novo primeiro nó da lista.

Esta função coloca o novo nó como o primeiro elemento da lista, e o restante da lista segue este novo nó. O uso de `**head` é importante para que a modificação do ponteiro `head` reflita fora da função, alterando efetivamente a cabeça da lista na função chamadora.

## Exibindo a Lista

Para exibir os elementos da lista:


```c
void printList(Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

```

## Exemplo Completo

Agora, vamos criar um programa simples para demonstrar o uso de listas encadeadas.
```c
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no início da lista
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Função para imprimir todos os elementos da lista
void printList(Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

// Função para deletar um nó da lista
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;

    // vERIFICA SE o nó a ser deletado está no início da lista
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Encontrar o nó a ser deletado, mantendo o nó anterior
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Se a chave não foi encontrada na lista
    if (temp == NULL) return;

    // Desvincular o nó da lista e liberar memória
    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    printf("Lista Original: ");
    printList(head);

    deleteNode(&head, 2);
    printf("Lista após deletar 2: ");
    printList(head);

    // Lembre-se de liberar a memória alocada!
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
```

Neste programa:

1.  Definimos a estrutura `Node` com um campo de dados e um ponteiro para o próximo nó.
2.  Implementamos as funções `createNode`, `insertAtBeginning`, `printList` e `deleteNode`.
3.  No método `main`, criamos uma lista encadeada, inserimos alguns elementos, exibimos a lista, deletamos um elemento e exibimos a lista novamente.
4.  Ao final do programa, liberamos a memória alocada para evitar vazamento de memória.



# Atividade a ser feita 


### Sistema de Gerenciamento de Reservas de Hotel

**Objetivo:** Desenvolver um sistema para gerenciar as reservas de um hotel usando **listas encadeadas** em C. Este sistema deve lidar com a adição, cancelamento, busca e exibição de reservas.

**Entradas e Saídas:**

1.  **Adicionar uma Reserva (`addReservation`):**
    
    -   **Entrada**: ID da reserva, nome do hóspede e duração da estadia (solicitar ao usuário via teclado).
    -   **Processamento**: Cria um novo nó na lista encadeada com estas informações.
    -   **Saída**: Não há saída direta, mas a reserva é adicionada à lista.
2.  **Cancelar uma Reserva (`cancelReservation`):**
    
    -   **Entrada**: ID da reserva a ser cancelada (solicitar ao usuário via teclado).
    -   **Processamento**: Localiza o nó correspondente na lista e o remove.
    -   **Saída**: Mensagem indicando se a reserva foi cancelada com sucesso ou se o ID não foi encontrado.
3.  **Listar Reservas (`printAllReservations`):**
    
    -   **Entrada**: Nenhuma entrada direta
    -   **Processamento**: Percorre a lista e coleta informações de cada reserva.
    -   **Saída**: Lista de todas as reservas, mostrando ID, nome do hóspede e duração da estadia para cada uma.
4.  **Buscar por Reserva (`findReservation`):**
    
    -   **Entrada**: ID da reserva a ser encontrada (solicitar ao usuário via teclado).
    -   **Processamento**: Procura na lista um nó com o ID fornecido.
    -   **Saída**: Detalhes da reserva encontrada ou uma mensagem indicando que não foi encontrada.

**Estrutura de Dados:**

-   Use a estrutura `Reservation` definida anteriormente para armazenar as informações de cada reserva (usando lista).

**Instruções Detalhadas:**

-   Implemente as funções conforme as descrições fornecidas.
-   Considere casos especiais, como lista vazia ou IDs não encontrados.
-   Utilize uma interface de usuário simples no console para interagir com o sistema. Por exemplo, um menu onde o usuário pode escolher entre adicionar, cancelar, listar ou buscar por reservas (similar a biblioteca que criamos ou a calculadora em atividades anteriores).
-   Para a entrada de dados, use `scanf` para ler do teclado.
-   Quando listar as reservas, formate a saída para fácil leitura, como mostrando cada reserva em uma linha separada com dados claramente identificados.

**Teste:**

-   Teste cada funcionalidade individualmente e em conjunto para garantir que o sistema esteja funcionando conforme esperado.
-   Tente adicionar várias reservas, cancelar algumas delas, buscar por IDs específicos e listar todas as reservas para verificar a integridade dos dados.


# O cliente deseja uma modificação no sistema: Atualização da Duração da Estadia

**Objetivo:** Implementar uma função que permita atualizar a duração da estadia de uma reserva existente na lista encadeada.

**Descrição da Função:**

-   **Nome da Função**: `updateStayDuration`
-   **Entrada**:
    -   `int id`: O ID da reserva que precisa ser atualizada.
    -   `int newDuration`: A nova duração da estadia em dias.
    
-   **Processamento**:
    -   Busca na lista encadeada a reserva com o ID fornecido.
    -   Uma vez que a reserva correta é encontrada, atualiza o campo `stayDuration` com o novo valor `newDuration`.
-   **Saída**:
    -   Mensagem indicando sucesso na atualização.
    -   Mensagem de erro se a reserva com o ID fornecido não for encontrada.

**Etapas para Implementação:**

1.  **Buscar a Reserva Correta**:
    
    -   Percorra a lista encadeada começando do primeiro nó.
    -   Compare o ID de cada reserva com o ID fornecido.
    -   Continue a busca até encontrar a reserva correspondente ou até o final da lista.
2.  **Atualizar a Reserva**:
    
    -   Se a reserva for encontrada, altere o valor de `stayDuration` para `newDuration`.
    -   Se a reserva não for encontrada, retorne uma mensagem de erro.
3.  **Retornar o Resultado**:
    
    -   Se a atualização for bem-sucedida, retorne uma mensagem de confirmação.
    -   Se a reserva não for encontrada, informe o usuário que o ID não corresponde a nenhuma reserva existente.

**Considerações Adicionais:**

-   Certifique-se de que a lista não seja modificada se o ID não for encontrado.
-   Trate os casos de uma lista vazia ou de uma busca por um ID inexistente.
-   A função deve ser robusta o suficiente para lidar com durações de estadia inválidas ou outros possíveis erros de entrada.

## Dica:

### Modificação da Estrutura `Reservation`

Primeiramente, modifique a estrutura `Reservation` para incluir o campo `stayDuration`:

```c
typedef struct Reservation {
    int id;
    char guestName[50];
    int stayDuration;  // Adicionado para armazenar a duração da estadia
    struct Reservation* next;
} Reservation;

```

Após modificar a estrutura, você pode implementar a função `updateStayDuration` seguindo estas etapas:

1.  **Definição da Função**:
    
    -   A função `updateStayDuration` deverá receber o ID da reserva e a nova duração da estadia como parâmetros.
2.  **Busca pela Reserva**:
    
    -   Percorra a lista encadeada à procura da reserva com o ID especificado.
3.  **Atualização**:
    
    -   Uma vez encontrada a reserva, atualize o campo `stayDuration` com o novo valor fornecido.
4.  **Feedback**:
    
    -   Se a reserva for atualizada com sucesso, retorne uma mensagem indicando isso.
    -   Se a reserva com o ID fornecido não for encontrada, retorne uma mensagem de erro.

### Exemplo de Assinatura da Função
```c
void updateStayDuration(Reservation** head, int id, int newDuration) {
//crie o código 
}
```
