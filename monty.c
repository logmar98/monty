#include "monty.h"
int main(int ac, char **av) {

    char *file = av[1];
    if (ac == 1 || ac > 2)
    {
        perror("USAGE: monty file");
        exit(EXIT_FAILURE);
    }else if (access(file, F_OK) != 0)
    {
        printf("Error: Can't open file %s\n", file);
        exit(EXIT_FAILURE);
    }
    

    return 0;
}