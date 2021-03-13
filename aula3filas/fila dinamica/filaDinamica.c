#ifndef filaDinamica_c
#define filaDinamica_c

#include "filaDinamica.h"

void iniciaFila(FilaDinamica *fila){
  fila->inicio=NULL;
  fila->fim=NULL;
  fila->tamanho=0;
}//iniciaFila

int tamanhoFila(FilaDinamica *fila){
  return (fila->tamanho);
}//tamanhoFila

int estaVazia(FilaDinamica *fila){
  return(fila->tamanho == 0);
}//estaVazia

void enfileira(Objeto x, FilaDinamica *fila){
  PtrNoFila aux;

  aux = (PtrNoFila)malloc(sizeof(NoFila));
  aux->obj = x;

  if(estaVazia(fila)){
    fila->inicio = aux;
    fila->fim = aux;
    aux->proximo= NULL;
  }//if
  else {
    aux->proximo=NULL;
    fila->fim->proximo=aux;
    fila->fim = aux;
  }//else
  fila->tamanho++;
}//enfileira

void desenfileira(FilaDinamica *fila, Objeto *x){
  PtrNoFila aux; //aloca memoria

  if(!estaVazia(fila)){
    aux = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    *x=aux->obj;
    free(aux);
    fila->tamanho--;
  } else{
    printf(" Fila vazia\n");
  }
}//desenfileira

void imprimeFila(FilaDinamica *fila){
  PtrNoFila aux;
  printf("\n Fila = { ");

  for(aux = fila->inicio; aux != NULL; aux = aux->proximo){
    printf("%d ",aux->obj);
  }//for
  printf("} \n");

}//imprimeFila

Objeto inicioFila(FilaDinamica *fila){
  return(fila->inicio->obj);
}//inicioFila

Objeto fimFila(FilaDinamica *fila){
  return(fila->fim->obj);
}//fimFila

void destroi(FilaDinamica *fila, Objeto *x){
  do{
    desenfileira(fila, x);
  }while(fila->tamanho!=0);

}//destruicao

#endif /* filaDinamica_h */
