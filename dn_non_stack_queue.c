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
 * dnqueue - program that change behavior to dn_queue
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
 * dncstack - program that change behavior to stack
 * @h: ptr
 * @l: line number
 */
void dncstack(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;

	flag = "stack";
}
