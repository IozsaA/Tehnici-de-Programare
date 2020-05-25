#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int stergere(int*v1,int n1,int*v2,int n2){
  //algoritmul de stergere
  int i,j,k;
  for(i=0;i<n1;i++){
    for(j=0;j<n2;j++){
      if(v1[i]==v2[j]){
        for(k=i;k<n1;k++){
          v1[k]=v1[k+1];
        }
        n1--;
        i--;
      }
    }
  }
  //returnam numarul de elemente
  return n1;
}

int main(){
  int v1[]={1,3,4,5,6,8},v2[]={3,7,8},n1=6,n2=3;
  //conditiile de existenta
  assert(v1!=NULL);
  assert(v2!=NULL);
  assert(n1>0);
  assert(n2>0);
  assert(n1==(sizeof(v1)/sizeof(int)));
  assert(n2==(sizeof(v2)/sizeof(int)));
  //testam functia
  printf("%d",stergere(v1,n1,v2,n2));
}
