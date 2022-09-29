#include "../include/apoio.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("ERRO: Quantidade de leituras nao informada!\n");
        return 1;
    }
    int i, qtd_leituras = atoi(argv[1]);
    
    /*EFETUA A LEITURA DOS ARQUIVOS APOIO.TXT E CUIDADORES.TXT*/
    Apoio* equipe = Inicializa_apoio();
    Carrega_idosos_apoio(equipe);
    Carrega_cuidadores_apoio(equipe);
    
    /*ATUALIZA E VERIFICA AS INFORMACOES DE CADA IDOSO EM CADA MOMENTO*/
    for(i = 0; i < qtd_leituras; i++){
        Atualiza_idosos_apoio(equipe, i);
        Atualiza_cuidadores_apoio(equipe, i);
        Verifica_idosos_apoio(equipe);
    }

    /*LIBERA TODA A MEMORIA ALOCADA*/
    Destroi_apoio(equipe);

    return 0;
}
