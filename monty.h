#ifndef __MONTY_H__
#define __MONTY_H__
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode ;
        void (*f)(stack_t **head, unsigned int counter);
} instruction_t;
/**
 * struct node - here we will store all our data
 * @stream:is the file stream
 * @line: our buffer
 * @line_num: the current line
 * @tokens: array of of command and input number
 * @num_tokens: number of token
 * @instruction: command instruction
 * @head: our head node
 * @stack_len: our stack len
 *
 */
typedef struct node_s
{
    FILE *stream;
    char *line;
    unsigned int line_num;
    char **tokens;
    int num_tokens;
    instruction_t *instruction;
    stack_t *head;
    int stack_len;
    
} node_t;
extern node_t *node;


void get_file(char *stream);
void malloc_failed(void);
void stream_faild(char *file);
void free_node();
void splite_line(void);
void get_cmd(void);
void run_cmd(void);
void free_tokens(void);
void close_stream(void);
int is_num(char *str);
void free_head(void);
void free_stack(stack_t *head);
void free_nodes(void);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif
