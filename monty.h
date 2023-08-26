#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*extern variable, stack or queue*/

extern char *flag;

#define BUF_LENGTH 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/*functions*/
stack_t *dn_add_node(stack_t **head, const int n);
void dn_free_stack(stack_t *head);
stack_t *dn_pop(stack_t **head);
stack_t *add_at_end(stack_t **head, int n);
stack_t *dn_queue(stack_t **head);

/*add,sub,div,mod and mul*/
int dn_argument(stack_t **h, char *opcode, unsigned int l);
void dn_add(stack_t **h, unsigned int l);
void dn_sub(stack_t **h, unsigned int l);
void dn_div(stack_t **h, unsigned int l);
void dn_mul(stack_t **h, unsigned int l);
void dn_mod(stack_t **h, unsigned int l);

/*print_func*/
void dn_pchar(stack_t **h, unsigned int l);
void dn_pall(stack_t **h, unsigned int l);
void dn_pint(stack_t **h, unsigned int l);
void dn_pstr(stack_t **h, unsigned int l);

/* dn_getline.c */
ssize_t dn_getline(char **buf, size_t *size, int file_strm);

/*dn_execute*/
int execute_program(stack_t **h, char *line, unsigned int line_number);

/*dn_pop_push*/
void dn2_pop(stack_t **h, unsigned int l);
int dn_push (stack_t **h, char *line, unsigned int l);

/*dn_elm_functions*/
void dn_swap(stack_t **h, unsigned int l);
void dn_rotl(stack_t **h, unsigned int l);
void dn_rotr(stack_t **h, unsigned int l);

/* dn_non_stack_queue*/
void dnqueue(stack_t **h, unsigned int l);
void dn_nop(stack_t **h, unsigned int l);
void dncstack(stack_t **h, unsigned int l);

/*support_func*/
int dn_strcmp(char *s1, char *s2);
int dn_strlen(char *s);
char *dn_reach_element(char *s);
int dn_strncmp(char *s1, char *s2, int n);
char *dn_skip(char *s);

#endif
