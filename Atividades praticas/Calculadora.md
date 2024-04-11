
  

#  Calculadora em C

  

Este tutorial ensina como criar uma calculadora simples em C que pode somar, subtrair, multiplicar e dividir dois números com base na escolha do usuário.

  

## Passo 1: Incluir Bibliotecas Necessárias

  

Comece seu programa incluindo a biblioteca padrão de entrada e saída.

  

```c

#include  <stdio.h>

```

  

## Passo 2: Criar Função Main

  

A função `main` será o coração do seu programa.

  

```c

int  main() {

int operacao;

double num1, num2;

  

while(1) {

printf("Calculadora\n");

printf("Digite 1 para somar\n");

printf("Digite 2 para subtrair\n");

printf("Digite 3 para multiplicar\n");

printf("Digite 4 para dividir\n");

printf("Digite 0 para sair\n");

printf("Escolha uma operação: ");

scanf("%d", &operacao);

  

if (operacao == 0) {

break;

}

  

printf("Digite o primeiro número: ");

scanf("%lf", &num1);

printf("Digite o segundo número: ");

scanf("%lf", &num2);

  

switch(operacao) {

case 1:

printf("Resultado: %.2lf\n", num1 + num2);

break;

case 2:

printf("Resultado: %.2lf\n", num1 - num2);

break;

case 3:

printf("Resultado: %.2lf\n", num1 * num2);

break;

case 4:

if(num2 != 0) {

printf("Resultado: %.2lf\n", num1 / num2);

} else {

printf("Não é possível dividir por zero.\n");

}

break;

default:

printf("Operação inválida!\n");

}

}

  

return 0;

}

```

  

### Explicação do Código:

  

1. **int main()**: Ponto de entrada do seu programa.

2. **Declaração de Variáveis**: Armazena a operação e os números para cálculo.

3. **Loop while(1)**: Permite realizar múltiplas operações.

4. **printf e scanf**: Para interação com o usuário.

5. **switch(operacao)**: Seleciona a operação baseada na escolha do usuário.

6. **Operações**: Realiza a soma, subtração, multiplicação ou divisão.

7. **default**: Captura escolhas inválidas.

8. **return 0;**: Encerra o programa.

  

 # Atividade: Expandindo a Calculadora em C

## Objetivo

Aprimore a calculadora criada  adicionando novas operações matemáticas. Isso ajudará a desenvolver sua compreensão de funções, estruturas de controle e entrada/saída em C.

## Instruções

1.  **Adicione Mais Operações Matemáticas**: Expanda o menu da calculadora para incluir as seguintes operações:
    
    -   Potência (digite 5 para potência)
    -   Raiz quadrada (digite 6 para raiz quadrada)
    -   Módulo (resto da divisão, digite 7 para módulo)
2.  **Implemente as Funções Correspondentes**:
    
    -   Para a potência, utilize a função `pow` da biblioteca `math.h`.
    -   Para a raiz quadrada, utilize a função `sqrt` da mesma biblioteca.
    -   Para o módulo, você pode usar o operador `%`. Lembre-se que o módulo só funciona com números inteiros.
3.  **Atualize o Menu de Escolha**:
    
    -   Adicione as novas opções ao menu de seleção e certifique-se de que os números de entrada são adequados para cada operação (por exemplo, raiz quadrada de números negativos não é permitida em números reais).
4.  **Teste o Programa**:
    
    -   Certifique-se de que todas as operações funcionam como esperado.
    -   Trate quaisquer erros ou entradas inválidas de maneira adequada.
## Dicas

-   Lembre-se de incluir `#include <math.h>` para acessar as funções matemáticas.
-   Considere a precisão dos números (inteiros vs. floats/doubles) em suas operações.
-   Use a estrutura `switch` para tratar as diferentes escolhas de operações matemáticas.
-   Mantenha seu código organizado e legível.

## Desafio 

Implemente uma função de "histórico", que guarda as últimas operações realizadas e seus resultados. Isso requer conhecimento de vetor (estruturas de dados)

**Dicas**

**Defina uma Estrutura para as Operações**: Primeiro, crie uma estrutura que pode armazenar uma operação e seu resultado. Por exemplo:

```c
typedef  struct {  
	char operacao[50]; // Para armazenar a descrição da operação, como "2 + 3"  
	double resultado; // Para armazenar o resultado da operação 
} Historico;
```

**Crie um Array (vetor) de Histórico**: Declare um array de `Historico` para armazenar um número fixo de operações passadas.
**Atualize o Histórico após cada Operação**: Após cada operação, atualize o histórico com a operação e o resultado.
**Mostrar o Histórico**: Implemente uma função para mostrar o histórico de operações.

  
Sim, é possível implementar uma função de "histórico" em sua calculadora em C usando um vetor (array). A ideia básica é criar um array para armazenar as operações realizadas e seus resultados. Vou te dar um esboço de como isso pode ser feito.

### Passos para Implementar a Função de Histórico

1.  **Defina uma Estrutura para as Operações**: Primeiro, crie uma estrutura que pode armazenar uma operação e seu resultado. Por exemplo:
    
    cCopy code
    
    `typedef struct {
        char operacao[50];  // Para armazenar a descrição da operação, como "2 + 3"
        double resultado;   // Para armazenar o resultado da operação
    } Historico;` 
    
2.  **Crie um Array de Histórico**: Declare um array de `Historico` para armazenar um número fixo de operações passadas.
    
    cCopy code
    
    `#define TAMANHO_HISTORICO 10
    Historico historico[TAMANHO_HISTORICO];
    int contadorHistorico = 0;` 
    
3.  **Atualize o Histórico após cada Operação**: Após cada operação, atualize o histórico com a operação e o resultado.
    
    cCopy code
    
    `void atualizarHistorico(char *operacao, double resultado) {
        if (contadorHistorico == TAMANHO_HISTORICO) {
            // Se o histórico estiver cheio, mova todos os itens uma posição para trás
            for (int i = 1; i < TAMANHO_HISTORICO; i++) {
                historico[i - 1] = historico[i];
            }
            contadorHistorico--;
        }
    
        // Adicionando a nova operação ao histórico
        strcpy(historico[contadorHistorico].operacao, operacao);
        historico[contadorHistorico].resultado = resultado;
        contadorHistorico++;
    }` 
    
4.  **Mostrar o Histórico**: Implemente uma função para mostrar o histórico de operações.
    
    cCopy code
    
    `void mostrarHistorico() {
        printf("Historico de Operacoes:\n");
        for (int i = 0; i < contadorHistorico; i++) {
            printf("%s = %.2lf\n", historico[i].operacao, historico[i].resultado);
        }
    }` 
    
5.  **Integre com a Calculadora**: Certifique-se de chamar `atualizarHistorico` após cada operação e de adicionar uma opção no menu para chamar `mostrarHistorico`.
    

### Considerações

-   Lembre-se de incluir `#include <string.h>` para usar funções como `strcpy`.
-   Este método armazena um número fixo de operações mais recentes. Quando o array está cheio, a operação mais antiga é descartada.
-   O tamanho do array pode ser ajustado conforme necessário, alterando a constante `TAMANHO_HISTORICO`.
-   O histórico não é persistente; ele é perdido quando o programa é fechado. Para manter um histórico persistente, você precisaria escrever e ler de um arquivo.
