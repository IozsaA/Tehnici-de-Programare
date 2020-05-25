#include <stdio.h>
#include <stdlib.h>

void char_to_binary(char c)
{
    for(int i=sizeof(char)*8-1;i>=0;i--)
    {
        printf("%d",(c>>i)&1);
    }
    printf(" ");
}
//Afisam vectorul de caractere in binar
void afisare_octeti(unsigned char (*v)[4])
{
    //verifiam daca avem de a face cu "Little Endian"
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        for(int i=2;i>=0;i--)
        {
            char_to_binary((*v)[i]);
        }
    #endif
    //verifiam daca avem de a face cu "Big Endian"
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        for(int i=0;i<3;i++)
        {
            char_to_binary((*v)[i]);
        }

    #endif
    printf("\n");
}
//testam functia
int main()
{
    char a[4]="abc";
    char (*ptr)[4];
    ptr = &a;

    afisare_octeti(ptr);

    return 0;
}
