
# Exercício: Soma dos dígitos de um número inteiro positivo (Recursão)

## Problema

A empresa fictícia **SoftCalc**, especializada em pequenos aplicativos matemáticos, precisa de uma função que calcule a **soma de todos os dígitos** de um número inteiro positivo qualquer.

### Exemplo:
- Se o número for `538`, a soma dos dígitos será:  
  `5 + 3 + 8 = 16`

A equipe da empresa quer que você implemente esta solução usando **recursão**.

---

## Requisitos

- O programa deverá conter uma função recursiva chamada `somaDigitos(int n)` que receba um número inteiro positivo `n` e retorne a soma de seus dígitos.
- Não é permitido utilizar **laços** (`for`, `while`, etc.).
- O programa deve ler um número do usuário e exibir o resultado da soma dos dígitos.

---

## Exemplo de entrada e saída

### Entrada:
```
Digite um número: 538
```

### Saída:
```
A soma dos dígitos de 538 é: 16
```

---

## Dicas para resolver:

- O **caso base** ocorre quando `n` for menor que 10 (número de um dígito).
- A **chamada recursiva** pode ser feita dividindo o número por 10 (`n/10`) e somando com o dígito mais à direita (`n % 10`).

