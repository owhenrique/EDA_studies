#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long
#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define Item unsigned
#define key(x) (x)
#define less(a, b) (a < b)
#define exch(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpexch(a, b) \
    if (less(b, a))   \
    exch(a, b)

int separa(Item *v, int l, int r)
{
    Item pivo = v[r];
    int j = l;

    for(int k = l; k < r; k++)
        if(less(v[k], pivo))
        {
            exch(v[k], v[j]);
            j++;
        }

    exch(v[j], v[r]);

    return j;
}

void quicksort(Item *v, int l, int r)
{
    if (r <= l)
        return;

    cmpexch(v[(l + r) / 2], v[r]);
    cmpexch(v[l], v[(l + r) / 2]);
    cmpexch(v[r], v[(l + r) / 2]);

    int meio = separa(v, l, r);

    quicksort(v, l, meio - 1);
    quicksort(v, meio + 1, r);
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Item t = v[i];

        for (j = i; j > 0 && less(t, v[j - 1]); j--)
            v[j] = v[j - 1];

        v[j] = t;
    }
}

void introsort(Item *v, int l, int r)
{
    quicksort(v, l, r);
    insertionsort(v, l, r);
}

void quickselect(Item *v, int l, int r, int i)
{
    if (i < l || i > r)
        return ;
    
    cmpexch(v[(l + r) / 2], v[r]);
    cmpexch(v[l], v[(l + r) / 2]);
    cmpexch(v[r], v[(l + r) / 2]);

    int meio = separa(v, l, r);

    if (meio > i)
        quickselect(v, l, meio - 1, i);

    else if (meio < i)
        quickselect(v, meio + 1, r, i);
}


int main()
{
    int n, p, x;

    scanf(" %d %d %d", &n, &p, &x);

    unsigned *v = malloc(n * sizeof(unsigned));

    for (int i = 0; i < n; i++)
        scanf(" %u", &v[i]);

    quickselect(v, 0, n - 1, min(n - 1, p * x));
    quickselect(v, 0, n - 1, min(n - 1, (p + 1) * x - 1));
    quicksort(v, min(n - 1, p * x), min(n - 1, (p + 1) * x - 1));

    for (int i = p * x; i < min(n, (p + 1) * x); i++)
        printf("%u\n", v[i]);

    return 0;
}