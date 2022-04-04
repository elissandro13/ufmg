#include <stdio.h>
#include <stdlib.h>

#define TAM 8 

//nao mude a ordem do struct!!!
typedef struct Jogador {

	int id;
	int num_blocos;
	int num_navios;
	int T[TAM][TAM];	

} Jogador;

int gerarNum(int min, int max){

    return min + (rand() % (max - min + 1));
}
//1
void initJogador(Jogador *jogador, int id, int num_blocos) {


    jogador->id = id;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
           jogador->T[i][j] = 0;
        }
        
    }
    jogador->num_navios = 0;

    if(jogador->num_blocos <= 0 || jogador->num_blocos > TAM*TAM) jogador->num_blocos = 20;
    

}

//2
int checarTabuleiro(Jogador *jogador, int linha, int col_ini, int tam) {

    for (int j = col_ini; j < col_ini + tam; j++)
    {
        if(jogador->T[linha][col_ini+j] != 0) return 0;
    }
    
    return 1;
}

void preencheNavio(Jogador *jogador, int linha, int col_ini, int tam) {

    for (int j = col_ini; j < col_ini + tam; j++)
    {
        jogador->T[linha][col_ini+j] = 1;
    }

    jogador->num_blocos = jogador->num_blocos - tam;
    jogador->num_navios = jogador->num_navios + 1;

    return;
}

int insereNavio(Jogador *jogador, int linha, int col_ini, int tam) {
    
    if(tam > jogador->num_blocos) return 0;
    else if(linha < 0 || col_ini < 0 || linha >= TAM || col_ini + (tam-1) >= TAM) return 0;

    if(checarTabuleiro(jogador, linha, col_ini, tam) == 1){
            
        preencheNavio(jogador, linha, col_ini, tam);
        return 1;
    }
    
    return 0;
}

//3
void preencheTabuleiro(Jogador *jogador, int modo) {
    
    int linha_inicial = 0;
    int coluna_inicial = 0;
    int tam_navio = 0;
    if (modo == 0){

        while (jogador->num_blocos > 0){

            linha_inicial = 0;
            coluna_inicial = 0;
            tam_navio = 0;

            scanf("%d", &linha_inicial);
            scanf("%d", &coluna_inicial);
            scanf("%d", &tam_navio);

            int status = insereNavio(jogador, linha_inicial, coluna_inicial, tam_navio);
        }
        

    } else {

         while (jogador->num_blocos > 0){

            linha_inicial = 0;
            coluna_inicial = 0;
            tam_navio = 0;

            linha_inicial = gerarNum(0,TAM);
            coluna_inicial = gerarNum(0,TAM);
            tam_navio = gerarNum(1,jogador->num_blocos+1);

            int status = insereNavio(jogador, linha_inicial, coluna_inicial, tam_navio);
        }
    }
    
}

int realizarAtaque(Jogador *defensor, int linha_ataque, int coluna_ataque) {

    if(defensor->T[linha_ataque][coluna_ataque] == 0) return 0;
    else {

        for (int j = coluna_ataque; j != 0 && j < TAM; j++)
        {
            defensor->T[linha_ataque][j] = 0;
        }
        
        defensor->num_navios = defensor->num_navios - 1;
        return 1;
    }

}

//4
int ataca(Jogador *defensor, int modo) {
    

    int linha_ataque = 0;
    int coluna_ataque = 0;
    int status = 0;

    if (modo == 0){


        linha_ataque = 0;
        coluna_ataque = 0;

        scanf("%d", &linha_ataque);
        scanf("%d", &coluna_ataque);

        if(linha_ataque < 0 || linha_ataque >= TAM || coluna_ataque < 0 || coluna_ataque >+ TAM) return 0;

        status = realizarAtaque(defensor, linha_ataque, coluna_ataque);
        
        

    } else {
        
        linha_ataque = gerarNum(0,TAM);
        coluna_ataque = gerarNum(0,TAM);
        status = realizarAtaque(defensor, linha_ataque, coluna_ataque);
        
    }

	return status;
}


// 5
int simulaJogo(int modo, int num_blocos) {
    
    Jogador jogador_1;
    Jogador jogador_2;

    initJogador(&jogador_1, 1, num_blocos);
    initJogador(&jogador_2, 2, num_blocos);
    
    preencheTabuleiro(&jogador_1, modo);
    preencheTabuleiro(&jogador_2, modo);

    while(jogador_1.num_navios > 0 || jogador_2.num_navios > 0){

        ataca(&jogador_2, modo);
        ataca(&jogador_1, modo);
    }
    if(jogador_1.num_navios == 0) return jogador_2.id;
    else return jogador_1.id;
    

    return -1;
}

//6
int classificaFrase(char *frase) {
    //seu código aqui
    return -1;
}

//7
int calculaOperacao(char *string1, char *string2) {
    //seu código aqui
    return -1;
}

void minha_main() {
   
}