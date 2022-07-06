#include <stdio.h>

void selecao(int *v, int tam){
    for(int i = 0; i < tam - 1; i++){
        int menor = i;

        for(int j = i + 1; j < tam; j++){
            if (v[j] < v[menor]){
                menor = j;
            }
        }

        int tmp = v[i];
        v[i] = v[menor];
        v[menor] = tmp;
    }
}

int main(void){

    int v[1001];
    int tam = 0, i = 0;

    while(scanf(" %d", v + tam) != EOF){
        tam++;
    }

    selecao(v, tam);

    while(i < tam){
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
        i++;
    }

    return 0;
}