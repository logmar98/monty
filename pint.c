#include "monty.h"
/**
 * pint - print the top element.
 * @stack: its a pointer to the slack
 * @line_number: the line that call the function
 */
void pint(stack_t **stack, unsigned int line_number)
{
(void)stack;
if (node->head == NULL)
{
dprintf(2, "L%d: can't pint, stack empty\n", line_number);
free_nodes();
exit(EXIT_FAILURE);
}
printf("%d\n", node->head->n);
}
