#include <stdio.h>
#include <stdlib.h>

int qtd[1000001];

int main(void){

    int n, x = 0;
    int presentes = 0;

    scanf("%d", &n);

    while(x < n){
        int i;
        scanf("%d", &i);

        qtd[i]++;
        x++;
    } 

    for(int j = 0; j < 1000001; j++){
        presentes += qtd[j] > 0;
    }

    printf("%d\n", presentes);
}