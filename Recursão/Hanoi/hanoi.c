#include <stdio.h>

void hanoi(int n, char origem, char destino, char aux){
    if (n == 1) {
        printf("Mova o disco %d de %c para %c\n", n, origem, destino);
        return;
    } else {
        hanoi(n - 1, origem, aux, destino);
        printf("Mova o disco %d de %c para %c\n", n, origem, destino);
        hanoi(n - 1, aux, destino, origem);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}