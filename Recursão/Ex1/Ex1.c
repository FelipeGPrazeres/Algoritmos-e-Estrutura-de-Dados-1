#include <stdio.h>

int fatorial(int n){
    printf("Entrando em fatorial(%d)\n", n);
    if(n == 0 || n == 1){
        printf("Caso base atingido: fatorial(%d) = 1\n", n);
        return 1;
    }
    else {
        int resultado = n * fatorial(n-1);
        printf("Retornando de fatorial(%d) = %d\n", n, resultado);
        return resultado;
    }
}

int main(){
    int num;
    scanf("%d", &num);
    printf("Calculando fatorial de %d...\n", num);
    printf("Resultado final: %d", fatorial(num));
    return 0;
}