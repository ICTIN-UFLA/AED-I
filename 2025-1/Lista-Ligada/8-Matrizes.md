
# 🧮 Matrizes em C

## 📌 Objetivo

Você vai aprender a trabalhar com **matrizes** na linguagem C, incluindo:

- Declaração e inicialização;
- Leitura e impressão;
- Operações básicas (soma, multiplicação, transposição);
- Diferenças entre alocação estática e dinâmica.

---

## 📚 O que é uma Matriz?

Uma **matriz** é uma estrutura de dados bidimensional (2D), representada por **linhas** e **colunas**. Em C, ela é declarada como um **vetor de vetores**.

---

## 🧱 Parte 1: Matrizes com Alocação Estática

### ✅ Declaração

```c
#define LINHAS 3
#define COLUNAS 3

int matriz[LINHAS][COLUNAS];
```

---

### 📥 Leitura

```c
void lerMatriz(int m[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Digite o valor para [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}
```

---

### 📤 Impressão

```c
void imprimirMatriz(int m[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
```

---

### ➕ Soma de Matrizes

```c
void somarMatrizes(int a[LINHAS][COLUNAS], int b[LINHAS][COLUNAS], int resultado[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            resultado[i][j] = a[i][j] + b[i][j];
        }
    }
}
```

---

### ✖️ Multiplicação de Matrizes

```c
void multiplicarMatrizes(int a[LINHAS][COLUNAS], int b[LINHAS][COLUNAS], int resultado[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < COLUNAS; k++) {
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
```

---

## 🔗 Parte 2: Matrizes com Alocação Dinâmica

### 🛠️ Criação de Matriz Dinâmica

```c
int** criarMatriz(int linhas, int colunas) {
    int **m = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        m[i] = (int*) malloc(colunas * sizeof(int));
    }
    return m;
}
```

---

### 🧹 Liberação de Memória

```c
void liberarMatriz(int **m, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(m[i]);
    }
    free(m);
}
```

---

### Leitura, Impressão e Operações

As funções de leitura, impressão, soma e multiplicação seguem o mesmo padrão da versão estática, trocando:

```c
m[i][j]
```

por:

```c
m[i][j]
```

---

## ⚖️ Estática vs Dinâmica

| Aspecto                | Estática                        | Dinâmica                        |
|------------------------|----------------------------------|----------------------------------|
| Tamanho fixo           | Sim                             | Não                              |
| Flexibilidade          | Limitada                        | Alta                             |
| Complexidade de código | Baixa                           | Alta (necessita ponteiros)       |
| Uso de memória         | Fixo                            | Ajustável conforme necessário    |

---

## 🧪 Exemplo de Uso

```c
int main() {
    int a[LINHAS][COLUNAS], b[LINHAS][COLUNAS], resultado[LINHAS][COLUNAS];

    printf("Matriz A:\n");
    lerMatriz(a);
    printf("Matriz B:\n");
    lerMatriz(b);

    somarMatrizes(a, b, resultado);
    printf("Soma das matrizes:\n");
    imprimirMatriz(resultado);

    multiplicarMatrizes(a, b, resultado);
    printf("Multiplicação das matrizes:\n");
    imprimirMatriz(resultado);

    return 0;
}
```

---

## 🧠 Desafios

1. Implemente a transposição de uma matriz.
2. Faça leitura de uma matriz dinâmica com tamanho fornecido pelo usuário.
3. Verifique se uma matriz é simétrica.

---

## ✅ Conclusão

Você aprendeu:

- Como declarar, ler e imprimir matrizes;
- Como realizar soma e multiplicação;
- Diferenças entre matriz estática e dinâmica.

---

## 📎 Licença

Este conteúdo está sob a Licença MIT. Use, modifique e compartilhe livremente!
