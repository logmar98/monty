#include "monty.h"

/*if the file won't open*/
void stream_faild(char *file) {
        fprintf(stderr, "Error:Can't open file %s\n", file);
        free_node();
        exit(EXIT_FAILURE);
}

/*if the malloc failed*/
void malloc_failed(void){
        dprintf(2, "Error: malloc failed\n");
        free_node();
        exit(EXIT_FAILURE);
}