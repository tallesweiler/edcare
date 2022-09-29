#include "../include/idoso.h"

#include "../include/cuidador.h"
#include "../include/lista_idoso.h"
#include "../include/lista_cuidador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct st_idoso{
    char* nome;
    long int latitude;
    long int longitude;
    float temperatura;
    int febres_seguidas;
    int queda;
    Lista_idoso* amigos;
    Lista_cuidador* cuidadores;
};

Idoso* Constroi_idoso(char* nome){
    Idoso* idoso = malloc(sizeof(Idoso));
    idoso->nome = malloc(sizeof(char)*strlen(nome)+1);
    strcpy(idoso->nome, nome);
    idoso->latitude = 0;
    idoso->longitude = 0;
    idoso->temperatura = 0;
    idoso->febres_seguidas = 0;
    idoso->queda = 0;
    idoso->amigos = Inicializa_lista_idoso();
    idoso->cuidadores = Inicializa_lista_cuidador();
    return idoso;
}

void Destroi_idoso(Idoso* idoso){
    free(idoso->nome);
    Destroi_lista_idoso(idoso->amigos);
    Destroi_lista_cuidador(idoso->cuidadores);
    free(idoso);
}

void Insere_amigo_idoso(Idoso* idoso, Idoso* amigo){
    idoso->amigos = Insere_lista_idoso(idoso->amigos, amigo);
}

void Remove_amigo_idoso(Idoso* idoso, char* nome){
    if(Encontra_lista_idoso(idoso->amigos, nome) != NULL){
        idoso->amigos = Remove_lista_idoso(idoso->amigos, nome);
    }
}

void Insere_cuidador_idoso(Idoso* idoso, Cuidador* cuidador){
    idoso->cuidadores = Insere_lista_cuidador(idoso->cuidadores, cuidador);
}

char* Retorna_nome_idoso(Idoso* idoso){
    return idoso->nome;
}

long int Retorna_latitude_idoso(Idoso* idoso){
    return idoso->latitude;
}

void Modifica_latitude_idoso(Idoso*idoso, long int latitude){
    idoso->latitude = latitude;
}

long int Retorna_longitude_idoso(Idoso* idoso){
    return idoso->longitude;
}

void Modifica_longitude_idoso(Idoso* idoso, long int longitude){
    idoso->longitude = longitude;
}

float Retorna_temperatura_idoso(Idoso* idoso){
    return idoso->temperatura;
}

void Modifica_temperatura_idoso(Idoso* idoso, float temperatura){
    idoso->temperatura = temperatura;
}

int Retorna_febres_seguidas_idoso(Idoso* idoso){
    return idoso->febres_seguidas;
}

void Modifica_febres_seguidas_idoso(Idoso* idoso, int febres_seguidas){
    idoso->febres_seguidas = febres_seguidas;
}

int Retorna_queda_idoso(Idoso* idoso){
    return idoso->queda;
}

void Modifica_queda_idoso(Idoso* idoso, int queda){
    idoso->queda = queda;
}

void Atualiza_leituras_idoso(Idoso* idoso, long int latitude, long int longitude, float temperatura, int queda){
    Modifica_latitude_idoso(idoso, latitude);
    Modifica_longitude_idoso(idoso, longitude);
    Modifica_temperatura_idoso(idoso, temperatura);
    Modifica_queda_idoso(idoso, queda);
}

Lista_idoso* Retorna_amigos_idoso(Idoso* idoso){
    return idoso->amigos;
}

Idoso* Encontra_amigo_menos_distante_idoso(Idoso* idoso){
    int i = 0;
    float menor_distancia;
    Idoso* amigo_menos_distante = NULL;
    Lista_idoso* lista_temp = idoso->amigos;
    while(lista_temp != NULL){
        Idoso* amigo = Retorna_idoso(lista_temp);
        double distancia = pow(Retorna_latitude_idoso(idoso) - Retorna_latitude_idoso(amigo),2) + pow(Retorna_longitude_idoso(idoso) - Retorna_longitude_idoso(amigo), 2);
        if(i == 0){
            menor_distancia = distancia;
            amigo_menos_distante = amigo;
        }
        else if(distancia < menor_distancia){
            menor_distancia = distancia;
            amigo_menos_distante = amigo;
        }
        i++;
        lista_temp = Retorna_prox_lista_idoso(lista_temp);
    }
    return amigo_menos_distante;
}

Lista_cuidador* Retorna_cuidadores_idoso(Idoso* idoso){
    return idoso->cuidadores;
}

Cuidador* Encontra_cuidador_menos_distante_idoso(Idoso* idoso){
    int i = 0;
    float menor_distancia;
    Cuidador* cuidador_menos_distante;

    Lista_cuidador* lista_temp = idoso->cuidadores;
    while(lista_temp != NULL){
        Cuidador* cuidador = Retorna_cuidador(lista_temp);
        float distancia = pow(Retorna_latitude_idoso(idoso) - Retorna_latitude_cuidador(cuidador),2) + pow(Retorna_longitude_idoso(idoso) - Retorna_longitude_cuidador(cuidador), 2);
        if(i == 0){
            menor_distancia = distancia;
            cuidador_menos_distante = cuidador;
        }
        else if(distancia < menor_distancia){
            menor_distancia = distancia;
            cuidador_menos_distante = cuidador;
        }
        i++;
        lista_temp = Retorna_prox_lista_cuidador(lista_temp);
    }
    return cuidador_menos_distante;
}