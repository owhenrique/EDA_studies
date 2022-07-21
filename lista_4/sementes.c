#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long
#define less_value(a, b) (a.value == b.value ? a.key < b.key : a.value < b.value)
#define less_key(a, b) (a.key == b.key ? a.value < b.value : a.key < b.key)
#define exch(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpexch(a, b) \
    if (less_value(b, a))   \
    exch(a, b)
#define cmpexchkey(a, b) \
    if (less_key(b, a))   \
    exch(a, b)

typedef struct
{
    long long key;
    int value;
} Item;

int separa(Item *v, int l, int r)
{
    Item pivo = v[r];
    int j = l;

    for(int k = l; k < r; k++)
        if(less_key(v[k], pivo))
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

    cmpexchkey(v[(l + r) / 2], v[r]);
    cmpexchkey(v[l], v[(l + r) / 2]);
    cmpexchkey(v[r], v[(l + r) / 2]);

    int meio = separa(v, l, r);

    quicksort(v, l, meio - 1);
    quicksort(v, meio + 1, r);
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Item t = v[i];

        for (j = i; j > 0 && less_key(t, v[j - 1]); j--)
            v[j] = v[j - 1];

        v[j] = t;
    }
}

void introsort(Item *v, int l, int r)
{
    quicksort(v, l, r);
    insertionsort(v, l, r);
}

int separaqs(Item *v, int l, int r)
{
    Item pivo = v[r];
    int j = l;

    for(int k = l; k < r; k++)
        if(less_value(v[k], pivo))
        {
            exch(v[k], v[j]);
            j++;
        }

    exch(v[j], v[r]);

    return j;
}

void quickselect(Item *v, int l, int r, int i)
{
    cmpexch(v[(l + r) / 2], v[r]);
    cmpexch(v[l], v[(l + r) / 2]);
    cmpexch(v[r], v[(l + r) / 2]);

    int meio = separaqs(v, l, r);

    if (meio > i)
        quickselect(v, l, meio - 1, i);

    else if (meio < i)
        quickselect(v, meio + 1, r, i);
}

Item v[10000001];

int main()
{
    int k;
    
    scanf(" %d", &k);
    
    int n;

    for (n = 0; scanf(" %lld %d", &v[n].key, &v[n].value) == 2; n++);

    quickselect(v, 0, n - 1, k - 1);
    quicksort(v, 0, k - 1);

    for (int i = 0; i < k; i++)
        printf("%lld %d\n", v[i].key, v[i].value);

    return 0;
}