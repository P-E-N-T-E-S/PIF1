#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "keyboard.h"

int bolaX = 5;
int bolaY = 5;
int velocidadeX = 1;
int velocidadeY = 1;
int seg = 30;
int mim = 1;
int temp = 0;
int pass = 0;
struct pontuacao player;



void Tela() {
    LimparTela();

    printf("\t\t\t\t\t %d | %d \n\n", player.player1, player.player2);

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            if (j == 0 || j == largura - 1) {
                printf("░");
            } else if ((i == 0 || i == altura - 1) && (j > 0 && j < largura - 1)) {
                printf("░");
            } else if (j == 2 && (i >= barraEsquerda - 2 && i <= barraEsquerda + 2)) {
                printf("█");
            } else if (j == largura - 3 && (i >= barraDireita - 2 && i <= barraDireita + 2)) {
                printf("█");
            } else if (i == (int)bolaY && j == (int)bolaX) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    Tempo();
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

    if (bolaX <= 0) {
        player.player2++;
        velocidadeX = -velocidadeX;
    }

    if (bolaX >= largura - 1) {
        player.player1++;
        velocidadeX = -velocidadeX;
    }

    if (bolaY <= 0 || bolaY >= altura - 1) {
        velocidadeY = -velocidadeY;
    }

    if (bolaX == 2) {
        if (bolaY >= barraEsquerda - 2 && bolaY <= barraEsquerda + 2) {
            velocidadeX = -velocidadeX;
        }
    }

    if (bolaX == largura - 3 && (bolaY >= barraDireita - 2 && bolaY <= barraDireita + 2)) {
        velocidadeX = -velocidadeX;
    }
}

void LimparTela() {
    system("clear");
}

void Tempo(){
    
    temp++;

    if (temp % 10 == 0) {
        seg--;
    }

    if (mim == 0 && seg == 0) {
        printf("O tempo acabou !");
        keyboardDestroy();
        exit(1);
    }
    printf("\n\t\t\t\t\t %02d:%02d\n\n", mim, seg);

    if (seg == 0) {
        mim--;
        seg = seg + 60;
    }

    if (temp == 300) {
        pass = 1;
        velocidadeX *= 2;
    }
  
    if (temp == 600) {
        pass = 2;
        velocidadeX /= 2;
    }
}

