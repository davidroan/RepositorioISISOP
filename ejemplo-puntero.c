/**************************************
Autor: David Roa Neisa
Materia: Sistemas Operativos
Fecha: 18/07/2024
Tema: Introduccion al lenguaje c y los entornos 
  -Entornos en la web(Cloud/Nube)
  -Comandos principales de linux 
  -programa 0: Hola mundo
***************************************/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  int variable = 123;
  int *ptr= &variable;
  printf("Valor de la variable %d\n",variable);
  printf("Direccion de memoria de la varibale %p\n", &variable);
  printf("Direccion  a la que apunta el puntero %p\n",(void *)ptr);
  printf("valor de la variable %i\n",*ptr);
  return 0;
}