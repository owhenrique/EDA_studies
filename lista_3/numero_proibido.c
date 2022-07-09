#include <stdio.h>
#include <stdlib.h>

int busca(int *v, int n, int x);
void merge(int *v, int l, int r1, int r2);
void merge_sort(int *v, int l, int r);

int main(void)
{
    int n, m;

    scanf(" %d", &n);

    int *v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
    {   
        scanf(" %d", &v[i]);
    }

    merge_sort(v, 0, n - 1);

    int x;

    while(scanf(" %d", &x) != EOF)
    {
        int rst;

        rst = busca(v, n, x);

        if(rst == 1)
            printf("sim\n");
        
        if(rst == 0)
            printf("nao\n");          
    }
    
    return 0;
}

int busca(int *v, int n, int x)
{
    int l = 0; 
    int r = n - 1;

    while(l <= r)
    {
        int meio = (r + l) / 2;

        if(v[meio] == x)
            return 1;

        else if(v[meio] < x)
            l = meio + 1;

        else
            r = meio - 1;
    }

    return 0;
}

void merge(int *v, int l, int r1, int r2)
{
    int *v2 = malloc(sizeof(int) * (r2 - l + 1));

    int k = 0;
    int i = l;
    int j = r1 +1;

    while(i <= r1 && j <= r2)
    {
        if(v[i] <= v[j])         // lesseq garante a estabilidade do algoritmo
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

void merge_sort(int *v, int l, int r)
{
    if(l >= r)
        return ;
    
    int meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);
    merge(v, l, meio, r);
}