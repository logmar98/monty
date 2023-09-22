#include "monty.h"
/**
 * pop - remove the top element.
 * @stack: its a pointer to the slack
 * @line_number: the line that call the function
 */
void pop(stack_t **stack, unsigned int line_number)
{
(void)stack;
if (node->head == NULL)
{
dprintf(2, "L%d: can't pop an empty stack\n", line_number);
free_nodes();
exit(EXIT_FAILURE);
}
if (1)
{
stack_t *temp;
temp = node->head;
node->head = temp->next;
free(temp);
}
node->stack_len -= 1;
}
