#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMES 20           // Define o número máximo de nomes
#define TAMANHO_NOME 50        // Define o tamanho máximo de cada nome

// Função para comparar duas strings sem considerar o case (maiúsculas/minúsculas)
int compara_case_insensitive(const char *a, const char *b) {
    // Enquanto não chegar ao final das duas strings
    while (*a && *b) {
        // Compara os caracteres, ignorando se são maiúsculos ou minúsculos
        if (tolower(*a) != tolower(*b)) {
            return tolower(*a) - tolower(*b);
        }
        a++;
        b++;
    }
    // Caso as strings tenham o mesmo conteúdo, a comparação termina
    return tolower(*a) - tolower(*b);
}

// Função de busca linear que compara os nomes de forma case-insensitive
int busca_linear_case_insensitive(char nomes[][TAMANHO_NOME], int n, const char *alvo) {
    // Percorre todos os nomes para procurar o alvo
    for (int i = 0; i < n; i++) {
        // Se o nome for encontrado, retorna o índice
        if (compara_case_insensitive(nomes[i], alvo) == 0) {
            return i;
        }
    }
    // Caso não encontre o nome, retorna -1
    return -1;
}

// Função de comparação para ser usada pelo qsort (ordenação)
int comparar(const void *a, const void *b) {
    return compara_case_insensitive(*(const char **)a, *(const char **)b);
}

// Função de busca binária, também com comparação case-insensitive
int busca_binaria(char nomes[][TAMANHO_NOME], int n, const char *alvo) {
    int ini = 0, fim = n - 1;
    
    // Enquanto o intervalo de pesquisa não se esgotar
    while (ini <= fim) {
        // Calcula o índice do meio
        int meio = ini + (fim - ini) / 2;
        
        // Compara o nome no meio do vetor com o alvo
        int cmp = compara_case_insensitive(nomes[meio], alvo);
        
        // Se encontrar o nome, retorna o índice
        if (cmp == 0) {
            return meio;
        } else if (cmp < 0) {
            // Se o nome do meio for menor que o alvo, continua a busca na metade direita
            ini = meio + 1;
        } else {
            // Se o nome do meio for maior que o alvo, continua a busca na metade esquerda
            fim = meio - 1;
        }
    }
    // Se não encontrar o nome, retorna -1
    return -1;
}

int main() {
    // Vetor de nomes (máximo de 20 nomes, cada um com até 50 caracteres)
    char nomes[MAX_NOMES][TAMANHO_NOME] = {
        "Ana", "Bruno", "Carlos", "Daniela", "Eduardo",
        "Fernanda", "Gabriel", "Helena", "Igor", "João",
        "Karla", "Lucas", "Maria", "Nicolas", "Otávio",
        "Paulo", "Quiteria", "Rafael", "Sofia", "Tiago"
    };

    int n = 20;  // Número de nomes
    char alvo[TAMANHO_NOME];  // Variável para armazenar o nome a ser buscado
    int idx;

    // Solicita ao usuário que digite o nome a ser buscado
    printf("Digite o nome a ser buscado (case-insensitive): ");
    scanf(" %49[^\n]", alvo);  // Lê o nome, permitindo espaços

    // Realiza a busca linear sem considerar maiúsculas/minúsculas
    idx = busca_linear_case_insensitive(nomes, n, alvo);
    if (idx == -1) {
        printf("Nome '%s' não encontrado.\n", alvo);
    } else {
        printf("Nome '%s' encontrado na posição %d (Busca Linear).\n", alvo, idx);
    }

    // Ordena o vetor de nomes em ordem alfabética (case-insensitive)
    qsort(nomes, n, sizeof(nomes[0]), (int (*)(const void *, const void *))compara_case_insensitive);

    // Solicita novamente ao usuário para buscar o nome após a ordenação
    printf("\nDigite o nome a ser buscado (case-insensitive) após ordenação: ");
    scanf(" %49[^\n]", alvo);

    // Realiza a busca binária após a ordenação
    idx = busca_binaria(nomes, n, alvo);
    if (idx == -1) {
        printf("Nome '%s' não encontrado.\n", alvo);
    } else {
        printf("Nome '%s' encontrado na posição %d (Busca Binária).\n", alvo, idx);
    }

    return 0; 
}
