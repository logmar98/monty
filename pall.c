#include "monty.h"
/**
 * pall - print all the push elements.
 * @stack: its a pointer to the slack
 * @line_number: the line that call the function
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if (node->head == NULL)
{
return;
}
(void)line_number;
(void)stack;
temp = node->head;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
