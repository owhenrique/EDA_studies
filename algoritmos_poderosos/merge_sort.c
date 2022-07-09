#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

void imprime(int *v, int tam);
void merge(int *v, int l, int r1, int r2);
void merge_sort(int *v, int l, int r);

int main(void)
{
    int v[6];

    srand(time(NULL));

    for(int i = 0; i <= 5; i++)
    {
        v[i] = rand() % 99;
    }

    imprime(v, 6);

    merge_sort(v, 0, 5);

    imprime(v, 6);

    return 0;
}

void imprime(int *v, int tam)
{   
    printf("VETOR:\n");
    for(int i = 0; i < tam; i++)
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
}

void merge(int *v, int l, int r1, int r2)
{
    int *v2 = malloc(sizeof(int) * (r2 - l + 1));

    int k = 0;
    int i = l;
    int j = r1 +1;

    while(i <= r1 && j <= r2)
    {
        //if(less(v[i], v[j]))   // Algoritmo instável por causa desse less
        if(lesseq(v[i], v[j]))   // lesseq garante a estabilidade do algoritmo
            v2[k++] = v[i++];

        else
            v2[k++] = v[j++];
    }

    while(i <= r1)
        v2[k++] = v[i++];
    
    while(j <= r2)
        v2[k++] = v[j++];

    k = 0;

    for(i = l; i <= r2; i++)
        v[i] = v2[k++];

    free(v2);
}

void merge_sort(int *v, int l, int r)
{
    if(l >= r)
        return ;

    int meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);
    merge(v, l, meio, r);
}