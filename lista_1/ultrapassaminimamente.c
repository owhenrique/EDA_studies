#include <stdio.h>
#include <stdlib.h>

void umnm(int *string, int utmt, int soma, int i, int tam){
    if (tam == i)
        return;

    soma += string[i];

    if(soma > utmt){
        umnm(string, utmt, 0, i + 1, tam);
        printf("%d\n", string[i]);
    }

    else{
        umnm(string, utmt, soma, i + 1, tam);
    }

}

int main(void){

    int *string = NULL;
    int i, tam = 0, utmt;
    
    while(scanf("%d", &i) == 1 && i != 0){
        tam++;
        string = realloc(string, sizeof(int) * tam);
        string[tam - 1] = i;
    }
    scanf("%d", &utmt);
    umnm(string, utmt, 0, 0, tam);

    return 0;
}