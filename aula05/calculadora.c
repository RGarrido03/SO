#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void checkArgs(int argc, int desiredArgc)
{
    if (argc != desiredArgc + 1)
    {
        printf("Arguments length is different from %d\n", desiredArgc);
        exit(EXIT_FAILURE);
    }
}

double argToDouble(char *arg){
    char *err_ptr;
    double n = strtod(arg, &err_ptr);

    if (*err_ptr != '\0') {
        printf("%s is not numeric, so conversion to number might not be accurate.\n", err_ptr);
    }

    return n;
}

int main(int argc, char *argv[])
{
    checkArgs(argc, 3);

    double n1 = argToDouble(argv[1]);
    double n2 = argToDouble(argv[3]);
    double result;

    switch (*argv[2])
    {
    case '+':
        result = n1 + n2;
        break;

    case '-':
        result = n1 - n2;
        break;

    case 'x':
        result = n1 * n2;
        break;

    case '/':
        result = n1 / n2;
        break;

    case 'p':
        result = pow(n1, n2);
        break;

    default:
        printf("Invalid operation: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    printf("%.1f\n", result);
    return EXIT_SUCCESS;
}
