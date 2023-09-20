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
} node_t;
extern node_t *node;


void stream_faild(char *file);
void free_node(node_t *stack);

#endif
