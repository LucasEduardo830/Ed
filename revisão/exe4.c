#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void preencheVetor(int *vet1, int n){

srand(time(NULL));

  for (int i = 0; i < n; i++) {
    vet1[i] = rand() % 100;
  }
}

int main() {

  int *vet,n,i;

  printf("Escolha o tamanho do vetor:");
    scanf("%d", &n);

  vet	=	(int*)malloc(n*sizeof(int));

  preencheVetor(vet, n);

  for(i = 0; i < n; i++){
    printf("vet[%d]:[%d]\n",i,vet[i]);
  }

  free(vet);

  return 0;
}
