#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    for(int i = 1, n; scanf("%d", &n) != EOF; i++){
        char *nome = malloc(21);
        int serie = -1;
        int x = 0;

        while(x < n){
            char *string = malloc(21);
            int s;
            scanf("%s %d", string, &s);

            if(serie == -1 || s < serie || (s == serie && strcmp(nome, string) < 0)){
                serie = s;
                strcpy(nome, string);
            }
            x++;
        }
        
        printf("Instancia %d\n", i);
        printf("%s\n\n", nome);

    }

    return 0;
}