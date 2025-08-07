#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addNum(int *vetor, int contador, int num){
    vetor = realloc(vetor, (contador + 1) * sizeof(int));
    if (vetor == NULL) {
        return; // falha ao alocar memória
    }
    vetor[contador] = num;
}

void rmvNum(int *vetor, int contador) {
    if (contador > 0) {
        vetor = realloc(vetor, contador * sizeof(int));
    }
}

void lstNums(int *vetor, int contador) {
    if (contador > 0){
        for(int i = 0; i < contador; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
    }
}

void somaNums(int *vetor, int contador){
    if (contador > 0) {
        int soma = 0;
       float media = 0;
        for (int i = 0; i < contador; i++) {
            soma += vetor[i];
        }
        media = (float)soma / contador;
        printf("Soma = %d, Média = %.2f\n", soma, media);
    }
}

void ordLista(int *vetor, int contador) {
    if (contador > 0) {
        for (int i = 0; i < contador - 1; i++) {
            for (int j = i + 1; j < contador; j++) {
                if (vetor[i] > vetor[j]) {
                    int temp = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = temp;
                }
            }
        }
    }
}

int main() {
    int opcao;
    int contador = 0;
    int *vetor = malloc(1 * sizeof(int));
    if (vetor == NULL) {
        return 1;
    }
    do {
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                // add num a lista
                int num;
                scanf("%d", &num);
                addNum(vetor, contador, num);
                contador++;
                break;
            case 2:
                // remover num da lista
                contador--;
                rmvNum(vetor, contador);
                break;
            case 3:
                // listar todos os valores
                lstNums(vetor, contador);
                break;
            case 4:
                // calcular soma e media
                somaNums(vetor, contador);
                break;
            case 5:
                // ordenar lista em ordem crescente
                ordLista(vetor, contador);
                break;
            case 6:
                // sair
                break;
        }
    } while (opcao != 6);
    free(vetor);
    return 0;
}