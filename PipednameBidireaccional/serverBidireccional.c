/**************
*                                          *
* Autor: Juan Diego Muñoz Angulo           *
* Materia: Sistemas Operativos             *
* Fecha: 17-10-24                          *
* Tema: Piped Named Bidireccional          *
* SERVER                                   *
*                                          *
***************/

/*
Descripcion:
    Este programa crea un FIFO de nombre /tmp/fifo_twoway y espera a que el cliente envie un mensaje
    para responderle con el mismo mensaje de vuelta, pero al reves. Siendo esta una conexion bidireccional.


*/


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
    int fd;             // Descriptor de archivo
    char readbuf[80];   // Buffer para leer datos del FIFO
    char end[10];       // Cadena para comparar el fin del proceso
    int to_end;         // Variable para determinar el fin del proceso
    int read_bytes;

   
    // Verificar si el archivo FIFO ya existe
    if (access(FIFO_FILE, F_OK) == -1) {
        // Crear el archivo FIFO si no existe
        if (mkfifo(FIFO_FILE, 0640) == -1) {
            perror("mkfifo");  // Imprimir error si mkfifo falla
            exit(EXIT_FAILURE); 
        }
    }

    strcpy(end, "end");  // Copiar la cadena "end" a la variable end
    fd = open(FIFO_FILE, O_RDWR);  // Abrir el FIFO para lectura y escritura
    if (fd == -1) {
        perror("open");  // Imprimir error si open falla
        exit(EXIT_FAILURE);  // Salir del programa con error
    }

    while (1) {
        // Leer datos del FIFO
        read_bytes = read(fd, readbuf, sizeof(readbuf));
        if (read_bytes == -1) {
            perror("read");  // Imprimir error si read falla
            close(fd);  // Cerrar el descriptor de archivo
            exit(EXIT_FAILURE);  // Salir del programa con error
        }
        readbuf[read_bytes] = '\0';  // Añadir terminador nulo a la cadena leída
        printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));  // Imprimir la cadena recibida y su longitud
        to_end = strcmp(readbuf, end);  // Comparar la cadena leída con "end"

        if (to_end == 0) {
            close(fd);  // Cerrar el descriptor de archivo
            break;  // Salir del bucle
        }
        reverse_string(readbuf);  // Invertir la cadena leída
        printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));  // Imprimir la cadena invertida y su longitud
        if (write(fd, readbuf, strlen(readbuf)) == -1) {
            perror("write");  // Imprimir error si write falla
            close(fd);  // Cerrar el descriptor de archivo
            exit(EXIT_FAILURE);  // Salir 
        }
        
        //Esto es para asegurarse de que el otro proceso lea bien todo
        sleep(2);  // Dormir por 2 segundos
    }
    return 0;  // Retornar 0 indicando que el programa terminó correctamente
}

// Función que invierte una cadena de caracteres
// Recibe: un puntero a una cadena de caracteres
// Retorno: No tiene
void reverse_string(char *str) {
    int last, limit, first;
    char temp;
    last = strlen(str) - 1;  // Índice del último carácter de la cadena
    limit = last/2;  // Límite para la inversión
    first = 0;  // Índice del primer carácter de la cadena

    while (first <= limit) {
        temp = str[first];  // Almacenar el carácter actual en una variable temporal
        str[first] = str[last];  // Intercambiar el carácter actual con el carácter del final
        str[last] = temp;  // Colocar el carácter temporal en la posición final
        first++;  // Incrementar el índice del primer carácter
        last--;  // Decrementar el índice del último carácter
    }
}