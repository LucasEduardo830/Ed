#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "filaDinamica.c"

int main() {

  FilaDinamica f;
  Objeto obj;

  iniciaFila(&f);

  for (int i = 0; i < 10; i++) {
    obj.chave = i;
    enfileira(obj, &f);
  }//for

  imprimeFila(&f);
    printf(" Tamanho: %d\n",tamanhoFila(&f));
      printf(" Primeiro elemento da fila: %d\n",inicioFila(&f));
        printf(" Ultimo elemento da fila: %d\n", fimFila(&f));

  for (int i = 0; i < 5 ; i++) {
    desenfileira(&f, &obj);
      printf(" Numero removido: %d \n",obj.chave);
  }//for

  for (int i = 10; i > 0; i--) {
    obj.chave = i;
    enfileira(obj, &f);
  }//for

  imprimeFila(&f);
    printf(" Tamanho: %d\n",tamanhoFila(&f));
      printf(" Primeiro elemento da fila: %d\n",inicioFila(&f));
        printf(" Ultimo elemento da fila: %d\n", fimFila(&f));

  destroi(&f, &obj);
    imprimeFila(&f);
      printf(" Tamanho: %d\n",tamanhoFila(&f));
        printf(" Primeiro elemento da fila: %d\n",inicioFila(&f));
          printf(" Ultimo elemento da fila: %d\n", fimFila(&f));

  return 0;
}//main
