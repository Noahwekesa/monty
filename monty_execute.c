#include "monty.h"


/**
 * execute_program - program that finds the function matching the opcode
 * @h: ptr
 * @line: command line
 * @line_number: line number of the command line in the file
 * Return: 0 on Success, 1 on blank
 * return -1 failure
 */
int execute_program(stack_t **h, char *line, unsigned int line_number)
{
	instruction_t instr[] = {
		{"pall", dn_pall}, {"add", dn_add},
		{"sub", dn_sub}, {"div", dn_div},
		{"mul", dn_mul}, {"mod", dn_mod},
		{"pint", dn_pint}, {"pchar", dn_pchar},
		{"pop", dn_pop}, {"rotl", dn_rotl},
		{"rotr", dn_rotr}, {"stack", dncstack},
		{"queue", dn_queue}, {"nop", dn_nop},
		{"swap", dn_swap}, {"pstr", dn_pstr},
		{NULL, NULL}
	};
	int i, push_return;
	char *start_c;

	start_c = skip_spaces(line);
	if (start_c == NULL)
	{
		free(line);
		return (1);
	}
	if (dn_strncmp(start_c, "push", dn_strlen("push")) == 0)
	{
		push_return = push(h, line, line_number);
		return ((push_return == 0) ? 0 : -1);
	}
	for (i = 0; instr[i].opcode; ++i)
	{
		if (dn_strncmp(start_c, instr[i].opcode, dn_strlen(instr[i].opcode)) == 0)
		{
			free(line), (instr[i].f)(h, line_number);
			return (0);
		}
	}
	printf("L%d: unknown instruction ", line_number);
	while (*start_c && (*start_c != ' ' && *start_c != '\t'))
		putchar(*start_c++);
	putchar('\n');
	free(line);
	return (-1);
}


/**
 * dn_argument - program that return the arguments for calulations
 * @h: ptr list
 * @opcode: opcode string
 * @l: line number
 * Return: arg
 */
int dn_argument(stack_t **h, char *opcode, unsigned int l)
{
	stack_t *elm;
	int element;

	elm = dn_pop(h);

	if (elm == NULL)
	{
		printf("L%d: can't %s, stack too short\n", l, opcode);
		dn_free_stack(*h);
		exit(EXIT_FAILURE);
	}
	element = elm->n;
	free(elm);
	return (element);
}
