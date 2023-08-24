#include "monty.h"
/**
 * dn_pop - program that Remove the top item from the stack
 * @stack: stack
 * @line_element: line
 */
void dn_pop(stack_t **stack, unsigned int line_element)
{
    stack_t *first_node;

    if (!valid_stack(stack))
    {
        global.mode = 2;
        process_function_error(line_element, "can't pop an empty stack");
        return;
    }

    first_node = *stack;
    if (first_node->next != NULL)
        first_node->next->prev = NULL;
    *stack = first_node->next;
    free(first_node);
}