#include <stdio.h>
#include <stdlib.h>

int busca_linear(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int busca_binaria(int v[], int n, int alvo) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == alvo) return meio;
        if (v[meio] < alvo) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int main() {
    int produtos[] = {1234, 5678, 3456, 7890, 2345, 6789, 3457, 1235, 2346, 5679,
                      9876, 4567, 2347, 5676, 1236, 6788, 3458, 1237, 9877, 6787,
                      2348, 9878, 3459, 1238, 6786, 9879, 2349, 1239, 3450, 2340, 6785, 2341};
    int n = sizeof(produtos) / sizeof(produtos[0]);

    int alvo, idx;

    printf("Digite o código do produto para buscar (linear): ");
    scanf("%d", &alvo);

    idx = busca_linear(produtos, n, alvo);
    if (idx == -1) {
        printf("Produto %d não encontrado.\n", alvo);
    } else {
        printf("Produto %d encontrado na posição %d (Busca Linear).\n", alvo, idx);
    }

    qsort(produtos, n, sizeof(produtos[0]), comparar);

    printf("\nDigite o código do produto para buscar (binária): ");
    scanf("%d", &alvo);

    idx = busca_binaria(produtos, n, alvo);
    if (idx == -1) {
        printf("Produto %d não encontrado.\n", alvo);
    } else {
        printf("Produto %d encontrado na posição %d (Busca Binária).\n", alvo, idx);
    }

    return 0;
}
