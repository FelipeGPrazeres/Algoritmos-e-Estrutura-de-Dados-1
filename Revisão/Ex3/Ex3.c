#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num = 0;
    int num2 = 0;
    int pos;
    scanf("%d", &num);
    int *vet = malloc(num * sizeof(int));
    if (vet == NULL) {
        return 1;
    }
    for (int i = 0; i < num; i++) {
        int buffer;
        scanf("%d", &buffer);
        vet[i] = buffer;
    }
    scanf("%d", &num2);
    scanf("%d", &pos);
    vet = realloc(vet, (num+1) * sizeof(int));
    if (vet == NULL) {
        return 1;
    }
    for(int i = num; i > pos; i--) {
        int buffer;
        buffer = vet[i-1];
        vet[i] = buffer;
    }
    vet[pos] = num2;
    for (int i = 0; i < num+1; i++) {
        printf("%d ", vet[i]);
    }
    free(vet);
    return 0;
}