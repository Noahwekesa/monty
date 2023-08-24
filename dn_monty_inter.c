#include "monty.h"
global_t global;

/**
 * main - main monty loop program execution
 * @argc: Number of arguments provide
 * @argv: Argument vector
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	char *opcode;
	unsigned int i, line;
	FILE *fd;
	size_t bufsize;
	instruction_t table[N_OPCODES] = {
	{"push", &dn_push}, {"pall", &dn_pall}, {"pint", &dn_pint}, {"pop", &dn_pop},
	{"swap", &dn_swap}, {"add", &dn_add}, {"nop", &dn_nop}, {"sub", &dn_sub},
	{"div", &dn_div}, {"mul", &dn_mul}, {"mod", &dn_mod},	{"pchar", &dn_pchar},
	{"pstr", &dn_pstr}, {"rotl", &dn_rotl}, {"rotr", &dn_rotr}, {"stack", &dn_stack},
	{"queue", &dn_queue}, };
	dn_init_program(argc, argv, &fd, &global.buf, &bufsize);
	line = 0;
	while (1)
	{
		if (getline(&global.buf, &bufsize, fd) == -1)
			break;
		line += 1;

		opcode = dn_find_arg1(global.buf);
		if (*opcode == '\0' || *opcode == '#' || *opcode == '\n')
			continue;

		for (i = 0; i < N_OPCODES; i++)
		{
			if (dn_word_match(table[i].opcode, opcode))
			{
				table[i].f(&global.stack, line);
				break;
			}
		}
		if (i >= N_OPCODES)
			global.mode = 2, code_invalid_error(line, opcode);
		if (global.mode == 2)
		{
			dn_exit_cleanup(global.buf, fd);
			exit(EXIT_FAILURE);
		}
	}
	dn_exit_cleanup(global.buf, fd);
	return (EXIT_SUCCESS);
}

/**
 * dn_init_program - progam that initiates and checks for correct input to program
 * @argc: number of arguments
 * @argv: argument vector
 * @fd: memory address
 * @buf: buffer to use for reading file
 * @bs: size of buffer
 */
void dn_init_program(int argc, char **argv, FILE **fd, char **buf, size_t *bs)
{
	(void) buf;
	*bs = 0;
	*fd = fopen(argv[1], "r");
	if (argc != 2)
		exit_w_error("USAGE: monty file\n");
	if (*fd == NULL)
		open_f_error(argv[1]);
	global.mode = 0;
	global.stack = NULL;
	global.tail = NULL;
}
/**
 * dn_exit_cleanup- program that clean up and exit the process
 * @buf: buffer to free
 * @fd: file to close
 */
void dn_exit_cleanup(char *buf, FILE *fd)
{

	(void) buf;
	free(global.buf);
	free_stack();
	fclose(fd);
}
/**
 * dn_free_stack - program that free all memory in the stack
 */
void dn_free_stack(void)
{
	stack_t *elm;

	while (global.stack != NULL)
	{
		elm = global.stack;
		global.stack = (global.stack)->next;
		free(elm);
	}
}
