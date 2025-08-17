#include <stdio.h>
#include <stdlib.h>

// Função que recebe o vetor e o preenche com valores digitados
void preencherVetor(int *vet, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o valor do elemento %d: ", i + 1);
        scanf("%d", &vet[i]); // leitura diretamente no vetor
    }
}

int main() {
    int n;
    int *vetor; // ponteiro para o vetor dinâmico

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // aloca dinamicamente espaço para n inteiros
    vetor = (int *) malloc(n * sizeof(int));

    if (vetor == NULL) { // verificação se a alocação deu certo
        printf("Erro: Memória insuficiente!\n");
        return 1;
    }

    // Preenche o vetor chamando a função
    preencherVetor(vetor, n);

    // Mostra os valores digitados (opcional, mas útil para testar)
    printf("\nValores no vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // libera a memória alocada
    free(vetor);

    return 0;
}
