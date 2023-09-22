#include "monty.h"

/**
 * push - push an element to the node.
 * @stack: its a pointer to the slack
 * @line_number: the line that call the function
 */
void push(stack_t **stack, unsigned int line_number)
{
if (node->num_tokens <= 1 || !(is_num(node->tokens[1])))
{
free_node();
dprintf(2, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
*stack = malloc(sizeof(stack_t));
if (*stack == NULL)
{
malloc_failed();
}
(*stack)->next = (*stack)->prev = NULL;
(*stack)->n = (int) atoi(node->tokens[1]);
if (node->head != NULL)
{
(*stack)->next = node->head;
node->head->prev = *stack;
}
node->head = *stack;
node->stack_len += 1;
}
/**
 * is_num - cheack if its a number.
 * @str: string
 * Return: 0 if not a digit 1 if it's a digit
 */
int is_num(char *str)
{
int i = 0;
while (str[i])
{
if (i == 0 && str[i] == '-' && str[i + 1])
{
i++;
continue;
}
if (str[i] < '0' || str[i] > '9')
{
return (0);
}
i++;
}
return (1);
}
