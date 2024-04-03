
  

# Atividade Prática: Sistema de Registro Escolar com Structs e Ponteiros

  

## Objetivo

Desenvolver um sistema para gerenciar informações de alunos utilizando structs e ponteiros em C.

  

## Parte 1: Definição da Struct

Reutilize a struct `SAluno` fornecida na aula, que contém:

-  `char nome[50]`

-  `int matricula`

-  `float nota`

  

## Parte 2: Funções Básicas

### Adicionar Aluno

```c

void  adicionarAluno(SAluno *alunos, int *total) {

// Aloca e pede informações do novo aluno.

// Incrementa total de alunos.

}

```

- Pedir informações do usuário.

- Armazenar os dados no vetor (array) de `SAluno`.

  

### Imprimir Alunos

```c

void  imprimirAlunos(SAluno *alunos, int  total) {

// Percorre o array de alunos e imprime suas informações.

}

```

- Imprimir informações de todos os alunos.

  

### Atualizar Nota

```c

void  atualizarNota(SAluno *alunos, int  total) {

// Atualiza a nota de um aluno baseado na sua matrícula.

}

```

- Pedir a matrícula e a nova nota.

- Atualizar a nota do aluno correspondente.

  

## Parte 3: Uso de Ponteiros

- Manipule as structs `SAluno` usando ponteiros.

- Utilize alocação dinâmica de memória para o array (vetor) de alunos.

- Certifique-se de desalocar a memória adequadamente.

  

## Parte 4: Main e Menu de Interação

Implemente um menu principal no método `main()` com as seguintes funcionalidades:

- Adicionar aluno

- Visualizar alunos

- Atualizar nota de aluno

- Sair do programa

  

```c

int  main() {

// Código para implementar o menu e as funcionalidades

}

```

  

## Instruções Adicionais

- Gerencie a memória cuidadosamente para evitar vazamentos.

- Valide os dados inseridos pelo usuário.

- Comente o código para melhor compreensão.

  

## Desafios Adicionais

- Implemente a funcionalidade de deletar um aluno.

- Calcule e mostre a média das notas dos alunos.

- Trate matrículas duplicadas de forma adequada.

  

## Entrega e Avaliação

- Essa atividade não vale pontos é apenas para aprendizado