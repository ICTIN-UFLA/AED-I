
# 📘 Lista de Exercícios Parte 2 

---

## 📚 Parte 1: Pilha (Estática e Dinâmica)

### Exercício 1 – Verificador de Parênteses

### 📄 Contexto:
Você foi contratado por uma empresa que desenvolve editores de texto. Um dos recursos solicitados é a verificação automática de parênteses balanceados em expressões matemáticas.

### 🎯 Objetivo:
Implemente um programa em C que utilize uma **pilha estática** para verificar se os parênteses estão corretamente balanceados.

### 🛠️ Funcionalidades:
- Ler uma expressão do usuário;
- Verificar se cada abertura `(` possui um fechamento correspondente `)` na ordem correta;
- Informar se a expressão está ou não balanceada.

### 💻 Exemplo:
```
Entrada: ((a + b) * (c - d))
Saída: Parênteses balanceados.
```

---

**Menu sugerido:**
```
--- Verificador de Parênteses ---
1. Inserir expressão
2. Verificar se está balanceada
0. Sair
```

### Exercício 2 – Navegador Web: Voltar Página

### 🌐 Contexto:
Você está desenvolvendo um navegador web e precisa implementar o recurso "voltar", que deve levar o usuário para a página anterior à atual.

### 🎯 Objetivo:
Utilize uma **pilha dinâmica** para armazenar o histórico de páginas visitadas. Quando o usuário clicar em “voltar”, a última página deve ser removida da pilha.

### 🛠️ Funcionalidades:
- Adicionar páginas visitadas à pilha;
- Remover a página atual ao voltar;
- Mostrar a página atual após voltar.

### 💻 Exemplo:
```
Visitou: Google → UFLA → GitHub
Voltar → Página atual: UFLA
```

---

**Menu sugerido:**
```
--- Navegador Web ---
1. Visitar nova página
2. Voltar página
3. Mostrar página atual
0. Sair
```

## 🚦 Parte 2: Fila (Estática e Dinâmica)

### Exercício 3 – Atendimento em Clínica



### 🩺 Contexto:
A clínica do Dr. João está enfrentando dificuldades para organizar o fluxo de pacientes. Com o aumento da demanda, ele precisa de um sistema simples que gerencie a ordem de atendimento de forma justa, seguindo o princípio **"primeiro a chegar, primeiro a ser atendido" (FIFO)**.

---

### 🎯 Objetivo:
Implemente uma **fila estática** (estrutura de dados com tamanho fixo) para simular o controle de pacientes.

---

### 🛠️ Funcionalidades esperadas:
- **Inserção**: Adicione pacientes à fila conforme eles chegam à clínica (no final da fila).
- **Remoção**: Atenda (remova) sempre o próximo paciente da fila (o primeiro da fila).
- **Visualização**: Mostre o estado atual da fila (quem está aguardando).

---

### 📋 Regras:
- A fila deve ter **capacidade limitada** (ex.: 10 pacientes).
- Trate casos de **fila cheia** (não é possível adicionar mais pacientes) e **fila vazia** (não há pacientes para atender).

---

### 💻 Exemplo de Funcionamento:
Chega "Maria" → Fila: [Maria]

Chega "José" → Fila: [Maria, José]

Atender → Remove "Maria" → Fila: [José]
---

### 🎁 Desafio:
- Permita que o usuário **interaja com o sistema** através de um menu (ex.: 1 - Adicionar paciente, 2 - Atender paciente, 3 - Mostrar fila, 0 - Sair).
- Mostre mensagens claras, como:
  - `"Paciente Carlos atendido!"`
  - `"Fila cheia! Aguarde liberação."`
  - `"Nenhum paciente para atender."`

---

### 🧠 Dica:
Utilize um vetor de strings (ou vetor de structs com nomes) para armazenar os pacientes. Utilize variáveis para controlar o `início`, `fim` e `tamanho` da fila, respeitando a lógica de fila circular, se desejar implementar com mais eficiência.

"""

**Menu sugerido:**
```
--- Sistema de Atendimento ---
1. Adicionar paciente à fila
2. Atender paciente
3. Mostrar fila de espera
0. Sair
```

### Exercício 4 – Impressora Compartilhada

### 🖨️ Contexto:
Em um laboratório de informática, vários usuários compartilham uma única impressora. Os arquivos devem ser impressos na ordem em que foram enviados.

### 🎯 Objetivo:
Utilize uma **fila dinâmica** para simular o controle de impressão.

### 🛠️ Funcionalidades:
- Inserir documentos na fila (nome do arquivo);
- Imprimir (remover o primeiro da fila);
- Mostrar quais arquivos ainda aguardam impressão.

### 💻 Exemplo:
```
Enviar: trabalho.pdf, relatorio.docx
Imprimir → trabalho.pdf
Fila: [relatorio.docx]
```

---

**Menu sugerido:**
```
--- Gerenciador de Impressão ---
1. Enviar documento para impressão
2. Imprimir próximo documento
3. Mostrar fila de impressão
0. Sair
```

## 🌀 Parte 3: Deque Dinâmico

### Exercício 5 – Editor com Desfazer/Refazer

### 📝 Contexto:
Você está desenvolvendo um editor de texto com suporte às operações "Desfazer" e "Refazer".

### 🎯 Objetivo:
Implemente um **deque dinâmico** para controlar as ações do usuário.

### 🛠️ Funcionalidades:
- Inserir ações no final do deque;
- Remover do final para desfazer;
- Inserir novamente no início ao refazer.

### 💻 Exemplo:
```
Ações: escreve "A", escreve "B", desfaz, refaz
Texto atual: AB
```

---

**Menu sugerido:**
```
--- Editor de Texto ---
1. Digitar texto
2. Desfazer
3. Refazer
4. Mostrar texto atual
0. Sair
```

### Exercício 6 – Controle de Trânsito Bidirecional

### 🚗 Contexto:
Você está desenvolvendo um simulador de tráfego para uma rua de mão dupla onde veículos podem entrar e sair por ambas as extremidades.

### 🎯 Objetivo:
Use um **deque dinâmico** para simular a entrada e saída de veículos.

### 🛠️ Funcionalidades:
- Inserir veículos pela frente ou fundo;
- Remover veículos pela frente ou fundo;
- Mostrar o estado atual da via.

### 💻 Exemplo:
```
Entra frente: carro 1  
Entra fundo: carro 2  
Sai frente  
Via: [carro 2]
```

---

**Menu sugerido:**
```
--- Controle de Trânsito ---
1. Entrar veículo pela frente
2. Entrar veículo pelo fundo
3. Sair veículo pela frente
4. Sair veículo pelo fundo
5. Mostrar via
0. Sair
```

## 🧱 Parte 4: Duas Pilhas Estáticas

### Exercício 7 – Gerenciador de Recursos

### 🧃 Contexto:
Um sistema precisa manter controle de recursos utilizados e disponíveis.

### 🎯 Objetivo:
Implemente duas pilhas dentro de um mesmo vetor (estrutura estática): uma para recursos disponíveis e outra para os utilizados.

### 🛠️ Funcionalidades:
- Inserir recursos na pilha de disponíveis;
- Mover recurso para a pilha de usados;
- Mostrar o topo das duas pilhas.

### 💻 Exemplo:
```
Adicionar recurso 1  
Usar recurso 1 → mover para pilha de usados  
Estado: disponíveis=[], usados=[1]
```

---

**Menu sugerido:**
```
--- Gerenciador de Recursos ---
1. Adicionar recurso disponível
2. Usar recurso
3. Mostrar recursos disponíveis
4. Mostrar recursos usados
0. Sair
```

### Exercício 8 – Calculadora com Pilhas

### 🔢 Contexto:
Você deve desenvolver uma calculadora que armazena operandos e operadores separadamente para processar expressões de forma reversa.

### 🎯 Objetivo:
Utilize **duas pilhas em vetor estático**: uma para operandos e outra para operadores.

### 🛠️ Funcionalidades:
- Adicionar operandos e operadores;
- Processar expressão ao final;
- Mostrar resultado.

### 💻 Exemplo:
```
Entradas: 4, 5, +
Resultado: 9
```

---

**Menu sugerido:**
```
--- Calculadora com Pilhas ---
1. Inserir operando
2. Inserir operador
3. Calcular resultado
4. Mostrar pilhas
0. Sair
```

## 🧮 Parte 5: Matrizes Estáticas e Dinâmicas

### Exercício 9 – Reservas de Assentos

### 🎟️ Contexto:
Você precisa criar um sistema para controlar os assentos de um teatro com 10 fileiras e 10 colunas.

### 🎯 Objetivo:
Implemente uma **matriz estática** para registrar reservas e mostrar os assentos ocupados.

### 🛠️ Funcionalidades:
- Reservar assento [i][j];
- Mostrar assentos ocupados.

### 💻 Exemplo:
```
Reservar assento [2][3]
Resultado: Assento reservado!
```

---

**Menu sugerido:**
```
--- Reserva de Assentos ---
1. Reservar assento
2. Cancelar reserva
3. Mostrar mapa de assentos
0. Sair
```

### Exercício 10 – Planilha com Tamanho Variável

### 📊 Contexto:
Você precisa de uma planilha que possa crescer de acordo com os dados fornecidos pelo usuário.

### 🎯 Objetivo:
Utilize **matriz dinâmica** alocada com `malloc` para criar uma planilha de tamanho definido em tempo de execução.

### 🛠️ Funcionalidades:
- Permitir ao usuário definir o número de linhas e colunas;
- Inserir e exibir os dados.

### 💻 Exemplo:
```
Linhas: 2 | Colunas: 3
Dados: 1 2 3 | 4 5 6
Saída:
1 2 3
4 5 6
```

**Menu sugerido:**
```
--- Planilha Dinâmica ---
1. Criar nova planilha
2. Preencher planilha
3. Mostrar planilha
0. Sair
```


## Exemplo de MENU em C 

### Exercício 3 – Atendimento em Clínica, utilizando switch e laço while para interação contínua com o usuário

```c
int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    do {
        printf("\n--- Sistema de Atendimento ---\n");
        printf("1. Adicionar paciente\n");
        printf("2. Atender paciente\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarPaciente(&fila);
                break;
            case 2:
                atenderPaciente(&fila);
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
```
