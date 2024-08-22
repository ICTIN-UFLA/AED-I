
# Revisão de Conteúdo: Aula 8 - Complexidade de Algoritmos (Parte 1)

## Introdução à Análise de Algoritmos

### O que é Analisar um Algoritmo?

A análise de algoritmos envolve a avaliação do custo de execução de um algoritmo, focando principalmente em:

-   **Tempo:** Tempo necessário para executar o algoritmo.
-   **Espaço:** Memória ocupada durante a execução.

Essa análise é crucial para escolher o algoritmo mais adequado para resolver um problema específico, especialmente em áreas como pesquisa operacional, otimização, teoria dos grafos, estatística, e probabilidade.

### Cálculo do Custo Real de Execução

Embora medir o custo real da execução de um algoritmo possa ser dependente de fatores como o compilador ou o hardware, essas medições são úteis para comparar algoritmos que resolvem o mesmo problema dentro da mesma ordem de grandeza.

## Tipos de Análise

### Análise de um Algoritmo Específico

-   **Objetivo:** Determinar o custo de usar um determinado algoritmo para resolver um problema específico.
-   **Aspectos Considerados:**
    -   Número de vezes que cada parte do algoritmo é executada (tempo).
    -   Quantidade de memória necessária (espaço).

### Análise de uma Classe de Algoritmos

-   **Objetivo:** Identificar o algoritmo de menor custo para resolver um problema específico, considerando toda uma família de algoritmos.

## Custo de um Algoritmo

### Modelo Matemático

O custo de um algoritmo é usualmente representado por uma função de complexidade, que mede o número de vezes que operações relevantes são executadas.

### Exemplo: Maior Elemento de um Vetor

Considerando um algoritmo que encontra o maior elemento de um vetor:

-   **Função de complexidade:** Se `f(n)` é o número de comparações para um vetor de tamanho `n`, então `f(n) = n - 1`.

### Exemplo: Pesquisa em Arquivos

Analisando o acesso a registros em um arquivo:

-   **Melhor Caso:** O registro procurado é o primeiro.
-   **Pior Caso:** O registro procurado é o último.
-   **Caso Médio:** Supondo que todos os registros têm a mesma probabilidade de serem acessados, a complexidade média é `(n + 1)/2`.

## Análise de Melhor Caso, Pior Caso e Caso Médio

### Exemplo: Maior e Menor Elementos de um Vetor

Três algoritmos são analisados para encontrar o maior e o menor elemento em um vetor:

-   **MaxMin1:** Realiza `2(n - 1)` comparações em todos os casos.
-   **MaxMin2:** Otimiza comparações, com complexidade de `n - 1` no melhor caso, `2(n - 1)` no pior caso, e `3n/2 - 3/2` no caso médio.
-   **MaxMin3:** Comparações feitas em pares, resultando em uma complexidade uniforme de `3n/2 - 2`.

### Conclusão

O algoritmo MaxMin3 se destaca como o mais eficiente, especialmente em termos de pior caso, sendo superior ao MaxMin2 e MaxMin1.

## Exercícios Propostos

1.  **Comparar Dois Procedimentos:** Avaliar os códigos fornecidos para verificar se produzem o mesmo resultado, determinar as funções de complexidade e justificar a escolha de um deles com base nos resultados.


# Revisão de Conteúdo: Aula 9 - Complexidade de Algoritmos (Parte 2)

## Introdução

Nesta aula, continuamos o estudo da análise de complexidade de algoritmos, focando no comportamento assintótico das funções de custo e nas notações utilizadas para expressar esse comportamento.

### Sumário

1.  Comportamento Assintótico de Funções
2.  Dominação Assintótica
    -   Notação O
    -   Notação Ω (Ômega)
    -   Notação Θ (Theta)
3.  Conclusão
4.  Exercícios

## Comportamento Assintótico de Funções

### Função de Complexidade

Na aula anterior, aprendemos a calcular a função de complexidade `f(n)`. Um ponto importante é que, para problemas de tamanho pequeno, a escolha do algoritmo tem pouca influência no desempenho. O foco da análise deve ser em valores grandes de `n`, onde o comportamento assintótico de `f(n)` se torna relevante.

### Crescimento e Dominação Assintótica

A medida de custo, ou complexidade, refere-se ao crescimento assintótico de uma operação específica em relação ao tamanho da entrada. Dizemos que uma função `f(n)` domina assintoticamente outra função `g(n)` se existem constantes positivas `c` e `m` tais que, para `n >= m`, temos |g(n)| <= c|f(n)|.

## Notações Assintóticas

### Notação O (Ordem de Grandeza)

A notação `O` expressa que uma função `g(n)` é dominada assintoticamente por `f(n)`. Formalmente, `g(n)` é `O(f(n))` se existem constantes positivas `c` e `m` tais que `g(n) <= c*f(n)` para todo `n >= m`. Esta notação é usada para expressar o limite superior do crescimento de uma função.

#### Exemplos:

-   `g(n) = (n + 1)²` é `O(n²)` para `m = 1` e `c = 4`, pois `(n + 1)² <= 4n²`.
-   `g(n) = n` é `O(n²)`, mas `f(n) = n²` não é `O(n)`.

### Notação Ω (Ômega)

A notação `Ω` especifica um limite inferior para o crescimento de uma função. Dizemos que `g(n)` é `Ω(f(n))` se existem constantes positivas `c` e `m` tais que, para `n >= m`, temos |g(n)| >= c|f(n)|.

#### Exemplos:

-   `g(n) = 3n³ + 2n²` é `Ω(n³)` com `c = 1` e `m = 0`.

### Notação Θ (Theta)

A notação `Θ` fornece um limite assintótico firme, indicando que a função `g(n)` cresce exatamente na mesma taxa que `f(n)` a menos de constantes multiplicativas. Formalmente, `g(n)` é `Θ(f(n))` se existem constantes positivas `c1`, `c2` e `m` tais que, para `n >= m`, temos `0 <= c1*f(n) <= g(n) <= c2*f(n)`.

#### Exemplos:

-   Para os algoritmos MinMax discutidos na aula anterior, todos possuem a mesma complexidade assintótica, sendo `Θ(n)`.

## Resumo e Conclusão

### Resumo das Notações:

-   **O (Ordem de Grandeza):** Limite superior de crescimento.
-   **Ω (Ômega):** Limite inferior de crescimento.
-   **Θ (Theta):** Limite exato de crescimento.



# Revisão de Conteúdo: Aula 10 - Recursividade

## Introdução à Recursividade

### Definição de Recursividade

A recursividade é uma técnica onde uma função é definida em termos dela mesma. Existem dois tipos principais:

-   **Recursão direta:** Quando a função chama a si própria diretamente.
-   **Recursão indireta:** Quando uma função chama outra função, que eventualmente chama a função original.

### Condição de Parada

Para evitar loops infinitos e definições circulares, toda função recursiva deve ter uma condição de parada. Esta condição garante que, em algum momento, o processo recursivo será interrompido.

### Consumo de Memória

Cada chamada de função, recursiva ou não, empilha os parâmetros e variáveis locais na pilha de execução. Isso cria um **Registro de Ativação** que armazena o ponto de retorno e as variáveis locais. Quando a função termina, o registro é desempilhado, e a execução retorna ao ponto de chamada anterior.

### Exemplo: Fatorial

Dois exemplos de implementação do fatorial foram discutidos:

-   **Fatorial Recursivo:** Tem complexidade de tempo `O(n)` e também complexidade de espaço `O(n)` devido ao uso da pilha de execução.
-   **Fatorial Iterativo:** Tem a mesma complexidade de tempo `O(n)`, mas uma complexidade de espaço `O(1)`.

Conclusão: Nem sempre a recursividade é a melhor solução, mesmo quando o problema é naturalmente definido de forma recursiva. Vale a pena considerar a implementação não-recursiva quando o consumo de espaço é uma preocupação.

## Exemplo Clássico: Série de Fibonacci

### Problema da Recursividade na Fibonacci

A série de Fibonacci é um exemplo clássico de recursividade, mas a implementação ingênua do algoritmo resulta em muita recomputação, tornando-o ineficiente. A solução iterativa ou uma abordagem com **memoização** pode ser mais eficiente.

## Quando Usar Recursividade?

### Casos Ideais para Recursividade

A recursividade é vantajosa em algoritmos complexos, onde a implementação iterativa seria muito complicada e requereria o uso explícito de uma pilha. Exemplos incluem:

-   **Dividir para Conquistar:** Como no Quicksort.
-   **Caminhamento em Árvores:** Pesquisa e backtracking.

## Divisão e Conquista

### Algoritmo Merge Sort

O Merge Sort é um exemplo de algoritmo que usa a estratégia "dividir para conquistar". Ele funciona dividindo uma lista de elementos em sub-listas menores, ordenando-as recursivamente, e depois combinando-as para formar a lista ordenada final.

## Equações de Recorrência

### Definição

Equações de recorrência são usadas para definir a complexidade de algoritmos recursivos. Elas descrevem o tempo de execução de uma função em termos do tempo de execução de instâncias menores do mesmo problema.

### Exemplo: Recorrência do Fatorial

A complexidade de tempo do algoritmo recursivo para o cálculo do fatorial pode ser descrita por uma equação de recorrência simples, que reflete a natureza linear do crescimento do tempo de execução em função do tamanho da entrada.

## Exercícios Propostos

1.  **Analisar Função Recursiva:** Determinar a complexidade de funções recursivas apresentadas.
2.  **Comparar Recursão e Iteração:** Avaliar as vantagens e desvantagens de soluções recursivas versus iterativas para determinados problemas.

### Método da Substituição em Análise Assintótica: Explicação Detalhada

O método da substituição é uma técnica fundamental na análise assintótica de algoritmos, utilizada principalmente para resolver recorrências que definem o tempo de execução de algoritmos recursivos. A análise assintótica permite determinar o comportamento de um algoritmo à medida que o tamanho da entrada aumenta, ajudando a prever o seu desempenho para grandes valores de `n`.

### Etapas do Método da Substituição

O método da substituição pode ser descrito em três etapas principais:

1.  **Proposição (Chute) da Forma da Solução:**
    
    -   A primeira etapa do método da substituição envolve propor uma forma geral para a solução da recorrência. Esta proposta é baseada na experiência com problemas similares ou na observação de padrões. Por exemplo, se temos uma recorrência como T(n)=2T(n2)+nT(n) = 2T\left(\frac{n}{2}\right) + nT(n)=2T(2n​)+n, podemos propor que a solução seja da forma T(n)=O(nlog⁡n)T(n) = O(n \log n)T(n)=O(nlogn), já que essa é uma solução comum para recorrências desse tipo.
2.  **Prova por Indução:**
    
    -   Após propor uma solução, a próxima etapa é provar que essa forma está correta usando **indução matemática**. A prova por indução segue dois passos:
        -   **Caso Base:** Verificar que a solução proposta satisfaz a recorrência para um valor pequeno de `n`, geralmente `n = 1`.
        -   **Passo Indutivo:** Suponha que a solução proposta seja válida para um valor arbitrário `k`, ou seja, T(k)≤c⋅g(k)T(k) \leq c \cdot g(k)T(k)≤c⋅g(k) para uma constante ccc. A partir dessa suposição, deve-se mostrar que a solução também é válida para n=k+1n = k + 1n=k+1 (ou, de modo equivalente, para `n` em termos da função original da recorrência).
3.  **Ajuste de Constantes e Cotas:**
    
    -   Por fim, é necessário ajustar as constantes e verificar as cotas superiores e inferiores. Esse passo garante que a função que propusemos realmente limita a recorrência tanto por cima quanto por baixo. Isso é feito manipulando a recorrência até que a solução proposta se encaixe dentro dos limites desejados.

### Exemplo Prático: Análise de uma Recorrência

Vamos aplicar o método da substituição a uma recorrência simples para ilustrar o processo.

**Recorrência:** T(n)=2T(n2)+nT(n) = 2T\left(\frac{n}{2}\right) + nT(n)=2T(2n​)+n Esta recorrência surge frequentemente em algoritmos de "dividir e conquistar", como o **Merge Sort**.

**Passo 1: Proposição da Solução**

-   Proponha que a solução é T(n)=O(nlog⁡n)T(n) = O(n \log n)T(n)=O(nlogn).

**Passo 2: Prova por Indução**

-   **Caso Base:** Para n=1n = 1n=1, temos:
    
    T(1)=2T(12)+1=1T(1) = 2T\left(\frac{1}{2}\right) + 1 = 1T(1)=2T(21​)+1=1
    
    A solução proposta T(n)=O(nlog⁡n)T(n) = O(n \log n)T(n)=O(nlogn) se mantém, já que O(1⋅log⁡1)=O(0)O(1 \cdot \log 1) = O(0)O(1⋅log1)=O(0), que é constante.
    
-   **Passo Indutivo:** Suponha que T(k)≤c⋅klog⁡kT(k) \leq c \cdot k \log kT(k)≤c⋅klogk seja verdadeiro para algum kkk. Precisamos mostrar que:
    
    T(2k)≤c⋅2klog⁡(2k)T(2k) \leq c \cdot 2k \log (2k)T(2k)≤c⋅2klog(2k)
    
    Usando a recorrência:
    
    T(2k)=2T(k)+2kT(2k) = 2T(k) + 2kT(2k)=2T(k)+2k
    
    Substituindo a hipótese indutiva:
    
    T(2k)≤2(c⋅klog⁡k)+2kT(2k) \leq 2(c \cdot k \log k) + 2kT(2k)≤2(c⋅klogk)+2k
    
    Simplificando:
    
    T(2k)≤2cklog⁡k+2k=2k(clog⁡k+1)T(2k) \leq 2ck \log k + 2k = 2k(c \log k + 1)T(2k)≤2cklogk+2k=2k(clogk+1)
    
    Como log⁡(2k)=log⁡2+log⁡k\log(2k) = \log 2 + \log klog(2k)=log2+logk, temos:
    
    T(2k)≤2k⋅(c(log⁡2+log⁡k))=2k⋅clog⁡(2k)T(2k) \leq 2k \cdot (c(\log 2 + \log k)) = 2k \cdot c \log(2k)T(2k)≤2k⋅(c(log2+logk))=2k⋅clog(2k)
    
    Então, a solução proposta é válida, com a constante ccc ajustada apropriadamente.
    

**Passo 3: Ajuste de Constantes e Verificação**

-   Ao final, ajusta-se a constante ccc para garantir que a desigualdade proposta se mantém em todas as condições do problema, o que conclui a prova de que T(n)=O(nlog⁡n)T(n) = O(n \log n)T(n)=O(nlogn) é a solução correta para a recorrência dada.

### Considerações Finais

O método da substituição é poderoso, mas exige prática para ser aplicado corretamente. É importante escolher bem a forma da solução e realizar a prova indutiva com cuidado. Além disso, sempre verificar se as constantes escolhidas são adequadas e se a solução proposta realmente satisfaz todas as condições da recorrência.

Esse método é uma ferramenta essencial na análise de algoritmos, especialmente em problemas que envolvem algoritmos recursivos e soluções de "dividir e conquistar". Quando aplicado corretamente, ele fornece insights valiosos sobre o comportamento de um algoritmo à medida que o tamanho do problema cresce.



### Método do Teorema Mestre: Explicação Passo a Passo

O **Teorema Mestre** é uma ferramenta prática e poderosa para resolver recorrências que surgem frequentemente na análise de algoritmos recursivos, especialmente aqueles que seguem a estratégia de "dividir e conquistar". Ele fornece uma maneira rápida de determinar a complexidade assintótica de algoritmos, sem a necessidade de calcular a solução exata das recorrências.

### Forma Geral da Recorrência

O Teorema Mestre aplica-se a recorrências da seguinte forma: T(n)=aT(nb)+f(n)T(n) = aT\left(\frac{n}{b}\right) + f(n)T(n)=aT(bn​)+f(n) Onde:

-   nnn é o tamanho do problema.
-   aaa é o número de subproblemas gerados pela divisão.
-   Cada subproblema tem tamanho nb\frac{n}{b}bn​.
-   f(n)f(n)f(n) é o custo da combinação das soluções dos subproblemas.

### Passo a Passo para Aplicar o Teorema Mestre

1.  **Identificar os Parâmetros da Recorrência:**
    
    -   Primeiro, identifique os valores de aaa, bbb, e a função f(n)f(n)f(n) na recorrência que você está tentando resolver.
2.  **Calcular a Dimensão Crítica nlog⁡ban^{\log_b a}nlogb​a:**
    
    -   Calcule log⁡ba\log_b alogb​a. Isso é feito calculando o logaritmo de aaa na base bbb.
3.  **Comparar f(n)f(n)f(n) com nlog⁡ban^{\log_b a}nlogb​a:**
    
    -   Determine como a função f(n)f(n)f(n) se compara com nlog⁡ban^{\log_b a}nlogb​a. Dependendo dessa comparação, o problema se enquadra em um dos três casos do Teorema Mestre.

### Os Três Casos do Teorema Mestre

O comportamento da função f(n)f(n)f(n) em relação a nlog⁡ban^{\log_b a}nlogb​a determina qual caso do Teorema Mestre deve ser aplicado:

#### **Caso 1: f(n)=O(nlog⁡ba−ϵ)f(n) = O(n^{\log_b a - \epsilon})f(n)=O(nlogb​a−ϵ) para algum ϵ>0\epsilon > 0ϵ>0**

-   **Condição:** O custo da combinação f(n)f(n)f(n) é assintoticamente menor que o custo de dividir e resolver os subproblemas.
-   **Interpretação:** A maior parte do trabalho está sendo feita na fase de divisão e resolução dos subproblemas.
-   **Complexidade:** T(n)=Θ(nlog⁡ba)T(n) = \Theta(n^{\log_b a})T(n)=Θ(nlogb​a) Isso significa que a complexidade é dominada pelo termo relacionado ao número de subproblemas e seu tamanho.

**Exemplo:**

-   Recorrência: T(n)=2T(n2)+nT(n) = 2T\left(\frac{n}{2}\right) + nT(n)=2T(2n​)+n
-   Aqui, a=2a = 2a=2, b=2b = 2b=2, então nlog⁡ba=nlog⁡22=nn^{\log_b a} = n^{\log_2 2} = nnlogb​a=nlog2​2=n.
-   f(n)=nf(n) = nf(n)=n, que é O(n1−ϵ)O(n^{1 - \epsilon})O(n1−ϵ) para ϵ=0\epsilon = 0ϵ=0.
-   Resultado: T(n)=Θ(nlog⁡n)T(n) = \Theta(n \log n)T(n)=Θ(nlogn).

#### **Caso 2: f(n)=Θ(nlog⁡ba)f(n) = \Theta(n^{\log_b a})f(n)=Θ(nlogb​a)**

-   **Condição:** O custo da combinação f(n)f(n)f(n) cresce na mesma proporção que o custo da divisão e solução dos subproblemas.
-   **Interpretação:** O trabalho está distribuído uniformemente entre a divisão, resolução dos subproblemas e a combinação.
-   **Complexidade:** T(n)=Θ(nlog⁡balog⁡n)T(n) = \Theta(n^{\log_b a} \log n)T(n)=Θ(nlogb​alogn) Aqui, a complexidade é aumentada por um fator logarítmico devido à combinação.

**Exemplo:**

-   Recorrência: T(n)=2T(n2)+nlog⁡nT(n) = 2T\left(\frac{n}{2}\right) + n\log nT(n)=2T(2n​)+nlogn
-   Aqui, a=2a = 2a=2, b=2b = 2b=2, então nlog⁡ba=nn^{\log_b a} = nnlogb​a=n.
-   f(n)=nlog⁡nf(n) = n\log nf(n)=nlogn, que é Θ(nlog⁡n)\Theta(n \log n)Θ(nlogn).
-   Resultado: T(n)=Θ(nlog⁡2n)T(n) = \Theta(n \log^2 n)T(n)=Θ(nlog2n).

#### **Caso 3: f(n)=Ω(nlog⁡ba+ϵ)f(n) = \Omega(n^{\log_b a + \epsilon})f(n)=Ω(nlogb​a+ϵ) para algum ϵ>0\epsilon > 0ϵ>0** e a condição regularidade af(nb)≤cf(n)a f\left(\frac{n}{b}\right) \leq c f(n)af(bn​)≤cf(n) para alguma constante c<1c < 1c<1 e suficientemente grande nnn.

-   **Condição:** O custo da combinação f(n)f(n)f(n) é assintoticamente maior que o custo da divisão e resolução dos subproblemas.
-   **Interpretação:** A maior parte do trabalho está sendo feita na fase de combinação dos resultados.
-   **Complexidade:** T(n)=Θ(f(n))T(n) = \Theta(f(n))T(n)=Θ(f(n)) Isso significa que a complexidade é dominada pelo custo da combinação f(n)f(n)f(n).

**Exemplo:**

-   Recorrência: T(n)=T(n2)+n2T(n) = T\left(\frac{n}{2}\right) + n^2T(n)=T(2n​)+n2
-   Aqui, a=1a = 1a=1, b=2b = 2b=2, então nlog⁡ba=n0=1n^{\log_b a} = n^0 = 1nlogb​a=n0=1.
-   f(n)=n2f(n) = n^2f(n)=n2, que é Ω(nlog⁡ba+ϵ)=Ω(n2)\Omega(n^{\log_b a + \epsilon}) = \Omega(n^2)Ω(nlogb​a+ϵ)=Ω(n2).
-   Resultado: T(n)=Θ(n2)T(n) = \Theta(n^2)T(n)=Θ(n2).

### Resumo dos Casos

-   **Caso 1:** f(n)f(n)f(n) cresce mais lentamente que nlog⁡ban^{\log_b a}nlogb​a → A complexidade é dominada pelo número de subproblemas: T(n)=Θ(nlog⁡ba)T(n) = \Theta(n^{\log_b a})T(n)=Θ(nlogb​a).
-   **Caso 2:** f(n)f(n)f(n) cresce na mesma proporção que nlog⁡ban^{\log_b a}nlogb​a → A complexidade inclui um fator logarítmico: T(n)=Θ(nlog⁡balog⁡n)T(n) = \Theta(n^{\log_b a} \log n)T(n)=Θ(nlogb​alogn).
-   **Caso 3:** f(n)f(n)f(n) cresce mais rapidamente que nlog⁡ban^{\log_b a}nlogb​a → A complexidade é dominada pela função f(n)f(n)f(n): T(n)=Θ(f(n))T(n) = \Theta(f(n))T(n)=Θ(f(n)).

### Considerações Finais

O Teorema Mestre simplifica significativamente a análise de recorrências comuns em algoritmos, oferecendo um método direto para determinar a complexidade assintótica sem a necessidade de uma análise detalhada por substituição ou outras técnicas. No entanto, é importante verificar se a recorrência está na forma correta para aplicar o teorema e identificar corretamente os parâmetros aaa, bbb, e f(n)f(n)f(n).
