#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    short int *px, *py;
    short int *pw, *pz;

    px = &a; // pa aponta para a
    py = &a+1;
    pw = &b;
    pz = &pw[1];

    *px = 3; // atribui valor para a apartir de pa
    *py = 5;
    *pw = 2;
    *pz = 4;

    printf("%d\n", (a = a+b));

    return 0;
}