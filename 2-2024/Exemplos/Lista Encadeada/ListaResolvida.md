
### **Gerenciamento de Tarefas utilizando Lista Encadeada**

### **Contexto do Problema**

Imagine que você está desenvolvendo um sistema de gerenciamento de tarefas para uso pessoal ou em pequenos projetos. O sistema precisa ser capaz de armazenar várias tarefas e permitir sua inserção, exibição e remoção conforme necessário. Como não sabemos quantas tarefas serão adicionadas ao longo do tempo, a estrutura lista encadeada é ideal para esse caso, pois permite que novas tarefas sejam inseridas dinamicamente e sem a necessidade de redimensionar a estrutura.

Cada tarefa terá as seguintes informações:

-   **ID**: Um número inteiro que identifica exclusivamente cada tarefa.
-   **Descrição**: Uma breve descrição do que precisa ser feito (até 50 caracteres).
-   **Prioridade**: Nível de importância da tarefa (1 – Alta, 2 – Média, 3 – Baixa).

As operações disponíveis no sistema incluem:

1.  **Adicionar uma nova tarefa no início da lista**.
2.  **Exibir todas as tarefas cadastradas**.
3.  **Remover uma tarefa com base no ID**.
4.  **Liberar a memória alocada** ao final da execução.


## **1. Estrutura da Tarefa**

Aqui, criamos a **estrutura `Tarefa`** que representa cada nó da lista encadeada. Essa estrutura contém:

-   O **ID** da tarefa.
-   A **descrição**.
-   A **prioridade**.
-   Um ponteiro para a **próxima tarefa** na lista.

### **Código:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da tarefa
struct Tarefa {
    int id;                // Identificação única da tarefa
    char descricao[50];     // Descrição da tarefa
    int prioridade;         // Prioridade: 1 - Alta, 2 - Média, 3 - Baixa
    struct Tarefa* proxima; // Ponteiro para a próxima tarefa
};

```

## **2. Função para Adicionar uma Nova Tarefa**

Nesta função, a nova tarefa é sempre adicionada **no início da lista**. Assim, o ponteiro da nova tarefa apontará para a tarefa atual que está na cabeça da lista, e a cabeça da lista será atualizada para a nova tarefa.

### **Código:**

```c
void adicionarTarefa(struct Tarefa** cabeca, int id, char* descricao, int prioridade) {
    struct Tarefa* novaTarefa = (struct Tarefa*)malloc(sizeof(struct Tarefa));
    novaTarefa->id = id;
    strcpy(novaTarefa->descricao, descricao);
    novaTarefa->prioridade = prioridade;
    novaTarefa->proxima = *cabeca;
    *cabeca = novaTarefa; // Atualiza a cabeça da lista
}

```

## **3. Função para Exibir Todas as Tarefas**

Esta função percorre a lista e exibe cada tarefa no terminal. Se não houver tarefas cadastradas, uma mensagem indicativa é exibida.

### **Código:**

```c
void exibirTarefas(struct Tarefa* cabeca) {
    if (cabeca == NULL) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    printf("Lista de Tarefas:\n");
    while (cabeca != NULL) {
        printf("ID: %d | Descrição: %s | Prioridade: %d\n", 
               cabeca->id, cabeca->descricao, cabeca->prioridade);
        cabeca = cabeca->proxima;
    }
}

```

## **4. Função para Remover uma Tarefa pelo ID**

Esta função percorre a lista procurando a tarefa com o **ID especificado**. Caso a tarefa seja encontrada, o nó é removido e a memória é liberada.

### **Código:**


```c
void removerTarefa(struct Tarefa** cabeca, int id) {
    struct Tarefa *temp = *cabeca, *anterior = NULL;

    // Caso a tarefa a ser removida seja a primeira
    if (temp != NULL && temp->id == id) {
        *cabeca = temp->proxima;
        free(temp);
        printf("Tarefa com ID %d removida.\n", id);
        return;
    }

    // Percorre a lista para encontrar a tarefa
    while (temp != NULL && temp->id != id) {
        anterior = temp;
        temp = temp->proxima;
    }

    // Se a tarefa não for encontrada
    if (temp == NULL) {
        printf("Tarefa com ID %d não encontrada.\n", id);
        return;
    }

    // Ajusta o ponteiro do nó anterior para o próximo
    anterior->proxima = temp->proxima;
    free(temp);
    printf("Tarefa com ID %d removida.\n", id);
}

```

## **5. Função para Liberar a Memória Alocada**

Esta função percorre a lista e libera a memória alocada para cada tarefa. Isso evita vazamento de memória.

### **Código:**

```c
void liberarTarefas(struct Tarefa* cabeca) {
    struct Tarefa* temp;
    while (cabeca != NULL) {
        temp = cabeca;
        cabeca = cabeca->proxima;
        free(temp);
    }
}
```

## **6. Função `main` com Exemplo Completo**

Aqui está a função `main` que demonstra a utilização das operações de **adicionar**, **exibir** e **remover** tarefas.

### **Código:**

```c
int main() {
    struct Tarefa* cabeca = NULL;

    // Adicionando tarefas
    adicionarTarefa(&cabeca, 1, "Estudar para prova de algoritmos", 1);
    adicionarTarefa(&cabeca, 2, "Comprar mantimentos", 3);
    adicionarTarefa(&cabeca, 3, "Enviar relatório semanal", 2);

    // Exibindo todas as tarefas
    printf("Antes da remoção:\n");
    exibirTarefas(cabeca);

    // Removendo uma tarefa
    removerTarefa(&cabeca, 2);

    // Exibindo as tarefas restantes
    printf("\nDepois da remoção:\n");
    exibirTarefas(cabeca);

    // Liberando a memória alocada
    liberarTarefas(cabeca);

    return 0;
}

```

**Exemplo de Saída**

```c
Antes da remoção:
Lista de Tarefas:
ID: 3 | Descrição: Enviar relatório semanal | Prioridade: 2
ID: 2 | Descrição: Comprar mantimentos | Prioridade: 3
ID: 1 | Descrição: Estudar para prova de algoritmos | Prioridade: 1

Tarefa com ID 2 removida.

Depois da remoção:
Lista de Tarefas:
ID: 3 | Descrição: Enviar relatório semanal | Prioridade: 2
ID: 1 | Descrição: Estudar para prova de algoritmos | Prioridade: 1

```


## **O que aprendemos hoje?**

Este exercício ilustra como uma **lista encadeada** pode ser utilizada para resolver um problema prático, como o gerenciamento dinâmico de tarefas. A lista permite:

-   Inserção dinâmica sem limite de tamanho.
-   Remoção de tarefas de forma eficiente.
-   Exibição fácil do conteúdo.

### **Desafio Adicional:**

-   Implemente uma função para **ordenar as tarefas por prioridade**.
-   Crie uma função para **buscar uma tarefa** pela descrição.

Este sistema é uma base para um gerenciador de tarefas mais completo. Você pode expandi-lo para incluir **data de vencimento** ou até **status de conclusão** das tarefas.
