#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pa, *pb;
    int a, b;

    pa = &a; // pa aponta para a
    pb = &b;

    *pa = 3; // atribui valor para a apartir de pa
    *pb = 5;

    printf("%d\n", a+b);

    return 0;
}