#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nMax 99

// metoda greedy deoarece trebuie sa sortam un vector si ne apropiem pas cu pas de solutia finala

typedef struct
{
    float x;
    float y;
    float d;
}Punct;

float distanta(Punct p1, Punct p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

void citire(Punct p[],int n)
{
    for(int i=0;i<n;i++){
        printf("p[%d].x = ",i);
        scanf("%f", &p[i].x);
        printf("p[%d].y = ",i);
        scanf("%f", &p[i].y);

        Punct O={0,0};
        float d = distanta(O,p[i]);
        p[i].d = d;
    }
}

void afisare(Punct p[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%g %g \n",p[i].x,p[i].y);
    }
    printf("\n");
}

Punct get_closest(Punct curr,Punct puncte[],int n)
{
    Punct closest;
    float min = distanta(curr,puncte[0]);
    float d;
    int px,py;
    px = puncte[0].x;
    py = puncte[0].y;

    for(int i=1;i<n;i++){
        d = distanta(curr,puncte[i]);
        if(d<min){
            min = d;
            px = puncte[i].x;
            py = puncte[i].y;
        }
    }

    closest.x = px;
    closest.y = py;

    return closest;
}



void stergere(Punct puncte[],int *n,int pos)
{
    for(int i=pos;i<*n-1;i++){
        puncte[i] = puncte[i+1];
    }
    *n--;
}

int search_point(Punct punct[],int n, Punct p){
    for(int i=0;i<n;i++){
        if(punct[i].x == p.x && punct[i].y == p.y){
            return i;
        }
    }
    return 0;
}

void print_order(Punct *puncte, int n){
    Punct init;
    init.x = init.y = 0;
    Punct next;
    int pos;

    next = get_closest(init,puncte,n);
    printf("%g %g\n",next.x,next.y);
    init = next;

    pos = search_point(puncte,n,next);
    stergere(puncte,&n,pos);
    n--;

    while(n){
        next = get_closest(init, puncte, n);
        printf("%g %g\n",next.x,next.y);
        pos = search_point(puncte,n,next);
        init = next;

        stergere(puncte,&n,pos);
        n--;
    }
}

int main()
{
    int n;
    Punct p[nMax];
    printf("n = ");
    scanf("%d",&n);
    if(n==0){
      return 0;
    }
    citire(p,n);
    afisare(p,n);

    print_order(p,n);

    return 0;
}
