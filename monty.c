#include "monty.h"
node_t *node = NULL;
int main(int ac, char *av[])
{
    int fd;
    size_t line_size = 0;
    /*if the user does not give any file*/
    if (ac != 2)
    {
        dprintf(2,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    /*create and fill our node datas and cheack if the malloc failed or seccess*/
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
    /*open the file and cheack if the file can't be open*/
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
    /*a loop that in every loop take a new line and splitite and cheak the command if there and run the command if it thir*/
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


