#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_null.h>

/*
  SUGESTÃO: utilize as páginas do manual para conhecer mais sobre as funções
  usadas: man system man date
*/

void printToConsoleAndFile(FILE *fp, char *format, char *str, ...) {
  printf(format, str);
  fprintf(fp, format, str);
}

int main(int argc, char *argv[]) {
  char text[1024];
  char out[1024];

  FILE *fp = fopen("command.log", "a");

  do {
    printToConsoleAndFile(fp, "%s", "Command: ");
    scanf("%1023[^\n]%*c", text);
    fprintf(fp, "%s", text);

    /*
      system(const char *command) executes a command specified in command
      by calling /bin/sh -c command, and returns after the command has been
      completed.
    */
    if (strcmp(text, "end")) {
      printToConsoleAndFile(fp, "\n * Command to be executed: %s\n", text);
      printToConsoleAndFile(fp, "%s", "---------------------------------\n");

      system(strcat(text, "> temp.txt"));
      FILE *fpOut = fopen("temp.txt", "r");
      fgets(out, sizeof(out), fpOut);
      fclose(fpOut);

      printToConsoleAndFile(fp, "%s", out);
      printToConsoleAndFile(fp, "%s", "---------------------------------\n");
    }
  } while (strcmp(text, "end"));

  printToConsoleAndFile(fp, "%s", "-------------The End-------------\n");

  return EXIT_SUCCESS;
}
