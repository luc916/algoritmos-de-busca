#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o índice do menor valor maior ou igual ao alvo
int lower_bound(float v[], int n, float alvo) {
    int ini = 0, fim = n;  // Inicializa os índices para a busca binária
    
    // Enquanto o intervalo de busca for válido
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;  // Calcula o ponto médio do intervalo
        
        // Se o valor no meio for menor que o alvo, a busca continua na metade direita
        if (v[meio] < alvo) {
            ini = meio + 1;
        } else {
            fim = meio;  // Caso contrário, a busca continua na metade esquerda
        }
    }
    
    // Retorna o índice do primeiro valor >= alvo
    return ini;
}

int main() {
    // Vetor de leituras já ordenado
    float leituras[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
    int n = sizeof(leituras) / sizeof(leituras[0]);  // Tamanho do vetor
    float alvo;
    
    // Solicita ao usuário o valor alvo
    printf("Digite o valor alvo para busca lower_bound: ");
    scanf("%f", &alvo);

    // Chama a função lower_bound para encontrar o índice
    int idx = lower_bound(leituras, n, alvo);

    // Verifica se o índice é válido e exibe o resultado
    if (idx < n) {
        printf("O primeiro valor >= %.2f está no índice %d, que é %.2f.\n", alvo, idx, leituras[idx]);
    } else {
        printf("Não há valores maiores ou iguais a %.2f no vetor.\n", alvo);
    }

    return 0;
}
