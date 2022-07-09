#include <stdio.h>
#include <stdlib.h>

int busca(int *v, int n, int x);

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    int *v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
        scanf(" %d", &v[i]);

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

int busca(int *v, int n, int x)
{
    int l = 0; 
    int r = n - 1;

    while(l <= r)
    {
        int meio = (r + l) / 2;

        if(v[meio] == x)
            return meio;

        else if(v[meio] < x)
            l = meio + 1;

        else
            r = meio - 1;
    }

    return l;
}