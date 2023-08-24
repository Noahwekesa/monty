#include "monty.h"
/**
 * dn_rotl - program that Rotate the top item of the stack to the bottom
 * @stack: stack
 * @line_number: line number
 */
void dn_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *old_head_stack, *temp_stack;

	(void) line_number;
	if (!dn_top_two(stack))
		return;

	old_head_stack = global.stack;
	global.stack = global.stack->next;
	global.stack->prev = NULL;

	temp_stack = global.stack;
	while (temp_stack->next != NULL)
		temp_stack = temp_stack->next;
	temp_stack->next = old_head_stack;
	old_head_stack->next = NULL;
}
