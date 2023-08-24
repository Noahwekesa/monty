#include "monty.h"
/**
 * dn_add - progam that adds the top two elements of the stack
 * @stack: top stack (head)
 * @line_number: element num
 **/
void dn_add(stack_t **stack, unsigned int line_number)
{
	stack_t *elm;

	if (*stack == NULL || (*stack)->next == NULL)
		printf("L%u: can't add, stack too short\n", line_number);

	elm = (*stack)->next;
	elm->n += (*stack)->n;
	dn_pop(stack, line_number);
}