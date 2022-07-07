#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

void imprime(int *v, int tam);
void bubble_sort(int *v, int l, int r);
void bubble_sort_recursivo(int *v, int l, int r);

int main(void)
{
    int v[6];

    srand(time(NULL));

    for(int i = 0; i <= 5; i++)
    {
        v[i] = rand() % 99;
    }

    imprime(v, 6);

    bubble_sort(v, 0, 5);

    imprime(v, 6);

    return 0;
}

void imprime(int *v, int tam)
{   
    printf("VETOR:\n");
    for(int i = 0; i < tam; i++)
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
}

void bubble_sort(int *v, int l, int r)
{
    for(int i = l; i < r; i++)
    {   
        for(int j = l; j < r; j++)
            cmpexch(v[j], v[j+1]);
        //imprime(v, 6);
    }
}

void bubble_sort_recursivo(int *v, int l, int r)
{
    if(l == r)
        return;

    for(int j = l; j < r; j++)
    {

        cmpexch(v[j], v[j + 1]);

    }

    bubble_sort_recursivo(v, l + 1, r);
}