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

int exista(elem *lista, int n)      ///complexitate O(n), parcurgem toata lista daca nu gasim elementul
{
    elem *k = lista;

    while(k != NULL)
    {
        if(k->n == n)   return 1;

        k=k->urm;
    }

    return 0;
}

elem *reuniune(elem *lista1, elem *lista2)      ///complexitate O(n x n) , parcurgem ambele liste in intregime iar
{                                                                       ///pt fiecare elem parcurgem intreaga lista
    elem *lista = NULL;

    while (lista1 != NULL)      ///introducem elementele listei 1 in lista finala, fara dubluri
    {
        if (!exista(lista, lista1->n))
        {
            lista = adaugaInceput(lista, lista1->n);
        }
        lista1 = lista1->urm;
    }

    while (lista2 != NULL)      ///introducem elementele listei 2 care nu se regasesc deja in lista finala
    {
        if (!exista(lista, lista2->n))
        {
            lista = adaugaInceput(lista, lista2->n);
        }
        lista2 = lista2->urm;
    }

    return lista;
}

int main()
{
    elem *lista, *lista1=NULL, *lista2=NULL;

    lista1=adaugaInceput(lista1, 49);
    lista1=adaugaInceput(lista1, -1);
    lista1=adaugaInceput(lista1, 108);
    lista1=adaugaInceput(lista1, -1);
    lista1=adaugaInceput(lista1, -1);

    lista2=adaugaInceput(lista2, 42);
    lista2=adaugaInceput(lista2, 22);
    lista2=adaugaInceput(lista2, 77);
    lista2=adaugaInceput(lista2, 108);
    lista2=adaugaInceput(lista2, 77);

    afisare(lista1);
    afisare(lista2);

    lista=reuniune(lista1, lista2);

    afisare(lista);

    eliberare(lista1);
    eliberare(lista2);

    return 0;
}
