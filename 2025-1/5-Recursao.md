
#  Algoritmos Recursivos em C

## ✅ O que é um Algoritmo Recursivo?

É um algoritmo que resolve um problema chamando a si mesmo (função chamando ela mesma) para resolver partes menores desse problema, até chegar a uma solução simples chamada de **caso base**.

## 🧩 Estrutura de uma função recursiva

Toda função recursiva tem dois elementos obrigatórios:
1. **Caso base** — condição que faz a função parar.
2. **Chamada recursiva** — a função se chama novamente, reduzindo o problema.

## 💡 Exemplo 1: Contagem regressiva simples

```c
#include <stdio.h>

void contagemRegressiva(int n) {
    if (n == 0) {  // Caso base
        printf("Fogo!\n");
    } else {
        printf("%d\n", n);
        contagemRegressiva(n - 1);  // Chamada recursiva
    }
}

int main() {
    contagemRegressiva(5);
    return 0;
}
```

### Saída:
```
5
4
3
2
1
Fogo!
```

## 💡 Exemplo 2: Fatorial

O cálculo do fatorial é um clássico exemplo de recursão.

> Definição matemática:
> - `n! = n * (n-1)!`
> - `0! = 1`

```c
#include <stdio.h>

int fatorial(int n) {
    if (n == 0) {  // Caso base
        return 1;
    } else {
        return n * fatorial(n - 1);  // Chamada recursiva
    }
}

int main() {
    int numero = 5;
    printf("Fatorial de %d = %d\n", numero, fatorial(numero));
    return 0;
}
```

### Saída:
```
Fatorial de 5 = 120
```

## 💡 Exemplo 3: Soma dos elementos de um vetor

```c
#include <stdio.h>

int somaVetor(int v[], int n) {
    if (n == 0) {  // Caso base
        return 0;
    } else {
        return v[n - 1] + somaVetor(v, n - 1);  // Chamada recursiva
    }
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    int tamanho = 5;
    printf("Soma dos elementos = %d\n", somaVetor(v, tamanho));
    return 0;
}
```

### Saída:
```
Soma dos elementos = 15
```

## ⚠️ Atenção:

- Toda função recursiva **deve** ter um caso base bem definido, ou o programa entrará em **loop infinito**.
- O uso de recursão muitas vezes envolve mais uso de **memória** (pilha de chamadas).
- Algumas tarefas que podem ser resolvidas de forma iterativa podem ser resolvidas recursivamente, e vice-versa.
- Funções recursivas são muito úteis em estruturas como **árvores** e **grafos**, que você vai aprender mais adiante.

## 🟣 Dica Visual

```
fatorial(3)
= 3 * fatorial(2)
= 3 * (2 * fatorial(1))
= 3 * (2 * (1 * fatorial(0)))
= 3 * (2 * (1 * 1))
= 3 * 2 * 1 = 6
```
