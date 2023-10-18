#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    int numChars = 0;
    for (int i = 1; i < argc; i++)
    {
        if (isalpha(argv[i][0]))
        {
            numChars += strlen(argv[i]);
        }
    }

    char *concatenatedStr = malloc((numChars + 1) * sizeof *concatenatedStr);

    if (concatenatedStr == NULL)
    {
        fprintf(stderr, "Malloc failed!\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        if (isalpha(argv[i][0]))
        {
            strcat(concatenatedStr, argv[i]);
        }
    }

    printf("Concatenated args: %s\n", concatenatedStr);

    free(concatenatedStr);
    return EXIT_SUCCESS;
}
