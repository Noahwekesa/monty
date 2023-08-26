#include "monty.h"

/**
 * dn_add_node - program that push or enqueue an elment_1 at the beginning of the stack
 * @head: ptr
 * @n: value to add
 * Return: ptr NULL
 */
stack_t *dn_add_node(stack_t **head, const int n)
{
	stack_t *elment_1;


	if (!head)
		return (NULL);

	elment_1 = malloc(sizeof(stack_t));
	if (elment_1 == NULL)
		return (NULL);

	elment_1->n = n;
	elment_1->prev = NULL;
	elment_1->next = *head;

	if (*head)
		(*head)->prev = elment_1;
	*head = elment_1;
	return (NULL);
}


/**
 * dn_free_stack - progam that free a dll of int
 * @head: a ptr
 */
void dn_free_stack(stack_t *head)
{
	stack_t *elm;


	while (head != NULL)
	{
		elm = head;
		head = head->next;
		free(elm);
	}
}



/**
 * dn_pop - program that return the node at the beginning
 * @head: ptr of list
 * Return: ptr or NULL
 */
stack_t *dn_pop(stack_t **head)
{
	stack_t *elm;

	if (!head || !*head)
		return (NULL);

	elm = *head;
	*head = (*head)->next;

	if (*head)
		(*head)->prev = NULL;


	return (elm);
}


/**
 * dn_queue - program that return the node at the end
 * @head: pointer to a dll
 * Return: pointer to node or NULL
 */
stack_t *dn_queue(stack_t **head)
{
	stack_t *top;

	if (!head || !*head)
		return (NULL);

	top = *head;
	while (top->next != NULL)
		top = top->next;

	if (top->prev)
		(top->prev)->next = NULL;
	else
		*head = NULL;

	return (top);
}

/**
 * add_at_end - program that add node at the end of a list
 * @head: ptr to a list
 * @n: input numbr
 * Return: address or NULL
 */
stack_t *add_at_end(stack_t **head, int n)
{
	stack_t *elment_1, *elm;

	if (!head)
		return (NULL);
	elment_1 = malloc(sizeof(stack_t));
	if (!elment_1)
		return (NULL);

	elment_1->n = n;
	elment_1->next = NULL;

	if (*head)
	{
		for (elm = *head; elm->next;)
			elm = elm->next;
		elment_1->prev = elm;
		elm->next = elment_1;
	}
	else
	{
		elment_1->prev = NULL;
		*head = elment_1;
	}
	return (NULL);
}
