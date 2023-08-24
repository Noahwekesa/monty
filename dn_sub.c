#include "monty.h"
/**
 * dn_sub - program that sub top two items of stack
 * @stack: stack
 * @line_number: line number
 */
void dn_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_element;

	temp_element = *stack;

	if (!dn_top_two(stack))
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		global.mode = 2;
		return;
	}
	temp_element->next->n -= temp_element->n;
	dn_pop(stack, line_number);
}