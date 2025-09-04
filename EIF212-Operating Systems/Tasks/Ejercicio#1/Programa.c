#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
int file, pid;

file=open("file.txt",O_RDONLY);

if(file<0){
printf("Error al abrir el archivo\n");
return 1;
}

pid=fork();

if(pid<0){
    printf("Error al crear el proceso hijo\n");
    return 1;
}

if(pid==0){
    printf("Soy el proceso hijo\n");
    close(file);
}

if(pid>0){
    printf("Soy el proceso padre\n");
     close(file);
}

return 0;
}
