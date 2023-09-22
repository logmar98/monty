#include "monty.h"
/**
 * get_cmd - get our command
 */
void get_cmd(void)
{
int i = 0;
instruction_t instructions[] = {
{"push", &push},
{"pall", &pall},
{"pint", &pint},
{"pop", &pop},
{"swap", &swap},
{"add", &add},
{"nop", &nop},
{NULL, NULL}
};

if (node->num_tokens == 0)
{
return;
}

for (; instructions[i].opcode != NULL; i++)
{
if (strcmp(instructions[i].opcode, node->tokens[0]) == 0)
{
node->instruction->opcode = instructions[i].opcode;
node->instruction->f = instructions[i].f;
return;
}

}

dprintf(2, "L%d: unknown instruction %s\n", node->line_num, node->tokens[0]);
close_stream();
free_tokens();
free_node();
exit(EXIT_FAILURE);

}
/**
 * run_cmd - run our command
 */
void run_cmd(void)
{
stack_t *stack = NULL;
if (node->num_tokens == 0)
{
return;
}
node->instruction->f(&stack, node->line_num);

}
