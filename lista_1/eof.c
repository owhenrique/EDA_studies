#include <stdio.h>

int main(void){

    int n = 0, contador = 0;

    while(scanf("%d", &n) != EOF){
        contador++;
    }

    printf("%d\n", contador);
    
    return 0;
}