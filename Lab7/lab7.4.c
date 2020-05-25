#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#if defined(DEBUG) || defined(_DEBUG)
    #define DBG(...)		fprintf(stderr,__VA_ARGS__)
#else
    #define DBG(...)
#endif

double vmax(double *v,int n)
{
  int i;
  double m=v[0];
  for(i=0;i<n;i++)
    DBG("%lg ",v[i]);
  DBG("\n");
  for(i=1;i<n;i++){
      if(m<v[i])m=v[i];
      }
  return m;
}
//functia "test" verifica prin variabila "x" daca intr-adevar am aflat maximul
unsigned int test(double*v,int n,double x){
  int i;
  double m=v[0];
  for(i=1;i<n;i++){
      if(m<v[i])m=v[i];
      }
  if(m==x)
    return 1;
  else return 0;
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
    assert(test(v,n,vmax(v,n)));
    for(i=0;i<n;i++){
        //in modul debug incercam sa ne dam seama de eroare
        DBG("i=%d, n=%d, v=%p\n",i,n,v);
        printf("v[%d]=",i);scanf("%lg",&v[i]);
         DBG("=> %g\n",v[i]);
        }
    //afisam maximul si golim vectorul v
    printf("maximul este: %g\n",vmax(v,n));
    free(v);
    return 0;
}
