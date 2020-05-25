#include <stdio.h>
#include <stdlib.h>

//D&C deoarece am impartit matricea in mai multe submatrici pentru a alfa solutia problemei

int minim(int **a,int linie_init,int linie_ultima, int col_init, int col_ultima)
{
    int min = a[linie_init][col_init];
    for(int i=linie_init;i<linie_ultima;i++){
        for(int j=col_init;j<col_ultima;j++){
            if(a[i][j] < min){
                min = a[i][j];
            }
        }
    }

    return min;
}

int maxim(int **a,int linie_init,int linie_ultima, int col_init, int col_ultima)
{
    int max = a[linie_init][col_init];
    for(int i=linie_init;i<linie_ultima;i++){
        for(int j=col_init;j<col_ultima;j++){
            if(a[i][j] > max){
                max = a[i][j];
            }
        }
    }

    return max;
}

int  **citire(int **a,int m,int n)
{
    a = (int**)malloc(m*sizeof(int*));
    if(a==NULL){
        printf("err");
        free(a);
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<m;i++){
        a[i] = (int*)malloc(n*sizeof(int));
        if(a[i] == NULL){
            printf("err");
            for(int j=0;j<i;j++)
            {
                free(a[i]);
            }
            free(a);
            exit(EXIT_FAILURE);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    return a;
}

void afisare(int **a,int m, int n)
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int reducere(int **a,int m,int n)   // m liniii
{
    int min1,min2,max1,max2,max,min;
                         // n col
    if(m==0 && n==0){
        return 0;
    }
    if(m==1 && n==1){
        return a[0][0];
    }

    int linie_init_up_left = 0;
    int col_init_up_left = 0;
    int linie_ultim_up_left;
    int col_ultim_up_left;

    int linie_init_up_right=0;
    int col_init_up_right ;
    int linie_ultim_up_right;
    int col_ultim_up_right = n;

    int linie_init_down_left;
    int col_init_down_left = 0;
    int linie_ultim_down_left = m;
    int col_ultim_down_left;

    int linie_init_down_right;
    int col_init_down_right;
    int linie_ultim_down_right = m;
    int col_ultim_down_right = n;

    linie_ultim_up_left = linie_ultim_up_right = m/2;
    if(m%2 == 0){  // m par, nu se taie prin linia de mijloc
        linie_init_down_left = linie_init_down_right = m/2;
    }
    else{
        linie_init_down_left = linie_init_down_right = m/2+1;
    }

    col_ultim_up_left = col_ultim_down_left = n/2;
    if(n%2 == 0){
        col_init_up_right = col_init_down_right = n/2;
    }
    else{
        col_init_up_right = col_init_down_right = n/2+1;
    }

    max1 = maxim(a,linie_init_up_left,linie_ultim_up_left,col_init_up_left,col_ultim_up_left);
    max2 = maxim(a,linie_init_up_right,linie_ultim_up_right,col_init_up_right,col_ultim_up_right);

    if(max1>=max2){
        max = max1;
    }
    else{
        max = max2;
    }

    min1 = minim(a,linie_init_down_left,linie_ultim_down_left,col_init_down_left,col_ultim_down_left);
    min2 = minim(a,linie_init_down_right,linie_ultim_down_right,col_init_down_right,col_ultim_down_right);

    if(min1<=min2){
        min = min1;
    }
    else{
        min = min2;
    }

    return max-min;
}

int main()
{
    int n,m,**a;

    printf("m = ");
    scanf("%d",&m);
    printf("n = ");
    scanf("%d",&n);
    a = citire(a,m,n);
    afisare(a,m,n);
    printf("red = %d",reducere(a,m,n));

    return 0;
}
