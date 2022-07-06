#include <stdio.h>

void insercao(int *v, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = i; j > 0; j--){
            if (v[j - 1] > v[j]){
                int tmp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = tmp;
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
    printf("%d\n%zu\n", tam, strlen(v));

    insercao(v, tam);

    while(i < tam){
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
        i++;
    }

    return 0;
}