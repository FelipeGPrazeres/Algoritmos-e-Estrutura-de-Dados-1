#include <stdio.h>
#include <stdlib.h>

// Função para imprimir um subvetor
void imprimir_subvetor(int vetor[], int l, int r) {
    for (int i = l; i <= r; i++) {
        // Imprime um espaço antes de cada número
        printf(" %d", vetor[i]);
    }
}

// Função para intercalar dois subvetores vetor[l..m] e vetor[m+1..r]
void intercalar(int vetor[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criar vetores temporários
    int L[n1], R[n2];

    // Copiar dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[m + 1 + j];

    // Intercalar os vetores temporários de volta em vetor[l..r]
    i = 0; // Índice inicial do primeiro subvetor
    j = 0; // Índice inicial do segundo subvetor
    k = l; // Índice inicial do subvetor intercalado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver algum
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver algum
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }

    // Imprimir o estado do subvetor após a intercalação
    printf("INTERCALACAO [%d,%d]:", l, r);
    imprimir_subvetor(vetor, l, r);
    printf("\n");
}

// Função principal do Merge Sort que ordena vetor[l..r]
void mergeSort(int vetor[], int l, int r) {
    if (l < r) {
        // Imprime a divisão do intervalo
        printf("DIVISAO [%d,%d]\n", l, r);

        // Encontra o ponto médio
        // l + (r-l)/2 é o mesmo que (l+r)/2, mas evita overflow para l e r muito grandes
        int m = l + (r - l) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);

        // Intercala as metades ordenadas
        intercalar(vetor, l, m, r);
    }
}

int main() {
    int n;
    // 1. Ler o tamanho do vetor
    scanf("%d", &n);

    if (n <= 0) {
        return 0; // Não há nada a fazer se o vetor estiver vazio ou for inválido
    }

    int vetor[n];
    // 2. Ler os n inteiros do vetor
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // 3. Chamar o Merge Sort para o vetor completo
    mergeSort(vetor, 0, n - 1);

    return 0;
}