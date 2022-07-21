#include <stdio.h>
#include <stdlib.h>

#define less(a, b) (a < b)
#define exch(a, b) {int t = a; a = b; b = t;}
#define cmpexch(a, b) if(less(b, a)) exch(a, b)

int separa(int *v, int tam);
void quick_sort(int *v, int tam);

int main()
{
    int n;
    scanf(" %d", &n);

    int *v = malloc(sizeof(int) * (2 * n));

    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i]);

    quick_sort(v, n);

    for (int i = 0; i < n; i++)
        printf("%d%c", v[i], " \n"[i == n-1]);

    return 0;
}

int separa(int *v, int tam)
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

void quick_sort(int *v, int tam)
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