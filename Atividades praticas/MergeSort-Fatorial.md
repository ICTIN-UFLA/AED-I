
  

# Algoritmo Recursivo 


## Fatorial 

```c
#include <stdio.h>
#include <stdlib.h>

unsigned long long fatorial(int n) {
  unsigned long long resultado = 1;

  printf("Passo a passo do cálculo de %d!: ", n);
  for (int i = n; i > 0; i--) {
    printf("%d", i);
    if (i > 1) {
      printf(" * ");
    }
    resultado *= i;
  }
  printf(" = %llu\n", resultado);

  return resultado;
}

int main() {
  int numero;
  unsigned long long resultado;

  printf("Digite um número para calcular o fatorial: ");
  scanf("%d", &numero);

  if (numero < 0) {
    printf("Número inválido!\n");
    return 1;
  }

  resultado = fatorial(numero);
  printf("Fatorial de %d e %llu\n", numero, resultado);

  return 0;
}


```
  
### O algoritmo a seguir apresenta um gerador de vetor

```c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para criar um array aleatório e imprimir a quantidade de elementos
void criarArrayAleatorio(int n) {
  // Aloca memória para o array
  int *arr = (int *)malloc(n * sizeof(int));

  // Verifica se a alocação foi bem-sucedida
  if (arr == NULL) {
    printf("Erro ao alocar memória!\n");
    return;
  }

  // Inicializa o gerador de números aleatórios
  srand(time(NULL));

  // Preenche o array com números aleatórios
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100000;  // Números aleatórios de 0 a 99999
  }

  // Imprime a quantidade de elementos no array
  printf("Quantidade de elementos no array: %d\n", n);

  // Opcional: Imprime os elementos do array
  printf("Elementos do array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Libera a memória alocada
  free(arr);
}

// Função principal
int main() {
  int n;

  // Solicita ao usuário o tamanho do array
  printf("Digite o tamanho do array: ");
  scanf("%d", &n);

  // Cria o array aleatório e imprime a quantidade de elementos
  criarArrayAleatorio(n);

  return 0;
}


```  

## Merge Sorte 

A partir do algoritmo anterior que gera vetor, rode o algoritmo Merge Sorte com as entradas fornecidas. Faça testes até o algoritmo travar o computador. Observe o consumo de memória e CPU no terminal /  gerenciador de tarefas do seu computador. 
```c
#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas metades
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Arrays temporários
  int leftArray[n1], rightArray[n2];

  // Copia os dados para os arrays temporários
  for (int i = 0; i < n1; i++) leftArray[i] = arr[left + i];
  for (int j = 0; j < n2; j++) rightArray[j] = arr[mid + 1 + j];

  // Índices iniciais das duas metades
  int i = 0, j = 0, k = left;

  // Mescla os arrays temporários de volta no array original
  while (i < n1 && j < n2) {
    if (leftArray[i] <= rightArray[j]) {
      arr[k] = leftArray[i];
      i++;
    } else {
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }

  // Copia os elementos restantes de leftArray, se houver
  while (i < n1) {
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  // Copia os elementos restantes de rightArray, se houver
  while (j < n2) {
    arr[k] = rightArray[j];
    j++;
    k++;
  }
}

// Função recursiva para ordenar o array usando MergeSort
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    // Ordena a primeira e a segunda metade
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Mescla as metades ordenadas
    merge(arr, left, mid, right);
  }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");
}

// Função principal
int main() {
  int n;

  // Solicita ao usuário o tamanho do array
  printf("Digite o tamanho do array: ");
  scanf("%d", &n);

  // Aloca memória para o array
  int *arr = (int *)malloc(n * sizeof(int));

  // Verifica se a alocação foi bem-sucedida
  if (arr == NULL) {
    printf("Erro ao alocar memória!\n");
    return 1;
  }

  // Solicita ao usuário os elementos do array
  printf("Digite os elementos do array: \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &i[arr]);  // equivalente a scanf("%d", &arr[i]);
  }

  printf("Array inicial: \n");
  printArray(arr, n);

  mergeSort(arr, 0, n - 1);

  printf("\nArray ordenado: \n");
  printArray(arr, n);

  // Libera a memória alocada
  free(arr);

  return 0;
}


```


  
