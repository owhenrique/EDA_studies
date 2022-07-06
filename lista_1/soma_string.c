#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    int n, x = 0;   
    int soma = 0;
    scanf("%d", &n);

    while(x < n){
        char string[101];
        scanf("%s", string);
        
        for(int i = 0; string[i] != '\0' && i < 100; i++){
            soma += ('0' <= string[i] && string[i] <= '9' ? string[i] - '0' : 0);
        }

        printf("%d\n", soma);
        soma = 0;
        x++;
    }

    return 0;
}