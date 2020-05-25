#include<stdio.h>
#include<stdlib.h>
//Macro-ul de citire
#define CITIRE(TEXT,P,VAR,MIN,MAX) do{printf(TEXT ": ");scanf("%" #P, &VAR);}while(VAR<=MIN||VAR>=MAX)
int main(){
  float x;
  CITIRE("x=",g,x,0,100);
  return 0;
}
