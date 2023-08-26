#include "monty.h"

/**
 * dn_swap - program that swap the values of the top and last elements
 * @h: head list
 * @l: line number
 */
void dn_swap(stack_t **h, unsigned int l)
{
	int number;

	if (!h || !*h)
	{
		printf("L%d: can't swap, %s too short\n", l, flag);
		dn_free_stack(*h);
		exit(EXIT_FAILURE);
	}

	number = (*h)->n;

	if ((*h)->next == NULL)
	{
		printf("L%d: can't swap, %s too short\n", l, flag);
		dn_free_stack(*h);
		exit(EXIT_FAILURE);
	}

	(*h)->n = ((*h)->next)->n;
	((*h)->next)->n = number;
}


/**
 * dn_rotl - program that top element of the stack moves to the back
 * @h: head
 * @l: line number
 */
void dn_rotl(stack_t **h, unsigned int l)
{
	stack_t *node, *elment;

	(void) l;

	if (!h || !*h)
		return;
	if (!(*h)->next)
		return;

	node = dn_pop(h);
	node->next = NULL;

	elment = *h;
	while (elment->next)
		elment = elment->next;
	elment->next = node;
	node->prev = elment;
}


/**
 * dn_rotr - program that the last element of the stack moves on top
 * @h: ptr
 * @l: line number
 */
void dn_rotr(stack_t **h, unsigned int l)
{
	stack_t *node;

	(void)l;

	if (!h || !*h)
		return;
	if (!(*h)->next)
		return; 

	node = dn_queue(h);
	node->prev = NULL;

	node->next = *h;
	(*h)->prev = node;
	*h = node;
}
