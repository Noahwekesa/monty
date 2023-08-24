#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
void dn_pop(stack_t **stack, unsigned int line_element)

/*3. dn_swap*/
void dn_swap(stack_t **stack, unsigned int line_number)

/*4. dn_add*/
void dn_add(stack_t **stack, unsigned int line_number)

/*5. dn_nop*/
void dn_nop(stack_t **stack, unsigned int elm);
#endif