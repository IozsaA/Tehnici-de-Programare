#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float *allocVec(int n,...)
{
      va_list va;     		// pointer la lista de argumente variabile (varargs)
      va_start(va,n);
      float*addInt;
      if((addInt=(float*)malloc(n*sizeof(float)))==NULL){
        // daca nu s-a reusit alocarea, afiseaza un mesaj
        // si iese din program returnand sistemului de operare un cod de eroare
        printf("memorie insuficienta\n");
        exit(EXIT_FAILURE);
      }
      for(int i=0;i<n;i++){
        addInt[i]=va_arg(va,double);
        printf("%g ",addInt[i]);
      }
      printf("\n");
      va_end(va);
      return addInt;
}

int main()
{
    float*v;
    v=allocVec(3,7.2,-1.0,0);
    for(int i=0;i<3;i++){
      printf("%g ",v[i]);
    }
    return 0;
}
