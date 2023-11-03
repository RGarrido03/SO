#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int age;
  double height;
  char name[64];
} Person;

void printPersonInfo(Person *p) {
  printf("Person: %s, %d, %3.2f\n", p->name, p->age, p->height);
}

int main(int argc, char *argv[]) {
  FILE *fp = NULL;
  Person p;

  /* Validate number of arguments */
  if (argc != 2) {
    printf("USAGE: %s fileName\n", argv[0]);
    return EXIT_FAILURE;
  }

  /* Open the file provided as argument */
  errno = 0;
  fp = fopen(argv[1], "rb+");
  if (fp == NULL) {
    perror("Error opening file!");
    return EXIT_FAILURE;
  }

  /* read all the itens of the file to an array */
  Person arr[100];
  Person *arrPtr = &arr[0];

  while (fread(&p, sizeof(Person), 1, fp) == 1) {
    *arrPtr = p;
    printPersonInfo(&p);
    arrPtr++;
  }

  // Ask for how many people
  printf("How many new people? ");
  int count;
  scanf("%d", &count);

  Person *newArrPtr;
  newArrPtr = arrPtr;

  // Get people info
  for (int i = 0; i < count; i++) {
    char name[64];
    int age = 0;
    double height = NAN;

    printf("\n");

    printf("Name: ");
    scanf("%s", name);

    printf("Age: ");
    scanf("%d", &age);

    printf("Height: ");
    scanf("%lf", &height);

    p.age = age;
    p.height = height;
    strcpy(p.name, name);

    *arrPtr = p;
    arrPtr++;
  }

  fwrite(newArrPtr, sizeof(Person), count, fp);

  fclose(fp);

  return EXIT_SUCCESS;
}
