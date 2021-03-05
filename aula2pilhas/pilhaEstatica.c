#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "pilhaEstatica.h"

void iniciaPilha(pilhaEstatica *p) {
  p->topo = 0;
}

bool estaVazia(pilhaEstatica *p) {
  return(p->topo == 0);
}

bool estaCheia(pilhaEstatica *p) {
  return(p->topo == MAXTAM);
}

void empilha(Objeto item, pilhaEstatica *p) {
  if(!estaCheia(p)){
    p->vetor[p->topo] = item;
    p->topo++;
  } else {
    printf(" Warning: nao inserido porque esta cheia\n");
  }
 }

void desempilha(Objeto *item, pilhaEstatica *p) {
  if(!estaVazia(p)){
    *item = p->vetor[p->topo-1];
    p->topo--;
  } else{
    printf(" Warning: nao removido porque esta vazia\n");
  }
}

int tamanhoPilha(pilhaEstatica *p) {
  return(p->topo);
}

Objeto topo(pilhaEstatica *p) {
   return(p->vetor[p->topo-1]);
}

void imprimePilha(pilhaEstatica *p) {
  int i = 0;
  printf("\n Pilha = {");
  for(i = 0; i < p->topo; i++) {
    printf("|%d| ", p->vetor[i]);
  }
  printf("}\n");
}

int main() {

  pilhaEstatica p;
  Objeto o;

  o.chave = 0;

  iniciaPilha(&p);

  if(estaVazia(&p)) {
    printf(" Pilha vazia\n");
  }

  for (int i = 0; i < MAXTAM; i++) {
    o.chave++;
    empilha(o, &p);
  }
  imprimePilha(&p);
    printf(" Tamanho: %d\n", tamanhoPilha(&p));

  for (int i = 0; i < 50; i++) {
    desempilha(&o,&p);
  }
  imprimePilha(&p);
    printf(" Tamanho: %d\n", tamanhoPilha(&p));

  printf(" Topo: %d\n", topo(&p));

  return 0;
}
