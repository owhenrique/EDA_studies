#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define less(a, b) (a < b)
#define exch(a, b) {Dado t = a; a = b; b = t;}
#define cmpexch(a, b) if(less(b, a)) exch(a, b)

typedef struct Dado
{
    int qtd;
    int pos;
    char ctr;
} Dado;

int separa(Dado *v, int tam);
void quick_sort(Dado *v, int tam);

int main(void)
{
    char *v = malloc(sizeof(char) * 100001);

    scanf(" %s", v);

    int tam = strlen(v);

    struct Dado sequencia[tam];

    int k = 0;

    sequencia[k].qtd = 0;

    int j = 0;

    for(int i = 0; i < tam; i++)
    {
        if(v[j] != v[i])
        {
            j = i;
            k++;
            sequencia[k].qtd = 0;
        }
        sequencia[k].qtd++;
        sequencia[k].pos = j;
        sequencia[k].ctr = v[j];
    }

    quick_sort(sequencia, k + 1);

    for(int i = k; i >= 0; i--)
        printf(" %d %c %d\n", sequencia[i].qtd, sequencia[i].ctr, sequencia[i].pos);

    return 0;
}

int separa(Dado *v, int tam)
{
    int l = -1, r = tam - 1;
    int pivo = v[r];

    while (1)
    {
        while (less(v[++l], pivo));
        while (less(pivo, v[--r]) && r > l);

        if (l >= r)
            break;

        exch(v[l], v[r]);
    }
    
    exch(v[l], v[tam - 1]);
    return l;
}

void quick_sort(Dado *v, int tam)
{
    if (tam < 2)
        return;

    exch(v[(tam - 1) / 2], v[tam - 2]);
    
    cmpexch(v[0], v[tam - 2]);
    cmpexch(v[0], v[tam - 1]);
    cmpexch(v[tam - 2], v[tam - 1]);

    int meio = separa(v, tam - 1);

    quick_sort(v, meio);
    quick_sort(v + meio + 1, tam - meio - 1);
}