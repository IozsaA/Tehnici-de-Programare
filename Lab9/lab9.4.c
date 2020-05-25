#include <stdio.h>
#include <stdlib.h>

typedef struct elem{

    int n;
    struct elem *urm;

}elem;

elem *nou(int n, elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));

    if(!e)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }

    e->n=n;
    e->urm=urm;

    return e;
}

typedef struct{

    elem *prim;
    elem *ultim;

}Lista;

void init(Lista *lista)
{
    lista->prim=NULL;
    lista->ultim=NULL;
}

void adaugaInceput(Lista *lista, int n)
{
    elem *prim = lista->prim;

    lista->prim = nou(n,prim);

    if(!prim)
    {
        lista->ultim = lista->prim;
    }
}

void adaugaSfarsit(Lista *lista, int n)
{
    elem *e=nou(n,NULL);

    if(lista->ultim)
    {
        lista->ultim->urm = e;
    }
    else
    {
        lista->prim = e;
    }

    lista->ultim = e;
}

void afisare(Lista *lista)
{
    elem *crt;

    for(crt = lista->prim; crt; crt = crt->urm)
    {
        printf("%d ", crt->n);
    }

    putchar('\n');
}

void eliberare(Lista *lista)
{
    elem *p, *crt = lista->prim;

    while(crt)
    {
        p = crt->urm;
        free(crt);
        crt = p;
    }
}

Lista *sterge(Lista *lista, int n)          /// complexitate O(n) , se parcurge lista, cel mai rau caz nu gasim elementul
{
    elem *pred, *crt;

    for(pred = NULL, crt = lista->prim; crt; pred = crt, crt = crt->urm)
    {
        if(crt->n == n)
        {
            if(pred == NULL)
            {
                lista->prim = lista->prim->urm;     /// sterge primul element din lista
            }
            else
            {
                if(crt->urm == NULL)
                {
                    lista->ultim = pred;            /// sterge ultimul element din lista
                    lista->ultim->urm = NULL;
                }
                else
                {
                    pred->urm=crt->urm;             /// sterge un element din interiorul listei
                }

            }

            free(crt);

            return lista;
        }
    }

    return lista;
}

int main()
{
    Lista lista;

    init(&lista);

    adaugaSfarsit(&lista, 108);
    adaugaSfarsit(&lista, -1);
    adaugaSfarsit(&lista, -66);
    adaugaSfarsit(&lista, 49);

    afisare(&lista);

    printf("\ncapul : %d\n", lista.prim->n);

    printf("\ncoada : %d\n\n\n", lista.ultim->n);

    sterge(&lista, 108);

    afisare(&lista);

    printf("\ncapul : %d\n", lista.prim->n);

    printf("\ncoada : %d\n\n\n", lista.ultim->n);

    sterge(&lista, 49);

    afisare(&lista);

    printf("\ncapul : %d\n", lista.prim->n);

    printf("\ncoada : %d\n\n\n", lista.ultim->n);

    eliberare(&lista);

    return 0;
}
