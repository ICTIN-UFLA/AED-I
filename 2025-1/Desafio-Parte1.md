
# Desafio 01: Cálculo de Bônus de Natal

## Contexto
Uma empresa deseja recompensar seus empregados na temporada de Natal com um bônus especial, calculado a partir de três critérios: tempo de serviço, idade e número de filhos.

## Critérios para o cálculo do bônus
- **Tempo de serviço:** R$ 20,00 por ano trabalhado.
- **Idade:** Caso o empregado tenha mais de 45 anos, recebe um adicional de R$ 5,00 por ano de serviço.
- **Filhos:** R$ 15,00 por filho, limitado ao máximo de R$ 45,00 (ou seja, no máximo três filhos contabilizam para o bônus).

## O que deve ser feito
Você deve desenvolver um programa em linguagem C que leia os dados de múltiplos empregados e calcule o bônus de Natal de cada um, de acordo com as regras descritas acima. O programa deve utilizar **Tipos Abstratos de Dados (TADs)** para representar os empregados e suas informações, e deve fazer uso de **alocação dinâmica de memória** para lidar com diferentes quantidades de empregados.

Além disso, o programa deve ler os dados a partir de um **arquivo de texto (`entrada.txt`)**, que conterá o número de empregados e, em seguida, as informações de cada um.

## Operações que o programa deve realizar
1. Abrir o arquivo `entrada.txt` para leitura.
2. Ler um número inteiro `n` indicando a quantidade de empregados.
3. Para cada empregado, ler:
   - número de inscrição (identificador único),
   - idade,
   - tempo de serviço (em anos),
   - número de filhos.
4. Calcular o bônus individual, conforme os critérios estabelecidos.
5. Exibir o número de inscrição e o valor do bônus de forma formatada.

## Formato da Entrada

A entrada será fornecida via arquivo `entrada.txt`, que conterá:
- Um número inteiro `n`, representando a quantidade de empregados.
- Em seguida, `n` linhas com quatro inteiros em cada linha:
  - número de inscrição,
  - idade,
  - tempo de serviço (em anos),
  - número de filhos.

### Exemplo do conteúdo do `entrada.txt`
```
2
42 45 10 1
33 55 20 2
```

## Formato da Saída

Para cada empregado, deve-se exibir duas linhas no seguinte formato:

```
Numero de inscricao.: <número de inscrição>
Bonus...............: <valor do bônus>
```

As saídas devem aparecer na mesma ordem de entrada.

### Exemplo de Saída no terminal
```
Numero de inscricao.: 42
Bonus...............: 215

Numero de inscricao.: 33
Bonus...............: 530
```

## Explicação dos Cálculos

### Empregado 1:
- Número de inscrição: 42
- Idade: 45 (não recebe adicional por idade)
- Tempo de serviço: 10 anos → 10 × R$ 20,00 = R$ 200,00
- Número de filhos: 1 → 1 × R$ 15,00 = R$ 15,00
- **Total do bônus: R$ 200,00 + R$ 15,00 = R$ 215,00**

### Empregado 2:
- Número de inscrição: 33
- Idade: 55 (recebe adicional de R$ 5,00 por ano de serviço)
- Tempo de serviço: 20 anos → 
  - R$ 20,00 × 20 = R$ 400,00 (bônus padrão)
  - R$ 5,00 × 20 = R$ 100,00 (adicional por idade)
- Número de filhos: 2 → 2 × R$ 15,00 = R$ 30,00
- **Total do bônus: R$ 400,00 + R$ 100,00 + R$ 30,00 = R$ 530,00**

## Observações Finais
- Utilize ponteiros e alocação dinâmica para armazenar os dados dos empregados.
- Crie uma estrutura (TAD) para representar um empregado, contendo os campos necessários.
- Mantenha o código modular, com funções para leitura, cálculo e exibição.
- Certifique-se de fechar corretamente o arquivo após a leitura.
- Não se esqueça de testar seu programa com diferentes cenários, inclusive empregados com mais de três filhos.
