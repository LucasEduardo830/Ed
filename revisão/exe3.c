#include <stdlib.h>
#include <stdio.h>

int recursiva(int x, int y){

  if(y == 0){
    return 1;
  }else if(y > 0){
    return x*recursiva(x,y-1);
  }
}

int main() {

  int x=5, y=4, r;

  r = recursiva(x,y);

  printf("%d\n\n",r);

  return 0;
}
