
  

### Leitura de Arquivo .txt em C


### Passo a Passo

  

#### Passo 1: Criar um Arquivo .txt de Exemplo

  

Crie um arquivo chamado `exemplo.txt` com o seguinte conteúdo:

```

Este e um exemplo de arquivo de texto
Cada linha contem apenas texto ou numeros
1234567890

```

#### Passo 2: Configurar o Ambiente de Desenvolvimento

  

1. Certifique-se de ter um compilador C instalado (por exemplo, GCC).

2. Abra seu editor de texto ou IDE de preferência (por exemplo, Visual Studio Code, Code::Blocks).

  

#### Passo 3: Escrever o Código em C


Crie um novo arquivo C chamado `leituraArquivo.c` e adicione o seguinte código:

 
```c

#include  <stdio.h>
#include  <stdlib.h>

  
int  main() {

	FILE *arquivo;
	char  linha[256];

	// Abertura do arquivo em modo leitura
	arquivo = fopen("exemplo.txt", "r");

	// Verificação se o arquivo foi aberto com sucesso
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	return  1; // Encerra o programa com erro
	}

	// Leitura e exibição do conteúdo do arquivo linha por linha
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		printf("%s", linha);
	}

	// Depois que termina tudo, temos que fechar o arquivo
	fclose(arquivo);
	return  0; // Encerra o programa com sucesso

}

```

  

#### Passo 4: Compilar o Programa

  

Abra o terminal ou prompt de comando (no VSCODE, por exemplo), navegue até o diretório onde o arquivo `leituraArquivo.c` está localizado e execute o comando:

 
```bash
gcc  leitura_arquivo.c  -o  leitura_arquivo
```
Este comando compilará o código-fonte e gerará um executável chamado `leituraArquivo`.

#### Passo 5: Executar o Programa

No terminal ou prompt de comando, execute o programa gerado:

```bash

./leituraArquivo
```

  

Você deverá ver a saída contendo o conteúdo do arquivo `exemplo.txt`:


```
Este e um exemplo de arquivo de texto
Cada linha contem apenas texto ou numeros
1234567890
```

  

### Explicação do Código

1.  **Inclusão de Bibliotecas**:

```c

#include <stdio.h>
#include <stdlib.h>

```

-  `stdio.h`: Biblioteca padrão de entrada e saída.

-  `stdlib.h`: Biblioteca padrão para funções de utilidade geral.

  

2.  **Declaração de Variáveis**:

```c

FILE *arquivo;

char  linha[256];

```

-  `FILE *arquivo`: Ponteiro para o arquivo.

-  `char linha[256]`: Buffer para armazenar cada linha lida do arquivo.

  

3.  **O que é `char linha[256];`?**

-  `char linha[256];` declara uma variável chamada `linha` que é um array de caracteres (string) com capacidade para armazenar até 256 caracteres.

- Isso significa que cada vez que uma linha do arquivo é lida, ela é armazenada nesse array antes de ser exibida.

- O valor `256` foi escolhido arbitrariamente para ser suficientemente grande para conter qualquer linha do arquivo de exemplo. Em um programa real, você pode ajustar esse valor conforme necessário ou usar uma abordagem dinâmica.

  

4.  **Abertura do Arquivo**:

```c

arquivo = fopen("exemplo.txt", "r");

```

-  `fopen`: Função para abrir o arquivo.

-  `"exemplo.txt"`: Nome do arquivo a ser aberto.

-  `"r"`: Modo de abertura (leitura).

  

5.  **Verificação de Erro na Abertura do Arquivo**:

```c

if (arquivo == NULL) {

printf("Erro ao abrir o arquivo!\n");

return  1;

}

```

- Verifica se o arquivo foi aberto com sucesso.

- Exibe uma mensagem de erro e encerra o programa caso não tenha sido possível abrir o arquivo.

  

6.  **Leitura e Exibição do Conteúdo do Arquivo**:

```c

while (fgets(linha, sizeof(linha), arquivo) != NULL) {

printf("%s", linha);

}

```

-  `fgets`: Função para ler uma linha do arquivo.

-  `sizeof(linha)`: Tamanho do buffer de linha.

-  `printf`: Função para exibir a linha lida.

  

7.  **Fechamento do Arquivo**:

```c

fclose(arquivo);

```

-  `fclose`: Função para fechar o arquivo.

  

### Exercício 

  
1. Modifique o programa para contar o número de linhas no arquivo.
3. Modifique o programa para ler e exibir apenas as linhas que contêm uma palavra específica fornecida pelo usuário.

 
