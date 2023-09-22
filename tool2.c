#include "monty.h"

/**
 * close_stream - close file.
 */
void close_stream(void)
{
if (node->stream == NULL)
{
return;
}
fclose(node->stream);
node->stream = NULL;
}
/**
 * splite_line - splite our line.
 */
void splite_line(void)
{
int i = 0;
char *dlm = " \n", *token = NULL, *cpy_l = NULL;
cpy_l = malloc(sizeof(char) * (strlen(node->line) + 1));
strcpy(cpy_l, node->line);
node->num_tokens = 0;
token = strtok(cpy_l, dlm);
while (token)
{
node->num_tokens += 1;
token = strtok(NULL, dlm);
}
node->tokens = malloc(sizeof(char *) * (node->num_tokens + 1));
strcpy(cpy_l, node->line);
token = strtok(cpy_l, dlm);
while (token)
{
node->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
if (node->tokens[i] == NULL)
{
malloc_failed();
}
strcpy(node->tokens[i], token);
token = strtok(NULL, dlm);
i++;
}
node->tokens[i] = NULL;
free(cpy_l);
}
