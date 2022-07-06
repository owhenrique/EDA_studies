#include <stdio.h>

int main(){
    int soma = 0;
    for(int i = 1; i <= 10; i++){
        for(int j = 0; j < i; j++){
            soma = soma + 1;
        }
    }
    printf("%d\n", soma);
    return 0;
}