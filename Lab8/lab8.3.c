#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
void modul(int n,...)
{
    va_list va;                     		// lista de argumente variabile
    va_start(va,n);             		// initializare cu ultimul argument fix
    double*p;
    for(int i=0;i<n;i++){
      p=va_arg(va,double*);
      *p=fabs(*p);
    }
    va_end(va);
}

int main()
{
    float x=-3.0,y=-7.2,z=5.4;
    printf("introduceti n, m, y si buf:\n");
    modul(3,&x,&y,&z);
    printf("\n%g, %g, %g\n",x,y,z);
    return 0;
}
