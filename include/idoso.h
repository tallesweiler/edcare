#if !defined (IDOSO_H)
#define IDOSO_H

#include "cuidador.h"

typedef struct st_idoso Idoso;
typedef struct st_lista_idoso Lista_idoso;

/*ALOCA MEMORIA PARA UM IDOSO*/
Idoso* Constroi_idoso(char* nome);
/*LIBERA MEMORIA DE UM IDOSO (NAO LIBERA OS AMIGOS NEM CUIDADORES)*/
void Destroi_idoso(Idoso* idoso);

/*FUNCOES "SET" DAS VARIAVEIS DE UM IDOSO*/
void Modifica_latitude_idoso(Idoso*idoso, long int latitude);
void Modifica_longitude_idoso(Idoso* idoso, long int longitude);
void Modifica_temperatura_idoso(Idoso* idoso, float temperatura);
void Modifica_febres_seguidas_idoso(Idoso* idoso, int febres_seguidas);
void Modifica_queda_idoso(Idoso* idoso, int queda);
void Atualiza_leituras_idoso(Idoso* idoso, long int latitude, long int longitude, float temperatura, int queda);

/*FUNCOES "GET" DAS VARIAVEIS DE UM IDOSO*/
char* Retorna_nome_idoso(Idoso* idoso);
long int Retorna_latitude_idoso(Idoso* idoso);
long int Retorna_longitude_idoso(Idoso* idoso);
float Retorna_temperatura_idoso(Idoso* idoso);
int Retorna_febres_seguidas_idoso(Idoso* idoso);
int Retorna_queda_idoso(Idoso* idoso);
Lista_idoso* Retorna_amigos_idoso(Idoso* idoso);
Lista_cuidador* Retorna_cuidadores_idoso(Idoso* idoso);

/*ADICIONA UM OUTRO IDOSO (AMIGO) NA LISTA DE AMIGOS DO IDOSO*/
void Insere_amigo_idoso(Idoso* idoso, Idoso* amigo);
/*BUSCA O NOME NA LISTA DE AMIGOS DO IDOSO E REMOVE O AMIGO (OUTRO IDOSO)*/
void Remove_amigo_idoso(Idoso* idoso, char* nome);
/*ADICIONA UM CUIDADOR NA LISTA DE CUIDADORES DO IDOSO*/
void Insere_cuidador_idoso(Idoso* idoso, Cuidador* cuidador);

/*PERCORRE TODOS OS IDOSOS DA LISTA DE AMIGOS DO IDOSO E RETORNA O MENOS DISTANTE*/
Idoso* Encontra_amigo_menos_distante_idoso(Idoso* idoso);
/*PERCORRE TODOS OS CUIDADORES DA LISTA DE CUIDADORES E RETORNA O MENOS DISTANTE*/
Cuidador* Encontra_cuidador_menos_distante_idoso(Idoso* idoso);

#endif