#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void err(int test,const char *fmt,...)
{
    if(test){
      va_list va;     		// pointer la lista de argumente variabile (varargs)
      va_start(va,fmt);   		// va trebuie initializat cu ultimul argument fix al functiei
      fprintf(stderr,"eroare: ");
      vfprintf(stderr,fmt,va);	// varianta de fprintf care primeste o lista de argumente variabile
      va_end(va);         		// dupa folosirea argumentelor variabile, trebuie apelat va_end
      fputc('\n',stderr);
      exit(EXIT_FAILURE);
    }
}

int main()
{
    int i,n;
    float x,y,e,min,max;

    printf("n=");scanf("%d",&n);
    err(n<=0||n>100,"n invalid: %d\n",n);
    printf("x=");scanf("%g",&x);
    printf("y=");scanf("%g",&y);
    err(x>=y,"x=%g nu este mai mic decat y=%g\n",x,y);
    max=x;
    min=y;
    for(i=0;i<n;i++){
        printf("e=");scanf("%g",&e);
        err(e<x||e>y,"element invalid: %g\n",e);
        if(e<min)min=e;
        if(e>max)max=e;
        }
    printf("min: %g, max: %g\n",min,max);
    return 0;
}
