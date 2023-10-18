#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int numChars = 0;
    for (int i = 1; i < argc; i++)
    {
        numChars += strlen(argv[i]);
    }

    char *concatenatedStr = malloc(numChars);
    for (int i = 1; i < argc; i++)
    {
        strcat(concatenatedStr, argv[i]);
    }

    printf("Concatenated args: %s\n", concatenatedStr);

    return EXIT_SUCCESS;
}
