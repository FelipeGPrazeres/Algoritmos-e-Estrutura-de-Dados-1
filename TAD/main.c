#include "Ponto.h"
#include "Ponto.c"
#include <stdio.h>

int main(){
    float x1, y1, x2, y2;
    scanf("%f %f", &x1, &y1);
    Ponto *p1 = criaPonto(x1, y1);

    scanf("%f %f", &x2, &y2);
    Ponto *p2 = criaPonto(x2, y2);

    int option;
    while(option != 9){
        scanf("%d", &option);
        switch(option){
            case 1:
                imprimePonto(p1);
                break;
            case 2:
                imprimePonto(p2);
                break;
            case 3:
                distancia(p1, p2);
                break;
            case 4:
                distanciaOrigem(p1);
                break;
            case 5:
                distanciaOrigem(p2);
                break;
            case 6:
                scanf("%f %f", &x1, &y1);
                atribuiPonto(p1, x1, y1);
                break;
            case 7:
                scanf("%f %f", &x1, &y1);
                atribuiPonto(p2, x1, y1);
                break;
            case 8:
                pontosIguais(p1, p2);
                break;
            case 9:
                liberaPonto(p1);
                liberaPonto(p2);
                break;
        }
    }
}