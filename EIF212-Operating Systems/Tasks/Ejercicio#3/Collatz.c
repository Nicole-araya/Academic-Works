#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int collatz(int n) {
   int count = 0;
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = 3 * n + 1;
    }
    printf(" %d,",n);
    count++;
  }
  return count;
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Uso: %s n\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int pid = fork();

    if(pid<0){
    printf("Error al crear el proceso hijo\n");
    return 1;
    }

    if(pid==0){
    printf("Holis, soy el proceso hijo ;D, la sucesion de %d es \n",n);
    int count = collatz(n);
    printf(" siendo %d pasos\n\n", count);
    }

    if(pid>0){
    wait(NULL);
    printf("Ahora soy el proceso padre y termino el programa :D\n");
    }

  return 0;
}
