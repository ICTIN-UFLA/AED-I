
# Aula 1 em C

Este guia é projetado para ajudá-lo a dar seus primeiros passos no mundo da programação usando a linguagem C.

## O que é C?

C é uma linguagem de programação de propósito geral originalmente desenvolvida por Dennis Ritchie no início dos anos 70. É conhecida por sua eficiência e é amplamente utilizada para desenvolver software de sistema e aplicações.

## Ambiente de Desenvolvimento

Antes de começarmos, você precisa configurar um ambiente de desenvolvimento em C. Vamos usar o Visual Studio Code (VSCode), um editor de código popular e gratuito.
### Instalando o Compilador C e as Extensões
Para programar em C, você precisará de um compilador C. O GCC (GNU Compiler Collection) é uma opção popular. Siga estas etapas para configurar o compilador e as extensões necessárias:

1.  **Instale o GCC:**  -  **Windows:** Você pode instalar o MinGW (um port do GCC para Windows) [aqui](http://www.mingw.org/). -  **Mac:** Instale o Xcode através da App Store, que inclui o GCC. -  **Linux:** O GCC geralmente já está instalado. Se não, você pode instalá-lo através do gerenciador de pacotes da sua distribuição. 
2.  **Instale as Extensões do VSCode:**  - Abra o VSCode e vá para a seção de extensões (`Ctrl+Shift+X`). - Procure e instale as seguintes extensões: -  `C/C++` da Microsoft, para suporte de linguagem C/C++. -  `Code Runner`, para compilar e executar facilmente o código. 

### Configurando o Compilador no VSCode  
1. Abra o VSCode. 
2. Crie um novo arquivo e salve-o com a extensão `.c`. 
3.  Escreva seu código C. 
4.  Pressione `Ctrl+Alt+N` para compilar e executar o código usando a extensão Code Runner.

## Seu Primeiro Programa em C

Vamos começar com o clássico "Hello, World!". Este programa simplesmente exibe a mensagem "Hello, World!" na tela.

### Código Fonte

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
````

## Desafios 

### Problema: Imprimir uma Palavra Inversa

Escreva um programa em C que solicita ao usuário uma palavra e, em seguida, imprime essa palavra de forma invertida. Por exemplo, se o usuário digitar "programa", o programa deve imprimir "amargorp". 

```c
#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    
    // Solicitar a palavra ao usuário
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra);

    // Imprimir a palavra de forma inversa
    printf("Palavra invertida: ");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", palavra[i]);
    }
    printf("\n");

    return 0;
}
````

### Agora é a sua vez de resolver o problema, mas sem ChatGPT

### Desafio para os Alunos:

**Problema: Calculadora de Média**

Escreva um programa em C que solicite ao usuário para inserir três números e, em seguida, calcule e exiba a média desses números.


### Passos para Resolver o Desafio "Calculadora de Média"

1.  **Solicitar Entrada do Usuário:**
    
    -   O programa deve começar pedindo ao usuário para inserir três números. Estes podem ser de qualquer tipo (inteiros ou flutuantes).
2.  **Armazenar as Entradas:**
    
    -   Armazene cada uma das três entradas em variáveis separadas. Certifique-se de que as variáveis são do tipo correto para armazenar os números (por exemplo, `float` ou `int`).
3.  **Calcular a Média:**
    
    -   Para calcular a média dos três números, some todos os números e, em seguida, divida o resultado pela quantidade de números (neste caso, 3).
    -   É importante garantir que a divisão seja feita de forma correta. Se você estiver usando inteiros, talvez precise converter os valores para um tipo flutuante para obter uma média precisa.
4.  **Exibir o Resultado:**
    
    -   Após calcular a média, o programa deve exibir o resultado para o usuário. Isso pode ser feito usando uma função de saída padrão, garantindo que o resultado seja apresentado de forma clara e legível.
