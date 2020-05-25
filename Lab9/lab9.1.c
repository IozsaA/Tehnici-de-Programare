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

int cmp(elem *lista1, elem *lista2)                 ///complexitate O(n) deoarece parcurgem listele in intregime
{
    for(; lista1 || lista2; lista1=lista1->urm, lista2=lista2->urm)
    {
        if((lista1 == NULL) || (lista2 == NULL))    return 0;   ///nu pot fi identice daca au dimensiuni diferite

        if(lista1->n != lista2->n)    return 0;     ///iteram ambele liste in acelasi timp, elementele de pe aceleasi pozitii ar trebui sa fie egale
    }

    return 1;
}

int main()
{
    elem *lista1=NULL, *lista2=NULL;

    lista1=adaugaInceput(lista1, 49);
    lista1=adaugaInceput(lista1, -1);
    lista1=adaugaInceput(lista1, 108);

    lista2=adaugaInceput(lista2, 49);
    lista2=adaugaInceput(lista2, -1);
    lista2=adaugaInceput(lista2, 108);

    afisare(lista1);
    afisare(lista2);

    if(cmp(lista1, lista2))
    {
        printf("\nListele sunt identice.\n");
    }
    else
    {
        printf("\nListele NU sunt identice.\n");
    }

    eliberare(lista1);
    eliberare(lista2);

    return 0;
}
