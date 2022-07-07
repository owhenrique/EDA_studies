#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

void imprime(int *v, int tam);
void insertion_sort(int *v, int l, int r);
void insertion_sort2(int *v, int l, int r);

int main(void)
{
    int v[6];

    srand(time(NULL));

    for(int i = 0; i <= 5; i++)
    {
        v[i] = rand() % 99;
    }

    imprime(v, 6);

    insertion_sort2(v, 0, 5);

    imprime(v, 6);

    return 0;
}

void imprime(int *v, int tam)
{   
    printf("VETOR:\n");
    for(int i = 0; i < tam; i++)
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
}

void insertion_sort(int *v, int l, int r)
{
    for(int i = l + 1; i <= r; i++)
    {
        for(int j = i; j > l; j--)
            cmpexch(v[j - 1], v[j]);
    }
}

void insertion_sort2(int *v, int l, int r)
{
    for(int i = r; i >= l; i--)
        cmpexch(v[i - 1], v[i]);

    for(int i = l + 2; i <= r; i++)
    {
        int j = i;
        int tmp = v[j];

        while(less(tmp, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }

        v[j] = tmp;
    }
}