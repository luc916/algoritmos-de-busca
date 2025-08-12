#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMES 20
#define TAMANHO_NOME 50

int compara_case_insensitive(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower(*a) != tolower(*b)) {
            return tolower(*a) - tolower(*b);
        }
        a++;
        b++;
    }
    return tolower(*a) - tolower(*b);
}

int busca_linear_case_insensitive(char nomes[][TAMANHO_NOME], int n, const char *alvo) {
    for (int i = 0; i < n; i++) {
        if (compara_case_insensitive(nomes[i], alvo) == 0) {
            return i;
        }
    }
    return -1;
}

int comparar(const void *a, const void *b) {
    return compara_case_insensitive(*(const char **)a, *(const char **)b);
}

int busca_binaria(char nomes[][TAMANHO_NOME], int n, const char *alvo) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        int cmp = compara_case_insensitive(nomes[meio], alvo);
        if (cmp == 0) {
            return meio;
        } else if (cmp < 0) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}


int main() {
    char nomes[MAX_NOMES][TAMANHO_NOME] = {
        "Ana", "Bruno", "Carlos", "Daniela", "Eduardo",
        "Fernanda", "Gabriel", "Helena", "Igor", "João",
        "Karla", "Lucas", "Maria", "Nicolas", "Otávio",
        "Paulo", "Quiteria", "Rafael", "Sofia", "Tiago"
    };

    int n = 20;
    char alvo[TAMANHO_NOME];
    int idx;

    printf("Digite o nome a ser buscado (case-insensitive): ");
    scanf(" %49[^\n]", alvo);

    idx = busca_linear_case_insensitive(nomes, n, alvo);
    if (idx == -1) {
        printf("Nome '%s' não encontrado.\n", alvo);
    } else {
        printf("Nome '%s' encontrado na posição %d (Busca Linear).\n", alvo, idx);
    }

    qsort(nomes, n, sizeof(nomes[0]), (int (*)(const void *, const void *))compara_case_insensitive);

    printf("\nDigite o nome a ser buscado (case-insensitive) após ordenação: ");
    scanf(" %49[^\n]", alvo);

    idx = busca_binaria(nomes, n, alvo);
    if (idx == -1) {
        printf("Nome '%s' não encontrado.\n", alvo);
    } else {
        printf("Nome '%s' encontrado na posição %d (Busca Binária).\n", alvo, idx);
    }

    return 0;
}
