## Exercício 5 (Livros)

**Cenário**\
Uma biblioteca precisa armazenar e recuperar rapidamente informações sobre seus livros.\
Cada livro possui um **ISBN (inteiro de 13 dígitos)** como chave e um
**título (string)** como valor.

Seu trabalho é implementar uma **tabela hash** para gerenciar esse
acervo.

### Requisitos

-   Chave: ISBN (long long).
-   Valor: título do livro (string).
-   Tamanho: M = 23 (primo).
-   Hash: `isbn % M`.
-   Colisões: encadeamento separado.

