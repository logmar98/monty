#include "monty.h"


void free_node(node_t *stack)
{
	free(stack);
}

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

void close_stream(void)
{
	if (node->stream == NULL)
	{
		return;
	}
	fclose(node->stream);
	node->stream = NULL;
}