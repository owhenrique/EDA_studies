#include <stdio.h>
#include <stdlib.h>

void imprime(int *v, int tam);
void merge(int *pv, int npv, int *sv, int nsv);

int main(void)
{
    int *v = malloc(sizeof(int) * 800008);
    int *tmpv = malloc(sizeof(int) * 100001);

    int n = 0;

    for(int i = 0; i < 8; i++)
    {
        int tam;

        scanf(" %d", &tam);

        for(int j = 0; j < tam; j++)
            scanf(" %d", &tmpv[j]);
        
        merge(v, n, tmpv, tam);
        n += tam;
    }

    imprime(v, n);

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
        if(pv[i] <= sv[j])         // lesseq garante a estábilidade do algoritmo
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