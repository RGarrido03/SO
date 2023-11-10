#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 65536

// Stolen from Stack Overflow, periodt
int count_lines(FILE *file) {
  char buf[BUF_SIZE];
  int counter = 0;

  while (!feof(file)) {
    size_t res = fread(buf, 1, BUF_SIZE, file);
    if (ferror(file))
      return -1;

    int i;
    for (i = 0; i < res; i++)
      if (buf[i] == '\n')
        counter++;
  }

  return counter;
}

int compareInts(const void *px1, const void *px2) {
  int x1 = *((int *)px1);
  int x2 = *((int *)px2);
  return (x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[]) {
  int i = 0, numSize;
  int *numbers;
  char line[BUF_SIZE];

  FILE *fp = fopen(argv[1], "r");

  numSize = count_lines(fp);
  rewind(fp);

  // Memory allocation for all the numbers in the arguments
  numbers = (int *)malloc(sizeof(int) * numSize);

  // Storing the arguments in the "array" numbers
  while (fgets(line, sizeof(line), fp)) {
    numbers[i] = atoi(line);
    i++;
  }

  fclose(fp);

  // Uncomment for using fscanf
  /*
  for (int i = 0; i < numSize; i++) {
    fscanf(fp, "%d", &numbers[i]);
  }
  */

  qsort(numbers, numSize, sizeof(int), compareInts);

  // Printing the sorted numbers
  printf("Sorted numbers: \n");
  for (i = 0; i < numSize; i++) {
    printf("%d\n", numbers[i]);
  }

  return EXIT_SUCCESS;
}
