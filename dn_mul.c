#include "monty.h"
/**
 * dn_mul - progam that multiply two top items
 * @stack: stack
 * @line_number: line number 
 */
void dn_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *elm;

	elm = *stack;

	if (!dn_top_two(stack))
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		global.mode = 2;
		return;
	}
	elm->next->n *= elm->n;
	dn_pop(stack, line_number);
}