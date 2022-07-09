#include <stdio.h>
#include <stdlib.h>

void imprime(int *v, int tam);
void merge(int *v, int l, int r1, int r2);
void merge_sort(int *v, int l, int r);

int main(void)
{
    int n = 0;

    scanf("%d", &n);

    int *v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
        scanf(" %d", &v[i]);

    //imprime(v, n);

    merge_sort(v, 0, n - 1);

    imprime(v, n);

    free(v);

    return 0;
}

void imprime(int *v, int tam)
{   
    //printf("VETOR:\n");
    for(int i = 0; i < tam; i++)
        printf("%d%c", v[i], (i == tam - 1 ? '\n' : ' '));
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