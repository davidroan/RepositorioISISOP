/**************************************
Autor: David Roa Neisa
Materia: Sistemas Operativos
Fecha: 15/08/2024
Tema: gestion de memoria
  -Entornos en la web(Cloud/Nube)
  -Comandos principales de linux 
  -programa :matrizV0
***************************************/
#include<stdio.h>
#include<stdlib.h>

  int mA[9];
  int mB[9];
  int mC[9];

void inicializar(int n, int matriz[]){
  for(int i=0;i<n;i++){
    matriz[i]=i;
  }
}

void impresion(int n, int matriz[]){
    for(int i=0;i<n;i++){
    if(i%3==0){
      printf("\n");
    }
    printf(" %d ",mA[i]);
  } 
}

int main(){
  int n=m*m;
  int m=9;
  inicializar(9, mA);
  inicializar(9, mB);
  inicializar(9, mB);
  impresion(n, mA);
  impresion(n, mB);
  impresion(n, mC);
  printf("fin del progama :v....\n");
  return 0;
}