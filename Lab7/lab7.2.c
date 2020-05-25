#include<stdio.h>
#include<math.h>
float abs_val(double n){
  //verificam daca este definit cuvantul "IMPLICIT"
  #if defined(IMPLICIT)
    //Daca este folosim functia "fabs(n)" pentru modul
    return fabs(n);
  #else
  //altfel definim functia modul
    if(n<0)
      return -n;
    else
      return n;
  #endif
}
//testam functia
int main(){
  printf("%lg",abs_val(-8.612));
  return 0;
}
