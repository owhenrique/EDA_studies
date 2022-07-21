#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

void imprime(int *v, int tam);
int separa(int *v, int l, int r);
void quick_sort(int *v, int l, int r);
void quick_sort_mediana(int *v, int l, int r);

int main(void)
{
    int v[10];

    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        v[i] = rand() % 99;
    }

    imprime(v, 10);

    printf("POSICAO DO PIVO: %d\n", separa(v, 0, 9));

    imprime(v, 10);

    quick_sort_mediana(v, 0, 9);
    
    imprime(v, 10);

    return 0;
}

void imprime(int *v, int tam)
{   
    printf("VETOR:\n");
    for(int i = 0; i < tam; i++)
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
}

int separa(int *v, int l, int r)
{
    int pivô = v[r];
    int j = l;

    for(int k = l; k < r; k++)
    {
        if(lesseq(v[k], pivô))
        {
            exch(v[j], v[k]);
            j++;
        }
    }
    
    exch(v[j], v[r]);

    return j;
}

void quick_sort(int *v, int l, int r)
{
    if(l < r)
    {
        int j = separa(v, l, r);

        quick_sort(v, l, j - 1);

        quick_sort(v, j + 1, r);
    }
}

void quick_sort_mediana(int *v, int l, int r)
{
    if(l < r)
    {   
        cmpexch(v[(l + r) / 2], v[r]);
        cmpexch(v[l], v[(l + r) / 2]);
        cmpexch(v[r], v[(l + r) / 2]);

        int j = separa(v, l, r);

        quick_sort(v, l, j - 1);

        quick_sort(v, j + 1, r);
    }
}