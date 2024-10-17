/**************
*                                          *
* Autor: JDavid Roa Neisa         *
* Materia: Sistemas Operativos             *
* Fecha: 17-10-24                          *
* Tema: Piped Named Bidireccional          *
* CLIENTE                                  *
*                                          *
***************/

/*
Descripcion:
      Este programa crea un FIFO de nombre /tmp/fifo_twoway y envia un mensaje.
      para que le respondan con el mismo mensaje de vuelta, pero al reves. Siendo esta una conexion bidireccional.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>  

#define FIFO_FILE "/tmp/fifo_twoway"  // Definición del nombre del archivo FIFO

int main() {
    int fd;
    int end_process;
    int stringlen; 
    int read_bytes;
    char readbuf[80];
    char end_str[5];


    printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");

    // Abre el archivo FIFO para lectura y escritura o lo crea si no existe
    fd = open(FIFO_FILE, O_CREAT | O_RDWR, 0640);
    if (fd == -1) {  // Verifica si hubo un error al abrir el archivo
        perror("open");  // Imprime el error
        exit(EXIT_FAILURE); 
    }

    // Copia la cadena "end" en la variable end_str
    strcpy(end_str, "end");

    // Bucle infinito para enviar mensajes
    while (1) {
        printf("Enter string: ");  // Solicita al usuario que ingrese una cadena
        fgets(readbuf, sizeof(readbuf), stdin);  // Lee la cadena ingresada por el usuario
        stringlen = strlen(readbuf);  // Calcula la longitud de la cadena
        readbuf[stringlen - 1] = '\0';  // Reemplaza el carácter de nueva línea con el carácter nulo
        end_process = strcmp(readbuf, end_str);  // Compara la cadena leída con "end"

        if (end_process != 0) {  // Si la cadena no es "end"
            // Escribe la cadena en el archivo FIFO
            write(fd, readbuf, strlen(readbuf));
            printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
        } else {
            // Escribe la cadena "end" en el archivo FIFO y termina el bucle
            write(fd, readbuf, strlen(readbuf));
            printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
            close(fd);  // Cierra el descriptor de archivo
            break;  // Termina el bucle
        }
    }

    return 0;  // Retorna 0 indicando que el programa terminó correctamente
}
