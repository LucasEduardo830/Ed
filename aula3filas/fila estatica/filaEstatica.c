#ifndef filaEstatica_c
#define filaEstatica_c

#include "filaEstatica.h"

void iniciaFila(FilaEstatica *f){
  f->inicio = 0;
  f->fim = -1;
  f->tamanho = 0;
}
bool estaVazia(FilaEstatica *f){
  return(f->tamanho == 0);
}
bool estaCheia(FilaEstatica *f){
  return(f->tamanho == MAXTAM);
}
int tamanhoFila(FilaEstatica *f){
  return(f->tamanho);
}

int incrementaIndice(int i){
  return((i+1)%MAXTAM);
}

void enfileira(Objeto x, FilaEstatica *f){
  if(estaCheia(f) == false){
    f->fim = incrementaIndice(f->fim);
    f->array[f->fim] = x;
    f->tamanho++;
  } else{
    printf(" Fila cheia\n");
  }
}

void imprimeFila(FilaEstatica *f){
  int indice;
    printf(" Fila = { " );
  for (int i = 0; i < f->tamanho ; i++) {
    indice = (f->inicio + i) % MAXTAM;
      printf("%d ", f->array[indice]);
  }//for
  printf("}\n");
}

Objeto desenfileira(FilaEstatica *f){
  Objeto obj;

  if(!estaVazia(f)){
    obj = f->array[f->inicio];
    f->inicio = incrementaIndice(f->inicio);
    f->tamanho--;
  }//if
  else{
    printf(" Fila vazia\n");
  }//else
  return(obj);
}

Objeto inicioFila(FilaEstatica *f){
  Objeto obj;
    if (!estaVazia(f)) {
      return(f->array[f->inicio]);
    }else{
      obj.chave = 0;
      return(f->array[f->inicio] = obj);
    }
}
Objeto fimFila(FilaEstatica *f){
  Objeto obj;
    if (!estaVazia(f)) {
      return(f->array[f->fim]);
    }else{
      obj.chave = -1;
      return(f->array[f->fim] = obj);
    }
}
#endif /* filaEstatica_c */
