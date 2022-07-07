#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

void imprime(int *v, int tam);
void selection_sort(int *v, int l, int r);
void selection_sort_interativa(int *v, int l, int r);

int main(void)
{
    int v[6];

    srand(time(NULL));

    for(int i = 0; i <= 5; i++)
    {
        v[i] = rand() % 99;
    }

    imprime(v, 6);

    selection_sort_iterativa(v, 0, 5);

    imprime(v, 6);

    return 0;
}

void imprime(int *v, int tam)
{   
    printf("VETOR:\n");
    for(int i = 0; i < tam; i++)
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
}

void selection_sort(int *v, int l, int r)
{
    if(l == r)
        return ;

    int menor_elem = l;

    for(int j = l+1; j <= r; j++)
    {
        if(less(v[j], v[menor_elem]))
            menor_elem = j;
    }

    exch(v[menor_elem], v[l]);

    //imprime(v, 6);

    selection_sort(v, l+1, r);
}

void selection_sort_iterativa(int *v, int l, int r)
{
    for(int i = l; i < r; i++)
    {
        int menor_elem = i;

        for(int j = i+1; j <= r; j++)
            cmpexch(v[menor_elem], v[j]);
    }

}