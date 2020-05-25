#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define ALOCARE(tip) \
    tip *alocare_v(tip *v,int n){\
        if((v=(tip*)malloc(n*sizeof(tip)))==NULL){\
            printf("err");\
            free(v);\
            exit(EXIT_FAILURE);\
        }\
        return v;\
    }

#define ORD_CRESCATOR(tip) \
    int compare(tip *v,int n){\
        for(int i=0;i<n-1;i++){\
            if(v[i] > v[i+1]){\
                return 0;\
            }\
        }\
        return 1;\
    }

int crescator(int n,char tip, ...){
    int *v;
    float *v_f;
    va_list va;
    va_start(va,tip);

    if(tip == 'd'){
        ALOCARE(int)
        v = alocare_v(v,n);
    }
    if(tip == 'f'){
        ALOCARE(float)
        v_f = alocare_v(v_f,n);
    }

    for(int i=0;i<n;i++){
        if(tip == 'd'){
            v[i] = va_arg(va,int);
        }
        if(tip == 'f'){
            v_f[i] = va_arg(va,double);
        }
    }

    if(tip == 'd'){
        ORD_CRESCATOR(int)
        return compare(v,n);
    }
    if(tip == 'f'){
        ORD_CRESCATOR(float)
        return compare(v,n);
    }

    va_end(va);
}

int main()
{
    printf("%d", crescator(5,'d',1,2,3,4,5) );
    return 0;
}
