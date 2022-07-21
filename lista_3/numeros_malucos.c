#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int r1, int r2);
void merge_sort(int *v, int l, int r);
int reorganiza_v(int *v, int n, int tam);

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int *v = malloc(sizeof(int) * (n * 2));
    
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    merge_sort(v, 0, n - 1);

    int tam = reorganiza_v(v, n, 1);

    if(tam %2 != 0)
        v[tam++] = 1000000000;

    int tam_tmp = 0;

    for (int i = 0; i < tam - 1; i += 2)
        v[tam + tam_tmp++] = v[i] + v[i + 1];

    merge(v, 0, tam, tam_tmp);

    tam = reorganiza_v(v, tam + tam_tmp, 1);

    for(int i = 0; i < tam; i += 4)
        printf("%d\n", v[i]);

    printf("Elementos: %d\n", tam);

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

int reorganiza_v(int *v, int n, int tam)
{
    for(int i = 1; i < n; i++)
    {
        if(v[i] != v[tam - 1])
            v[tam++] = v[i];
    }

    return tam;
}