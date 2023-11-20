#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

enum {
    NTIMES = 50
};

static void Interrupt(int /*signum*/);

int main(int argc, char *argv[]) {
    struct sigaction sigact;
    unsigned int i = 0;

    /* altera a rotina de atendimento ao ^C */
    sigact.sa_handler = Interrupt;
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = 0;
    if (sigaction(SIGINT, &sigact, NULL) < 0) {
        perror("Rotina de atendimento não instalada\n");
        return EXIT_FAILURE;
    }

    /* contador */
    printf("PID = %u\n", getpid());
    i = 0;
    while (i <= NTIMES) {
        printf("\r%08u ", i++);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

int count = 0;

static void Interrupt(int signum) {
    count++;
    if (signum == SIGINT && count < 5) {
        printf("\nCalma, ainda não cheguei a %d!\n", NTIMES);
    } else {
        exit(EXIT_FAILURE);
    }
}
