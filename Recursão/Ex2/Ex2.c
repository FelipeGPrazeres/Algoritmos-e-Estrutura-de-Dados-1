#include <stdio.h>
int fibonacci(int n){
    int resultado;
    printf("Entrando em fibonacci(%d)\n", n);
    if(n == 0){
        resultado = 0;
        printf("Caso base atingido: fibonacci(%d) = %d\n", n, resultado);
    } else if(n == 1){
        resultado = 1;
        printf("Caso base atingido: fibonacci(%d) = %d\n", n, resultado);
    } else {
        resultado = fibonacci(n-1) + fibonacci(n-2);
        printf("Retornando de fibonacci(%d) = %d\n", n, resultado);
    }
    return resultado;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("Calculando fibonacci de %d...\n", n);
    printf("Resultado final: %d\n", fibonacci(n));
    return 0;
}