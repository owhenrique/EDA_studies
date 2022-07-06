#include <stdio.h>
#include <stdlib.h>

void teste(int *a)
{
    printf("VALOR DE X: %d\n", *a);
    *a = 15+1;
}

void teste_vetor(int *x, int tam)
{
    printf("VETOR: \n");

    for(int i = 0; i < tam; i++)
        printf("%d%c", x[i], (i == tam - 1 ? '\n' : ' '));
    
    x[0] = 0;
    *(x+1) = 1;
    x[2] = 2;
    *(x+3) = 3;
    
    printf("VETOR: \n");
    for(int i = 0; i < tam; i++)
        printf("%d%c", x[i], (i == tam - 1 ? '\n' : ' '));

    printf("\n");
}

void imprime_intervalo(int *ini, int *fim)
{
    int *pos = ini;

    printf("IMPRIMINDO INTERVALO: \n");

    while(pos <= fim)
    {
        printf("%d%c", *pos, (pos == fim ? '\n' : ' '));
        pos++;
    }
}   

int main(void)
{
    int x = 15;
    int v[4] = {1, 2, 3, 4};
    int v2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    teste(&x);
    
    printf("VALOR DE X: %d\n\n", x);
    
    teste_vetor(v, 4);
    teste_vetor(&v[2], 2); // passando um intervalo menor do vetor
    imprime_intervalo(&v2[3], &v2[6]);

    return 0;
}