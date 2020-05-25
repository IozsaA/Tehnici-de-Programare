#include <stdio.h>
#include <stdlib.h>

// un element al listei
typedef struct elem{
    int n;                          // informatia utila
    struct elem *urm;       // camp de inlantuire catre urmatorul element
    }elem;

// aloca un nou element si ii seteaza campurile corespunzatoare
elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(!e){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }
    e->n=n;
    e->urm=urm;
    return e;
}

// adauga un element la inceputul listei
// returneaza noua lista
elem *adaugaInceput(elem *lista,int n)
{
    return nou(n,lista);
}

// adauga un element la sfarsitul listei
// returneaza noua lista
elem *adaugaSfarsit(elem *lista,int n)
{
    if(!lista)return nou(n,NULL);
    elem *p=lista,*urm;
    for(urm=p->urm;urm;p=urm,urm=p->urm){}
    p->urm=nou(n,NULL);
    return lista;
}

void afisare(elem *lista)
{
    for(;lista;lista=lista->urm){
        printf("%d ",lista->n);
        }
    putchar('\n');
}

// elibereaza memoria ocupata de o lista
void eliberare(elem *lista)
{
    elem *p;
    while(lista){
        p=lista->urm;
        free(lista);
        lista=p;
        }
}

int main()
{
    // varianta 1: construieste direct lista dorita
    elem *lista1=nou(108,nou(-1,nou(49,NULL)));
    afisare(lista1);
    eliberare(lista1);
    // varianta 2: adauga la inceputul listei elementele in ordinea inversa
    elem *lista2=NULL;
    lista2=adaugaInceput(lista2,49);
    lista2=adaugaInceput(lista2,-1);
    lista2=adaugaInceput(lista2,108);
    afisare(lista2);
    eliberare(lista2);
    // varianta 3: adauga la sfarsitul listei
    elem *lista3=NULL;
    lista3=adaugaSfarsit(lista3,108);
    lista3=adaugaSfarsit(lista3,-1);
    lista3=adaugaSfarsit(lista3,49);
    afisare(lista3);
    eliberare(lista3);
    return 0;
}
