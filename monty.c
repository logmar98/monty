#include "monty.h"
node_t *node = NULL;
int main(int ac, char *av[])
{
    int fd;
    size_t line_size = 0;

    if (ac != 2)
    {
        dprintf(2,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    node = malloc(sizeof(node_t));
    if (node == NULL) {
        dprintf(2, "Error: malloc failed\n");
        free_node(node);
        exit(EXIT_FAILURE);
    }
    node->stream = NULL;
    node->line = NULL;
    
    fd = open(av[1], O_RDONLY);
    if (fd == -1){
        stream_faild(av[1]);
    }
    node->stream = fdopen(fd, "r");
    if (node->stream == NULL)
    {
        close(fd);
        stream_faild(av[1]);
    }
    
    while (getline(&node->line, &line_size, node->stream) != -1)
    {
        printf("%s", node->line);
    }
    
    return (0);
}

void stream_faild(char *file) {
        fprintf(stderr, "Error:Can't open file %s\n", file);
        free_node(node);
        exit(EXIT_FAILURE);
}
