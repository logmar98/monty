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


typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **head, unsigned int counter);
} instruction_t;


typedef struct node_s
{
    FILE *stream;
    char *line;
    unsigned int line_num;
    char **tokens;
    int num_tokens;
    instruction_t *instruction;
} node_t;
extern node_t *node;

void malloc_failed(void);
void stream_faild(char *file);
void free_node(node_t *stack);
void tokenize_line(void);
void get_inst(void);
void run_inst(void);
void free_tokens(void);
void close_stream(void);

void push(stack_t **stack, unsigned int line_numer);


#endif
