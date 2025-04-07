
# 📘 Lista de Exercícios – Estruturas de Listas em C

Cada exercício a seguir foi cuidadosamente elaborado para reforçar os conceitos das diferentes variações de listas ligadas estudadas. As explicações a seguir justificam a escolha da estrutura de dados utilizada em cada situação.

---

## 🧱 Parte 1: Lista Ligada (Estática e Dinâmica)

### Exercício 1 – Cadastro de Pacientes
**Contexto**: Uma clínica médica precisa organizar os nomes dos pacientes na ordem em que eles chegam para a consulta.

**Solicitação**: Implemente um programa em C que utilize uma **lista ligada dinâmica** para registrar os nomes (apenas um número de identificação, como `int id`) e imprimi-los na ordem de chegada. Permita inserção no final da lista.

**Por que usar lista dinâmica?**
A lista dinâmica permite que novos pacientes sejam adicionados sem precisar saber antecipadamente a quantidade total. Isso oferece flexibilidade de memória e é ideal para cenários com crescimento indefinido.

**Por que não lista estática?**
A lista estática possui tamanho fixo e pode limitar a quantidade de pacientes, além de exigir mais cuidado na manipulação de índices.

---

### Exercício 2 – Controle de Estoque de Produtos
**Contexto**: Uma pequena loja deseja controlar os produtos em estoque utilizando uma lista.

**Solicitação**: Implemente uma **lista estática**, com funções de inserção no início e impressão da lista.

**Por que usar lista estática?**
Como o número de produtos da loja tende a ser pequeno e controlado, a lista estática é simples, rápida e eficiente em termos de acesso. Ideal quando a memória é suficiente e o número de elementos é previsível.

**Por que não lista dinâmica?**
A dinâmica adicionaria complexidade desnecessária, como alocação e liberação de memória, para um problema simples com tamanho previsível.

---

## 🔷 Parte 2: Lista Ligada com Nó Cabeça

### Exercício 3 – Controle de Tarefas
**Contexto**: Gerenciamento de tarefas com inserções frequentes no início e remoções específicas.

**Solicitação**: Implemente uma **lista com nó cabeça**, com inserção no início e remoção de elementos.

**Por que usar nó cabeça?**
Facilita inserções e remoções uniformes, inclusive no início da lista, sem precisar tratar o primeiro elemento como caso especial. Ideal quando as operações de manipulação são frequentes e devem ser padronizadas.

**Por que não lista sem nó cabeça?**
Sem o nó cabeça, o código teria que verificar se o nó a ser manipulado é o primeiro da lista a cada operação, o que aumenta a complexidade.

---

### Exercício 4 – Sistema de Registro de Temperaturas
**Contexto**: Coleta de dados de sensores de temperatura a cada hora.

**Solicitação**: Utilize uma **lista com nó cabeça** para armazenar valores inseridos no início e permitir remoções.

**Por que usar nó cabeça?**
A coleta de dados exige inserções frequentes e a lista pode começar vazia. O nó cabeça garante que a lista nunca seja `NULL`, simplificando o código de inserção e remoção.

**Por que não usar lista circular ou estática?**
Circular não é necessária porque não há necessidade de voltar ao início após o fim. Estática limitaria a quantidade de registros e complicaria a manutenção.

---

## 🔁 Parte 3: Lista Circular com Nó Cabeça

### Exercício 5 – Sistema de Jogadores em um Jogo Circular
**Contexto**: Um jogo em que os jogadores se revezam em ciclos.

**Solicitação**: Implemente com **lista circular com nó cabeça**, inserindo no final e imprimindo a ordem.

**Por que usar lista circular?**
A natureza do jogo é cíclica – após o último jogador, volta-se ao primeiro. A lista circular permite essa navegação contínua de forma natural e eficiente.

**Por que não usar lista linear?**
A lista linear exigiria lógica extra para "voltar ao início", enquanto a circular já fornece isso automaticamente.

---

### Exercício 6 – Gerenciamento de Músicas em um Player
**Contexto**: Player musical que deve passar pela lista de músicas continuamente.

**Solicitação**: Use uma **lista circular com nó cabeça** para armazenar e manipular as faixas.

**Por que usar lista circular?**
Permite que o reprodutor continue automaticamente do fim para o início, simulando uma playlist infinita, comum em players de música.

**Por que não usar lista linear?**
Não se adapta bem à navegação contínua entre elementos, exigindo verificações extras para reiniciar o ciclo.
