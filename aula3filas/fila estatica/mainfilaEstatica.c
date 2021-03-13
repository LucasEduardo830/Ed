#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "filaEstatica.c"

int main(){

  FilaEstatica fila;
  Objeto o;

  iniciaFila(&fila);
    imprimeFila(&fila);
      printf(" Tamanho da fila: %d \n", tamanhoFila(&fila));
        printf(" primeiro %d\n", inicioFila(&fila));
        printf(" ultimo %d\n", fimFila(&fila));

  for (int i = 1; i < 7; i++) {
    o.chave = i;
    enfileira(o, &fila);
  }

  imprimeFila(&fila);
    printf(" Tamanho da fila: %d \n", tamanhoFila(&fila));
      printf(" primeiro %d\n", inicioFila(&fila));
      printf(" ultimo %d\n", fimFila(&fila));

  for (int i = 1; i < 4; i++) {
    desenfileira(&fila);
  }
  imprimeFila(&fila);
    printf(" Tamanho da fila: %d \n", tamanhoFila(&fila));
      printf(" primeiro %d\n", inicioFila(&fila));
      printf(" ultimo %d\n", fimFila(&fila));

  for (int i = 9; i > 1; i--) {
    o.chave = i;
    enfileira(o,&fila);
  }

  imprimeFila(&fila);
    printf(" Tamanho da fila: %d \n", tamanhoFila(&fila));
      printf(" primeiro %d\n", inicioFila(&fila));
      printf(" ultimo %d\n", fimFila(&fila));

  return 0;
}
