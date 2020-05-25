#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b,c) ((a)>(b)?(((a)>(c)?(a):(c))):(((b)>(c)?(b):(c)))) //functia de maxim
int main(){
  printf("%d",MAX(MAX(14,15,1),7,5));
}
