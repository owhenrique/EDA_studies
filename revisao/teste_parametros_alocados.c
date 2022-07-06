#include <stdio.h>
#include <stdlib.h>

int* alocador(size_t elementos)
{
    int *v;
    
    v = calloc(elementos, sizeof(int));

    if(v == NULL)
        return 1;
    
    return v;
}

void alocador2(int **x, int elementos)
{

    *x = realloc(*x, sizeof(int) * elementos);

    if(*x == NULL)
        printf("ERROR\n");

}

int main(void)
{
    int *a;

    a = alocador(30);

    for(int x = 0; x < 30; x++)
    {
        printf("%d%c", a[x], (x == 29 ? '\n' : ' '));
    }

    alocador2(&a, 5);

    for(int x = 0; x < 5; x++)
    {
        a[x] = 1;
        printf("%d%c", a[x], (x == 4 ? '\n' : ' '));
    }

    free(a);

    return 0;
}