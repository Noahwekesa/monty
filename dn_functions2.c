#include "monty.h"
/**
 * dn_stack - program that find if stack is initialized to have nodes
 * @stack: stack
 * Return: 1 if items exist, 0 if not
 */
int dn_stack(stack_t **stack)
{
	if (stack == NULL || *stack == NULL)
		return (0);
	return (1);
}
/**
 * dn_top_two - program that find if top two in stack are valid nodes
 * @stack: stack
 * Return: 1 exist, 0 not
 */
int dn_top_two(stack_t **stack)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (0);
	return (1);
}
