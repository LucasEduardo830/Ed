#ifndef pilhaEstatica_c
#define pilhaEstatica_c

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
    printf(" Pilha cheia\n");
  }
 }

void desempilha(Objeto *item, pilhaEstatica *p) {
  if(!estaVazia(p)){
    *item = p->vetor[p->topo-1];
    p->topo--;
  } else{
    printf(" Pilha vazia\n");
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

#endif
