#include "../include/lista_cuidador.h"

#include "../include/cuidador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_lista_cuidador{
    Cuidador* cuidador;
    Lista_cuidador* prox;
    Lista_cuidador* anterior;
};

Lista_cuidador* Inicializa_lista_cuidador(){
    return NULL;
}

void Destroi_lista_cuidador(Lista_cuidador* lista){
    if(lista == NULL){
        printf("ERRO: Lista vazia!\n");
        return;
    }
    Lista_cuidador* lista_temp = lista;
    Lista_cuidador* lista_temp_prox = NULL;
    /*PERCORRE A LISTA*/
    while(lista_temp != NULL){
        lista_temp_prox = lista_temp->prox;
        free(lista_temp);
        lista_temp = lista_temp_prox;
    }
}

Lista_cuidador* Insere_lista_cuidador(Lista_cuidador* lista, Cuidador* cuidador){
    Lista_cuidador* nova_lista = malloc(sizeof(Lista_cuidador));
    nova_lista->cuidador = cuidador;
    nova_lista->prox = NULL;
    
    /*CASO A LISTA ESTEJA VAZIA*/
    if(lista == NULL){
        lista = nova_lista;
        lista->anterior = NULL;
    }
    else{
        Lista_cuidador* lista_temp = lista;
        
        /*PROCURA O ULTIMO ELEMENTO DA LISTA*/
        while(lista_temp->prox != NULL){
            lista_temp = lista_temp->prox;
        }
        /*INSERE A NOVA LISTA*/
        lista_temp->prox = nova_lista;
        nova_lista->anterior = lista_temp;
    }
    return lista;
}

Lista_cuidador* Encontra_lista_cuidador(Lista_cuidador* lista, char* nome){
    Lista_cuidador* lista_temp = lista;
    while(lista_temp != NULL && strcmp(Retorna_nome_cuidador(lista_temp->cuidador), nome) != 0){
        lista_temp = lista_temp->prox;
    }
    if(lista_temp == NULL){
        printf("ERRO: Cuidador nao encontrado!\n");
        return NULL;
    }
    return lista_temp;
}

Cuidador* Retorna_cuidador(Lista_cuidador* lista){
    return lista->cuidador;
}

Lista_cuidador* Retorna_prox_lista_cuidador(Lista_cuidador* lista){
    return lista->prox;
}
Lista_cuidador* Retorna_anterior_lista_cuidador(Lista_cuidador* lista){
    return lista->anterior;
}

void Imprime_lista_cuidador(Lista_cuidador* lista){
    Lista_cuidador* lista_temp = lista;
    while(lista_temp != NULL){
        printf("%s\n", Retorna_nome_cuidador(lista_temp->cuidador));
        lista_temp = lista_temp->prox;
    }
    printf("\n");
}