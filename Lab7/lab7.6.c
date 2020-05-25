#include<stdio.h>
#include<stdlib.h>
//macro-ul pentru afisarea unei linii
#define STRINGIFY_AUX(val)  #val
#define STRINGIFY(txt)  STRINGIFY_AUX(txt)
//functia de afisare a numelui si a liniei fisierului si a argumentelor acestuia
#define SRCSHOW(...)                    \
     fprintf(stderr,__FILE__ " [" STRINGIFY(__LINE__) "]:");     \
    fprintf (stderr, __VA_ARGS__);
//testarea macro-ului
int main(){
  float x=0.5,y=-7.8;
  SRCSHOW("x=%g,y=%g",x,y);
}
