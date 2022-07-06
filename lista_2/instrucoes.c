#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char palavra_chave[16];
} instrucao;

#define inc instrucao

void insercao(inc *v, int n){
    for(int i = n - 1; i > 0; i--){
        if(v[i].codigo < v[0].codigo){
            inc tmp = v[0];
            v[0] = v[i];
            v[i] = tmp;
        }
    }
    for(int j = 2, k; j < n; j++){
        inc tmp = v[j];
        for(k = j; tmp.codigo < v[k - 1].codigo; k--){
            v[k] = v[k - 1];
        }
        v[k] = tmp;
    }
}

char *busca(inc *v, int n, int codigo, int l, int r){
    while(l <= r){
        int meio = (l + r) / 2;
        if(v[meio].codigo == codigo){
            return v[meio].palavra_chave;
        }
        if(v[meio].codigo > codigo){
            r = meio - 1;
        }
        else{
            l = meio + 1;
        }
    }

    return "undefined";
}

int main(void){

    int n, input_codigo;
    scanf(" %d", &n);
    inc *v = (inc*)malloc(n * sizeof(inc));

    for(int i = 0; i < n; i++){
        scanf("%d %s", &v[i].codigo, &v[i].palavra_chave);
    }

    insercao(v, n);

    while(scanf(" %d", &input_codigo) != EOF){
        printf("%s\n", busca(v, n, input_codigo, 0, n - 1));
    }

    return 0;
}