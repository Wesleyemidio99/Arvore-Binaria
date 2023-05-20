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
        (*no) ->esquerda = inicializarArvore();
        (*no) -> direita = inicializarArvore();
        (*no) -> info = letra;
    }
    else{
        if(letra < (*no) -> info){
            inserir(&(*no) ->esquerda,letra);
        }
        else{
            inserir(&(*no) ->direita, letra);
        }
    }
}
bool vazia(Arvore * PA){
    return PA == NULL;
}

void imprimir(Arvore * pA){
    if(!vazia(pA)){
        printf("%c ", pA->info);
        imprimir(pA->esquerda);
        imprimir(pA->direita);
    }
}

int altura(Arvore * PA){
    if(PA == NULL){
       return -1;
    }
    else{
        int esq = altura(PA->esquerda);
        int dir = altura(PA->direita);
        if(esq > dir){
            return esq ;
        }
        else{
            return dir +1;
        }

    }
}

int main() {
    Arvore *A = inicializarArvore();

    inserir(&A, 'c');
    inserir(&A, 'b');
    inserir(&A, 'd');
    inserir(&A, 'a');
    inserir(&A, 'e');
    inserir(&A, 'f');



    printf("Arvore Binaria\n\n");
    imprimir(A);
    printf("\nAltura da Arvore = %d",altura(A));

    /*Arvore * D = criar('d',inicializarArvore(),inicializarArvore());
    Arvore * E = criar('e',inicializarArvore(),inicializarArvore());
    Arvore * F = criar('f',inicializarArvore(),inicializarArvore());
    Arvore * B = criar('b',inicializarArvore(),D);
    Arvore * C = criar('c',E,F);
    A = criar('a',B,C);*/


    return 0;
}
