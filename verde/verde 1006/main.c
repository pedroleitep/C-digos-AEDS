#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STR 100

int main() {
    int N;
    printf("Digite o número de strings: ");
    scanf("%d", &N);
    getchar();

    char strings[N][TAM_STR];
    char maiorComprimento[TAM_STR] = "";
    char maiorLexico[TAM_STR] = "";

    for (int i = 0; i < N; i++) {
        printf("Digite a string %d: ", i + 1);
        fgets(strings[i], TAM_STR, stdin);


        if (strlen(strings[i]) > strlen(maiorComprimento)) {
            strcpy(maiorComprimento, strings[i]);
        }

        if (strcmp(strings[i], maiorLexico) > 0) {
            strcpy(maiorLexico, strings[i]);
        }
    }

    printf("\nMaior string em termos de comprimento: %s\n", maiorComprimento);
    printf("\nMaior string em termos lexicográficos: %s\n", maiorLexico);

    return 0;
}
