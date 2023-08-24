#include "monty.h"
/**
 * dn_queue - program that set the mode to queuing
 * @stack:stack
 * @line_number: line_number number
 */
void dn_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	 (void) line_number;
	global.mode = 1;
}
