#ifndef pilhaDinamica_c
#define pilhaDinamica_c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "PilhaDinamica.h"

void iniciaPilha(PilhaDinamica *p) {
  p->topo = NULL;
  p->tamanho = 0;
}

bool estaVazia(PilhaDinamica *p) {
  return(p->tamanho == 0);
}

void empilha(PilhaDinamica *p, Objeto obj) {
  PtrNoPilha aux;
    aux = (PtrNoPilha)malloc(sizeof(PtrNoPilha));
      aux->obj = obj;
      aux->proximo = p->topo;
      p->topo = aux;
      p->tamanho++;
 }

void desempilha(PilhaDinamica *p, Objeto *obj) {
  if(!estaVazia(p)){
    PtrNoPilha aux;
      aux = p->topo;
        printf(" Valor removido: %d\n", aux->obj);
      p->topo = aux->proximo;
      free(aux);
      p->tamanho--;
  } else{
    printf(" Warning: nao removido porque esta vazia\n");
  }
}

int tamanhoPilha(PilhaDinamica *p) {
  return(p->tamanho);
}

void topo(PilhaDinamica *p, Objeto *obj) {
  if (p->topo != NULL){
      printf(" Topo: %d\n",p->topo->obj.chave);
  }
}

void imprimePilha(PilhaDinamica *p) {
  PtrNoPilha ptr;
    printf("\n Pilha = {");
      for(ptr = p->topo; ptr != NULL; ptr = ptr->proximo) {
        printf("|%d| ", ptr->obj);
      }
    printf("}\n");
}

#endif
