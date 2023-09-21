#include "monty.h"

/*free our node*/
void free_node(node_t *stack)
{
	free(stack);
}
/*free our tokens*/
void free_tokens(void){
	int i = 0;
	if (node->tokens == NULL)
	{
		return;
	}
	while (node->tokens[i])
	{
		free(node->tokens[i]);
		i++;
	}
	free(node->tokens);
	node->tokens = NULL;
	
	
}
/*close our stream, stream is the file_name*/
void close_stream(void)
{
	if (node->stream == NULL)
	{
		return;
	}
	fclose(node->stream);
	node->stream = NULL;
}
/*splite our line to get the command and the input*/
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