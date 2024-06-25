#include <stdio.h>
#include <string.h>

#define TAM_STR 100

int main() {
    int N;
    scanf("%d", &N);
    fflush(stdin);

    char str[TAM_STR], maiorComprimento[TAM_STR] = "", maiorLexico[TAM_STR] = "";

    for (int i = 0; i < N; i++) {
        fgets(str, TAM_STR, stdin);
        str[strcspn(str, "\n")] = '\0';

        if (strlen(str) > strlen(maiorComprimento)) {
            strcpy(maiorComprimento, str);
        }

        if (strcmp(str, maiorLexico) > 0) {
            strcpy(maiorLexico, str);
        }
    }

    puts(maiorComprimento);
    puts(maiorLexico);

    return 0;
}
