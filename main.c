#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arv{
    char info;
    struct arv * esquerda;
    struct arv * direita;

};
typedef struct arv Arvore;

Arvore * inicializarArvore(){
    return NULL;
}

Arvore * criar(char info,Arvore * SAE, Arvore * SAD){
    Arvore * nodo = (Arvore *) malloc(sizeof(Arvore));
    if(nodo != NULL){
        nodo->info = info;
        nodo->esquerda = SAE;
        nodo->direita = SAD;
        printf("Nodo: %c \n",nodo->info);
    }
    return nodo;

}

void inserir(Arvore **no,char letra){
    if(*no == NULL){
        *no =(Arvore *) malloc(sizeof(Arvore));
        *no->esquerda = inicializarArvore();
        *no -> direitra = inicializarArvore();
        *no -> info = letra;
    }
    else{
        if(letra < (*no) -> esquerda){
            inserir(&(*no) ->esquerda,letra);
        }
        else{
            inserir(&(*no) ->direita, letra);
        }
    }
}

int main() {
    Arvore * A = inicializarArvore();

    inserir(&A,'c');
    /*Arvore * D = criar('d',inicializarArvore(),inicializarArvore());
    Arvore * E = criar('e',inicializarArvore(),inicializarArvore());
    Arvore * F = criar('f',inicializarArvore(),inicializarArvore());
    Arvore * B = criar('b',inicializarArvore(),D);
    Arvore * C = criar('c',E,F);
    A = criar('a',B,C);*/


    return 0;
}
