#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define Item struct Elemento
#define key(x) (x.jp)
#define less(a, b) (strcmp(key(a), key(b)) < 0)
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) if(less(b, a)) exch(a, b)
#define less_key(a, k) (strcmp(key(a), k) < 0)
#define eq_key(a, k) (strcmp(key(a), k) == 0)

struct Elemento
{
    char jp[82];
    char br[82];
};

int separa(Item *v, int l, int r);
void quick_sort_mediana(Item *v, int l, int r);
void insertion_sort(Item *v, int l, int r);
void intro_sort(Item *v, int l, int r);
int busca(Item *v, int l, int r, char *x);
void traduz();

Item v[1000001];

int main()
{
    int t;
    scanf(" %d", &t);

    while (t--)
        traduz();

    return 0;
}

int separa(Item *v, int l, int r)
{
    Item pivo = v[r];

    int j = l;

    for(int k = l; k < r; k++)
    {
        if(less(v[k], pivo))
        {
            exch(v[k], v[j]);
            j++;
        }
    }

    exch(v[j], v[r]);
    
    return j;
}

void quick_sort_mediana(Item *v, int l, int r)
{
    if (r - l <= 32)
        return;

    exch(v[(l + r) / 2], v[r - 1]);;
    
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int meio = separa(v, l, r);

    quick_sort_mediana(v, l, meio - 1);
    quick_sort_mediana(v, meio + 1, r);
}

void insertion_sort(Item *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Item tmp = v[i];

        for (j = i; j > 0 && less(tmp, v[j - 1]); j--)
            v[j] = v[j - 1];

        v[j] = tmp;
    }
}

void intro_sort(Item *v, int l, int r)
{
    quick_sort_mediana(v, l, r);
    insertion_sort(v, l, r);
}

int busca(Item *v, int l, int r, char *x)
{
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (eq_key(v[m], x))
            return m;

        else if (less_key(v[m], x))
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

void traduz()
{
    int m, n;
    scanf(" %d %d\n", &m, &n);

    for (int i = 0; i < m; i++)
    {
        gets(v[i].jp);
        gets(v[i].br);
    }

    intro_sort(v, 0, m - 1);

    while (n--)
    {
        char entrada[81];
        gets(entrada);

        char *palavra;

        palavra = strtok(entrada, " ");

        while (palavra != NULL)
        {
            int pos = busca(v, 0, m - 1, palavra);

            printf("%s", (pos != -1 ? v[pos].br : palavra));

            palavra = strtok(NULL, " ");

            printf("%c", " \n"[palavra == NULL]);
        }
    }

    printf("\n");
}