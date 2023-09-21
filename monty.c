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
        node->line_num += 1;
        tokenize_line();
        get_inst();
        run_inst();
        free_tokens();
    }
    
    return (0);
}

void stream_faild(char *file) {
        fprintf(stderr, "Error:Can't open file %s\n", file);
        free_node(node);
        exit(EXIT_FAILURE);
}
void malloc_failed(void){
        dprintf(2, "Error: malloc failed\n");
        free_node(node);
        exit(EXIT_FAILURE);
}
void tokenize_line(void) {
    int i = 0;
    char *dlm = " \n", *token =NULL, *cpy_l =NULL;

    cpy_l =malloc(sizeof(char) * (strlen(node->line) + 1));
    strcpy(cpy_l, node->line);
    node->num_tokens = 0;
    token = strtok(cpy_l, dlm);
    while (token)
    {
        node->num_tokens += 1;
        token = strtok(NULL,dlm);
    }
    node->tokens = malloc(sizeof(char *) * (node->num_tokens + 1));
    strcpy(cpy_l, node->line);
    token = strtok(cpy_l, dlm);
    while (token)
    {
        node ->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
        if (node->tokens[i] == NULL)
        {
            malloc_failed();
        }
        strcpy(node->tokens[i], token);
        token = strtok(NULL,dlm);
        i++;
    }
    node->tokens[i] = NULL;
    free(cpy_l);
    
    
}