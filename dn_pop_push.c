#include "monty.h"

/**
 * dn_push - program that add an element to the stack
 * @h: ptr
 * @line: pointer to line
 * @l: line number
 * Return: 0 success, -1 failure
 */
int dn_push(stack_t **h, char *line, unsigned int l)
{
	char *begin_n;
	stack_t *node;

	begin_n = reach_number(line);
	if (begin_n == NULL)
	{
		printf("L%d: usage: push integer\n", l);
		free(line);
		return (-1);
	};

	if (_strcmp(flag, "stack") == 0)
		node = dn_add_node(h, atoi(begin_n));
	else
		node = add_at_end(h, atoi(begin_n));

	free(line);
	if (node == NULL)
	{
		puts("Error: malloc failed");
		return (-1);
	}
	return (0);
}

/**
 * dn2_pop - program that pull an element from the stack
 * @h: ptr
 * @l: line number
 */
void dn2_pop(stack_t **h, unsigned int l)
{
	stack_t *node;

	node = dn_pop(h);

	if (node == NULL)
	{
		printf("L%d: can't pop an empty %s\n", l, flag);
		dn_free_stack(*h);
		exit(EXIT_FAILURE);
	}
	free(node);
}