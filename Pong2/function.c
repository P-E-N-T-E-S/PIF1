#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int bolaX = 5;
int bolaY = 5;
int velocidadeX = 1;
int velocidadeY = 1;


void Tela() {
    LimparTela();

    for(int i = 0; i < largura; i++) {
        printf("░");
    }
    printf("\n");

    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {
            if(j == 0 || j == largura - 1) {
                printf("░");
            }
            else if(i == bolaY && j == bolaX) {
                printf("O");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for(int i = 0; i < largura; i++) {
        printf("░");
    }
    printf("\n");
}

void EscreverArquivo(FILE* arquivo, pontuacao players){  
    fprintf(arquivo, "Player 1: %d\n", players.player1);
    fprintf(arquivo, "Player 2: %d\n", players.player2);
}

void PrintPontos(pontuacao pontos){
    printf("\n\t titulo: %d\n", pontos.player1);
    printf("\tAutor: %d\n", pontos.player2);
    puts("==================================");
}

void AtualizarBola() {

    bolaX += velocidadeX;
    bolaY += velocidadeY;

    if(bolaX <= 0 || bolaX >= largura - 1) {
        velocidadeX = -velocidadeX;
    }
    if(bolaY <= 0 || bolaY >= altura - 1) {
        velocidadeY = -velocidadeY;
    }
}


void LimparTela() {
    system("clear");
}