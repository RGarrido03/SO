#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int desiredArgc = 2;

    if (argc == desiredArgc + 1)
    {
        for (int i = 0; i < argc; i++)
        {
            printf("Argument %02d: \"%s\"\n", i, argv[i]);
        }
        return EXIT_SUCCESS;
    }

    printf("Arguments length is different from %d\n", desiredArgc);
    return EXIT_FAILURE;
}
