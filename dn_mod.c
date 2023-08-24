#include "monty.h"

/**
 * dn_mod - program that computes the rem of the seconf top element by the top 
 * 
 * @stack: stack
 * @line_number: line num 
 */
void dn_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *num_elm = *stack;

	if (!dn_top_two(stack))
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		global.mode = 2;
		return;
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		global.mode = 2;
		return;
	}

	num_elm->next->n %= num_elm->n;
	dn_pop(stack, line_number);
}
