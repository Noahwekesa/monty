#include "monty.h"
/**
 * dn_rotr - program that bottom element of the stack rotates to the top
 * @stack: the stack
 * @line_number: line_number 
 */
void dn_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last_tail, *temp_elm;

	(void) line_number;
	if (!dn_top_two(stack))
		return;

	temp_elm = global.stack;
	while (temp_elm->next != NULL)
		temp_elm = temp_elm->next;
	temp_elm->prev->next = NULL;
	last_tail = temp_elm;

	last_tail->next = global.stack;
	last_tail->prev = NULL;
	global.stack->prev = last_tail;
	global.stack = last_tail;
}
