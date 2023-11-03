#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/*
  SUGESTÃO: utilize as páginas do manual para conhecer mais sobre as funções
  usadas: man fopen man fgets
*/

#define MAXLINESIZE 1000 /* or other suitable maximum line size */

int main(int argc, char *argv[]) {
  FILE *fp = NULL;
  char line[MAXLINESIZE];

  /* Validate number of arguments */
  if (argc < 2) {
    printf("USAGE: %s fileNames\n", argv[0]);
    return EXIT_FAILURE;
  }

  /* Open the file provided as argument */
  errno = 0;
  for (int i = 1; i < argc; i++) {
    int lineCount = 0;

    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      perror("Error opening file!");
      return EXIT_FAILURE;
    }

    /* Read all the lines of the file */
    while (fgets(line, sizeof(line), fp) != NULL) {
      lineCount++;
      // not needed to add '\n' to printf because fgets will read the '\n' that
      // ends each line in the file
      printf("%d  %s", lineCount, line);
    }

    fclose(fp);
  }

  return EXIT_SUCCESS;
}
