
# 🧱 Duas Pilhas com Implementação Estática em C

## 📌 Objetivo

Você aprenderá a implementar **duas pilhas em uma única estrutura estática (vetor)** na linguagem C, aproveitando ao máximo o espaço disponível na memória.

---

## ❓ Por que duas pilhas em um vetor?

- Em vez de usar dois vetores distintos, podemos usar **um único vetor** para armazenar **duas pilhas** que crescem em direções opostas.
- Isso **otimiza o uso de memória**, pois as pilhas compartilham o mesmo espaço e o limite real de cada uma se ajusta dinamicamente.

---

## 🧠 Ideia principal

- A **Pilha 1** cresce do **início** para o **fim** do vetor.
- A **Pilha 2** cresce do **fim** para o **início** do vetor.

---

## 🧱 Estrutura de Dados

```c
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo1;
    int topo2;
} DuasPilhas;
```

- `topo1` começa em `-1`;
- `topo2` começa em `MAX`.

---

## 🚀 Inicializar

```c
void inicializar(DuasPilhas *p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}
```

---

## ➕ Push nas Pilhas

```c
void push1(DuasPilhas *p, int valor) {
    if (p->topo1 + 1 == p->topo2) {
        printf("Estouro de pilha!\n");
        return;
    }
    p->dados[++(p->topo1)] = valor;
}

void push2(DuasPilhas *p, int valor) {
    if (p->topo2 - 1 == p->topo1) {
        printf("Estouro de pilha!\n");
        return;
    }
    p->dados[--(p->topo2)] = valor;
}
```

---

## ➖ Pop das Pilhas

```c
int pop1(DuasPilhas *p) {
    if (p->topo1 == -1) {
        printf("Pilha 1 vazia!\n");
        return -1;
    }
    return p->dados[(p->topo1)--];
}

int pop2(DuasPilhas *p) {
    if (p->topo2 == MAX) {
        printf("Pilha 2 vazia!\n");
        return -1;
    }
    return p->dados[(p->topo2)++];
}
```

---

## 🔍 Topo das Pilhas

```c
int topo1(DuasPilhas *p) {
    if (p->topo1 == -1) {
        printf("Pilha 1 vazia!\n");
        return -1;
    }
    return p->dados[p->topo1];
}

int topo2(DuasPilhas *p) {
    if (p->topo2 == MAX) {
        printf("Pilha 2 vazia!\n");
        return -1;
    }
    return p->dados[p->topo2];
}
```

---

## 🧪 Exemplo de Uso

```c
int main() {
    DuasPilhas p;
    inicializar(&p);

    push1(&p, 10);
    push1(&p, 20);
    push2(&p, 30);
    push2(&p, 40);

    printf("Topo da Pilha 1: %d\n", topo1(&p));
    printf("Topo da Pilha 2: %d\n", topo2(&p));

    printf("Pop Pilha 1: %d\n", pop1(&p));
    printf("Pop Pilha 2: %d\n", pop2(&p));

    return 0;
}
```

---

## 🧠 Desafios

1. Implemente funções para `isEmpty1()` e `isEmpty2()`.
2. Implemente `tamanhoPilha1()` e `tamanhoPilha2()`.
3. Modifique para suportar tipos genéricos com `void*`.

---

## ✅ Conclusão

Você aprendeu:

- Como implementar duas pilhas em um vetor estático;
- Como fazer inserções, remoções e consultas de topo;
- Como otimizar o uso de espaço em memória fixa.

---

## 📎 Licença

Este conteúdo está sob a Licença MIT. Use, compartilhe e adapte livremente!
