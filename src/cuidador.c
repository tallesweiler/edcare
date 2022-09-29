#include "../include/cuidador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_cuidador{
    char* nome;
    long int latitude;
    long int longitude;
};

Cuidador* Constroi_cuidador(char* nome){
    Cuidador* cuidador = malloc(sizeof(Cuidador));
    cuidador->nome = malloc(sizeof(char)*strlen(nome)+1);
    strcpy(cuidador->nome, nome);
    cuidador->latitude = 0;
    cuidador->longitude = 0;
    return cuidador;
}

void Destroi_cuidador(Cuidador* cuidador){
    free(cuidador->nome);
    free(cuidador);
}

char* Retorna_nome_cuidador(Cuidador* cuidador){
    return cuidador->nome;
}

long int Retorna_latitude_cuidador(Cuidador* cuidador){
    return cuidador->latitude;
}

void Modifica_latitude_cuidador(Cuidador* cuidador, long int latitude){
    cuidador->latitude = latitude;
}

long int Retorna_longitude_cuidador(Cuidador* cuidador){
    return cuidador->longitude;
}

void Modifica_longitude_cuidador(Cuidador* cuidador, long int longitude){
    cuidador->longitude = longitude;
}

void Atualiza_leituras_cuidador(Cuidador* cuidador, long int latitude, long int longitude){
    Modifica_latitude_cuidador(cuidador, latitude);
    Modifica_longitude_cuidador(cuidador, longitude);
}

