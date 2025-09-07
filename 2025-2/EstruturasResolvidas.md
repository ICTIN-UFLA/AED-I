# 📘 Estruturas de Dados em C – Exercícios Resolvidos

  

Este material contém **8 questões práticas** resolvidas em C, com explicação didática, enunciado contextualizado, passo a passo e código comentado.

---

## ✅ Questão 1 – Vetor: Controle de Temperaturas

  

### 📖 Explicação didática

Uma **lista sequencial simples** de dados armazenados em um **vetor (array)**.

Usamos índices para acessar cada posição. Aplicações comuns: dados diários,

leituras de sensores, tabelas simples.

  

### 📝 Enunciado

Um meteorologista deseja analisar as **temperaturas máximas** registradas em uma semana de 7 dias.

  

Ele precisa calcular:

1. A média semanal das temperaturas.

2. O maior valor e o dia correspondente.

3. O menor valor e o dia correspondente.

  

### 🔎 Passo a passo

1. Declarar um vetor `temp[7]`.

2. Percorrer com laço para somar e encontrar maior/menor valor.

3. Imprimir os resultados.

  

### 💻 Código em C

  

```c

#include  <stdio.h>

int  main(void) {
int  temp[7] = {22, 25, 20, 26, 24, 23, 27};
int soma = 0, imax = 0, imin = 0;

for (int i = 0; i < 7; ++i) {
soma += temp[i];
if (temp[i] > temp[imax]) imax = i;
if (temp[i] < temp[imin]) imin = i;
}

double media = soma / 7.0;

printf("Temperaturas: ");

for (int i = 0; i < 7; ++i) printf("%d ", temp[i]);
printf("\nMedia = %.2f\nMaior = %d (dia %d)\nMenor = %d (dia %d)\n",
media, temp[imax], imax+1, temp[imin], imin+1);
return  0;
}

```

---



## ✅ Questão 2 – Matriz: Produção em Fábrica

  

### 📖 Explicação didática

Uma **matriz** é um arranjo bidimensional de dados. Útil para representar tabelas, planilhas, mapas.

 
### 📝 Enunciado

Uma fábrica registra a **produção de peças** em três turnos (manhã, tarde e noite) durante 4 semanas.

Deseja-se calcular:

1. O total produzido em cada semana.
2. O total produzido em cada turno.
3. A semana/turno com maior produção individual.

  

### 🔎 Passo a passo

1. Declarar matriz `prod[4][3]`.
2. Calcular somas por linha e coluna.
3. Encontrar o maior valor e sua posição.

 
### 💻 Código em C

```c

#include  <stdio.h>

int  main(void) {
int  prod[4][3] = {

{120, 130, 110},
{150, 140, 135},
{160, 155, 145},
{170, 165, 150}

};

int  somaLinha[4] = {0}, somaCol[3] = {0};
int maxV = prod[0][0], imax = 0, jmax = 0;

  

for (int i = 0; i < 4; ++i) {
for (int j = 0; j < 3; ++j) {

somaLinha[i] += prod[i][j];
somaCol[j] += prod[i][j];

if (prod[i][j] > maxV) { maxV = prod[i][j]; imax=i; jmax=j; }

}

}

printf("Totais por semana: ");

for (int i=0;i<4;i++) printf("%d ", somaLinha[i]);
printf("\nTotais por turno: ");

for (int j=0;j<3;j++) printf("%d ", somaCol[j]);
printf("\nMaximo=%d (semana %d, turno %d)\n", maxV, imax+1, jmax+1);

return  0;

}

```

  

---

  

## ✅ Questão 3 – Lista Sequencial (Array)

  

### 📖 Explicação didática

Uma **lista sequencial** é implementada com um vetor e um contador de elementos.

Permite inserções, remoções e acesso por índice.

  

### 📝 Enunciado

Gerenciar uma lista de tarefas (duração em minutos), permitindo:

1. Inserir no fim.

2. Inserir em posição específica.

3. Remover por posição.

4. Imprimir a lista.

  

### 💻 Código em C

```c

#include  <stdio.h>

#include  <stdlib.h>

#define MAX 100

  

typedef  struct {

int  dados[MAX];

int tamanho;

} Lista;

  

void  init(Lista *L) { L->tamanho = 0; }

int  inserirFim(Lista *L, int  x) {

if (L->tamanho == MAX) return  0;

L->dados[L->tamanho++] = x;

return  1;

}

int  inserirPos(Lista *L, int  pos, int  x) {

if (L->tamanho == MAX || pos < 0 || pos > L->tamanho) return  0;

for (int i = L->tamanho; i > pos; --i)

L->dados[i] = L->dados[i-1];

L->dados[pos] = x; L->tamanho++;

return  1;

}

int  removerPos(Lista *L, int  pos) {

if (pos < 0 || pos >= L->tamanho) return  0;

for (int i = pos; i < L->tamanho-1; ++i)

L->dados[i] = L->dados[i+1];

L->tamanho--; return  1;

}

void  imprimir(const Lista *L) {

printf("[");

for (int i = 0; i < L->tamanho; ++i) {

printf("%d", L->dados[i]);

if (i < L->tamanho-1) printf(", ");

}

printf("]\n");

}

int  main(void) {

Lista L; init(&L);

inserirFim(&L,30); inserirFim(&L,45); inserirFim(&L,20);

imprimir(&L);

inserirPos(&L,1,60);

imprimir(&L);

removerPos(&L,2);

imprimir(&L);

return  0;

}

```
---

  

## ✅ Questão 4 – Lista Encadeada Simples

  

### 📖 Explicação didática

Uma **lista encadeada simples** é formada por nós, cada um contendo um dado e

um ponteiro para o próximo. O tamanho cresce dinamicamente.

  

### 📝 Enunciado

Gerenciar IDs de peças em estoque:

1. Inserir peça no final.

2. Remover por ID.

3. Imprimir lista.

  

### 💻 Código em C

```c

#include  <stdio.h>

#include  <stdlib.h>

  

typedef  struct No {

int id;

struct No *prox;

} No;

  

No* novo_no(int  id) {

No *n = (No*)malloc(sizeof(No));

n->id = id; n->prox = NULL;

return n;

}

void  push_back(No **inicio, int  id) {

No *n = novo_no(id);

if (*inicio == NULL) { *inicio = n; return; }

No *p = *inicio;

while (p->prox) p = p->prox;

p->prox = n;

}

int  remove_valor(No **inicio, int  id) {

No *p = *inicio, *ant = NULL;

while (p && p->id != id) { ant = p; p = p->prox; }

if (!p) return  0;

if (!ant) *inicio = p->prox; else  ant->prox = p->prox;

free(p);

return  1;

}

void  imprimir(No *inicio) {

printf("[");

for (No *p = inicio; p; p = p->prox) {

printf("%d", p->id);

if (p->prox) printf(" -> ");

}

printf("]\n");

}

int  main(void) {

No *lista = NULL;

push_back(&lista, 101);

push_back(&lista, 203);

push_back(&lista, 150);

imprimir(lista);

remove_valor(&lista, 203);

imprimir(lista);

return  0;

}

```

  

---

  

## ✅ Questão 5 – Lista com Cabeça (Sentinela)

  

### 📖 Explicação didática

Uma lista com cabeça tem um nó sentinela que não guarda dados úteis,

mas simplifica inserções e remoções.

  

### 📝 Enunciado

Gerenciar notas de alunos:

1. Inserir em ordem crescente.

2. Remover abaixo de um ponto de corte.

3. Imprimir lista.

  

### 💻 Código em C

```c

#include  <stdio.h>

#include  <stdlib.h>

  

typedef  struct No {

int nota;

struct No *prox;

} No;

  

No* novo_no(int  v) {

No *n = (No*)malloc(sizeof(No));

n->nota = v; n->prox = NULL;

return n;

}

void  inserir_ordenado(No *head, int  v) {

No *ant = head, *p = head->prox;

while (p && p->nota < v) { ant = p; p = p->prox; }

No *n = novo_no(v);

n->prox = p; ant->prox = n;

}

void  remover_abaixo(No *head, int  corte) {

No *ant = head, *p = head->prox;

while (p) {

if (p->nota < corte) {

ant->prox = p->prox; free(p); p = ant->prox;

} else { ant = p; p = p->prox; }

}

}

void  imprimir(No *head) {

printf("[");

for (No *p = head->prox; p; p = p->prox) {

printf("%d", p->nota);

if (p->prox) printf(" -> ");

}

printf("]\n");

}

int  main(void) {

No *head = novo_no(-1);

inserir_ordenado(head, 70);

inserir_ordenado(head, 85);

inserir_ordenado(head, 60);

inserir_ordenado(head, 90);

imprimir(head);

remover_abaixo(head, 70);

imprimir(head);

return  0;

}
```
---

  

## ✅ Questão 6 – Lista Circular

  

### 📖 Explicação didática

Na lista circular o último nó aponta para o primeiro.

Usa-se ponteiro `tail` para simplificar inserções.

  

### 📝 Enunciado

Gerenciar uma playlist de músicas:

1. Inserir músicas no fim.

2. Avançar k posições.

3. Remover por ID.

4. Buscar por ID.

  

### 💻 Código em C

```c

#include  <stdio.h>
#include  <stdlib.h>

  

typedef  struct No {

int id;

struct No *prox;

} No;

  

No* novo_no(int  id) {

No *n = (No*)malloc(sizeof(No));

n->id = id; n->prox = n;

return n;

}

void  append(No **tail, int  id) {

No *n = novo_no(id);

if (*tail == NULL) { *tail = n; return; }

n->prox = (*tail)->prox;

(*tail)->prox = n;

*tail = n;

}

void  imprimir_uma_volta(No *tail) {

if (!tail) { printf("[]\n"); return; }

No *p = tail->prox;

printf("[");

do {

printf("%d", p->id);

p = p->prox;

if (p != tail->prox) printf(" -> ");

} while (p != tail->prox);

printf("]\n");

}

int  buscar_id(No *tail, int  id) {

if (!tail) return  0;

No *p = tail->prox;

do {

if (p->id == id) return  1;

p = p->prox;

} while (p != tail->prox);

return  0;

}

int  remover_id(No **tail, int  id) {

if (!*tail) return  0;

No *p = (*tail)->prox, *ant = *tail;

do {

if (p->id == id) {

if (p == ant) { free(p); *tail = NULL; return  1; }

ant->prox = p->prox;

if (p == *tail) *tail = ant;

free(p); return  1;

}

ant = p; p = p->prox;

} while (p != (*tail)->prox);

return  0;

}

int  main(void) {

No *tail = NULL;

append(&tail, 101); append(&tail, 102);

append(&tail, 103); append(&tail, 104);

imprimir_uma_volta(tail);

printf("Buscar 104: %d\n", buscar_id(tail,104));

remover_id(&tail,103);

imprimir_uma_volta(tail);

return  0;

}

```

  

---

  

## ✅ Questão 7 – Pilha

  

### 📖 Explicação didática

A pilha segue a lógica LIFO: o último a entrar é o primeiro a sair.

Usada para controle de escopos, desfazer operações, validação de expressões.

  

### 📝 Enunciado

Verificar se uma expressão com `()[]{}` está corretamente balanceada.

  

### 💻 Código em C

```c

#include  <stdio.h>

#include  <string.h>

#define MAX 1000

  

typedef  struct {

char  dados[MAX];

int topo;

} Pilha;

  

void  init(Pilha *P){ P->topo=-1; }

int  vazia(Pilha *P){ return  P->topo==-1; }

int  push(Pilha *P,char  c){ if(P->topo==MAX-1) return  0; P->dados[++P->topo]=c; return  1; }

int  pop(Pilha *P,char *out){ if(vazia(P)) return  0; *out=P->dados[P->topo--]; return  1; }

int  par(char  a,char  f){ return (a=='('&&f==')')||(a=='['&&f==']')||(a=='{'&&f=='}'); }

  

int  balanceada(const  char *s){

Pilha P; init(&P);

for(int i=0;s[i];i++){

char c=s[i];

if(c=='('||c=='['||c=='{') push(&P,c);

else  if(c==')'||c==']'||c=='}'){

char topo; if(!pop(&P,&topo) || !par(topo,c)) return  0;

}

}

return  vazia(&P);

}

int  main(void){

const  char *a="{ [ ( ) ] }";

const  char *b="{ [ ( ] ) }";

printf("%s -> %s\n",a,balanceada(a)?"OK":"ERRO");

printf("%s -> %s\n",b,balanceada(b)?"OK":"ERRO");

return  0;

}

```

  

---

  

## ✅ Questão 8 – Fila Circular

  

### 📖 Explicação didática

A fila segue a lógica FIFO: o primeiro a entrar é o primeiro a sair.

Para evitar desperdício de espaço, implementa-se de forma circular em arranjo.

  

### 📝 Enunciado

Simular uma fila de atendimento bancário:

1. Enfileirar clientes (enqueue).

2. Atender clientes (dequeue).

3. Mostrar fila.

4. Tratar fila cheia/vazia.

  

### 💻 Código em C

```c

#include  <stdio.h>

#define N 5

  

typedef  struct {

int  v[N]; int ini,fim,tam;

} Fila;

  

void  init(Fila *F){ F->ini=F->fim=F->tam=0; }

int  vazia(Fila *F){ return  F->tam==0; }

int  cheia(Fila *F){ return  F->tam==N; }

  

int  enqueue(Fila *F,int  x){

if(cheia(F)) return  0;

F->v[F->fim]=x; F->fim=(F->fim+1)%N; F->tam++; return  1;

}

int  dequeue(Fila *F,int *out){

if(vazia(F)) return  0;

*out=F->v[F->ini]; F->ini=(F->ini+1)%N; F->tam--; return  1;

}

void  imprimir(Fila *F){

printf("Fila(tam=%d): [",F->tam);

for(int i=0;i<F->tam;i++){

int idx=(F->ini+i)%N;

printf("%d",F->v[idx]);

if(i<F->tam-1) printf(", ");

}

printf("]\n");

}

int  main(void){

Fila F; init(&F);

enqueue(&F,10); enqueue(&F,11); enqueue(&F,12);

imprimir(&F);

int x; dequeue(&F,&x); printf("Atendido: %d\n",x);

imprimir(&F);

enqueue(&F,13); enqueue(&F,14);

if(!enqueue(&F,15)) printf("Fila cheia\n");

imprimir(&F);

while(dequeue(&F,&x)) printf("Atendido: %d\n",x);

imprimir(&F);

return  0;

}

```

  

---

  

📌 **Observação:** este material é uma coletânea didática de exemplos práticos

em C para auxiliar na disciplina de **Estrutura de Dados**.
