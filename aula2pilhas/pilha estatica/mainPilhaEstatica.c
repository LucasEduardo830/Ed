#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "pilhaEstatica.h"
#include "pilhaEstatica.c"

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
