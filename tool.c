#include "monty.h"

/**
 * free_node - free our node
 */
void free_node(void)
{
if (node == NULL)
{
return;
}
if (node->instruction)
{
free(node->instruction);
node->instruction = NULL;
}
free_head();

if (node->line)
{
free(node->line);
node->line = NULL;
}
free(node);

}
/**
 * free_head - free our heads
 */
void free_head(void)
{
if (node->head)
{
free_stack(node->head);
}
node->head = NULL;
}
/**
 * free_stack - free our stack
 * @head: head node
 */
void free_stack(stack_t *head)
{
if (head == NULL)
{
return;
}
if (head->next != NULL)
{
free_stack(head->next);
}
free(head);

}
/**
 * free_tokens - free our tokens
 */
void free_tokens(void)
{
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
/**
 * free_nodes - free our nodes
 */
void free_nodes(void)
{
close_stream();
free_tokens();
free_node();
}
