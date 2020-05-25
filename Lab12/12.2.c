#include <stdio.h>
#include <stdlib.h>

#define G 6.674e-11

//D&C pt ca impartim problema in mai multe subprobleme independente

float gravitational_force(float m1, float m2, float d)
{
    return (G*m1*m2)/(d*d);
}

int main()
{
    unsigned int n;
    float ma,mb,m,d;

    printf("n = ");
    scanf("%d",&n);
    printf("m = ");
    scanf("%f",&m);
    printf("ma = ");
    scanf("%f",&ma);
    printf("mb = ");
    scanf("%f",&mb);
    printf("distanta dintre a si b = ");
    scanf("%f",&d);

    float div = (float)d/n;

    for(int i=1; i<n; i++)
    {
        float Fa = gravitational_force(m,ma,div*i);
        float Fb = gravitational_force(m,mb,div*(n-i));

        printf("forta cand m este la %d diviziuni distanta de a = %g\n",i, (Fb - Fa));
    }

    return 0;
}
