#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a, *b, *c;

    a = malloc(8);

    *a = 1;
    printf("MALLOC:\n");
    printf("%d\n\n", *a);

    b = malloc(sizeof(int) * 3);

    printf("MALLOC VETOR:\n");
    for(int i = 0; i < 3; i++)
    {
        b[i] = i;
        printf("%d%c", b[i], (i == 2 ? '\n' : ' '));
    }
    
    c = calloc(3, sizeof(int));
    
    printf("\nCALLOC:\n");
    for(int i = 0; i < 3; i++)
    {
        printf("%d%c", c[i], (i == 2 ? '\n' : ' '));
    }
    
    c = realloc(c, sizeof(int) * 6);

    printf("\nREALLOC:\n");
    for(int i = 0; i < 6; i++)
    {
        printf("%d%c", c[i], (i == 5 ? '\n' : ' '));
    }

    free(a);
    free(b);
    free(c);

    return 0;
}