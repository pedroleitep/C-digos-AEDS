#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;


    if (scanf("%d %d", &N, &K) != 2 || N < 1 || N > 500000 || K < 0 || K > 1000000) {
        return 1;
    }


    int *X = (int *)malloc(N * sizeof(int));
    if (X == NULL) {
        return 1;
    }


    for (int i = 0; i < N; i++) {
        if (scanf("%d", &X[i]) != 1 || X[i] < 0 || X[i] > 100) {
            return 1;
        }
    }

    int contaRetangulos = 0;


    for (int inicio = 0; inicio < N; inicio++) {
        int soma = 0;
        for (int fim = inicio; fim < N; fim++) {
            soma += X[fim];
            if (soma == K) {
                contaRetangulos++;
            }
        }
    }


    printf("%d\n", contaRetangulos);

    return 0;
}
