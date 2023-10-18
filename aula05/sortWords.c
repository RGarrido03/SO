#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/_types/_null.h>

#define MAX_WORDS 100
#define MAX_WORDS_LENGTH 100

int compare(const void *a, const void *b) {
  char *order = getenv("SORTORDER");
  if (order != NULL && strcmp(order, "DESC") == 0) {
    return strcasecmp(*(char **)b, *(char **)a);
  } else {
    return strcasecmp(*(char **)a, *(char **)b);
  }
}

int main(int argc, char **argv) {
  int i;
  char **input = malloc(MAX_WORDS * sizeof(char *));

  printf("Enter words (one per line, empty line to finish):\n");

  for (i = 0; i < MAX_WORDS; i++) {
    input[i] = malloc(MAX_WORDS_LENGTH * sizeof(char));
    fgets(input[i], MAX_WORDS_LENGTH, stdin);

    if (input[i] == NULL || input[i][0] == '\n') {
      break;
    }
  }
  qsort(input, i, sizeof(char *), compare);

  for (int j = 0; j < i; j++) {
    printf("%s", input[j]);
    free(input[j]);
  }
  free(input);

  return 0;
}