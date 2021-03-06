#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "PilhaDinamica.h"
#include "PilhaDinamica.c"

int main() {

  PilhaDinamica p;
  Objeto o;


  o.chave = 10;

  iniciaPilha(&p);
  imprimePilha(&p);
  printf(" Tamanho = %d\n", tamanhoPilha(&p));


  for (int i = 0; i < 10; i++) {
    o.chave++;
    empilha(&p, o);
  }

  imprimePilha(&p);
  topo(&p,&o);
  printf(" Tamanho = %d\n", tamanhoPilha(&p));

  for (int i = 0; i < 7; i++) {
    desempilha(&p,&o);
  }
  imprimePilha(&p);
  topo(&p,&o);
  printf(" Tamanho = %d\n", tamanhoPilha(&p));

  return 0;
}
