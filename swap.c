#include "monty.h"
/**
 * swap - swap the top two numbers.
 * @stack: its a pointer to the slack
 * @line_number: the line that call the function
 */
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *temp1, *temp2;
(void)stack;
if (node->stack_len < 2)
{
dprintf(2, "L%d: can't swap, stack too short\n", line_number);
free_nodes();
exit(EXIT_FAILURE);
}
temp1 = node->head;
temp2 = node->head->next;
temp1->next = temp2->next;
if (temp1->next)
{
temp1->next->prev = temp1;
}
temp2->next = temp1;
temp1->prev = temp2;
temp2->prev = NULL;
node->head = temp2;
}
