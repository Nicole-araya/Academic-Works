/*
 * Proyecto #1 SO
 Integrantes:
                Nicole Araya Ballestero
                Esteban Mojica Gonzalez

 */

#include <bits/types/idtype_t.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <signal.h>
#define MAX_ARGS 10


int amperson(char programa[], char* token, char *args[]);
int pipes(char *args[], char* token);
void normal(char programa[], char *args[]);
char* comandoAdmiracion(char *comando, int tam,char *historial[]);
int buildIn(char comando[],char *historial[], int *tam);
void sig_child(int signo);


int main() {
    setbuf(stdout, NULL);
    char* historial[16]={NULL};
    int tam=0;

    while (1) {

        char comando[100]="";

        printf("uwu > ");

        fgets(comando, sizeof(comando), stdin);
        strtok(comando, "\n"); // eliminar el salto de línea

        // Verificar si el comando es una cadena vacía
        int is_empty = 1;
        for (int i = 0; i < strlen(comando); i++) {
            if (!isspace(comando[i])) {
                is_empty = 0;
            }
        }

                                                             // Si es false = salir del programa si se ingresa "exit" o enseñar el historial y no entra
        if(buildIn(comando,historial,&tam) && !is_empty){    //si esta vacio no entra


            char* cmd = comandoAdmiracion(comando, tam, historial);
            if (cmd != NULL) {
                strcpy(comando, cmd); //si existe !N se sobreescribe a comando
            }

             //Guardar comandos en historial
           for(int i = tam; i>0;i--){
             free(historial[i]);
             historial[i] = strdup(historial[i-1]);
           }

           free(historial[0]);
           historial[0]=strdup(comando);
           if(tam<15){tam++;}


            char* programa = strtok(comando, " \t"); // primer token es el nombre del programa
            char* args[MAX_ARGS+1] = {programa, NULL}; // arreglo de apuntadores para los argumentos
            int num_args = 1; // contador para el número de argumentos

            // procesa los tokens restantes
            char* token;
            bool pipeBool=0;
            bool ampersonBool=0;
            bool overflow = 0;
            while ((token = strtok(NULL, " \t")) != NULL) {

                if(amperson(programa, token, args)){
                    ampersonBool=1;
                    break;
                }               //nicole hermosa &

                else if(pipes(args, token)){
                    pipeBool=1;
                    break;
                }               //nicole hermosa | exitosa

                else{
                    // almacenar el argumento en el arreglo
                    if (num_args >= MAX_ARGS) {
                        printf("Demasiados argumentos\n");
                        overflow=1;
                        break;
                    }
                    args[num_args++] = token;
                }
            }

            // si no se especificó "&" o "|" y no sobre pasa los argumentos, ejecutar comando normal
            if (!ampersonBool && !pipeBool && !overflow ) {
                    normal(programa, args);
            }
        }

    }
    return 0;//nicolesteban pendejo
}

char* comandoAdmiracion(char *comando, int tam,char *historial[]) {

    if (comando[0] != '!') {  // si el comando no empieza con "!", no tiene "!"
        return NULL;
    }

    int n = atoi(&comando[1]); // obtener el número N después del "!"
    if (n <= 0 || n > 16) { // verificar si el número es válido
        return NULL;
    }

    // obtener el comando en la posición N-1 del historial
    char* cmd = historial[n-1];
    if (cmd == NULL) { // verificar si el comando existe
        return NULL;
    }

    // devolver el comando
    return cmd;
}

int amperson(char programa[], char* token, char *args[]){

    if(!strcmp(token, "&")){

            signal(SIGCHLD, sig_child); //Terminar el hijo que esta en segundo plano

            pid_t pid = fork();

            if (pid == -1) {
                printf("Error al crear proceso hijo\n");
                return 0;

            } else if (pid == 0) {
                // proceso hijo
                printf("Background, PID %d \n", getpid() );  //PID Del hijo

                if (execvp(programa, args) == -1) {
                    printf("Error al ejecutar el comando\n");
                    return 1;
                }

            } else { // proceso padre
                sleep(0);// sin esto se tira antes el uwu
                return 1;
            }

        }
        return 0;
}

int pipes( char *args[], char* token) {
    if (!strcmp(token, "|")) {

        char* otros_args[MAX_ARGS];
        int num_otros= 0;

        while ((token = strtok(NULL, " \t")) != NULL) { // obtener los otros argumentos despues de "|"

             otros_args[num_otros++] = token;
        }

        otros_args[num_otros] = NULL; //final de los argumentos

        int fd1[2];     //leer, escribir
        int status, pid;

        if (pipe(fd1) == -1) {
            printf("Error al crear la tubería\n");
            return 0;
        }

        pid = fork();

        if(pid == 0){              /* hijo 1*/
            close(fd1[0]);   /* cerrar  READ */

            dup2(fd1[1], STDOUT_FILENO);  //duplicamos write

            close(fd1[1]);  //cerrar WRITE

            if (execvp(args[0], args) == -1) {
            printf("Error al ejecutar el primer programa\n");
            exit(1);
            }

        }else{                  /* padre */
            close(fd1[1]);    /* cerrar WRITE */

            pid = fork();

            if(pid == 0){               /* hijo 2 */

                dup2(fd1[0], STDIN_FILENO); //duplicamos read
                close(fd1[0]);

                if (execvp(otros_args[0], otros_args) == -1) {
                    printf("Error al ejecutar el segundo programa\n");
                    exit(1);
                }

            }
            else{  /* padre */
                close(fd1[0]);      /* cerrar extremo no necesario */


            }
        }

        /* wait para cada hijo */
        wait(&status);
        wait(&status);
        return 1;
    }
    return 0;
}


void normal(char programa[], char *args[]){

   printf("Ejecutando %s:\n", programa);

    pid_t pid = fork();  // crear un nuevo proceso hijo

    if (pid < 0) {
        printf("Error al crear el proceso hijo\n");
        return;
    }

    if (pid == 0) { // proceso hijo

        if (execvp(programa, args) == -1) { // ejecutar el comando utilizando execvp
            printf("Error al ejecutar el comando\n");
            exit(0); // salir del proceso hijo
        }
    } else { // proceso padre
        wait(NULL); // esperar a que el proceso hijo termine
    }
}

int buildIn(char comando[], char *historial[], int *tam){

    if (strcmp(comando, "exit") == 0) {
        printf("Saliendo de la shell...\n");

        // liberar la memoria del historial
        for (int i = 0; i < *tam; i++) {
            free(historial[i]);
        }
        exit(0); // y se sale

    }else if(strcmp(comando, "historial") == 0){
        printf("--HISTORIAL--\n");
        for(int i=0; i<=*tam; i++){

            if(historial[i]!=NULL)
            printf("%d. %s \n",i+1,historial[i]);
        }
        return 0;
    }
    return 1;
}

void sig_child(int signo) {  //metodo para cuando termina de ejecutarse hijo en segundo plano
    int status;
    pid_t pid;
    // Limpiar procesos hijos terminados
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        printf("Done PID:%d \nuwu > ", pid);
    }
}
