#include <stdio.h>
#include <stdlib.h>

// Função de busca linear
int busca_linear(int v[], int n, int alvo) {
    // Percorre o vetor buscando o alvo
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {  // Se encontrar o valor, retorna o índice
            return i;
        }
    }
    // Se não encontrar o valor, retorna -1
    return -1;
}

// Função de comparação para ser utilizada pelo qsort (para ordenação)
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);  // Compara dois inteiros
}

// Função de busca binária
int busca_binaria(int v[], int n, int alvo) {
    int ini = 0, fim = n - 1;  // Define o intervalo inicial e final da busca
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;  // Calcula o meio do intervalo
        if (v[meio] == alvo) return meio;  // Se encontrar o alvo, retorna o índice
        if (v[meio] < alvo) ini = meio + 1;  // Se o valor do meio for menor que o alvo, procura na metade direita
        else fim = meio - 1;  // Se o valor do meio for maior que o alvo, procura na metade esquerda
    }
    // Se não encontrar o valor, retorna -1
    return -1;
}

int main() {
    // Vetor de códigos de produtos
    int produtos[] = {1234, 5678, 3456, 7890, 2345, 6789, 3457, 1235, 2346, 5679,
                      9876, 4567, 2347, 5676, 1236, 6788, 3458, 1237, 9877, 6787,
                      2348, 9878, 3459, 1238, 6786, 9879, 2349, 1239, 3450, 2340, 6785, 2341};
    int n = sizeof(produtos) / sizeof(produtos[0]);  // Tamanho do vetor produtos

    int alvo, idx;

    // Solicita ao usuário o código do produto para busca linear
    printf("Digite o código do produto para buscar (linear): ");
    scanf("%d", &alvo);

    // Realiza a busca linear
    idx = busca_linear(produtos, n, alvo);
    if (idx == -1) {
        printf("Produto %d não encontrado.\n", alvo);  // Caso não encontre
    } else {
        printf("Produto %d encontrado na posição %d (Busca Linear).\n", alvo, idx);  // Caso encontre
    }

    // Ordena o vetor de produtos em ordem crescente
    qsort(produtos, n, sizeof(produtos[0]), comparar);

    // Solicita ao usuário o código do produto para busca binária após ordenação
    printf("\nDigite o código do produto para buscar (binária): ");
    scanf("%d", &alvo);

    // Realiza a busca binária
    idx = busca_binaria(produtos, n, alvo);
    if (idx == -1) {
        printf("Produto %d não encontrado.\n", alvo);  // Caso não encontre
    } else {
        printf("Produto %d encontrado na posição %d (Busca Binária).\n", alvo, idx);  // Caso encontre
    }

    return 0;  
}
