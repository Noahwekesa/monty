#include "monty.h"

/**
 * dn_pall - program that print all the elements in a dll as numbers
 * @head: ptr
`* @l: line number
 */
void dn_pall(stack_t **head, unsigned int l)
{
	stack_t *top_head;
	(void) l;

	if (!head)
		return;
	top_head = *head;
	while (top_head != NULL)
	{
		printf("%d\n", top_head->n);
		top_head = top_head->next;
	}
}

/**
 * dn_pstr - program that print all the list as chars
 * @head: ptr
 * @l: line number
 */
void dn_pstr(stack_t **head, unsigned int l)
{
	stack_t *top;
	(void) l;

	if (head != NULL)
	{
		top = *head;
		while (top != NULL && top->n > 0 && top->n < 127)
		{
			printf("%c", top->n);
			top = top->next;
		}
	}
	putchar('\n');
}


/**
 * dn_pint - program that peek the top of the stack
 * @h: ptr
 * @l: line number
 */
void dn_pint(stack_t **h, unsigned int l)
{

	if (!h || !*h)
	{
		printf("L%d: can't pint, stack empty\n", l);
		dn_free_stack(*h);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*h)->n);
}

/**
 * dn_pchar - peek the top of the stack
 * @h: ptr
 * @l: line number
 */
void dn_pchar(stack_t **h, unsigned int l)
{
	int elment;

	if (!h || !*h)
	{
		printf("L%d: can't pchar, stack empty\n", l);
		dn_free_stack(*h);
		exit(EXIT_FAILURE);
	}

	elment = (*h)->n;
	if (elment < 0 || elment > 127)
	{
		printf("L%d: can't pchar, elment out of range\n", l);
		dn_free_stack(*h);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", elment);
}
