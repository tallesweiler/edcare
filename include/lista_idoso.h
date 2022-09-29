#if !defined(LISTA_IDOSO_H)
#define LISTA_IDOSO_H

#include "idoso.h"

/*INICIALIZA UMA LISTA VAZIA (NAO ALOCA MEMORIA)*/
Lista_idoso* Inicializa_lista_idoso();
/*PERCORRE E LIBERA A MEMORIA DE TODAS AS LISTAS (NAO LIBERA OS IDOSOS)*/
void Destroi_lista_idoso(Lista_idoso* lista);

/*FUNCOES "GET" DAS VARIAVEIS DE UMA LISTA IDOSO*/
Idoso* Retorna_idoso(Lista_idoso* lista);
Lista_idoso* Retorna_prox_lista_idoso(Lista_idoso* lista);
Lista_idoso* Retorna_anterior_lista_idoso(Lista_idoso* lista);

/*INSERE UM IDOSO NA LISTA*/
Lista_idoso* Insere_lista_idoso(Lista_idoso* lista, Idoso* idoso);
/*BUSCA O NOME NA LISTA E REMOVE O IDOSO*/
Lista_idoso* Remove_lista_idoso(Lista_idoso* lista, char* nome);
/*BUSCA O NOME NA LISTA E RETORNA A CELULA DA LISTA QUE CONTEM O IDOSO*/
Lista_idoso* Encontra_lista_idoso(Lista_idoso* lista, char* nome);

/*IMPRIME TODOS OS IDOSOS DA LISTA*/
void Imprime_lista_idoso(Lista_idoso* lista);
/*IMPRIME TODOS OS IDOSOS DA LISTA, INCLUINDO SUA LISTA DE AMIGOS E DE CUIDADORES*/
void Imprime_lista_detalhada_idoso(Lista_idoso* lista);

#endif