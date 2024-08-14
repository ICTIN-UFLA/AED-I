
  

# Atividade Prática: Aplicação de Tabela Hash em C

  

## Contexto do Problema

Você foi contratado para desenvolver um sistema de gerenciamento de alunos para uma universidade. O sistema deve armazenar informações dos alunos, incluindo o número de matrícula (como chave), o nome do aluno e o curso que ele está matriculado. A universidade precisa de uma forma eficiente de adicionar novos alunos, buscar informações de alunos específicos e remover alunos que se formaram ou cancelaram a matrícula.
  

## Objetivo

Implementar uma tabela hash em C para gerenciar os dados dos alunos da universidade, permitindo as operações de inserção, busca e remoção de alunos.

 ### Instruções

Crie um arquivo chamado `alunos.c`.

#### Estrutura da Tabela Hash

Cada aluno terá um número de matrícula único que será usado como chave na tabela hash. A tabela armazenará informações sobre o aluno, como nome e curso.

#### Função de Hash

A função de hash será baseada na soma dos valores ASCII dos caracteres do número de matrícula.

#### Funções para Manipulação da Tabela Hash

##### Inicialização

Inicialize a tabela hash definindo todos os ponteiros como NULL.

##### Inserção

Para inserir um novo aluno na tabela hash, use a função de hash para calcular o índice onde o aluno será armazenado e adicione o aluno à lista encadeada no índice apropriado.

##### Busca

Para buscar informações sobre um aluno específico, use a função de hash para calcular o índice e percorra a lista encadeada no índice até encontrar o aluno.

##### Remoção

Para remover um aluno do sistema, encontre o índice usando a função de hash e remova o aluno correspondente da lista encadeada.

#### Função Principal para Teste

Implemente a função principal para testar a tabela hash. Crie um arquivo chamado `alunos.c` e adicione o código abaixo.

### Conclusão

Nesta atividade prática, você implementou uma tabela hash para gerenciar os dados dos alunos de uma universidade. A tabela hash permite adicionar, buscar e remover alunos de maneira eficiente. Essa abordagem é útil para sistemas onde operações rápidas de busca e atualização são essenciais.
