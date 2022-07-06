#include <stdio.h>

void insercao(int *v, int tam){
    for(int i = i, j; i < tam; i++){
        int tmp = v[i];
        for(j = i; j > 0 && tmp < v[j - 1]; j--){
            v[j] = v[j - 1];
        }
        v[j] = tmp;
    }
}

int main(void){

    int v[50001];
    int tam = 0, i = 0;

    while(scanf(" %d", v + tam) != EOF){
        tam++;
    } 

    insercao(v, tam);

    while(i < tam){
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
        i++;
    }

    return 0;
}