#include <stdio.h>
#include <stdlib.h>

#define size 10

int main(int argc, char *argv[]){
  int *vectorPuntero[3];
  int p=40, q=80, r=120;
  vectorPuntero[0]=&p;
  vectorPuntero[1]=&q;
  vectorPuntero[2]=&r;
  printf("\nForma de accesoal vetor de punteros:\n");
  for(int i=0;i<3;i++){
    printf("Para la direccion: %p \t el valor = %d\n",vectorPuntero[i],*vectorPuntero[i]);
  }
  return 0;
}