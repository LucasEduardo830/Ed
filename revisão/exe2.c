#include <stdlib.h>
#include <stdio.h>


int main() {

FILE *arq, *arq1;
int linhas = 0;
char c;

arq = fopen("original.txt","r");
arq1 = fopen("novo.txt","w");

  if(arq == NULL || arq1 == NULL ){ // Verifica se não ocorreu um erro ao tentar abrir os arquivos
    printf("Erro ao executar o arquivo");
    exit(1);
  }

  while( (c = fgetc(arq)) != EOF ){
    if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u')c = '*';
      fprintf(arq1, "%c", c);

    if (c=='\n'){
      linhas++;
    };
  }
  printf("O arquivo possui %d linhas.\n\n", linhas);

  fclose(arq);
  fclose(arq1);

  return 0;
}
