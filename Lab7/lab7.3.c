#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//in modul debug definim un macro pentru printare
#if defined(DEBUG) || defined(_DEBUG)
    #define DBG(...)		fprintf(stderr,__VA_ARGS__)
#else
    #define DBG(...)
#endif

double vmax(double *v,int n)
{
  int i;
  double m=v[0];
  //in modul debug afisam vectorul
  for(i=0;i<n;i++)
    DBG("%lg ",v[i]);
  DBG("\n");
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
