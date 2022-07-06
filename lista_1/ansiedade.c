#include <stdio.h>
#include <string.h>

int main(void){

    char perguntas[4];
    int contador = 0, triagem = 0, formulario = 0;

    while(scanf("%s", perguntas) != EOF){
        if(formulario > 9){
            contador = 0;
            formulario = 0;
        }
        
        if(strcmp(perguntas, "sim") == 0)
            contador++;

        if(formulario == 9){
            if(contador >= 2){
                triagem++;
                contador = 0;
            }
        }

        formulario++;
    }

    printf("%d\n", triagem);

    return 0;
}