
  

#  Exercício Vetor e Matriz
## Pontos 5
**Data de Entrega: 21/04/2024**

## Contexto

Você foi contratado por uma biblioteca para criar um sistema simples de gerenciamento de empréstimos de livros. O sistema precisa manter um registro de livros e usuários, bem como permitir empréstimos e devoluções.

## Objetivos

Desenvolva um programa em C que utiliza vetores e matrizes para gerenciar os empréstimos de livros na biblioteca. O programa deve oferecer um menu com opções para o usuário realizar diferentes operações.

## Requisitos do Sistema

1.  **Dados dos Livros e Usuários**:
    
    -   Crie um vetor para armazenar o nome dos livros disponíveis na biblioteca.
    -   Crie outro vetor para armazenar os nomes dos usuários.
2.  **Registro de Empréstimos**:
    
    -   Use uma matriz para registrar os empréstimos. Cada linha representa um usuário e cada coluna um livro.
    -   Se um usuário (linha) tem um livro (coluna) emprestado, essa célula na matriz deve conter `1`, caso contrário `0`.
3.  **Menu de Opções**:
    
    -   Implemente um menu que ofereça as seguintes opções ao usuário:
        -   `1` para listar todos os livros.
        -   `2` para listar todos os usuários.
        -   `3` para realizar um empréstimo.
        -   `4` para realizar uma devolução.
        -   `5` para verificar o status de um livro (emprestado ou disponível).
        -   `6` para sair do programa.
4.  **Realizando Empréstimos e Devoluções**:
    
    -   Ao escolher realizar um empréstimo, o programa deve pedir ao usuário o nome do usuário e o livro que deseja emprestar.
    -   Verifique se o livro está disponível. Se estiver, atualize a matriz de empréstimos e informe que o empréstimo foi bem-sucedido.
    -   Para devoluções, o processo é similar, mas a célula correspondente na matriz deve ser mudada para `0`.
5.  **Verificação de Status**:
    
    -   Ao escolher verificar o status de um livro, o programa deve informar se o livro está emprestado e, se sim, a quem.

# Critérios de avaliação 

A atividade será avaliada com base nos seguintes critérios, totalizando 4.5 pontos:

### 1. Funcionalidade e Correção do Código (2,5 pontos)

-   **1.5 ponto**: O programa implementa todas as funcionalidades descritas nos requisitos (menus, registro de empréstimos, verificação de status, etc.).
-   **1.0 ponto**: O programa executa corretamente sem erros ou falhas. Operações de empréstimo e devolução são executadas conforme esperado e os dados são manipulados e armazenados corretamente.

### 2. Uso Eficiente de Vetores e Matrizes (1 ponto)

-   **0.5 ponto**: Vetores são usados de forma eficaz para armazenar informações sobre livros e usuários.
-   **0.5 ponto**: Matrizes são utilizadas corretamente para gerenciar o estado dos empréstimos (disponibilidade dos livros).

### 3. Qualidade do Código e Estrutura (1 ponto)

-   **1 ponto**: O código é bem organizado, seguindo boas práticas de programação, como nomes de variáveis claros.

### 4. Interatividade e Facilidade de Uso (0.5 ponto)

-   **0.5 ponto**: O menu é claro e fácil de usar, com instruções claras para o usuário sobre como realizar cada operação. Seguindo o padrão solicitado na atividade. 

### Observações Finais

-   A soma total desses critérios resultará na pontuação final da atividade, sendo 5 pontos a nota máxima.
-   A atividade deve ser concluída individualmente e refletir o trabalho independente do aluno. Um aluno pode ajudar o outro, mas sem copiar. 
-   Qualquer plágio ou cópia resultará em zero pontos.

## Considerações 
Este projeto vai ajudá-lo a entender como vetores e matrizes podem ser usados em aplicações do mundo real, além de praticar a construção de um sistema interativo em C. Use seu conhecimento em estruturas de controle e entrada/saída para tornar o programa fácil de usar e eficiente. Boa sorte!
