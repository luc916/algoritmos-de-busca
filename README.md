Algoritmos de Busca em C

Este repositório contém implementações dos algoritmos de Busca Linear e Busca Binária, escritos em C. A principal diferença entre esses dois algoritmos é o desempenho em relação ao tamanho do conjunto de dados e a organização dos mesmos.

Diferenças entre Busca Linear e Busca Binária

Busca Linear
Descrição: A busca linear percorre todos os elementos de um vetor até encontrar o alvo. Não exige que o vetor esteja ordenado.

Vantagens: Simples de implementar e pode ser usada em vetores desordenados.

Desvantagens: Menos eficiente, pois percorre todos os elementos do vetor até encontrar o valor desejado.

Complexidade de Tempo: O(n), onde n é o número de elementos no vetor.

Busca Binária
Descrição: A busca binária encontra o valor desejado dividindo o vetor ordenado em metades repetidamente, descartando metade a cada iteração.

Vantagens: Muito mais eficiente para grandes vetores, mas exige que os dados estejam ordenados.

Desvantagens: Requer que o vetor esteja ordenado, o que pode ser um custo adicional se os dados não estiverem previamente ordenados.

Complexidade de Tempo: O(log n), onde n é o número de elementos no vetor.

Como Compilar e Executar
1. Busca Linear
Nome: busca_linear.c

Passos para compilar e executar:

bash
Copiar
Editar
gcc busca_linear.c -o busca_linear.exe
./busca_linear.exe

2. Busca Binária
Nome: busca_binaria.c

Passos para compilar e executar:

bash
Copiar
Editar
gcc busca_binaria.c -o busca_binaria.exe
./busca_binaria.exe

3. Busca CPF
Nome: cpf_busca.c

Passos para compilar e executar:

bash
Copiar
Editar
gcc cpf_busca.c -o cpf_busca.exe
./cpf_busca.exe

Quando Usar Cada Técnica

Busca Linear
Quando usar: Utilize a busca linear quando:

O vetor não está ordenado.

O vetor é pequeno e a simplicidade do algoritmo é mais importante que a performance.

A sobrecarga de ordenar o vetor para usar uma busca binária não é justificada.

Busca Binária
Quando usar: Utilize a busca binária quando:

O vetor está ordenado ou você tem certeza de que será ordenado antes da busca.

A performance é crítica, pois a busca binária é muito mais eficiente em vetores grandes.

A sobrecarga de manter o vetor ordenado ou ordená-lo inicialmente é aceitável.

Observações
Busca Linear: A busca linear não exige que o vetor esteja ordenado, mas sua eficiência é baixa, pois ela percorre todos os elementos até encontrar o valor ou chegar ao final do vetor.

Busca Binária: A busca binária é altamente eficiente, com complexidade O(log n), mas só pode ser aplicada em vetores ordenados. Caso o vetor não esteja ordenado, seria necessário ordenar o vetor primeiro, o que introduz um custo adicional.

