
### 1) Atividade: Calculadora de IMC em C

**Objetivo:** Escrever um programa em C que captura o peso e a altura do usuário através do teclado e calcula seu Índice de Massa Corporal (IMC).

#### Especificações:

1.  **Captura de Dados:** O programa deve pedir ao usuário para inserir seu peso em quilogramas e sua altura em metros.
2.  **Cálculo do IMC:** O IMC é calculado pela fórmula `IMC = peso / (altura * altura)`.
3.  **Exibição do Resultado:** O programa deve exibir o IMC calculado.


#### Complete o código-fonte a seguir: 

````C
#include <stdio.h>  
int  main() { 
float peso, altura, imc; // Solicita entrada do usuário  
printf("Digite seu peso em quilogramas: "); 
scanf("%f", &peso); 
printf("Digite sua altura em metros: "); 
scanf("%f", &altura);

````

 ## 2) A calculadora de IMC em C deverá ser modificada para receber vários usuários.
**Objetivo:** Modificar o programa anterior para que ele calcule o IMC de vários usuários. O programa deve armazenar pesos e alturas em vetores e os IMCs em uma matriz.

#### Especificações:

1.  **Armazenamento em Vetores:** Utilize dois vetores para armazenar os pesos e as alturas de vários usuários.
2.  **Cálculo e Armazenamento de IMC em Matriz:** Armazene os resultados do IMC em uma matriz.
3.  **Entrada de Dados para Múltiplos Usuários:** Permita que o usuário insira os dados para um número específico de usuários.
4.  **Exibição dos Resultados:** Exiba o IMC de cada usuário.
