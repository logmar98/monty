#include "monty.h"
int main(int ac, char **av) {

    char *file = av[1];
    if (ac == 1 || ac > 2)
    {
        perror("USAGE: monty file");
        exit(EXIT_FAILURE);
    }
    if (access(file, F_OK) != 0)
    {
        printf("Error: Can't open file %s\n", file);
        exit(EXIT_FAILURE);
    }
    

    return 0;
}

#include "monty.h"
node_s node = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @ac: number of arguments
* @av: monty file location
* Return: 0 on success
*/
int main(int ac, char *av[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if ((ac == 1 || ac > 2))
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	node.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		node.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
