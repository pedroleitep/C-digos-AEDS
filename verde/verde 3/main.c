#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STR 100

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    char strings[N][TAM_STR];
    char maiorComprimento[TAM_STR] = "";
    char maiorLexico[TAM_STR] = "";

    for (int i = 0; i < N; i++) {
        fgets(strings[i], TAM_STR, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';

        if (strlen(strings[i]) > strlen(maiorComprimento)) {
            strcpy(maiorComprimento, strings[i]);
        }

        if (strcmp(strings[i], maiorLexico) > 0) {
            strcpy(maiorLexico, strings[i]);
        }
    }

    puts(maiorComprimento);
    puts(maiorLexico);

    return 0;
}
