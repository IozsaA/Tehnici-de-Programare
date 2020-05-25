#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[]){
  FILE *fin,*fout;
  char s[4096],c;
  if((fin=fopen(argv[1],"r"))==NULL){ //deschidem fisierul de intrare
      printf("nu se poate deschide fisierul\n");
      exit(EXIT_FAILURE);
      }
  if((fout=fopen(argv[2],"w"))==NULL){ //deschidem fisierul de iesire
    printf("nu se poate deschide fisierul\n");
    exit(EXIT_FAILURE);
  }
  int i=0;
  while(fread(&c,sizeof(char),1,fin)){ // retinem caracter cu caractere datele
                                      //din fisier cat timp exista
    s[i]=c;
    i++;
  }
  fwrite(s,sizeof(char),strlen(s),fout);
  return 0;
}
