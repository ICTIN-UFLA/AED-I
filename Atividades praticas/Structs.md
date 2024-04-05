
# Universidade Federal de Lavras - UFLA

### Lista de exercícios de programação em linguagem C

#### Exercícios: Structs

1.  **Escreva um trecho de código para fazer a criação dos novos tipos de dados conforme solicitado abaixo:**
    
    -   Horário: composto de hora, minutos e segundos.
    -   Data: composto de dia, mês e ano.
    -   Compromisso: composto de uma data, horário e texto que descreve o compromisso.
    
2.  **Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e armazene os dados em uma estrutura.**
    Dica:   **A função scanf()** É utilizada para fazer a leitura de dados formatados via teclado. Ex: 
  ````c
    //declaração de variáveis do tipo inteiro
int a, b, soma;
printf("Digite um numero inteiro: ");
scanf("%d", &a); //recebe um inteiro e armazena na variável a
  ````

3.  **Construa uma estrutura aluno com nome, número de matrícula e curso. Leia do usuário a informação de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na tela.**
Dica: para criar um vetor, faça:   int numeros[5] = {10, 20, 30, 40, 50};

Exemplo de código fonte: 

````c
#include<stdio.h>
#include<conio.h>
int main(void)
{
  float notas[5] = {7, 8, 9.5, 9.9, 5.2};
  // declarando e inicializando o vetor notas
  
  printf("Exibindo os Valores do Vetor \n\n");
  printf("notas[0] = %.1f\n", notas[0]);
  printf("notas[1] = %.1f\n", notas[1]);
  printf("notas[2] = %.1f\n", notas[2]);
  printf("notas[3] = %.1f\n", notas[3]);
  printf("notas[4] = %.1f\n", notas[4]);
  
  return 0;
}
````
    
4.  **Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.**
    
    -  a) Permita ao usuário entrar com os dados de 5 alunos.
    -  b) Encontre o aluno com maior nota da primeira prova.
    -  c) Encontre o aluno com maior média geral.
    -  d) Encontre o aluno com menor média geral.
    -  e) Para cada aluno, diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.
    
5.  **Considerando a estrutura**
  ````c
struct Vetor{
    float x;
    float y;
    float z;
};
````

  
6. **Faça um programa que realize a leitura dos seguintes dados relativos a um conjunto de alunos: Matrícula, Nome, Código da Disciplina, Nota1 e Nota2. Considere uma turma de até 10 alunos. Após ler todos os dados digitados e depois de armazená-los em um vetor de estrutura, exiba na tela a listagem final dos alunos com as suas respectivas médias finais (use uma média ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).**
