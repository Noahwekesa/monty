#include "monty.h"
/**
 * dn_pchar - program that Add top two items of stack
 * @stack: stack
 * @line_number: line number
 */
void dn_pchar(stack_t **stack, unsigned int line_number)
{
	if (!dn_stack(stack))
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		global.mode = 2;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		global.mode = 2;
		return;
	}
	printf("%c\n", (*stack)->n);
}
