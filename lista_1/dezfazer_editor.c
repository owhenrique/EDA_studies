#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    struct no *prox_no;
    char *string;
} no;

typedef struct {
    int tam;
    no *p;
} pilha_st;

void cria_pilha(pilha_st *p){
    p->tam = 0;
    p->p = NULL;
}

int pilha_vazia(pilha_st *p){
    if(p->tam == 0)
        return 1;
    else 
        return 0;
}

char *desempilha(pilha_st *p){
    char *ret = p->p->string;
    no *x = p->p;
    p->p = p->p->prox_no;
    free(x);
    p->tam--;
    return ret;
}

int empilha(pilha_st *p, char *texto){
    no *x = malloc(sizeof(no));
    if (x == NULL)
        return 0;

    x->string = texto;
    x->prox_no = p->p;
    p->p = x;
    p->tam++;
    return 1;
}


int main(void){

    char comando[9];
    pilha_st pilha;
    cria_pilha(&pilha);

    while(scanf(" %s", comando) != EOF){

        if(strcmp(comando, "desfazer") == 0){
            if((pilha_vazia(&pilha)) == 0){
                printf("%s\n", desempilha(&pilha));
            }
            
            else{
                printf("NULL\n");
            }

        }

        if(strcmp(comando, "inserir") == 0){
            char *texto = malloc(101);
            scanf(" %[^\n]", texto);
            empilha(&pilha, texto);

        }

    }

    return 0;
}