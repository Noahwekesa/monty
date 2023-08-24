#include "monty.h"

/**
 * dn_div - progam that computes the division of the second top
 * element by the top
 * @stack: stack
 * @line_number: line number 
 * 
 */
void dn_div(stack_t **stack, unsigned int line_number)
{
	stack_t *element;

	element = *stack;

	if (!dn_top_two(stack))
	{
		printf("L%u: can't div, stack too short\n", line_number);
		global.mode = 2;
		return;
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		global.mode = 2;
		return;
	}

	element->next->n /= element->n;
	dn_pop(stack, line_number);
}