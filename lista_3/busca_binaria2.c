#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int ind;
    int pos;
} Item;

int busca(Item *v, int n, int x);
void merge(Item *v, int l, int r1, int r2);
void merge_sort(Item *v, int l, int r);

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    Item *v = malloc(sizeof(Item) * n);

    for(int i = 0; i < n; i++)
    {   
        scanf(" %d", &v[i].ind);
        v[i].pos = i;
    }

    merge_sort(v, 0, n - 1);

    int cont = 0;

    while(cont < m)
    {
        int x, rst;

        scanf(" %d", &x);
        
        rst = busca(v, n, x);
        
        printf("%d\n", rst);
        
        cont++;
    }
    
    return 0;
}

int busca(Item *v, int n, int x)
{
    int l = 0; 
    int r = n - 1;

    while(l <= r)
    {
        int meio = (r + l) / 2;

        if(v[meio].ind == x)
            return v[meio].pos;

        else if(v[meio].ind < x)
            l = meio + 1;

        else
            r = meio - 1;
    }

    return -1;
}

void merge(Item *v, int l, int r1, int r2)
{
    Item *v2 = malloc(sizeof(Item) * (r2 - l + 1));

    int k = 0;
    int i = l;
    int j = r1 +1;

    while(i <= r1 && j <= r2)
    {
        if(v[i].ind <= v[j].ind)         // lesseq garante a estabilidade do algoritmo
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

void merge_sort(Item *v, int l, int r)
{
    if(l >= r)
        return ;
    
    int meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);
    merge(v, l, meio, r);
}