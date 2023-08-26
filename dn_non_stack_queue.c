#include "monty.h"

/**
 * dn_nop - program that does nothing
 * @h: ptr
 * @l: line number
 */
void dn_nop(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;
}


/**
 * dn_queue - program that change behavior to dn_queue
 * @h: ptr
 * @l: line number
 */
void dnqueue(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;

	flag = "dn_queue";
}


/**
 * stack - change behavior to stack
 * @h: pointer to dll
 * @l: line number
 */
void dnc_stack(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;

	flag = "stack";
}
