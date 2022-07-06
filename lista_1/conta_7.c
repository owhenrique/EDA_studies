#include <stdio.h>
#include <stdlib.h>


int conta7(char string[], int i){
    if(string[i] == '\0')
        return 0;

    return(string[i] == '7') + conta7(string, i+1);
}

int main(){

    char string[20];
    scanf("%s", string);

    int n_digitos = conta7(string, 0);

    printf("%d\n", n_digitos);

    return 0;
}