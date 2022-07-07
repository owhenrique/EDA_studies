#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 5, b = 3;

    printf("VALORES DE A E B:\n%d %d\n", a, b);

    int *c = &a; 

    int **d = &c; // ponteiro de ponteiro d recebe o valor contido em c (endereço de a)

    **d = 8;
    *d = &b; // ponteiro d que aponta para c recebe o endereço de b
    

    printf("VALORES DE A E B:\n%d %d\n", a, *c);

    *c = 4;

    printf("VALORES DE A E B:\n%d %d\n", a, b);

    return 0;
}