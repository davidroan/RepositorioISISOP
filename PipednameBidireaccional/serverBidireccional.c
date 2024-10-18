/**************
 Autor: David Roa Neisa
 Materia: Sistemas Operativos 
 Fecha: 17-10-24                        
 Tema: Piped Named Bidireccional          
 SERVER                                                                             *
***************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_FILE "/tmp/fifo_twoway"  // Definición del nombre del archivo FIFO

// firma de la función que invierte una cadena de caracteres
void reverse_string(char *str);

int main() {
    //creacion de varibles
    int fd;             
    char readbuf[80];  
    char end[10];      
    int to_end;        
    int read_bytes;

   
    // Verificar si el archivo FIFO ya existe
    if (access(FIFO_FILE, F_OK) == -1) {
        // Crear el archivo FIFO si no existe
        if (mkfifo(FIFO_FILE, 0640) == -1) {
            perror("mkfifo");  
            exit(EXIT_FAILURE); 
        }
    }

    strcpy(end, "end"); 
    fd = open(FIFO_FILE, O_RDWR);  // Abrir el FIFO para lectura y escritur

    while (1) {
        // Leer datos del FIFO
        read_bytes = read(fd, readbuf, sizeof(readbuf));
        // Cerrar el descriptor de archivo
        if (read_bytes == -1) {
            perror("read");  
            close(fd);  
            exit(EXIT_FAILURE); 
        }
        readbuf[read_bytes] = '\0';  // Añadir terminador nulo a la cadena leída
        printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));  // Imprimir
        to_end = strcmp(readbuf, end);  // Comparar la cadena

        if (to_end == 0) {
            close(fd);  // Cerrar el descriptor de archivo
            break;  // Salir del bucle
        }
        reverse_string(readbuf);  // Invertir la cadena leída
        printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));  // Imprimir 
        if (write(fd, readbuf, strlen(readbuf)) == -1) {
            perror("write");  
            close(fd);
            exit(EXIT_FAILURE);  
        }
        sleep(2);
    }
    return 0; 
}

/*
Nombre:reverse_string
Entrada: revibe un puntero a una cadena de caracteres
Retorno: No devulve ningun dato
funcion:invierte una cadena de caracteres recibida por apuntador
*/
void reverse_string(char *str) {
    //creacion de variables
    int last, limit, first;
    char temp;
    last = strlen(str) - 1; 
    limit = last/2; 
    first = 0;  

    //Ciclo para cambiar el orden de la cadena
    while (first <= limit) {
        temp = str[first];  
        str[first] = str[last];  // Intercambiar el carácter actual con el carácter del final
        str[last] = temp;  // Colocar el carácter temporal en la posición final
        first++;  // Incrementar el índice del primer carácter
        last--;  // Decrementar el índice del último carácter
    }
}
