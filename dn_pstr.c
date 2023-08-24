#include "monty.h"
/**
 * dn_pstr - program print string from the stack
 * @stack: stack
 * @line_number: line_number number
 */
void dn_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *elm;

	(void) line_number;
	if (!dn_stack(stack))
	{
		printf("\n");
		return;
	}

	elm = *stack;
	while (elm != NULL && elm->n >= 1 && elm->n <= 127)
	{
		printf("%c", elm->n);
		elm = elm->next;
	}
	printf("\n");
}
