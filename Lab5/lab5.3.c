#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int  indRow,indCol,rows,cols;//aceste variabile sunt globale pentru a evita declararea lor repetitiva
//functia error reduce codul repetitiv
void error(){
  printf("Memorie insuficienta.");
  exit(EXIT_FAILURE);
}
//aloca dinamic o matrice de tip int
int **alocare(){
  int **matrix;
  if((matrix=(int**)malloc(rows*sizeof(int*)))==NULL){
    error();
  }
  for(indRow=0;indRow<rows;indRow++){
    if((matrix[indRow]=(int*)malloc(cols*sizeof(int)))==NULL){
      error();
    }
  }
  return matrix;
}
//afiseaza o matrice int
void afisare(int**matrix){
  for(indRow=0;indRow<rows;indRow++){
    for(indCol=0;indCol<cols;indCol++){
      printf("%d ",matrix[indRow][indCol]);
    }
    printf("\n");
  }
}
//citeste o matrice int
void citire(int**matrix){
  for(indRow=0;indRow<rows;indRow++){
    for(indCol=0;indCol<cols;indCol++){
      printf("a[%d][%d]=",indRow+1,indCol+1);
      scanf("%d",&matrix[indRow][indCol]);
    }
  }
}

int main(int argc,char*argv[]){
  FILE *fis;
  int**mat;
  //introducem datele de intrare
  printf("nr linii=");scanf("%d",&rows);
  printf("nr coloane=");scanf("%d",&cols);
  mat=alocare();
  citire(mat);
  if((fis=fopen("dst.dat","w"))==NULL){
      error();
    }
  //scriem datele in fisierul binar
  fwrite(mat,cols*rows*sizeof(int),1,fis);
  fclose(fis);
  //alocam dinamic matricea
  int**b;
  b=alocare();
  if((fis=fopen("dst.dat","r"))==NULL){
      error();
    }
  //citim datele din fisierul binar
  fread(b,sizeof(int),rows*cols,fis);
  printf("\n");
  afisare(b);// afisam matricea citita
  fclose(fis);
  return 0;
}
