#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    unsigned long long ind;
    unsigned long long ant;
    unsigned long long prox;
} Item;

int busca(Item *v, int n, unsigned long long x);
void merge(Item *v, int l, int r1, int r2);
void merge_sort(Item *v, int l, int r);
void imprime_ant(Item *v, int n, unsigned long long x);
void imprime_prox(Item *v, int n, unsigned long long x);
void imprime(Item *v, int n, unsigned long long x, unsigned long long y);

int main(void)
{
    int n = 0;
    
    Item *v = malloc(sizeof(Item) * 250001);

    while(scanf(" %llx %llx %llx", &v[n].ind, &v[n].ant, &v[n].prox) != 3)
        n++;

    merge_sort(v, 0, n - 1);

    Item i1 = v[0], i2 = v[1];

    v[busca(v, n, i1.ant)].prox = i2.prox;
    v[busca(v, n, i2.prox)].ant = i1.ant;

    imprime_ant(v, n, i1.ant);
    imprime_prox(v, n, i2.prox);

    printf("\n");

    imprime(v, n, i1.ind, i2.prox);

    return 0;
}

int busca(Item *v, int n, unsigned long long x)
{
    int l = 0; 
    int r = n - 1;

    while(l <= r)
    {
        int meio = (r + l) / 2;

        if(v[meio].ind == x)
            return meio;

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

void imprime_ant(Item *v, int n, unsigned long long x)
{
    int bsc = busca(v, n, x);

    for(int i = 0; i < n; i++)
    {
        if(bsc != -1 || v[bsc].ind != 0)
            printf("%llx %llx %llx\n", v[bsc].ind, v[bsc].ant, v[bsc].prox);
    }

}

void imprime_prox(Item *v, int n, unsigned long long x)
{
    int bsc = busca(v, n, x);
    
    for(int i = 0; i < n; i++)
    {
        if(bsc != -1 || v[bsc].ind != 0)
            printf("%llx %llx %llx\n", v[bsc].ind, v[bsc].ant, v[bsc].prox);
    }
}
void imprime(Item *v, int n, unsigned long long x, unsigned long long y)
{
    int bsc = busca(v, n, x);
    
    for(int i = 0; i < n; i++)
    {
        if(bsc != -1 || v[bsc].ind != y)
            printf("%llx\n", v[bsc].ind);
    }
}