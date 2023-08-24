#include "monty.h"
/**
 * dn_pall - progam that prints all the elements of a stack_t list.
 *
 * @stack: stack.
 * @line_number: Line number of the current
 */
void dn_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_step;

	(void)line_number;

	if (!stack)
		return;

	current_step = *stack;
	while (current_step)
	{
		printf("%d\n", current_step->n);
		current_step = current_step->next;
	}
}