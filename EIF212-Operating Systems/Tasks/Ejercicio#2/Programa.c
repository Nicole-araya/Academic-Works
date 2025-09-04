#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    int pid;
    pid=fork();
    char *envp[]={"HOME=/","PATH=/bin:/usr/bin",NULL};
    char *argv[]={"ls","-l",NULL};

    if(pid<0){
        printf("Erro al crear el proceso\n");
        return 1;
    }

    if(pid==0){
        printf("Soy el proceso hijo \n");
        //execl("/bin/ls","ls","-l",NULL);
        //execle("/bin/ls","ls","-l",NULL, envp);
        //execlp("ls","ls","-l",NULL);
        //execv("/bin/ls",argv);
        //execvp("ls",argv);
        execvpe("ls",argv,envp);


    }

    if(pid>0){
        wait(NULL);
        printf("Soy el proceso padre \n");
    }
   return 0;
}
