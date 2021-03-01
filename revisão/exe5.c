#include <stdlib.h>
#include <stdio.h>

typedef struct{
  char nome[50];
  char tipo[50];
  int quant;
  int ranking;
}Banda;

  Banda bandas[5];

void preencheBanda(){

  for (int i = 0; i < 5; i++) {

    printf("Banda[%d]\nDigite o nome da banda: ", i+1);
      scanf("%50[^\n]",&bandas[i].nome);
        fflush(stdin);

    printf("Digite o tipo de musica da banda: ");
      scanf("%50[^\n]",&bandas[i].tipo);
        fflush(stdin);

    printf("Digite o numero de integrantes: ");
      scanf("%d", &bandas[i].quant);
        fflush(stdin);

    printf("Diga a posicao que a banda esta entre as suas 5 favoritas: ");
      scanf("%d", &bandas[i].ranking);
        fflush(stdin);
    printf("\n\n");
  }
    printf("Exibindo todas as bandas:\n\n");

  for (int i = 0; i < 5; i++) {
    printf("Banda [%d]\nNome da banda: %s\n", i+1, bandas[i].nome);

    printf("Tipo de musica da banda: %s\n", bandas[i].tipo);

    printf("Numero de integrantes: %d\n", bandas[i].quant);

    printf("Posicao que a banda esta entre as suas 5 favoritas: %d\n\n", bandas[i].ranking);
  }
}

void exibeBanda(){
  int n;

  printf("Informe um numero de 1 a 5: ");
    scanf("%d", &n);

  for (int i = 0; i < 5; i++) {
  	if (bandas[i].ranking == n) {
  			printf("Nome da banda: %s\n", bandas[i].nome);
  			printf("Tipo de musica: %s\n", bandas[i].tipo);
  			printf("Numero de integrantes: %d\n", bandas[i].quant);
  			printf("Ranking: %d\n", bandas[i].ranking);
  	}
  }
}

int main() {

  preencheBanda();
  exibeBanda();

  return 0;
}
