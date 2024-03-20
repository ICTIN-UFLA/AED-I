#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    
    // Solicitar a palavra ao usuário
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra);

    // Imprimir a palavra de forma inversa
    printf("Palavra invertida: ");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", palavra[i]);
    }
    printf("\n");

    return 0;
}
