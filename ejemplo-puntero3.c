/**************************************
Autor: David Roa Neisa
Materia: Sistemas Operativos
Fecha: 18/07/2024
Tema: Introduccion al lenguaje c y los entornos 
  -Entornos en la web(Cloud/Nube)
  -Comandos principales de linux 
  -programa 0: Hola mundo
***************************************/
#include <stdio.h>
#include <stdlib.h>

#define size 10

int main(int argc, char *argv[]){
  int valor1,valor2;
  int *ptrv1,*ptrv2;
  ptrv1=&valor1;
  ptrv2=&valor2;
  printf("\nIngrese dos valores a ser sumados:\n");
  scanf("%d %d",&valor1,&valor2);
  printf("\nLa suma es= %d\n",*ptrv1+*ptrv2);
  return 0;
}