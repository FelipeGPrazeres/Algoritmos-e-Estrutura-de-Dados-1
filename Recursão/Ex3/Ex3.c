#include <stdio.h>

int somaPar(int vet[], int m){
    if(m < 0){
        return 0; 
    }
    else if(vet[m] % 2 == 0){
        int soma = vet[m] + somaPar(vet, m-1);
        return soma;
    }
    else{
        return somaPar(vet, m-1);
    }
}

int main (){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    printf("Soma dos pares: %d\n", somaPar(vetor, n-1));
}
