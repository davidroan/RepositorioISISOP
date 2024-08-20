/**************************************
Autor: David Roa Neisa
Materia: Sistemas Operativos
Fecha: 15/08/2024
Tema: gestion de memoria
  -Entornos en la web(Cloud/Nube)
  -Comandos principales de linux 
  -programa :matrizV1
***************************************/
#include<stdio.h>
#include<stdlib.h>

/*void inicializar(int n, int matriz){
  for(int i=0;i<n;i++){
    mA[i]=1;
    mB[i]=2;
    mC[i]=3;
  }
}*/

/**
 * Función: multiplicar
 * --------------------
 * Realiza la multiplicación de dos matrices cuadradas de tamaño nxn.
 *
 * Parámetros:
 *  n  : Dimensión de las matrices (n x n).
 *  mA : Puntero a la matriz A.
 *  mB : Puntero a la matriz B.
 *  mC : Puntero a la matriz C donde se almacenará el resultado.
 *
 * Retorna:
 *  No retorna ningún valor. El resultado se almacena en la matriz C.
 */

void multiplicar(int n, int *mA, int *mB, int *mC){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int suma = 0;
            for(int k=0; k<n; k++){
                suma += mA[i*n + k] * mB[k*n + j];
            }
            mC[i*n + j] = suma;
        }
    }
}
/**
 * Función: impresion
 * ------------------
 * Imprime en consola una matriz cuadrada de tamaño nxn.
 *
 * Parámetros:
 *  n      : Dimensión de la matriz (n x n).
 *  matriz : Puntero a la matriz a imprimir.
 *
 * Retorna:
 *  No retorna ningún valor. Imprime la matriz en consola.
 */
void impresion(int n, int *matriz){
    for(int i=0; i<n*n; i++){
        if(i%n == 0){
            printf("\n");
        }
        printf("%d ", *(matriz+i));
    } 
    printf("\n");
}
/**
 * Función: main
 * -------------
 * Función principal del programa. Se encarga de inicializar las matrices, 
 * realizar la multiplicación y mostrar los resultados.
 *
 * Parámetros:
 *  argc : Número de argumentos pasados al programa.
 *  argv : Array de cadenas de caracteres que contiene los argumentos.
 *
 * Retorna:
 *  0 si la ejecución del programa es exitosa.
 */
int main(int argc, char *argv[]){
    if(argc != 2){
        printf("\nArgumentos validos: $");
        exit(0);
    }
    int n = atoi(argv[1]);
    int size = n*n;
    int mA[size];
    int mB[size];
    int mC[size];

    for(int i=0; i<size; i++){
        mA[i] = 1;  
        mB[i] = 2;  
        mC[i] = 0;  
    }

    printf("\nMatriz A:");
    impresion(n, mA);

    printf("\nMatriz B:");
    impresion(n, mB);

    multiplicar(n, mA, mB, mC);

    printf("\nResultado de la multiplicación (Matriz C):");
    impresion(n, mC);
  
    printf("\nFin del programa :v....\n");
    return 0;
}
