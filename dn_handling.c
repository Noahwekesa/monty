#include "monty.h"

/**
 * exit_w_error - program to exit program on generic error
 * @msg: message to print before exit
 */
void exit_w_error(const char *msg)
{
    fprintf(stderr, "%s", msg);
    exit(EXIT_FAILURE);
}

/**
 * open_f_error - exit when Error on opening file
 * @file: file we tried to open
 */
void open_f_error(const char *file)
{
    fprintf(stderr, "Error: Can't open file %s\n", file);
    exit(EXIT_FAILURE);
}

/**
 * code_invalid_error - Error in opcode
 * @line: line number of error
 * @opcode: opcode that doesn't exist
 */
void code_invalid_error(int line, const char *opcode)
{
    fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
}

/**
 * process_function_error - Error processing opcode function
 * @line: line number of error
 * @msg: message to send
 */
void process_function_error(int line, const char *msg)
{
    fprintf(stderr, "L%d: %s\n", line, msg);
}
