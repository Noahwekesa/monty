#include "monty.h"

/**
 * dn_swap - program that swap the values of the top and last elements
 * @h: head list
 * @l: line number
 */
void dn_swap(stack_t **h, unsigned int l)
{
    stack_t *top1, *top2;
    int temp;

    if (!*h || !(*h)->next)
    {
        printf("L%d: can't swap, stack too short\n", l);
        exit(EXIT_FAILURE);
    }

    top1 = *h;
    top2 = (*h)->next;

    temp = top1->n;
    top1->n = top2->n;
    top2->n = temp;
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
