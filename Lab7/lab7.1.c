//In exemplul 2 nu s-au utilizat corect parantezele pentru alocarea dinamica a vectorului
//La citire in loc de "%g" trebuia sa folosim "%lg" deoarece citim date de tip "double", nu de tip "float"
//In functia pentru determinarea maximului am inceput iteratia de la 1 in loc de 0
//Am initializat maximul cu valoarea "0" in loc de primul element sau valoarea minima a tipului double

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(DEBUG) || defined(_DEBUG)
    #define DBG(...)		fprintf(stderr,__VA_ARGS__)
#else
    #define DBG(...)
#endif

double vmax(double *v,int n)
{
    int i;
    double m=v[0];
    for(i=1;i<n;i++){
        if(m<v[i])m=v[i];
        }
    return m;
}

int main()
{
    double *v;
    int i,n;
    printf("n=");scanf("%d",&n);
    if((v=(double*)malloc(n))==NULL){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }
    for(i=0;i<n;i++){
        DBG("i=%d, n=%d, v=%p\n",i,n,v);
        printf("v[%d]=",i);scanf("%lg",&v[i]);
         DBG("=> %g\n",v[i]);
        }
    printf("maximul este: %g\n",vmax(v,n));
    free(v);
    return 0;
}
