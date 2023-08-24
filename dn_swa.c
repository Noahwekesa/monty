#include "monty.h"
/**
 * dn_swap - program that swap the values of the to two node
 * @stack: stack
 * @line_number: line number
 *  
 */
void dn_swap(stack_t **stack, unsigned int line_number)
{
	int elm;

	if (*stack == NULL || (*stack)->next == NULL)
		process_function_error(line_number, "can't swap, stack too short");

	elm = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = elm;
}