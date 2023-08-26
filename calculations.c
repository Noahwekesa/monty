#include "monty.h"

/**
 * dn_add - program that add the top 2 values on the stack
 * @h: ptr line
 * @l: line number
 */
void dn_add(stack_t **h, unsigned int l)
{
	int number1, number2;

	number1 = dn_argument(h, "add", l);
	number2 = dn_argument(h, "add", l);

	dn_add_node(h, number1 + number2);
}


/**
 * dn_sub - program that subtract the top 2 values on the stack
 * @h: ptr
 * @l: line number
 */
void dn_sub(stack_t **h, unsigned int l)
{
	int number1, number2;

	number1 = dn_argument(h, "sub", l);
	number2 = dn_argument(h, "sub", l);

	dn_add_node(h, number2 - number1);
}


/**
 * dn_div - program that divides the top 2 values on the stack
 * @h: ptr list
 * @l: line number
 */
void dn_div(stack_t **h, unsigned int l)
{
	int number1, number2;

	number1 = dn_argument(h, "div", l);
	number2 = dn_argument(h, "div", l);

	if (number1 == 0)
	{
		printf("L%d: division by zero\n", l);
		dn_free_stack(*h);
		exit(EXIT_FAILURE);
	}
	dn_add_node(h, number2 / number1);
}


/**
 * dn_mul - program that multiply the top 2 values on the stack
 * @h: ptr
 * @l: line number
 */
void dn_mul(stack_t **h, unsigned int l)
{
	int number1, number2;

	number1 = dn_argument(h, "mul", l);
	number2 = dn_argument(h, "mul", l);

	dn_add_node(h, number2 * number1);
}



/**
 * dn_mod - progam that get the modulo of the top 2 values on the stack
 * @h: ptr
 * @l: line number
 */
void dn_mod(stack_t **h, unsigned int l)
{
	int number1, number2;

	number1 = dn_argument(h, "mod", l);
	number2 = dn_argument(h, "mod", l);

	if (number1 == 0)
	{
		printf("L%d: division by zero\n", l);
		dn_free_stack(*h);
		exit(EXIT_FAILURE);
	}
	dn_add_node(h, number2 % number1);
}
