#include "monty.h"
node_t *node = NULL;
/**
 * main - our main program
 * @ac: argument counter
 * @av: argument index
 * Return: return 0
 */
int main(int ac, char *av[])
{
size_t line_size = 0;
if (ac != 2)
{
dprintf(2, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
node = malloc(sizeof(node_t));
if (node == NULL)
{
malloc_failed();
}
node->instruction = malloc(sizeof(instruction_t));
if (node->instruction == NULL)
{
malloc_failed();
}
node->stream = NULL;
node->line = NULL;
node->num_tokens = 0;
node->line_num = 0;
get_file(av[1]);
while (getline(&node->line, &line_size, node->stream) != -1)
{
node->line_num += 1;
splite_line();
get_cmd();
run_cmd();
free_tokens();
}
return (0);
}
/**
 * get_file - our main program
 * @stream: file name
 */
void get_file(char *stream)
{
int fd;
fd = open(stream, O_RDONLY);
if (fd == -1)
{
stream_faild(stream);
}
node->stream = fdopen(fd, "r");
if (node->stream == NULL)
{
close(fd);
stream_faild(stream);
}
}
