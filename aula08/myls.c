#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int stat = 0;
    printf("================================================\n");

    switch (fork()) {
        case -1: // Fork falhou
            perror("Erro no fork\n");
            return EXIT_FAILURE;

        case 0: // Processo filho
            system("ls -l");
            break;

        default: // Processo pai
            if (wait(&stat) < 0) {
                perror("erro na espera da terminação do processo-filho");
                return EXIT_FAILURE;
            }
            printf("================================================\n");
    }

    return EXIT_SUCCESS;
}
