#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXTAM 100

typedef struct {
  int valor;
} Objeto;

typedef struct {
  Objeto vetor[MAXTAM];
  int topo;
} pilhaEstatica;

void iniciaPilha(pilhaEstatica *p) {
  p->topo = 0;
}

bool estaVazia(pilhaEstatica *p) {
  return(p->topo == 0);
}

bool estaCheia(pilhaEstatica *p) {
  return(p->topo == MAXTAM);
}

void empilha(Objeto item, pilhaEstatica *p) {
  if(!estaCheia(p)){
    p->vetor[p->topo] = item;
    p->topo++;
  } else {
    printf(" Pilha cheia\n");
  }
 }

int desempilha(Objeto *item, pilhaEstatica *p) {
  if(!estaVazia(p)){
    *item = p->vetor[p->topo-1];
    p->topo--;
  } else{
    printf(" Pilha vazia\n");
  }
  return(item->valor);
}

int tamanhoPilha(pilhaEstatica *p) {
  return(p->topo);
}

Objeto topo(pilhaEstatica *p) {
   return(p->vetor[p->topo-1]);
}

void imprimePilha(pilhaEstatica *p) {
  int i = 0;
  printf("\n Pilha = {");
  for(i = 0; i < p->topo; i++) {
    printf("|%d| ", p->vetor[i]);
  }
  printf("}\n");
}

int main() {

  pilhaEstatica pilha;
  Objeto o;
  FILE *arqE, *arqS;
  int retorno, arquivo, linhas = 0, contador = 0;
  char caracter;

  arqE = fopen("arquivoE.txt","r");// abre o arquivoEntrada.txt para leitura
  arqS = fopen("arquivoS.txt","w");// abre o arquivoSaida.txt para escrita

  if(arqE == NULL || arqS == NULL ){ // Verifica se não ocorreu um erro ao tentar abrir os arquivos
    printf("Erro ao executar o arquivo / ou arquivo inexistente\n");
    exit(1);
  }//if

  fseek (arqE, 0, SEEK_END);
    arquivo = ftell(arqE);//pega o tamanho do arquivoE

  if (arquivo == 0) {//se o tamanho do arquivoE for igual a 0 o programa é encerrado
    printf(" O arquivo esta vazio\n");
    exit(1);
  }

  fseek(arqE, 0, SEEK_SET);

  while( (caracter = fgetc(arqE)) != EOF ){
      if(ispunct(caracter)){  //verifica se os numeros no arquivoE são inteiros, caso contrario encerra o programa
        printf(" Erro: Numeros nao inteiros presentes no arquivo\n");
        exit(1);
      }
      if(isalpha(caracter)){//verifica se o caracter atual é uma letra
        contador++;
      }
      if (contador > 1){//se o arquivoE possuir mais que uma letra o programa é encerrado
        printf("Letras alem das necessarias no arquivo\n");
        exit(1);
      }
      if (caracter=='\n'){//conta quantas linhas o arquivoE possui
        linhas++;
      }//if
  }//while
  fseek(arqE, 0, SEEK_SET);

  while( (caracter = fgetc(arqE)) != EOF ){
      if(caracter != 'e'){//verifica se o primeiro caracter é igual 'e', caso contrario encerra o programa
        printf(" Primeiro caracter diferente do necessario\n");
        exit(1);
      }else{
        break;
      }
  }//while

  iniciaPilha(&pilha);

  while(!feof(arqE)){
    fscanf(arqE,"%d", &o.valor);
      empilha(o ,&pilha);
  }//while

  //Para correção do tamanho ocupado na pilha
  while(linhas <= tamanhoPilha(&pilha)){
    retorno = desempilha(&o, &pilha);
  }//while

  imprimePilha(&pilha);
    printf(" Tamanho pilha %d\n", tamanhoPilha(&pilha));

  for (int i = 0; i < tamanhoPilha(&pilha);) {
    retorno = desempilha(&o, &pilha);//recebe em ordem contraria a de entreda os valores que estavam no pilha

    char binario[33], a = 0;

    if(retorno == 0){// se o retorno for 0 o binario sera 0
      binario[a] = 0;
        fprintf(arqS, "%d", binario[a]);

    }else if (retorno == 1) {// se o retorno for 1 o binario sera 1
      binario[a] = 1;
        fprintf(arqS, "%d", binario[a]);

    }else{
      while(retorno > 0){
        binario[a] = retorno % 2;//pega o resto 1 ou 0 da divisão por 2
        a++;
        retorno = retorno / 2;
      }//while
    }//if else
    for(int x = a - 1; x >= 0; x--){//percorre o vetor, escrevendo cada numero do binario no arquivoS
      fprintf(arqS, "%d", binario[x]);
    }//for
    fprintf(arqS, "\n");//pula para a proxima linha no arquivoS
  }//for

  imprimePilha(&pilha);
    printf(" Tamanho pilha %d\n", tamanhoPilha(&pilha));

  fclose(arqE);
  fclose(arqS);

  return 0;
}
