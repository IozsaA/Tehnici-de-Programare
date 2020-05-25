#include<stdio.h>
#include<stdlib.h>
//functia de comparare a doua elemente
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
// macro-ul de sortare
#define FN_SORTARE(tip)                               \
  void sortare_##tip(vector,dim){                      \
    qsort(vector, dim, sizeof(int), compare);          \
  }
// exemplificarea functiei
FN_SORTARE(int)
int main(){

  int  v[]={1,7,23,9,12,4};
  int i;
  for(i=0;i<6;i++){
    printf("%d ",v[i]);
  }
  printf("\n");
  sortare_int(v,6);
  for(i=0;i<6;i++){
    printf("%d ",v[i]);
  }
  return 0;
}
