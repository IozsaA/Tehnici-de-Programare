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

elem * rev(elem *lista)     ///complexitate O(n) deoarece parcurgem intreaga lista
{
    elem *pred = NULL;
    elem *crt = lista;
    elem *urm = NULL;

    while (crt != NULL)
    {
        urm = crt->urm;     ///salvam urmatorul element

        crt->urm = pred;    ///inversam sensul pointerului

        pred = crt;         ///mutam pe urmatoarea pozitie
        crt = urm;          ///mutam pe urmatoarea pozitie
    }

    return pred;    ///noul cap al listei
}

int main()
{
    elem *lista=NULL;

    lista=adaugaInceput(lista, 49);
    lista=adaugaInceput(lista, -1);
    lista=adaugaInceput(lista, 108);
    lista=adaugaInceput(lista, 22);
    lista=adaugaInceput(lista, 77);
    lista=adaugaInceput(lista, -99);

    afisare(lista);

    lista=rev(lista);

    afisare(lista);

    eliberare(lista);

    return 0;
}
