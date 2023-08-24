#include "monty.h"
/**
 * dn_push - program that pushes an element to the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: none
*/
void dn_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_elm_node;

	
	if (stack == NULL)
		printf("DEBUG: We made a mistake creating our stack\n");
	if (*stack == NULL)
	{
		global.stack = create_new_node();
		if (global.mode == 2)
			printf("L%u: usage: push integer\n", line);
	}
	else
	{
		new_elm_node = *stack;
		global.stack = create_new_node();
		if (global.mode == 2)
		{
			printf("L%u: usage: push integer\n", line);
			return;
		}
		global.stack->next = new_elm_node;
	}
	
}
/**
 * create_node - program that creates a new node
 * Return: pointer to node
 */
stack_t *create_new_node(void)
{
    stack_t *node = malloc(sizeof(stack_t));
    if (node == NULL)
    {
        exit_w_error("Error: malloc failed");
    }

    node->n = parse_number();
    node->prev = NULL;
    node->next = NULL;

    return node;
}
