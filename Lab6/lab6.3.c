#include <stdio.h>

 #define LINIE(baza)	(16*baza+0),(16*baza+1),(16*baza+2),(16*baza+3),	\
                                  	(16*baza+4),(16*baza+5),(16*baza+6),(16*baza+7),	\
                                  	(16*baza+8),(16*baza+9),(16*baza+10),(16*baza+11),	\
                                  	(16*baza+12),(16*baza+13),(16*baza+14),(16*baza+15)

const int tabela[]={
    LINIE(0),LINIE(1),LINIE(2),LINIE(3),
    LINIE(4),LINIE(5),LINIE(6),LINIE(7),
    LINIE(8),LINIE(9),LINIE(10),LINIE(11),
    LINIE(12),LINIE(13),LINIE(14),LINIE(15)
    };


#define ISLOWER(c)  (tabela[c])&1 ? 1 : 0
#define ISUPPER(c)  (tabela[c]>>1)&1 ? 1 : 0
#define ISDIGIT(c)  (tabela[c]>>2)&1 ? 1 : 0

int main()
{
    printf("%d\n",ISLOWER('\n')); // => 0
    printf("%d\n",ISLOWER('a'));	// => 1
    printf("%d\n",ISUPPER('A'));	// => 0
    printf("%d\n",ISDIGIT('2'));  // => 0


    return 0;
}
