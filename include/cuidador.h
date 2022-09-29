#if !defined (CUIDADOR_H)
#define CUIDADOR_H

typedef struct st_cuidador Cuidador;
typedef struct st_lista_cuidador Lista_cuidador;

/*ALOCA MEMORIA PARA UM CUIDADOR*/
Cuidador* Constroi_cuidador(char* nome);
/*LIBERA MEMORIA DE UM CUIDADOR*/
void Destroi_cuidador(Cuidador* cuidador);

/*FUNCOES "SET" DAS VARIAVEIS DE UM CUIDADOR*/
void Modifica_latitude_cuidador(Cuidador* cuidador, long int latitude);
void Modifica_longitude_cuidador(Cuidador* cuidador, long int longitude);
void Atualiza_leituras_cuidador(Cuidador* cuidador, long int latitude, long int longitude);

/*FUNCOES "GET" DAS VARIAVEIS DE UM CUIDADOR*/
char* Retorna_nome_cuidador(Cuidador* cuidador);
long int Retorna_latitude_cuidador(Cuidador* cuidador);
long int Retorna_longitude_cuidador(Cuidador* cuidador);

#endif
