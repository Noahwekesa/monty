#include "monty.h"
/**
 * dn_pint - program that print the value at the 
 * top of stack followed by a newline
 * @stack: pointer to stack
 * @line_element: line number
 */
void dn_pint(stack_t **stack, unsigned int line_element)
{
	if (!dn_stack(stack))
	{
		printf("L%u: can't pint, stack empty\n", line_element);
		global.mode = 2;
		return;
	}
	printf("%d\n", (*stack)->n);
}
