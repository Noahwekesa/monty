#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define N_OPCODES 17
#include <stdio.h>

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
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global - function of useful global variables
 * @stack: top stack
 * @tail: bottom stack
 * @buf: buffer
 * @mode: 0 = stacking, 1 = queuing, 2 = program error, clean and exit
 */
typedef struct global_s
{
    stack_t *stack;
    stack_t *tail;
    char *buf;
    int mode;
} global_t;

extern global_t global;

/* dn_monty_interpreter */
void dn_exit_cleanup(char *buf, FILE *fd);
void dn_init_program(int argc, char **argv, FILE **fd, char **buf, size_t *bs);
void dn_free_stack(void);

/*dn_function1&2*/
char *dn_find_arg0(char *buf);
char *dn_find_arg1(char *buf);
int dn_word_match(char *s1, char *s2);
int dn_parse_number(void);
int dn_stack(stack_t **stack);
int dn_top_two(stack_t **stack);
/*Tasks*/
/* push, pall, create, error handling*/
void dn_push(stack_t **stack, unsigned int line_number);
stack_t *create_new_node(void);
void dn_pall(stack_t **stack, unsigned int line_number);
void exit_w_error(const char *msg);
void open_f_error(const char *file);
void code_invalid_error(int line, const char *opcode);
void process_function_error(int line, const char *msg);

/*1. dn_pint*/
void dn_pint(stack_t **stack, unsigned int line_element);

/* 2. dn_pop */
void dn_pop(stack_t **stack, unsigned int line_element);

/*3. dn_swap*/
void dn_swap(stack_t **stack, unsigned int line_number);

/*4. dn_add*/
void dn_add(stack_t **stack, unsigned int line_number);

/*5. dn_nop*/
void dn_nop(stack_t **stack, unsigned int elm);

/*6 dn_div*/
void dn_div(stack_t **stack, unsigned int line_number);

/*7 dn_mul*/
void dn_mul(stack_t **stack, unsigned int line_number);

/*9. dn_mod*/
void dn_mod(stack_t **stack, unsigned int line_number);
/*dn_pchar*/
void dn_pchar(stack_t **stack, unsigned int line_number);

/*12. dn_pstr*/
void dn_pstr(stack_t **stack, unsigned int line_number);

/*13 dn_rotl*/
void dn_rotl(stack_t **stack, unsigned int line_number);

/*14. rotr*/
void dn_rotr(stack_t **stack, unsigned int line_number);

/*15. stack, queue*/
void dn_stack1(stack_t **stack, unsigned int line_number);
void dn_queue(stack_t **stack, unsigned int line_number);

/*others*/
void dn_sub(stack_t **stack, unsigned int line_number);
#endif