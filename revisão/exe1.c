#include <stdlib.h>
#include <stdio.h>

void converte(int* tm, int* hr, int* min){

  if (*tm < 60) {
    *hr = 0;
    *min = *tm%60;
  }else if(*tm >= 60){
    *hr = *tm/60;
    *min = *tm%60;
  }
}

int main() {

  int totalMinutos, horas, minutos;

  printf("Digite quantos minutos deseja converter: ");
    scanf("%d", &totalMinutos);

  converte(&totalMinutos, &horas, &minutos);

  printf("Horas: %d \nMinutos: %d \n", horas, minutos);

  return 0;
}
