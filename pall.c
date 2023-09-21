#include "monty.h"
/*print all the data number in the node or the int n*/
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