#if !defined(LISTA_CUIDADOR_H)
#define LISTA_CUIDADOR_H

#include "cuidador.h"

/*INICIALIZA UMA LISTA VAZIA (NAO ALOCA MEMORIA)*/
Lista_cuidador* Inicializa_lista_cuidador();
/*PERCORRE E LIBERA A MEMORIA DE TODAS AS LISTAS (NAO LIBERA OS CUIDADORES)*/
void Destroi_lista_cuidador(Lista_cuidador* lista);

/*FUNCOES "GET" DAS VARIAVEIS DE UMA LISTA CUIDADOR*/
Cuidador* Retorna_cuidador(Lista_cuidador* lista);
Lista_cuidador* Retorna_prox_lista_cuidador(Lista_cuidador* lista);
Lista_cuidador* Retorna_anterior_lista_cuidador(Lista_cuidador* lista);

/*INSERE UM CUIDADOR NA LISTA*/
Lista_cuidador* Insere_lista_cuidador(Lista_cuidador* lista, Cuidador* cuidador);
/*BUSCA O NOME NA LISTA E RETORNA A CELULA DA LISTA QUE CONTEM O CUIDADOR*/
Lista_cuidador* Encontra_lista_cuidador(Lista_cuidador* lista, char* nome);

/*IMPRIME TODOS OS CUIDADORES DA LISTA*/
void Imprime_lista_cuidador(Lista_cuidador* lista);

#endif
