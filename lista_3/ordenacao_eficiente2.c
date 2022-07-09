#include <stdio.h>
#include <stdlib.h>

void imprime(int *v, int tam);
void merge(int *pv, int npv, int *sv, int nsv);
void merge_sort(int *v, int n);

int main(void)
{
    int n = 0;

    int *v = malloc(sizeof(int) * 100000);

    while(scanf(" %d", &v[n]) != EOF)
        n++;
    
    //imprime(v, n);

    merge_sort(v, n);

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

void merge(int *pv, int npv, int *sv, int nsv)
{
    int *v2 = malloc(sizeof(int) * (npv + nsv));

    int k = 0;
    int i = 0;
    int j = 0;

    while(i < npv && j < nsv)
    {
        if(pv[i] <= sv[j])         // lesseq garante a estabilidade do algoritmo
            v2[k++] = pv[i++];

        else
            v2[k++] = sv[j++];
    }

    while(i < npv)
        v2[k++] = pv[i++];
    
    while(j < nsv)
        v2[k++] = sv[j++];

    k = 0;

    for(i = 0; i < (npv + nsv); i++)
        pv[i] = v2[k++];

    free(v2);
}

void merge_sort(int *v, int n)
{
    if(n < 2)
        return ;
    
    int meio = n / 2;

    merge_sort(v, meio);
    merge_sort(&v[meio], n - meio);
    merge(v, meio, v + meio, n - meio);
}