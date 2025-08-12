#include <stdio.h>
#include <stdlib.h>

int lower_bound(float v[], int n, float alvo) {
    int ini = 0, fim = n;
    
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        
        if (v[meio] < alvo) {
            ini = meio + 1;
        } else {
            fim = meio;
        }
    }
    return ini;
}

int main() {
    float leituras[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
    int n = sizeof(leituras) / sizeof(leituras[0]);
    float alvo;
    
    printf("Digite o valor alvo para busca lower_bound: ");
    scanf("%f", &alvo);

    int idx = lower_bound(leituras, n, alvo);

    if (idx < n) {
        printf("O primeiro valor >= %.2f está no índice %d, que é %.2f.\n", alvo, idx, leituras[idx]);
    } else {
        printf("Não há valores maiores ou iguais a %.2f no vetor.\n", alvo);
    }

    return 0;
}
