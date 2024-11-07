
# Lista de Exercícios - Alocação Dinâmica de Memória - AULA -2


1. Faça um programa em C que:
- Leia um valor `n` do usuário.
- Crie dinamicamente um vetor de `n` elementos inteiros.
- Passe o vetor para uma função que deve preenchê-lo com valores fornecidos pelo usuário.
- Imprima o vetor após o preenchimento.
- Não se esqueça de liberar a memória alocada para o vetor.

*Dica:* Utilize `malloc` para alocar o vetor e `free` para liberar a memória.

2. Implemente um programa que simule o cadastro de clientes em uma loja. O programa deve:
- Solicitar ao usuário quantos cadastros ele deseja inserir.
- Alocar dinamicamente um vetor de estruturas onde cada estrutura armazena os dados de um cliente (nome, idade e telefone).
- Imprimir os dados cadastrados.
- Liberar toda a memória alocada ao final.


*Dica:* Defina uma estrutura `Cliente` para armazenar os dados. Use `malloc` e `free` para alocação e liberação de memória.

3. Escreva um programa que:
- Solicite ao usuário as dimensões de uma matriz (linhas e colunas).
- Aloque dinamicamente a matriz utilizando ponteiros.
- Preencha a matriz com valores inteiros digitados pelo usuário.
- Calcule e exiba a soma de todos os elementos.
- Libere a memória alocada para a matriz.


*Dica:* Utilize ponteiros para ponteiros para representar a matriz e `malloc` para a alocação dinâmica.

4. Escreva uma função que recebe dois ponteiros para inteiros e um tamanho `n`. A função deve:
- Copiar os valores de um vetor para outro.
- Caso o vetor destino não tenha memória suficiente, a função deve realocar a memória.

*Exemplo:* Se o vetor de origem possui 5 elementos e o destino apenas 3, realoque o destino para comportar todos os elementos antes de copiar.

*Dica:* Utilize `malloc` e `realloc` para garantir o tamanho necessário no vetor destino.

5. Crie um programa que:
- Solicite ao usuário uma frase de até 100 caracteres.
- Aloque dinamicamente uma string para armazenar essa frase.
- Converta todos os caracteres da frase para maiúsculas.
- Exiba a frase convertida.
- Libere a memória alocada.


*Dica:* Use `malloc` para alocar a memória para a string e `toupper` para converter os caracteres.

6. mplemente uma lista encadeada para armazenar uma lista de compras. Cada nó deve conter o nome do item e a quantidade. O programa deve:
- Permitir adicionar itens na lista.
- Imprimir todos os itens da lista.
- Permitir a remoção de um item específico.
- Liberar toda a memória alocada ao encerrar o programa.


*Dica:* Utilize uma estrutura de nó com ponteiros para formar a lista encadeada e `free` para liberar a memória.

7. Faça um programa que:
- Crie um vetor de inteiros com tamanho `n` definido pelo usuário.
- Preencha o vetor com valores aleatórios entre 0 e 100.
- Ao final do preenchimento, libere a memória do vetor e peça ao usuário para inserir um novo valor de `n`.
- Repita o processo de alocação, preenchimento e liberação até que o usuário insira um valor negativo para `n`.


*Dica:* Use `rand` para gerar valores aleatórios e `malloc` para alocação.


8. Explique e corrija os seguintes trechos de código:

### Trecho A
```c
int *ptr;
*ptr = 10;
```
### Trecho B
```c
int *ptr = (int*) malloc(10 * sizeof(int));
free(ptr);
*ptr = 5;
```

9. Escreva uma função que:

- Receba um ponteiro para um vetor e um valor `n`.
- Aloque dinamicamente um vetor de `n` elementos e preencha com números aleatórios.
- Retorne o ponteiro para o vetor ao programa principal.


## Aula -2 Parte Teórica - Alocação Dinâmica de Memória

## Questões de Verdadeiro ou Falso

1. **Verdadeiro ou Falso**: A função `malloc` aloca memória, mas não inicializa os valores da memória alocada.
   
2. **Verdadeiro ou Falso**: A função `free` libera memória alocada dinamicamente e a torna inutilizável, mas o ponteiro ainda continua apontando para o mesmo endereço até ser redefinido.
   
3. **Verdadeiro ou Falso**: Quando usamos `malloc` para alocar um bloco de memória, é necessário especificar o número de bytes a serem alocados.
   
4. **Verdadeiro ou Falso**: Variáveis alocadas estaticamente são liberadas automaticamente pelo compilador no fim da execução do programa.
   
5. **Verdadeiro ou Falso**: É seguro acessar uma área de memória que foi liberada com `free`, pois a memória é automaticamente reassociada ao ponteiro.

## Questões de Múltipla Escolha

6. Ao tentar alocar memória para um vetor de inteiros com 10 posições, qual linha de código abaixo é a mais correta?
   - a) `int *v = malloc(10);`
   - b) `int *v = (int) malloc(10 * sizeof(int));`
   - c) `int *v = (int*) malloc(10 * sizeof(int));`
   - d) `int v = malloc(10 * sizeof(int));`

7. Qual função deve ser usada para redimensionar um bloco de memória alocado dinamicamente em C?
   - a) `malloc`
   - b) `realloc`
   - c) `calloc`
   - d) `free`

8. Se `p` é um ponteiro alocado dinamicamente, qual das seguintes instruções está correta para liberar a memória apontada por `p`?
   - a) `delete p;`
   - b) `release(p);`
   - c) `free(p);`
   - d) `remove(p);`

9. Qual das opções abaixo descreve melhor o uso do operador `*` em ponteiros?
   - a) Serve para inicializar um ponteiro.
   - b) Acessa o valor armazenado no endereço de memória apontado pelo ponteiro.
   - c) Converte o ponteiro para o tipo `int`.
   - d) Libera o espaço de memória apontado pelo ponteiro.

10. Dado o seguinte trecho de código:
    ```c
    int *ptr;
    ptr = malloc(sizeof(int));
    *ptr = 50;
    free(ptr);
    ```
    Qual das opções abaixo descreve o estado da variável `ptr` após a execução?
    - a) `ptr` agora aponta para NULL.
    - b) `ptr` ainda aponta para o endereço anteriormente alocado, mas o conteúdo pode ser inválido.
    - c) `ptr` foi completamente removido da memória.
    - d) `ptr` foi redefinido automaticamente para um novo valor.

## Questões de Correção

11. Analise o código abaixo e identifique o erro relacionado à alocação de memória:
    ```c
    int *array;
    array[0] = 10;
    ```
    **Pergunta:** Qual é o erro neste código e como corrigir?

12. Considere o seguinte código:
    ```c
    int *ptr;
    ptr = malloc(5 * sizeof(int));
    ptr = NULL;
    free(ptr);
    ```
    **Pergunta:** Explique o problema de memória nesse código e sugira uma correção.

13. Encontre o erro no seguinte trecho de código e corrija:
    ```c
    int *p = (int*) malloc(10 * sizeof(int));
    free(p);
    *p = 5;
    ```
    **Pergunta:** O que está incorreto e qual seria a forma correta de liberar a memória?

## Questões Conceituais

14. Explique a diferença entre alocação de memória estática e dinâmica. Quando seria mais apropriado utilizar cada uma delas?

15. Quais são os riscos de não liberar a memória alocada dinamicamente após o uso? Descreva pelo menos dois possíveis problemas que podem surgir.

16. O que acontece quando uma função tenta acessar um ponteiro que aponta para uma área de memória já liberada? Como evitar esse problema no código?

17. Em suas próprias palavras, descreva como `malloc`, `calloc` e `realloc` diferem em termos de uso e funcionalidade.

18. Qual é o propósito de inicializar ponteiros com `NULL` após a liberação da memória? Explique como essa prática pode ajudar na prevenção de erros.


# Aula 3-  Lista Simples

## Questões de Verdadeiro ou Falso

1. **Verdadeiro ou Falso**: Em C, arrays podem ser usados como uma representação de listas, pois C não possui uma estrutura de dados nativa de listas.
   
2. **Verdadeiro ou Falso**: O tamanho de um array em C precisa ser conhecido no momento da compilação.
   
3. **Verdadeiro ou Falso**: A função `malloc` permite a criação de uma lista com tamanho variável em tempo de execução, alocando memória dinamicamente.

## Questões de Múltipla Escolha

4. Qual das opções abaixo representa uma maneira correta de declarar e alocar dinamicamente um array de 10 inteiros em C?
   - a) `int array[10];`
   - b) `int *array = (int*) malloc(10);`
   - c) `int *array = malloc(10 * sizeof(int));`
   - d) `int *array = int[10];`

5. Ao iterar sobre uma lista (array) de inteiros em C, qual código permite imprimir todos os elementos do array `vetor` com 5 elementos?
   - a) `for (int i = 1; i <= 5; i++) printf("%d ", vetor[i]);`
   - b) `for (int i = 0; i < 5; i++) printf("%d ", vetor[i]);`
   - c) `for (int i = 0; i <= 5; i++) printf("%d ", vetor[i]);`
   - d) `for (int i = 1; i < 5; i++) printf("%d ", vetor[i]);`

## Questões de Correção

6. Identifique o erro no código abaixo para a alocação dinâmica de um array e sugira uma correção:
   ```c
   int *lista;
   lista = malloc(5);
   lista[0] = 1;
   ```
   **Pergunta:** O que está incorreto na alocação de memória e qual seria a forma correta de alocar a memória?


7.  O seguinte código tenta liberar a memória de um array dinâmico:

```c
int *lista = (int*) malloc(10 * sizeof(int));
free(lista);
lista[5] = 10;
```

**Pergunta:** Qual é o erro ao tentar acessar `lista` após a liberação e como isso pode ser evitado?


## Aula-3 - Atividade Prática 

 1. **Alocação e Preenchimento Dinâmico de Lista** Implemente um programa em C que:
    
    1.  Solicite ao usuário o tamanho de uma lista.
    2.  Aloque dinamicamente uma lista de inteiros com o tamanho fornecido.
    3.  Preencha a lista com números inteiros fornecidos pelo usuário.
    4.  Imprima todos os elementos da lista.
    5.  Libere a memória alocada.
2. **Expansão de Lista Dinâmica** Escreva um programa que:
    
    1.  Aloca dinamicamente uma lista de inteiros com tamanho 5.
    2.  Preenche a lista com valores de 1 a 5.
    3.  Expanda a lista para comportar mais 5 elementos.
    4.  Preencha os novos elementos com valores de 6 a 10.
    5.  Imprima todos os elementos da lista.
    6.  Libere a memória.
3.  **Operações Básicas em Listas** Crie um programa que permita ao usuário realizar operações básicas em uma lista:
    
    -   Inserir um número em uma posição específica.
    -   Remover um número de uma posição específica.
    -   Imprimir a lista completa.
    -   Liberar a memória da lista ao final do programa.
4.   **Lista com Remoção Dinâmica** Escreva um programa que cria uma lista dinamicamente e permite que o usuário remova um elemento específico digitado. Após a remoção, o programa deve ajustar os elementos restantes e imprimir a lista atualizada.
    
5.  **Soma dos Elementos da Lista** Implemente um programa que:
    
    1.  Solicite ao usuário o tamanho da lista.
    2.  Aloca dinamicamente uma lista com o tamanho fornecido.
    3.  Preencha a lista com valores inteiros.
    4.  Calcule a soma de todos os elementos e exiba o resultado.
    5.  Libere a memória alocada.

6.  Gerenciamento de Estoque
**Contexto:** Uma loja deseja gerenciar o estoque de produtos usando uma lista simples. Cada produto tem um código único e uma quantidade.

**Tarefa:**
1. Crie um programa que permita ao usuário informar quantos produtos ele deseja adicionar ao estoque.
2. Aloque dinamicamente uma lista de estruturas, onde cada estrutura armazene o código e a quantidade do produto.
3. Implemente uma função para buscar um produto pelo código e atualizar sua quantidade no estoque.
4. Após as atualizações, exiba todos os produtos com suas respectivas quantidades.
5. Libere a memória alocada ao final.

*Dica:* Defina uma estrutura `Produto` para armazenar as informações.

---

7.  Histórico de Temperaturas
**Contexto:** Um sistema meteorológico precisa registrar as temperaturas diárias de uma cidade por um período de `n` dias.

**Tarefa:**
1. Solicite ao usuário o número de dias para o qual deseja registrar as temperaturas.
2. Aloque dinamicamente um array de `float` para armazenar a temperatura de cada dia.
3. Permita que o usuário insira a temperatura para cada dia.
4. Calcule e exiba a temperatura média ao final.
5. Libere a memória alocada.

*Dica:* Use a alocação dinâmica para permitir que o número de dias seja flexível.

---

8.  Cadastro de Alunos para uma Turma
**Contexto:** Uma escola deseja cadastrar alunos para uma turma específica. Cada aluno possui um nome e uma nota final.

**Tarefa:**
1. Crie uma estrutura `Aluno` com os campos `nome` (string) e `nota` (float).
2. Solicite ao usuário quantos alunos deseja cadastrar.
3. Aloque dinamicamente uma lista de `Aluno` e preencha com os dados fornecidos pelo usuário.
4. Implemente uma função que exiba o aluno com a maior nota.
5. Implemente uma função que calcule e exiba a média das notas da turma.
6. Libere a memória ao final.

---

9.  Sistema de Votação
**Contexto:** Um sistema de votação quer registrar os votos para diferentes candidatos. Cada candidato possui um código único, e o sistema precisa armazenar o total de votos para cada um.

**Tarefa:**
1. Defina uma estrutura `Candidato` com os campos `codigo` (inteiro) e `votos` (inteiro).
2. Solicite ao usuário quantos candidatos participarão.
3. Aloque dinamicamente uma lista de `Candidato`.
4. Implemente uma função para registrar um voto, onde o usuário informa o código do candidato, e o total de votos para o candidato é atualizado.
5. Após registrar todos os votos, exiba o código do candidato vencedor (com maior número de votos).
6. Libere a memória alocada.

---

10.  Biblioteca de Livros
**Contexto:** Uma biblioteca deseja manter um catálogo de livros disponíveis para empréstimo. Cada livro possui um título, autor e status (disponível ou emprestado).

**Tarefa:**
1. Crie uma estrutura `Livro` com os campos `titulo`, `autor` e `status`.
2. Solicite ao usuário quantos livros ele deseja cadastrar.
3. Aloque dinamicamente uma lista de `Livro` e preencha com as informações fornecidas.
4. Implemente uma função que permita atualizar o status de um livro para "emprestado" ou "disponível" conforme o usuário informe o título.
5. Implemente uma função que exiba todos os livros disponíveis para empréstimo.
6. Libere a memória alocada.

---

11.   Controle de Produção em uma Linha de Montagem
**Contexto:** Uma fábrica precisa monitorar a quantidade de produtos finalizados em cada etapa da linha de montagem ao longo do dia.

**Tarefa:**
1. Solicite ao usuário o número de etapas da linha de montagem.
2. Aloque dinamicamente uma lista de inteiros para armazenar a quantidade de produtos produzidos em cada etapa.
3. Após registrar a produção de cada etapa, exiba o total produzido no dia e a média por etapa.
4. Libere a memória alocada.

*Dica:* Esse exercício reforça a alocação dinâmica com base na quantidade de etapas, que pode variar.

---

12.   Registro de Transações Bancárias
**Contexto:** Um banco deseja registrar as transações realizadas em um dia. Cada transação possui um valor e um tipo (crédito ou débito).

**Tarefa:**
1. Crie uma estrutura `Transacao` com os campos `valor` (float) e `tipo` (caractere: 'C' para crédito e 'D' para débito).
2. Solicite ao usuário o número de transações realizadas no dia.
3. Aloque dinamicamente uma lista de `Transacao`.
4. Calcule e exiba o saldo final após todas as transações.
5. Libere a memória alocada.

*Dica:* Esse exercício permite a prática de operações em uma lista dinâmica e a manipulação de estruturas.

---

13.  Cadastro de Competidores em uma Maratona
**Contexto:** Em uma maratona, cada competidor possui um número de identificação único e um tempo final de corrida.

**Tarefa:**
1. Defina uma estrutura `Competidor` com os campos `numero` (inteiro) e `tempo` (float).
2. Solicite ao usuário quantos competidores deseja cadastrar.
3. Aloque dinamicamente uma lista de `Competidor` e preencha com as informações fornecidas.
4. Implemente uma função para ordenar os competidores pelo tempo de corrida em ordem crescente e exibir o pódio (três primeiros colocados).
5. Libere a memória alocada.

---

14.  Sistema de Reservas de Salas
**Contexto:** Uma empresa precisa controlar as reservas de suas salas de reunião. Cada reserva possui uma data, uma hora e o nome do responsável.

**Tarefa:**
1. Crie uma estrutura `Reserva` com os campos `data` (string), `hora` (string) e `responsavel` (string).
2. Solicite ao usuário o número de reservas para cadastrar.
3. Aloque dinamicamente uma lista de `Reserva` e preencha com as informações.
4. Implemente uma função que permita buscar uma reserva específica por data e hora.
5. Libere a memória ao final.

---

15.  Registro de Notas Fiscais
**Contexto:** Uma empresa deseja registrar suas notas fiscais em um sistema que permite o armazenamento e consulta dinâmica.

**Tarefa:**
1. Crie uma estrutura `NotaFiscal` com os campos `numero` (inteiro), `data` (string) e `valor` (float).
2. Solicite ao usuário o número de notas fiscais a registrar.
3. Aloque dinamicamente uma lista de `NotaFiscal` e preencha com os dados.
4. Implemente uma função que permita calcular o valor total de todas as notas fiscais registradas.
5. Libere a memória ao final.

---
# Aula 3.2  - Listas Encadeadas em C

16.  Criando uma Lista Encadeada Básica
**Contexto:** Implemente uma lista encadeada para armazenar números inteiros. A lista deve permitir inserção de novos elementos e impressão dos elementos atuais.

**Tarefa:**
1. Crie uma estrutura `Node` com os campos `data` (inteiro) e `next` (ponteiro para o próximo nó).
2. Implemente uma função para inserir um novo nó no início da lista.
3. Implemente uma função para imprimir todos os elementos da lista.
4. Crie uma função `main` que ofereça ao usuário as opções de inserir um novo elemento ou imprimir a lista.

*Dica:* Utilize o operador `->` para acessar os campos da estrutura ao manipular ponteiros.

---

17.  Lista de Tarefas com Inserção e Remoção
**Contexto:** Um aplicativo de tarefas deseja gerenciar uma lista de atividades do usuário, permitindo adicionar e remover tarefas.

**Tarefa:**
1. Crie uma estrutura `Tarefa` com os campos `descricao` (string) e `next` (ponteiro para o próximo nó).
2. Implemente uma função para inserir uma nova tarefa no início da lista.
3. Implemente uma função para remover uma tarefa específica da lista, com base na descrição fornecida pelo usuário.
4. Implemente uma função para exibir todas as tarefas.

*Dica:* Para remover um nó, ajuste o ponteiro do nó anterior para o próximo da tarefa removida e libere a memória.

---

18.  Fila de Atendimento
**Contexto:** Em uma clínica, os pacientes são atendidos em ordem de chegada. Cada paciente possui um número de atendimento.

**Tarefa:**
1. Crie uma estrutura `Paciente` com os campos `numeroAtendimento` (inteiro) e `next`.
2. Implemente uma função para inserir um novo paciente ao final da lista (fila).
3. Implemente uma função para atender o próximo paciente, removendo o primeiro nó da lista.
4. Exiba a lista de pacientes na fila de atendimento.

*Dica:* A operação de remoção deve ajustar a cabeça da lista para o próximo nó após o atendimento.

---

19.  Verificação de Elemento na Lista
**Contexto:** Um sistema de gerenciamento de inventário utiliza uma lista encadeada para armazenar códigos de produtos.

**Tarefa:**
1. Crie uma função `buscarElemento` que receba a cabeça da lista e um código de produto.
2. A função deve retornar `true` se o produto estiver na lista e `false` caso contrário.
3. Teste a função inserindo alguns códigos de produtos e procurando por um específico.

---

20.  Removendo Duplicatas
**Contexto:** Em uma lista de convidados, é necessário remover nomes duplicados para garantir que cada pessoa apareça apenas uma vez.

**Tarefa:**
1. Crie uma estrutura `Convidado` com os campos `nome` (string) e `next`.
2. Implemente uma função que remova todas as duplicatas da lista de convidados, mantendo apenas a primeira ocorrência.
3. Implemente uma função para exibir a lista de convidados sem duplicatas.

---

21.  Lista Encadeada Ordenada
**Contexto:** Um sistema de classificação precisa manter uma lista de pontuações em ordem crescente.

**Tarefa:**
1. Crie uma estrutura `Pontuacao` com os campos `valor` (inteiro) e `next`.
2. Implemente uma função para inserir uma nova pontuação na lista de forma que a lista permaneça ordenada.
3. Implemente uma função para exibir a lista de pontuações.

*Dica:* Insira cada elemento na posição correta, comparando-o com os valores já presentes na lista.

---

22. Verificar se a Lista Está Vazia
**Contexto:** Implemente uma função que verifica se a lista está vazia.

**Tarefa:**
1. Crie uma função `estaVazia` que receba a cabeça da lista e retorne `true` se a lista estiver vazia e `false` caso contrário.
2. Teste a função em uma lista recém-criada (sem elementos) e após adicionar elementos.

---

23.  Liberando Memória de uma Lista Encadeada
**Contexto:** Um programa que utiliza listas encadeadas deve liberar toda a memória alocada antes de encerrar.

**Tarefa:**
1. Implemente uma função `liberarLista` que percorre a lista e libera a memória de cada nó.
2. Teste a função criando uma lista com alguns elementos, imprimindo-a e depois liberando a memória ao final.

---

24. Inserção no Fim e Início da Lista
**Contexto:** Um cadastro de clientes permite que o usuário adicione um cliente ao final ou no início da lista.

**Tarefa:**
1. Crie uma estrutura `Cliente` com os campos `nome` (string) e `next`.
2. Implemente duas funções de inserção: uma que insere no início e outra que insere no final da lista.
3. Implemente uma função para exibir todos os clientes na lista.

---

25.  Lista Encadeada Circular para Jogadores em um Jogo
**Contexto:** Em um jogo multiplayer, os jogadores são armazenados em uma lista encadeada circular para que o turno passe de jogador para jogador.

**Tarefa:**
1. Crie uma estrutura `Jogador` com os campos `nome` (string) e `next`.
2. Implemente uma lista encadeada circular onde o último jogador aponte para o primeiro.
3. Implemente uma função para adicionar um jogador à lista.
4. Crie uma função para simular a passagem de turno, onde o próximo jogador se torna o atual, repetidamente.

---

26.  Questões de Verdadeiro o**Verdadeiro ou Falso**: Em uma lista encadeada, os elementos são armazenados de forma contínua na memória.
   
27. **Verdadeiro ou Falso**: Para acessar o terceiro elemento de uma lista encadeada, é necessário percorrer todos os nós até ele, a partir da cabeça da lista.

28. **Verdadeiro ou Falso**: O operador `->` é utilizado para acessar os campos de uma estrutura quando temos um ponteiro para essa estrutura.

29. **Verdadeiro ou Falso**: Em uma lista encadeada, a inserção de elementos no final da lista é sempre mais rápida do que a inserção no início.

30. **Verdadeiro ou Falso**: Uma lista encadeada permite remoção de elementos sem a necessidade de reorganizar os elementos restantes na memória.

31. Em uma lista encadeada, cada nó contém:
   - a) Um valor e o índice do próximo nó.
   - b) Um ponteiro para o próximo nó e um valor armazenado.
   - c) O endereço da cabeça da lista e um valor armazenado.
   - d) Um ponteiro para o primeiro e o último nó da lista.

32. Qual das seguintes operações geralmente é mais eficiente em uma lista encadeada do que em um array?
   - a) Acesso direto a um elemento específico.
   - b) Ordenação dos elementos.
   - c) Inserção de um elemento no meio da lista.
   - d) Comparação de todos os elementos.

33. Qual das seguintes afirmações é verdadeira sobre o uso do operador `->` em listas encadeadas?
   - a) `->` é usado apenas para definir um ponteiro para uma estrutura.
   - b) `->` acessa o campo de uma estrutura apontada por um ponteiro.
   - c) `->` sempre aponta para o último elemento da lista.
   - d) `->` remove o elemento final de uma lista.

34. Considere o código abaixo. O que ele faz?
   ```c
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = 5;
   newNode->next = NULL;
 ```
 -   a) Cria um novo nó, define o valor `data` como `5` e o próximo nó como `NULL`.
-   b) Cria um novo nó sem inicializar o valor de `data` e `next`.
-   c) Cria um nó temporário para uso local.
-   d) Aponta `newNode` para o último nó da lista.

35. Qual função a seguir é usada para liberar a memória alocada para um nó em uma lista encadeada?

-   a) `malloc`
-   b) `free`
-   c) `realloc`
-   d) `calloc`

36. **Identifique e corrija o erro no código abaixo para inserir um novo nó no início de uma lista:**

   ```c

struct Node* head = NULL;
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = 10;
head = newNode;
```

-   **Pergunta:** O que está faltando para que o nó `newNode` seja realmente o primeiro da lista?

37. **Análise de Código:** Considere o seguinte código para remover um nó com valor específico de uma lista encadeada. Corrija o código se houver erros.


   ```c
void removerElemento(struct Node* head, int valor) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != valor) {
        temp = temp->next;
    }
    free(temp);
}
   ```
-   **Pergunta:** Quais são os problemas no código e como corrigi-los?
38. **Erro de Referência:** Analise o trecho de código e corrija-o para que insira um nó ao final da lista encadeada.


   ```c
   struct Node* inserirNoFinal(struct Node* head, int valor) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = valor;
    newNode->next = NULL;
    head->next = newNode;
    return head;
}

   ```
  -  **Pergunta:** O que está faltando para que o novo nó seja adicionado ao final da lista?
  
39.  **Explique a diferença entre uma lista encadeada e um array em termos de armazenamento de dados na memória.** Quais são as principais vantagens e desvantagens de cada um?
    
40.  **Descreva o processo de remoção de um nó específico de uma lista encadeada.** Quais cuidados devem ser tomados para evitar problemas de memória?
    
41.  **Explique o que acontece na memória quando usamos a função `free` em um nó de uma lista encadeada.** Por que é importante garantir que o ponteiro do nó anterior aponte para o próximo nó, ao invés do nó removido?
    
42.  **Discuta o papel da cabeça (ou nó sentinela) em uma lista encadeada.** Quais são as vantagens de manter um nó sentinela para apontar para o início da lista?
    
43.    **Qual é a importância de verificar se um ponteiro é `NULL` ao manipular uma lista encadeada?** Forneça exemplos de situações em que essa verificação é essencial.

# Aula 4-Struct  e Ponteiros 

## Questões de Verdadeiro ou Falso

44. **Verdadeiro ou Falso**: Em C, o operador `.` é usado para acessar os campos de uma estrutura quando trabalhamos com variáveis de estrutura, e `->` é usado com ponteiros para estruturas.
   
45. **Verdadeiro ou Falso**: A função `malloc` aloca memória na stack (pilha) do programa.
   
46. **Verdadeiro ou Falso**: Uma estrutura (`struct`) em C pode conter diferentes tipos de dados, como `int`, `float` e `char`.
   
47. **Verdadeiro ou Falso**: Em C, a função `sizeof` retorna o número de bits ocupados por um tipo de dado.
   
48. **Verdadeiro ou Falso**: A expressão `typedef struct {...} NomeEstrutura;` cria um novo tipo de dados chamado `NomeEstrutura`, que pode ser usado como um tipo padrão no código.

---

49. Qual das seguintes opções é a maneira correta de definir uma estrutura `Pessoa` com os campos `idade` e `altura`?
   - a) `struct Pessoa { int idade; int altura; };`
   - b) `typedef Pessoa { int idade; int altura; }`
   - c) `struct Pessoa = { int idade, int altura };`
   - d) `typedef struct Pessoa { idade; altura; }`

50. Qual operador é utilizado para acessar os campos de uma estrutura usando um ponteiro em C?
   - a) `.`
   - b) `*`
   - c) `->`
   - d) `&`

51. Qual das alternativas abaixo representa a função da instrução `int *p = (int*) malloc(sizeof(int));`?
   - a) Declara um ponteiro `p` para um inteiro e inicializa o valor com `sizeof(int)`.
   - b) Aloca memória para um valor inteiro e armazena o endereço no ponteiro `p`.
   - c) Aloca memória para um array de inteiros.
   - d) Libera a memória apontada por `p`.

52. Considerando a estrutura abaixo, qual é a maneira correta de definir uma variável `aluno1` da estrutura `Aluno` e atribuir o valor `20` para o campo `idade`?
   ```c
   typedef struct {
       int idade;
       float nota;
   } Aluno;
   ```
   - a) `Aluno aluno1; aluno1->idade = 20;`
   - b) `struct Aluno aluno1; aluno1.idade = 20;`
   - c) `Aluno aluno1; aluno1.idade = 20;`
   - d) `Aluno *aluno1; aluno1->idade = 20;`

53. Qual das seguintes opções representa o uso correto da função `malloc` para alocar memória para uma estrutura `Pessoa` e acessar seus campos?
    - a) `Pessoa *p = (Pessoa) malloc(sizeof(Pessoa)); p.idade = 25;`
    - b) `Pessoa p = malloc(sizeof(Pessoa)); p.idade = 25;`
    - c) `Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa)); p->idade = 25;`
    - d) `Pessoa p; p->idade = 25;`

---


54. **Identifique e corrija o erro no código abaixo que tenta alocar memória para uma estrutura `Pessoa` e definir valores para seus campos:**
    ```c
    typedef struct {
        int idade;
        float altura;
    } Pessoa;

    Pessoa *pessoa1;
    pessoa1->idade = 30;
    pessoa1->altura = 1.75;
    ```
    **Pergunta:** Qual é o erro e como corrigi-lo para que a estrutura seja corretamente alocada e inicializada?

55. **Corrija o código abaixo para liberar corretamente a memória alocada para um ponteiro de tipo `PesoAltura`:**
    ```c
    typedef struct {
        int peso;
        int altura;
    } PesoAltura;

    PesoAltura *pessoa = (PesoAltura*) malloc(sizeof(PesoAltura));
    pessoa.peso = 70;
    pessoa.altura = 180;
    free(pessoa);
    ```
    **Pergunta:** O que está incorreto no acesso e liberação da memória?

56. **Erro de Tipagem:** Considere o trecho de código abaixo que define e inicializa uma variável usando uma estrutura. Corrija-o para que funcione corretamente:
    ```c
    typedef struct {
        int codigo;
        char nome[30];
    } Produto;

    Produto produto1;
    produto1.codigo = "1234";
    produto1.nome = "Teclado";
    ```
    **Pergunta:** O que está incorreto na atribuição dos valores para os campos da estrutura?

---


57. **Cadastro de Alunos:** Crie um programa que armazene informações de alunos em uma estrutura. A estrutura deve conter os campos `nome` (string), `idade` (inteiro) e `nota` (float). Permita que o usuário cadastre até 5 alunos e exiba os dados cadastrados.

58. **Gestão de Produtos em Estoque:** Defina uma estrutura `Produto` com os campos `codigo` (inteiro), `nome` (string) e `preco` (float). Implemente um programa que permita cadastrar novos produtos e exibir o produto com o preço mais alto.

59. **Verificação de Peso Máximo:** Usando a estrutura `PesoAltura` definida nos slides, crie um programa que solicite ao usuário o peso e a altura de várias pessoas e verifique se a altura de alguma delas excede `alturaMaxima` (225 cm). Use alocação dinâmica para permitir que o usuário defina quantas pessoas deseja cadastrar.

60. **Atualização de Informações usando Ponteiros:** Defina uma estrutura `ContaBancaria` com os campos `numeroConta` (inteiro) e `saldo` (float). Escreva uma função que receba um ponteiro para uma `ContaBancaria` e atualize o saldo ao adicionar um valor fornecido pelo usuário. Teste a função com diferentes contas.

61. **Ponteiros e Aritmética de Ponteiros:** Usando uma estrutura `Retangulo` com os campos `largura` e `altura`, implemente um programa que aloque dinamicamente um array de `Retangulo` e permita ao usuário preencher as dimensões de vários retângulos. O programa deve calcular e exibir a área de cada retângulo.

# Aula 5 - Listas Encadeadas com e sem Cabeça, Listas Circulares

62. **Verdadeiro ou Falso**: Em uma lista encadeada com cabeça, o primeiro elemento da lista é um nó especial que contém dados.
   
63. **Verdadeiro ou Falso**: Em uma lista encadeada sem cabeça, o primeiro elemento da lista é um nó que contém dados.
   
64. **Verdadeiro ou Falso**: Em uma lista encadeada com cabeça, o ponteiro "cabeça" aponta para o primeiro nó real da lista, não para o nó cabeça.
   
65. **Verdadeiro ou Falso**: Em listas circulares, o último nó aponta de volta para o primeiro nó, formando um ciclo.

66. **Verdadeiro ou Falso**: A remoção de um elemento em uma lista encadeada com cabeça é sempre mais complexa do que em uma lista sem cabeça.

---

67. Qual das afirmações é verdadeira para uma lista encadeada com cabeça?
   - a) O nó cabeça sempre contém dados.
   - b) O nó cabeça facilita operações de inserção e remoção.
   - c) O nó cabeça deve ser removido quando a lista está vazia.
   - d) Não há diferença entre uma lista com cabeça e uma lista sem cabeça.

68. Em uma lista circular, para qual elemento o ponteiro "next" do último nó aponta?
   - a) Para o último nó
   - b) Para o nó cabeça
   - c) Para o primeiro nó
   - d) Para `NULL`

69. Em uma lista encadeada com cabeça, qual das operações abaixo é facilitada pela presença do nó cabeça?
   - a) Inserção de um elemento no final
   - b) Inserção de um elemento no meio
   - c) Remoção do primeiro elemento
   - d) Remoção do último elemento

70. Em uma lista encadeada sem cabeça, qual operação exige uma verificação especial para o caso de um único elemento na lista?
   - a) Inserção no início
   - b) Inserção no final
   - c) Remoção de um elemento
   - d) Pesquisa de um elemento

71. Em listas ligadas circulares, qual é o critério de parada típico para percorrer todos os elementos?
    - a) Quando o ponteiro "next" é `NULL`
    - b) Quando o ponteiro "next" aponta para o nó cabeça
    - c) Quando o ponteiro "next" aponta para o primeiro elemento
    - d) Quando todos os nós são `NULL`

---

72. **Identifique e corrija o erro no código abaixo que tenta criar uma lista encadeada com cabeça:**
    ```c
    struct Node {
        int data;
        struct Node* next;
    };

    struct Node* criarListaComCabeca() {
        struct Node* cabeca = (struct Node*)malloc(sizeof(struct Node));
        cabeca->next = NULL;
        cabeca->data = 0;
        return cabeca;
    }
    ```
    **Pergunta:** Qual é o erro no código e como ajustá-lo para garantir que o nó cabeça não contenha dados?

73. **Corrija o código abaixo para que insira um novo elemento no final de uma lista encadeada circular:**
    ```c
    void inserirNoFinalCircular(struct Node** head, int data) {
        struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
        novo->data = data;
        novo->next = *head;
        if (*head == NULL) {
            *head = novo;
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = novo;
        }
    }
    ```
    **Pergunta:** O que está incorreto no tratamento da lista circular?

74. **Erro de Ponteiro:** Corrija o seguinte código para que remova corretamente um nó específico em uma lista encadeada com cabeça:
    ```c
    void removerElemento(struct Node* head, int valor) {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->data != valor) {
            temp = temp->next;
        }
        struct Node* aRemover = temp->next;
        temp->next = aRemover->next;
        free(aRemover);
    }
    ```
    **Pergunta:** Qual é o problema com o código ao lidar com o nó cabeça?

---

75. **Implementação de Lista com Cabeça para Gerenciar Números Inteiros:** Crie uma lista encadeada com cabeça para armazenar números inteiros. Implemente as operações:
    - Inserção no início, no fim e após um valor específico.
    - Remoção de um elemento.
    - Impressão de todos os elementos.

76. **Gerenciamento de Fila com Lista Circular:** Implemente uma lista circular para simular uma fila em um banco. Cada nó representa um cliente com um `id` único. Implemente as operações:
    - Inserir um novo cliente no final da fila.
    - Atender o próximo cliente (remover do início da fila).
    - Exibir todos os clientes na fila em ordem.

77. **Lista Sem Cabeça para Cadastro de Produtos:** Crie uma lista encadeada sem cabeça para armazenar produtos em um sistema de estoque. Cada nó deve conter o código do produto e o nome. Implemente as operações:
    - Inserir produto no início e no final da lista.
    - Remover um produto específico da lista.
    - Exibir todos os produtos.

78. **Implementação de Lista Circular para Jogo Multiplayer:** Em um jogo multiplayer, os jogadores são armazenados em uma lista circular. Cada nó contém o nome do jogador. Implemente as operações:
    - Adicionar um novo jogador ao final da lista.
    - Passar o turno para o próximo jogador (simular rodadas).
    - Exibir a lista de jogadores na ordem do ciclo.

79. **Operações de Inserção e Remoção em Lista com Cabeça:** Crie uma lista encadeada com cabeça para gerenciar uma sequência de eventos (descritos por strings). Implemente as operações:
    - Inserir um evento no início, no final e após um evento específico.
    - Remover um evento específico.
    - Exibir todos os eventos da lista.

---

# Aula 7- Pilha


80. **Verdadeiro ou Falso**: Em uma pilha, o primeiro elemento inserido é o primeiro a ser removido.
   
81. **Verdadeiro ou Falso**: A operação `pop` remove o elemento do topo da pilha.
   
82. **Verdadeiro ou Falso**: A estrutura de dados pilha segue a política LIFO (Last-In-First-Out).
   
83. **Verdadeiro ou Falso**: A função `peek` retorna o elemento do topo da pilha sem removê-lo.
   
84. **Verdadeiro ou Falso**: Em uma pilha estática, a pilha está cheia se o topo é igual ao tamanho máximo `n`.

---


85. Qual das operações a seguir NÃO faz parte das operações típicas de uma pilha?
   - a) push
   - b) pop
   - c) peek
   - d) enqueue

86. Em uma pilha, qual operação adiciona um novo elemento no topo?
   - a) push
   - b) pop
   - c) peek
   - d) remove

87. Qual das afirmações abaixo é verdadeira para uma pilha estática com tamanho máximo `n`?
   - a) A pilha está cheia quando `topo == n`.
   - b) A pilha está vazia quando `topo == n`.
   - c) A pilha está cheia quando `topo == 0`.
   - d) A pilha está vazia quando `topo == n - 1`.

88. Dado o código `x = pilha[--topo];`, qual operação está sendo realizada?
   - a) push
   - b) pop
   - c) peek
   - d) full

89. Em uma pilha dinâmica implementada com uma lista encadeada, qual é o critério para verificar se a pilha está vazia?
   - a) `topo == NULL`
   - b) `topo == n`
   - c) `topo == 0`
   - d) `topo == -1`

---

90. **Identifique e corrija o erro no código abaixo que tenta implementar a operação `push` em uma pilha estática:**
    ```c
    void push(int pilha[], int *topo, int elemento) {
        if (*topo >= 5) {
            printf("Pilha cheia\n");
        } else {
            pilha[*topo] = elemento;
            *topo++;
        }
    }
    ```
    **Pergunta:** Qual é o erro na atualização do ponteiro `topo`?

91. **Corrija o código abaixo para que a operação `pop` funcione corretamente em uma pilha estática:**
    ```c
    int pop(int pilha[], int *topo) {
        if (*topo == 0) {
            printf("Pilha vazia\n");
            return -1;
        } else {
            return pilha[*topo];
            *topo--;
        }
    }
    ```
    **Pergunta:** O que está incorreto na manipulação do `topo` durante a remoção?

92. **Erro de Condição de Cheio:** Considere o seguinte código que verifica se uma pilha está cheia. Corrija o código para que funcione corretamente:
    ```c
    int cheio(int topo) {
        return topo > n;
    }
    ```
    **Pergunta:** Como modificar a condição para que a função retorne `true` apenas quando a pilha estiver cheia?

---


93. **Implementação de Pilha Estática para Calculadora:** Implemente uma pilha estática para armazenar operações aritméticas de uma calculadora. A pilha deve:
    - Permitir `push` de resultados intermediários.
    - Realizar `pop` para desfazer a última operação.
    - Mostrar o valor atual no topo com `peek`.

94. **Controle de Navegação em Browser com Pilha Dinâmica:** Em um navegador de internet, o histórico de páginas visitadas pode ser representado por uma pilha. Implemente uma pilha dinâmica que permita:
    - `push` de uma nova página visitada.
    - `pop` para voltar à página anterior.
    - Exibir a página atual sem removê-la com `peek`.

95. **Conversão de Notação Infixa para Pós-fixa usando Pilha:** Utilize uma pilha para converter expressões aritméticas da notação infixa para a pós-fixa (notação polonesa reversa). Implemente uma função que:
    - Receba uma expressão em notação infixa.
    - Converta e exiba a expressão em notação pós-fixa usando uma pilha.

96. **Verificação de Parênteses Balanceados:** Crie um programa que utiliza uma pilha para verificar se os parênteses em uma expressão matemática estão balanceados. O programa deve:
    - Percorrer a expressão e empilhar cada parêntese de abertura.
    - Realizar `pop` para cada parêntese de fechamento encontrado.
    - Verificar se todos os parênteses foram corretamente fechados.

97. **Desfazer e Refazer em Editor de Texto com Pilha:** Em um editor de texto, as operações de desfazer e refazer podem ser implementadas com duas pilhas. Implemente um programa que:
    - Utilize uma pilha para armazenar ações de texto (inserções e deleções).
    - Permita desfazer (`pop` da pilha de ações) e refazer (`push` em uma pilha de refazer).
    - Exiba o conteúdo atual do texto após cada operação.

# Aula 8 - Filas em C


98. **Verdadeiro ou Falso**: Em uma fila, o primeiro elemento inserido é o primeiro a ser removido.
   
99. **Verdadeiro ou Falso**: A estrutura de dados fila segue a política FIFO (First-In-First-Out).
   
100. **Verdadeiro ou Falso**: Em uma fila estática implementada com um array, o último elemento está sempre na posição final do array.
   
101. **Verdadeiro ou Falso**: A operação `desenfileirar` remove o elemento na frente da fila.
   
102. **Verdadeiro ou Falso**: Uma fila circular permite reutilizar o espaço de memória do início do array quando ele é liberado.

---


103. Qual das operações a seguir é usada para adicionar um novo elemento ao final de uma fila?
   - a) empilhar
   - b) desenfileirar
   - c) enfileirar
   - d) adicionar_fim

104. Em uma fila circular, o que acontece quando o índice `fim` atinge o final do array?
   - a) O índice `fim` é redefinido para 0.
   - b) O índice `fim` permanece no final.
   - c) A fila é expandida automaticamente.
   - d) Um erro é gerado indicando que a fila está cheia.

105. Em uma fila dinâmica implementada com ponteiros, como se verifica se a fila está vazia?
   - a) `inicio == fim`
   - b) `inicio == NULL`
   - c) `fim == NULL`
   - d) `inicio == fim == NULL`

106. Em uma fila circular implementada com array, qual é a fórmula para calcular a nova posição de `fim` ao enfileirar um elemento?
   - a) `fim + 1`
   - b) `(fim + 1) % tamanho_maximo`
   - c) `(inicio + 1) % tamanho_maximo`
   - d) `fim % tamanho_maximo`

107. Qual das opções abaixo representa um uso típico de uma fila em sistemas operacionais?
   - a) Pilha de chamadas de função
   - b) Lista de processos prontos para execução
   - c) Lista de comandos de desfazer/refazer
   - d) Armazenamento temporário de variáveis locais

---


108. **Identifique e corrija o erro no código abaixo que tenta implementar a operação `enfileirar` em uma fila estática:**
    ```c
    void enfileirar(int fila[], int *fim, int elemento, int max) {
        if (*fim == max) {
            printf("Fila cheia\n");
        } else {
            fila[*fim] = elemento;
            *fim = (*fim + 1) % max;
        }
    }
    ```
    **Pergunta:** Qual é o erro no controle de `fim` ao enfileirar em uma fila circular?

109. **Corrija o código abaixo para que a operação `desenfileirar` funcione corretamente em uma fila estática:**
    ```c
    int desenfileirar(int fila[], int *inicio, int *fim) {
        if (*inicio == *fim) {
            printf("Fila vazia\n");
            return -1;
        } else {
            int elemento = fila[*inicio];
            *inicio++;
            return elemento;
        }
    }
    ```
    **Pergunta:** O que está incorreto na atualização do índice `inicio` ao desenfileirar?

110. **Erro de Condição de Cheio em Fila Circular:** Corrija o código abaixo para que verifique corretamente se a fila está cheia:
    ```c
    int cheia(int inicio, int fim, int max) {
        return (fim + 1) % max == inicio;
    }
    ```
    **Pergunta:** Como essa condição verifica se a fila circular está cheia?

---


111. **Simulação de Fila de Impressão com Fila Estática:** Implemente uma fila estática para gerenciar uma fila de impressão. A fila deve:
    - Permitir `enfileirar` um novo trabalho de impressão.
    - Realizar `desenfileirar` para processar o próximo trabalho.
    - Exibir o número total de trabalhos na fila.

112. **Gerenciamento de Atendimento em Banco com Fila Dinâmica:** Em um banco, clientes aguardam atendimento em uma fila. Implemente uma fila dinâmica que permita:
    - `enfileirar` novos clientes.
    - `desenfileirar` o próximo cliente a ser atendido.
    - Exibir a lista atual de clientes aguardando.

113. **Fila Circular para Armazenamento de Dados em Sensor:** Em um sistema de monitoramento, os dados são armazenados em uma fila circular com capacidade fixa. Implemente uma fila que:
    - Permita `enfileirar` novos dados do sensor.
    - Armazene apenas os últimos `n` valores devido à capacidade fixa.
    - Exiba todos os dados atualmente armazenados na fila.

114. **Simulação de Escalonamento de Processos com Fila Circular:** Implemente uma fila circular para simular o escalonamento de processos em um sistema operacional. Cada processo tem um ID único. A fila deve:
    - `enfileirar` novos processos.
    - `desenfileirar` o processo atual após sua execução.
    - Exibir a ordem atual dos processos na fila.

115. **Gestão de Pedidos em Restaurante com Fila Dinâmica:** Em um restaurante, pedidos são processados em uma fila dinâmica. Implemente uma fila que permita:
    - `enfileirar` um novo pedido.
    - `desenfileirar` o próximo pedido a ser atendido.
    - Exibir todos os pedidos aguardando atendimento.

---

# Aula 9 - Matrizes em C

## Questões de Verdadeiro ou Falso

115. **Verdadeiro ou Falso**: Em C, uma matriz é uma estrutura de dados homogênea que armazena valores em duas dimensões.
   
116. **Verdadeiro ou Falso**: Para acessar o elemento de uma matriz em C, usamos o operador de índice duplo, como `matriz[i][j]`.
   
117. **Verdadeiro ou Falso**: A declaração `int matriz[3][4];` cria uma matriz com 3 linhas e 4 colunas.
   
118. **Verdadeiro ou Falso**: Em uma matriz `float matriz[2][2];`, a posição `matriz[0][1]` armazena o segundo elemento da primeira linha.
   
119. **Verdadeiro ou Falso**: O operador `sizeof` em C retorna o número total de elementos em uma matriz.

---


120. Qual das seguintes opções é a maneira correta de declarar uma matriz de inteiros com 5 linhas e 3 colunas?
   - a) `int matriz[3][5];`
   - b) `int matriz[5][3];`
   - c) `int matriz[3][3];`
   - d) `int matriz[5];`

121. Suponha que `int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};`. Qual é o valor de `matriz[1][2]`?
   - a) 2
   - b) 3
   - c) 5
   - d) 6

122. Qual das alternativas abaixo representa a forma correta de somar todos os elementos de uma matriz `int matriz[3][3]`?
   - a) `soma = matriz[0] + matriz[1] + matriz[2];`
   - b) `for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) soma += matriz[i][j];`
   - c) `soma = matriz[3][3];`
   - d) `soma = matriz[i][j];`

123. Em uma matriz `float matriz[4][4];`, quantos elementos no total essa matriz pode armazenar?
   - a) 8
   - b) 12
   - c) 16
   - d) 20

124. Qual das opções a seguir descreve corretamente o processo de transposição de uma matriz `M`?
   - a) A matriz `M` é espelhada horizontalmente.
   - b) A matriz `M` é espelhada verticalmente.
   - c) As linhas e colunas de `M` são trocadas, formando uma nova matriz `N`.
   - d) A matriz `M` é ordenada em ordem crescente.

---


125. **Identifique e corrija o erro no código abaixo que tenta calcular a média dos elementos de uma matriz 2x2:**
    ```c
    float matriz[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
    float soma = matriz[0][0] + matriz[0][1] + matriz[1][0] + matriz[1][2];
    float media = soma / 4.0;
    ```
    **Pergunta:** Qual é o erro no acesso aos elementos da matriz?

126. **Corrija o código abaixo para que ele leia corretamente uma matriz 3x3 preenchida pelo usuário:**
    ```c
    int matriz[3][3];
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    ```
    **Pergunta:** O que está incorreto nos limites do loop?

127. **Erro de Cálculo da Transposta:** Corrija o código abaixo que tenta calcular a transposta de uma matriz 2x2:
    ```c
    int matriz[2][2] = {{1, 2}, {3, 4}};
    int transposta[2][2];
    transposta[0][0] = matriz[0][0];
    transposta[1][1] = matriz[1][1];
    transposta[0][1] = matriz[1][0];
    transposta[1][0] = matriz[0][1];
    ```
    **Pergunta:** Qual é o erro na ordem de atribuição para a transposição?

---

128. **Cálculo da Média dos Elementos de uma Matriz:** Crie um programa que leia os elementos de uma matriz 3x3, calcule e exiba a média dos valores armazenados.

129. **Verificação de Simetria em Matriz Quadrada:** Implemente um programa que verifique se uma matriz quadrada 3x3 é simétrica. Uma matriz é simétrica se `matriz[i][j] == matriz[j][i]` para todos os `i` e `j`.

130. **Transposição de Matrizes:** Crie um programa que leia uma matriz `M` de tamanho 4x2 e gere a matriz transposta `N` de tamanho 2x4.

131. **Multiplicação de Matrizes:** Elabore um programa que solicite ao usuário duas matrizes 2x2 e calcule a matriz resultante da multiplicação entre elas.

132. **Cálculo de Média e Classificação de Alunos:** Crie um programa que leia os nomes de 5 alunos e suas notas em duas provas. O programa deve:
    - Calcular a média de cada aluno.
    - Exibir os nomes dos alunos com média maior que a média da turma.

---

# Aula 10- Algoritmos Recursivos 


133. **Verdadeiro ou Falso**: Uma função recursiva deve sempre ter um caso base para evitar uma recursão infinita.

134. **Verdadeiro ou Falso**: A recursão em C permite que a função chame a si mesma ou outra função que eventualmente a chame de volta.

135. **Verdadeiro ou Falso**: Na recursão, cada chamada da função mantém seu próprio estado independente das demais chamadas.

136. **Verdadeiro ou Falso**: O fatorial de um número é um exemplo clássico de algoritmo recursivo.

137. **Verdadeiro ou Falso**: Em uma função recursiva, variáveis estáticas podem ser acessadas e modificadas por todas as chamadas recursivas.

---


138. Qual é o elemento essencial que toda função recursiva deve ter para evitar uma execução infinita?
   - a) Um retorno `NULL`
   - b) Um caso base
   - c) Uma variável estática
   - d) Um loop `for`



140. Em uma função recursiva, o que ocorre quando a condição do caso base é satisfeita?
   - a) A função chama a si mesma novamente.
   - b) A execução retorna para a chamada anterior.
   - c) As variáveis locais são transferidas para a próxima chamada.
   - d) O programa entra em um loop infinito.

141. Considere a função recursiva de divisão inteira. Qual é o caso base para essa função?
   - a) `dividendo == divisor`
   - b) `dividendo < divisor`
   - c) `dividendo > divisor`
   - d) `dividendo >= divisor`

142. Em uma função de Fibonacci recursiva, quantas chamadas recursivas a função `fib(4)` realizará no total?
   - a) 3
   - b) 5
   - c) 7
   - d) 9

---

143. **Identifique e corrija o erro no código abaixo que calcula o fatorial de um número recursivamente:**
    ```c
    int fatorial(int n) {
        if (n == 0) {
            return 0;
        } else {
            return n * fatorial(n - 1);
        }
    }
    ```
    **Pergunta:** Qual é o erro no caso base para calcular o fatorial?

144. **Corrija o código abaixo para calcular corretamente a sequência de Fibonacci de um número `n`:**
    ```c
    int fibonacci(int n) {
        if (n <= 1) {
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    ```
    **Pergunta:** O que está incorreto no caso base para o cálculo da sequência de Fibonacci?

145. **Erro de Chamada Recursiva em Divisão Inteira:** Corrija o código abaixo para que ele calcule corretamente o quociente de uma divisão inteira usando recursão:
    ```c
    int divisao(int dividendo, int divisor) {
        if (dividendo == 0) {
            return 1;
        } else {
            return 1 + divisao(dividendo - divisor, divisor);
        }
    }
    ```
    **Pergunta:** Qual é o erro na condição de parada para a divisão inteira?

---


146. **Impressão de Frase ao Contrário Usando Recursão:** Escreva um programa que leia uma frase até o ponto final (`.`) e a imprima ao contrário usando recursão. A frase deve ser lida caractere a caractere.

147. **Cálculo Recursivo da Sequência de Fibonacci:** Escreva uma função recursiva que receba um número `N` e exiba os `N` primeiros termos da sequência de Fibonacci.

148. **Conversão Recursiva de Base Numérica:** Implemente um procedimento recursivo para converter um número decimal para uma base entre 2 e 9. A função deve receber o número e a base desejada e exibir o resultado na nova base.

149. **Divisão Inteira Recursiva:** Escreva uma função recursiva que calcule a divisão inteira de dois números sem utilizar o operador de divisão, apenas usando subtrações sucessivas.


# Aula 11 - Algoritmos Recursivos: Divisão e Conquista 


150. **Verdadeiro ou Falso**: O paradigma de divisão e conquista divide um problema em partes menores, resolve essas partes e depois combina os resultados.

151. **Verdadeiro ou Falso**: No algoritmo MergeSort, a divisão é a parte mais complexa, enquanto a combinação é trivial.

152. **Verdadeiro ou Falso**: A abordagem de divisão e conquista pode ser aplicada a problemas em que as sub-instâncias são independentes e de tamanho semelhante.

153. **Verdadeiro ou Falso**: Em um vetor totalmente ordenado de forma decrescente, o número de inversões é zero.

154. **Verdadeiro ou Falso**: Algoritmos de divisão e conquista podem ser paralelizados facilmente em sistemas com múltiplos processadores.

---


155. Qual das etapas a seguir faz parte do paradigma de divisão e conquista?
   - a) Dividir o problema em subproblemas menores.
   - b) Comprimir os dados para otimizar a memória.
   - c) Excluir subproblemas irrelevantes antes de resolver.
   - d) Verificar duplicidade de dados.

156. No contexto do MergeSort, qual das etapas a seguir ocorre após a divisão do problema?
   - a) A divisão de subproblemas em partes ainda menores.
   - b) A combinação de subsoluções para resolver o problema.
   - c) A ordenação direta dos elementos.
   - d) A remoção de duplicatas.

157. Em um vetor, uma inversão ocorre quando um elemento anterior é maior que um elemento seguinte, indicando que esses elementos estão "fora de ordem" para um vetor em ordem crescente. Para o vetor A = [4, 3, 2, 1], quantas inversões existem?
   - a) 4
   - b) 5
   - c) 6
   - d) 7

158. Em qual dos casos abaixo a abordagem de divisão e conquista é mais indicada?
   - a) Quando o problema pode ser dividido em subproblemas que podem ser resolvidos independentemente.
   - b) Quando o problema exige acesso sequencial a todos os dados.
   - c) Quando o problema não pode ser quebrado em subproblemas.
   - d) Quando a ordem de processamento dos dados não importa.


---

160. **Identifique e corrija o erro no código abaixo que tenta contar o número de inversões em um vetor usando divisão e conquista:**
    ```c
    int contarInversoes(int arr[], int inicio, int fim) {
        if (inicio == fim) return 0;
        int meio = (inicio + fim) / 2;
        int inversoes = contarInversoes(arr, inicio, meio);
        inversoes += contarInversoes(arr, meio + 1, fim);
        inversoes += combinarInversoes(arr, inicio, meio, fim);
        return meio;
    }
    ```
    **Pergunta:** Qual é o erro no retorno final da função?

161. **Corrija o código abaixo para que ele implemente o algoritmo MergeSort corretamente:**
    ```c
    void mergeSort(int arr[], int inicio, int fim) {
        if (inicio < fim) {
            int meio = (inicio + fim) / 2;
            mergeSort(arr, inicio, meio);
            mergeSort(arr, meio, fim);
            merge(arr, inicio, meio, fim);
        }
    }
    ```
    **Pergunta:** Qual é o erro na chamada recursiva para a segunda metade do array?

162. **Erro de Combinação em Inversões:** Corrija o seguinte trecho de código que combina as inversões de duas metades de um vetor dividido:
    ```c
    int combinarInversoes(int arr[], int inicio, int meio, int fim) {
        int i = inicio, j = meio + 1, inversoes = 0;
        while (i <= meio && j <= fim) {
            if (arr[i] < arr[j]) {
                i++;
            } else {
                inversoes += (meio - i + 1);
                j++;
            }
        }
        return inversoes;
    }
    ```
    **Pergunta:** Qual é o problema com o critério de comparação na contagem de inversões?

---


163. **Comparação de Listas de Preferências:** Escreva um programa que compare duas listas de preferência de filmes, cada uma com 10 elementos, e conte o número de inversões para verificar a compatibilidade entre as listas.

164. **Ordenação de um Vetor com MergeSort:** Implemente o algoritmo MergeSort para ordenar um vetor de inteiros fornecido pelo usuário. Exiba o vetor antes e depois da ordenação.

165. **Contagem de Inversões com MergeSort Modificado:** Modifique o MergeSort para contar o número de inversões durante o processo de ordenação. Mostre o número total de inversões no final.


167. **Multiplicação de Matrizes usando Divisão e Conquista:** Crie uma função recursiva para multiplicar duas matrizes quadradas de ordem 2, dividindo o problema em submatrizes menores e combinando os resultados.

---

## Questões sobre a escolha das Estruturas de Dados

1.  Você foi encarregado de desenvolver um sistema para gerenciar as contas de clientes em um banco. O número de clientes pode aumentar ou diminuir constantemente, dependendo de novos cadastros e encerramentos de contas. Como o banco está crescendo, o sistema precisa de flexibilidade para acomodar facilmente as adições e remoções de clientes. Cada cliente possui informações como número da conta, nome e saldo, que precisam estar acessíveis para consultas e operações.

**Requisitos principais do sistema:**

- Cadastro Dinâmico: O sistema deve permitir o cadastro de novos clientes, sem precisar redimensionar a estrutura que armazena os dados.
- Encerramento de Conta: Quando um cliente encerra sua conta, ele deve ser removido da estrutura sem reorganizar todos os dados restantes.
- Consulta de Informações: O sistema deve permitir que gerentes possam visualizar os dados de todos os clientes registrados, além de poder localizar um cliente específico pelo número da conta.

- Pergunta: Qual seria a estrutura de dados mais adequada que você escolheria para implementar esse sistema de gerenciamento de clientes e por quê? Considere as operações de adição, remoção e consulta, e explique como a estrutura de dados escolhida permite que essas operações sejam realizadas de forma eficiente e flexível. Descreva como essa estrutura funciona e como ela facilita a adaptação do sistema ao número variável de clientes.
---
2.  Imagine que você está desenvolvendo um sistema para organizar o atendimento de uma equipe de suporte técnico de uma grande empresa. Os clientes fazem solicitações de atendimento ao suporte e, para garantir uma experiência justa, a empresa deseja que os clientes sejam atendidos na ordem em que solicitaram ajuda. Como o número de solicitações pode variar ao longo do dia, o sistema precisa ser capaz de registrar novos pedidos de atendimento e processá-los na sequência correta.

### Requisitos do sistema:

1. **Registro de Solicitações**: O sistema deve ser capaz de registrar cada nova solicitação de atendimento à medida que ela chega.
2. **Atendimento Ordenado**: O atendimento deve ocorrer na mesma ordem em que as solicitações foram registradas, garantindo que os primeiros a solicitar sejam atendidos primeiro.
3. **Exclusão após Atendimento**: Após o atendimento de cada cliente, a solicitação dele deve ser removida do sistema para dar lugar ao próximo cliente na fila.

**Pergunta**: Qual estrutura de dados você escolheria para implementar esse sistema de gerenciamento de solicitações de suporte técnico e por quê? Considere as operações de adição e atendimento das solicitações, explicando como a estrutura escolhida permite que essas operações sejam realizadas de forma eficiente. Descreva como a estrutura de dados escolhida atende aos requisitos de ordem de chegada e remoção após o atendimento.

3. Imagine que você está desenvolvendo um sistema para gerenciar o histórico de navegação de um navegador de internet. Quando o usuário visita uma nova página, ela é adicionada ao topo do histórico. Caso o usuário queira voltar para a página anterior, ele deve ser capaz de desfazer sua última ação, retornando à página anterior. Da mesma forma, se o usuário voltar para uma página anterior, ele deve ter a opção de refazer a navegação e avançar para a próxima página visitada.

### Requisitos do sistema:

1. **Adição ao Histórico**: Sempre que uma nova página é visitada, ela deve ser registrada no histórico como a página mais recente.
2. **Navegação para Páginas Anteriores**: O sistema deve permitir que o usuário volte para a página anterior, desfazendo a última ação de navegação.
3. **Navegação para Páginas Recentes**: Caso o usuário tenha retornado a uma página anterior, ele deve poder avançar para a página seguinte.

**Pergunta**: Qual estrutura de dados você escolheria para implementar esse sistema de histórico de navegação e por quê? Considere as operações de adição de uma nova página e de navegação para páginas anteriores e seguintes, explicando como a estrutura escolhida permite que essas operações sejam realizadas de forma eficiente. Descreva como essa estrutura de dados gerencia o histórico de navegação e atende aos requisitos de desfazer e refazer ações.

3.  Imagine que você está desenvolvendo um sistema para organizar o fluxo de chamadas em um centro de atendimento. Durante o atendimento, os operadores recebem novas chamadas, e, em algumas situações, precisam colocar uma chamada em espera para atender uma questão urgente. Assim, a última chamada recebida ou colocada em espera deve ser a primeira a ser retomada quando o operador estiver disponível.

### Requisitos do sistema:

1. **Recebimento de Chamadas**: O sistema deve registrar cada nova chamada que chega, colocando-a no topo da lista de atendimento.
2. **Atendimento de Chamadas**: Quando o operador estiver disponível, ele deve atender a chamada mais recente, ou seja, a última chamada recebida.
3. **Retorno de Chamadas em Espera**: Se o operador colocou uma chamada em espera para atender outra mais urgente, ele deve retomar a chamada em espera na ordem inversa, atendendo a chamada mais recente primeiro.

**Pergunta**: Qual estrutura de dados você escolheria para implementar esse sistema de controle de chamadas e por quê? Considere as operações de recebimento, atendimento e retomada de chamadas, explicando como a estrutura escolhida permite que essas operações sejam realizadas de forma eficiente. Descreva como essa estrutura de dados gerencia o fluxo de chamadas e atende aos requisitos de atendimento e retomada na ordem correta.


4.  Imagine que você está desenvolvendo um sistema para registrar os alunos de uma academia. O número de alunos pode variar constantemente, e o sistema deve ser flexível para adicionar ou remover registros conforme novos alunos se matriculam ou cancelam suas matrículas. Cada aluno possui um número de matrícula único e outras informações, como nome e data de início na academia. O sistema precisa garantir que a remoção ou inserção de alunos ocorra de forma simples, sem a necessidade de reordenar todos os registros.

### Requisitos do sistema:

1. **Cadastro Flexível**: O sistema deve permitir a adição de novos alunos sem reorganizar todos os registros, garantindo uma adição eficiente de novos cadastros.
2. **Remoção Simples**: Quando um aluno decide cancelar a matrícula, o sistema deve remover seu registro sem comprometer a estrutura dos demais dados de alunos.
3. **Ponto de Referência (Cabeça)**: O sistema deve ter um ponto de referência inicial para facilitar o controle e a consulta de todos os alunos registrados, servindo como uma base para percorrer a lista.

**Pergunta**: Qual estrutura de dados você escolheria para implementar esse sistema de registro de alunos e por quê? Considere as operações de inserção e remoção de alunos, e explique como a estrutura escolhida permite realizar essas operações de forma eficiente. Descreva como essa estrutura de dados pode utilizar um ponto de referência inicial para gerenciar todos os registros e atender aos requisitos de flexibilidade para adicionar e remover alunos.













