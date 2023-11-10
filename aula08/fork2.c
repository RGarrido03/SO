#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    int ret = fork();

    if (ret < 0) {
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret == 0) {
        printf("\nFILHO\n");
    }
    if (ret > 0) {
        sleep(1);
        printf("\nPAI\n");
    }

    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d\n",
           getpid(), getppid(), ret);

    return EXIT_SUCCESS;
}
