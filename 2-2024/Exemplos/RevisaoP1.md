# Lista de Exercícios - Alocação Dinâmica de Memória - AULA -2

## Exercício 1: Vetor Dinâmico
Faça um programa em C que:
1. Leia um valor `n` do usuário.
2. Crie dinamicamente um vetor de `n` elementos inteiros.
3. Passe o vetor para uma função que deve preenchê-lo com valores fornecidos pelo usuário.
4. Imprima o vetor após o preenchimento.
5. Não se esqueça de liberar a memória alocada para o vetor.

*Dica:* Utilize `malloc` para alocar o vetor e `free` para liberar a memória.

## Exercício 2: Simulando um Sistema de Cadastro
Implemente um programa que simule o cadastro de clientes em uma loja. O programa deve:
1. Solicitar ao usuário quantos cadastros ele deseja inserir.
2. Alocar dinamicamente um vetor de estruturas onde cada estrutura armazena os dados de um cliente (nome, idade e telefone).
3. Imprimir os dados cadastrados.
4. Liberar toda a memória alocada ao final.

*Dica:* Defina uma estrutura `Cliente` para armazenar os dados. Use `malloc` e `free` para alocação e liberação de memória.

## Exercício 3: Operações com Matrizes Dinâmicas
Escreva um programa que:
1. Solicite ao usuário as dimensões de uma matriz (linhas e colunas).
2. Aloque dinamicamente a matriz utilizando ponteiros.
3. Preencha a matriz com valores inteiros digitados pelo usuário.
4. Calcule e exiba a soma de todos os elementos.
5. Libere a memória alocada para a matriz.

*Dica:* Utilize ponteiros para ponteiros para representar a matriz e `malloc` para a alocação dinâmica.

## Exercício 4: Cópia de Vetores com Ponteiros
Escreva uma função que recebe dois ponteiros para inteiros e um tamanho `n`. A função deve:
1. Copiar os valores de um vetor para outro.
2. Caso o vetor destino não tenha memória suficiente, a função deve realocar a memória.

*Exemplo:* Se o vetor de origem possui 5 elementos e o destino apenas 3, realoque o destino para comportar todos os elementos antes de copiar.

*Dica:* Utilize `malloc` e `realloc` para garantir o tamanho necessário no vetor destino.

## Exercício 5: Manipulação de Strings com Ponteiros
Crie um programa que:
1. Solicite ao usuário uma frase de até 100 caracteres.
2. Aloque dinamicamente uma string para armazenar essa frase.
3. Converta todos os caracteres da frase para maiúsculas.
4. Exiba a frase convertida.
5. Libere a memória alocada.

*Dica:* Use `malloc` para alocar a memória para a string e `toupper` para converter os caracteres.

## Exercício 6: Lista Encadeada
Implemente uma lista encadeada para armazenar uma lista de compras. Cada nó deve conter o nome do item e a quantidade. O programa deve:
1. Permitir adicionar itens na lista.
2. Imprimir todos os itens da lista.
3. Permitir a remoção de um item específico.
4. Liberar toda a memória alocada ao encerrar o programa.

*Dica:* Utilize uma estrutura de nó com ponteiros para formar a lista encadeada e `free` para liberar a memória.

## Exercício 7: Alocação e Liberação Sequencial
Faça um programa que:
1. Crie um vetor de inteiros com tamanho `n` definido pelo usuário.
2. Preencha o vetor com valores aleatórios entre 0 e 100.
3. Ao final do preenchimento, libere a memória do vetor e peça ao usuário para inserir um novo valor de `n`.
4. Repita o processo de alocação, preenchimento e liberação até que o usuário insira um valor negativo para `n`.

*Dica:* Use `rand` para gerar valores aleatórios e `malloc` para alocação.


## Exercício 8: Gerenciamento de Memória - Erros Comuns
Explique e corrija os seguintes trechos de código:

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

## Exercício 9: Funções que Alocam Memória

Escreva uma função que:

1.  Receba um ponteiro para um vetor e um valor `n`.
2.  Aloque dinamicamente um vetor de `n` elementos e preencha com números aleatórios.
3.  Retorne o ponteiro para o vetor ao programa principal.

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



