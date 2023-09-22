#include "monty.h"

/**
 * add - add the top two elements in the head.
 * @stack: its a pointer to the slack
 * @line_number: the line that call the function
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *temp1, *temp2;
(void)stack;
if (node->stack_len < 2)
{
dprintf(2, "L%d: can't add, stack too short\n", line_number);
free_nodes();
exit(EXIT_FAILURE);
}
temp1 = node->head;
temp2 = node->head->next;
temp2->n = temp1->n + temp2->n;
if (1)
{
stack_t *temp;
temp = node->head;
node->head = temp->next;
node->head->prev = NULL;
free(temp);
}
node->stack_len -= 1;
}
