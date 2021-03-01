#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
  char valor;
  char naipe;
  bool foiJogada;
}Carta;

typedef struct{
  Carta carta[52];
}Baralho;

void criaBaralho(Baralho *baralho){ //inicia um novo baralho criando todas as cartas nele contido.

  int i, l, c;
  char naipe[4] = {'P','C','E','O'};
  char valor[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};

  for ( l = 0; l < 4; l++) {
    for ( c = 0; c < 13; c++) {
      i = (13*l)+c;
      baralho->carta[i].valor = valor[c];
      baralho->carta[i].naipe = naipe[l];
      baralho->carta[i].foiJogada = false;
    }//for
  }//for
}// criaBaralho

int cartasNaoJogadas(Baralho *baralho){ //Consulta o numero de cartas disponıveis para jogo.

int disponiveis = 0;

  for (int i = 0; i < 52; i++) {
        if(  baralho->carta[i].foiJogada == false){
          disponiveis++;
        }//if
    }//for
    return(disponiveis);
}//cartasNaoJogadas

Carta topo(Baralho *baralho){ //Consulta a carta do topo de um baralho.

Carta cartaT;

    for (int i = 51; i >= 0; i--) {
            if(  baralho->carta[i].foiJogada == false){
              cartaT.valor = baralho->carta[i].valor;
              cartaT.naipe = baralho->carta[i].naipe;
              break;
            }//if
        }//for
return cartaT;
}//topo

Carta fundo(Baralho *baralho){ //Consulta a carta do fundo de um baralho.

Carta cartaF;

for (int i = 0; i < 52; i++) {
      if(  baralho->carta[i].foiJogada == false){
        cartaF.valor = baralho->carta[i].valor;
        cartaF.naipe = baralho->carta[i].naipe;
        break;
      }//if
  }//for
return cartaF;
}//fundo


void carteado(Baralho *baralho, Carta aleatoria[3]){//Retorna um array com 3 cartas aleatorias para um jogador;
  srand(time(NULL));
  int n;

  for(int i = 0; i < 3; i++){
    do{
      n = rand() % 52;
    }while(baralho->carta[n].foiJogada == true);
      aleatoria[i].valor = baralho->carta[n].valor;
      aleatoria[i].naipe = baralho->carta[n].naipe;
      baralho->carta[n].foiJogada = true;
  }//for
}//carteado

int main() {

  Baralho b;
  int escolha = 0, controle;
  Carta aleatoria[3], cartaTopo, cartaFundo;

  criaBaralho(&b);

  do{
    printf("\n 1- Jogar 3 cartas");
    printf("\n 0- Sair\n\n");
      scanf("%d", &escolha);
        if (controle <= 1) {
          escolha = 0;
        }//if
    switch(escolha){
      case 1: carteado(&b, &aleatoria[0]);
              for (int i = 0; i < 3; i++) {
                printf(" cartas: %c | %c\n", aleatoria[i].valor, aleatoria[i].naipe);
              }
              printf(" Cartas disponiveis: %d\n", controle = cartasNaoJogadas(&b));
                cartaTopo = topo(&b);
                cartaFundo = fundo(&b);
              printf(" Carta topo  %c | %c\n", cartaTopo.valor, cartaTopo.naipe);
              printf(" Carta fundo %c | %c\n", cartaFundo.valor, cartaFundo.naipe);
        break;
    }//switch
  }while(escolha!=0);

  return 0;
}//main
