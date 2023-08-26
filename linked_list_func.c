#include "monty.h"

/**
 * dn_add_node - program that push or enqueue an elment_1 at the beginning of the stack
 * @head: ptr
 * @n: value to add
 * Return: ptr NULL
 */
stack_t *dn_add_node(stack_t **head, const int n)
{
	stack_t *new_node;
    if (!head)
        return (NULL);

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head)
        (*head)->prev = new_node;
    
    *head = new_node;
    return (new_node);
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
    stack_t *new_node, *elm;

    if (!head)
        return (NULL);

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (*head)
    {
        elm = *head;
        while (elm->next)
            elm = elm->next;
        new_node->prev = elm;
        elm->next = new_node;
    }
    else
    {
        new_node->prev = NULL;
        *head = new_node;
    }
    return (new_node);
}
