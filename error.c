#include "monty.h"

/**
 * stream_faild - if the file won't open.
 * @file: the file path or the stream
 */
void stream_faild(char *file)
{
fprintf(stderr, "Error:Can't open file %s\n", file);
free_node();
exit(EXIT_FAILURE);
}

/**
 * malloc_failed - if malloc failed
 */
void malloc_failed(void)
{
dprintf(2, "Error: malloc failed\n");
free_node();
exit(EXIT_FAILURE);
}
