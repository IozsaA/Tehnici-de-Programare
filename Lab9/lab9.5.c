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

elem *adaugaInceput(elem *lista, int n)
{
    return nou(n,lista);
}

void afisare(elem *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }
    putchar('\n');
}

void eliberare(elem *lista)
{
    elem *p;
    while(lista)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

int egal(elem *lista1, elem *lista2)                ///complexitate O(n x n) , parcurgem lista 1
{                                                   ///si comp fiecarei elem al sau cu elementele listei 2
    elem *l1 = lista1, *l2 = lista2;
    int ok;

    for(l1 = lista1; l1; l1 = l1->urm)
    {
        ok=0;

        for(l2 = lista2; l2; l2 = l2->urm)
        {
            if(l1->n == l2->n)
            {
                ok=1;
                break;
            }
        }

        if(!ok) return 0;
    }

    return 1;
}

int main()
{
    elem *lista1=NULL, *lista2=NULL;

    lista1=adaugaInceput(lista1, 49);
    lista1=adaugaInceput(lista1, -1);
    lista1=adaugaInceput(lista1, 108);
    lista1=adaugaInceput(lista1, 108);

    lista2=adaugaInceput(lista2, 49);
    lista2=adaugaInceput(lista2, 108);
    lista2=adaugaInceput(lista2, -1);

    afisare(lista1);
    afisare(lista2);

    if(egal(lista1, lista2))
    {
        printf("\nListele sunt egale.\n");
    }
    else
    {
        printf("\nListele NU sunt egale.\n");
    }

    eliberare(lista1);
    eliberare(lista2);

    return 0;
}
