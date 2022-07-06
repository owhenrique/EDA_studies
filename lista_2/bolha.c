#include <stdio.h>
#include <stdlib.h>

void bolha(int *v, int tam){
    for(int i = 0; i < tam - 1; i++){
        for(int j = 1; j < tam; j++){
            if(v[j - 1] > v[j]){
                int x = v[j - 1];
                v[j - 1] = v[j];
                v[j] = x;
            }
        }
    }
}

int main(void){

    int v[1001];
    int tam = 0, i = 0;

    while(scanf(" %d", v + tam) != EOF){
        tam++;
    }

    bolha(v, tam);

    while(i < tam){
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
        i++;
    }

    return 0;
}