#include <stdio.h>

int main(void){

    int n, soma = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        scanf("%d", &tmp);
        soma += tmp;
    }

    printf("%d\n", soma);

    return 0;
}