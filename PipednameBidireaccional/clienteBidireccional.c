/********
Autor: David Roa Neisa         
Materia: Sistemas Operativos             
Fecha: 17-10-24                          
Tema: Piped Named Bidireccional                                            *                                        
**************/

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

    // Copia la cadena "end" en la variable end_str
    strcpy(end_str, "end");

    // Bucle infinito
    while (1) {
      // Solicita al usuario que ingrese una cadena
        printf("Enter string: ");  
        fgets(readbuf, sizeof(readbuf), stdin);  
        stringlen = strlen(readbuf);  
        readbuf[stringlen - 1] = '\0';  
        end_process = strcmp(readbuf, end_str);  

        if (end_process != 0) {  
            // Escribe la cadena en el archivo FIFO
            write(fd, readbuf, strlen(readbuf));
            printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
        } else {
            // Escribe la cadena "end" en el archivo FIFO y termina el bucle
            write(fd, readbuf, strlen(readbuf));
            printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
            close(fd); 
            //acaba con el bucle
            break; 
        }
    }

    return 0; 
}
