/**************************************
Autor: David Roa Neisa
Materia: Sistemas Operativos
Fecha: 18/07/2024
Tema: Introduccion al lenguaje c y los entornos 
  -Entornos en la web(Cloud/Nube)
  -Comandos principales de linux 
  -programa 0: Hola mundo
***************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char *function(char*p){
  char q[strlen(p)+1];
  strcpy(q,p);
  printf("from q: the string is %s\n",q);
  return q;
}

int main(){
  char *a=NULL;
  char *b=NULL;
  a=function("Hi, its so fun to learn\n");
  b=function("System Engineer\n");
  printf("from main:%s %s\n",a,b);
  return 0;
}

