#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double argToDouble(char *arg) {
  char *err_ptr;
  double n = strtod(arg, &err_ptr);

  if (*err_ptr != '\0') {
    printf(
        "%s is not numeric, so conversion to number might not be accurate.\n",
        err_ptr);
  }

  return n;
}

int main(int argc, char **argv) {
  int min = (int)argToDouble(argv[1]);
  int max = (int)argToDouble(argv[2]);

  int tries = 0;

  srand(time(0));
  int randomNumber = rand() % (max - min + 1) + min;
  int input;

  while (1) {
    tries++;
    scanf("%d", &input);

    if (input > randomNumber) {
      printf("High\n");
    } else if (input == randomNumber) {
      printf("You did it! You took %d tries.\n", tries);
      break;
    } else {
      printf("Low\n");
    }
  }

  return 0;
}