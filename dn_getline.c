#include "monty.h"

/**
 * dn_clean_up - program cleanup
 * @buffer: a buf
 * @size: size of buf
 */
void dn_clean_up(char *buffer, size_t size)
{
	size_t elm;

	for (elm = 0; elm < size; ++elm)
		buffer[elm] = '\0';
}

/**
 * dn_fill_buf - program that fill buffer with '\0' char
 * @buf: ptr to buf
 * @size: ptr to size of buf
 * @c: char
 * @index: index
 */
void dn_fill_buf(char **buf, size_t *size, char c, size_t index)
{
	char *ptr;

	if (!buf || !size)
		return; /*should exit really*/
	if (index >= *size - 1) /*I need 2 free spots at this point*/
	{
		*buf = realloc(*buf, *size * 2);
		if (*buf == NULL)
			return;
		*size = *size * 2;
	}
	ptr = *buf;
	*(ptr + index) = c;
}

/**
 * dn_getline - program that read a line from standard input
 * @buf: ptr to a buf
 * @size: size of buf
 * @file_strm: input stream
 * Return: num chr read on success, -1 otherwise
 */
ssize_t dn_getline(char **buf, size_t *size, int file_strm)
{
	size_t index;
	char c;
	int chk;

	if (!buf || !size)
		return (-1);
	if (!*buf)
	{
		*size = BUF_LENGTH;
		*buf = malloc(*size * sizeof(char));
		if (*buf == NULL)
			return (-1);
	}
	index = 0;
	dn_clearn_up(*buf, *size);
	while (1)
	{
		chk = read(file_strm, &c, 1);
		if (chk == -1)
			return (-1); /*buffer freed elsewhere*/
		if (chk == 0 && index == 0) /*EOF*/
			return (-1);
		if (c != EOF)
		{
			dn_fill_buf(buf, size, c, index);
			if (*buf == NULL)
				return (-1);
			++index;
		}
		if (c == '\n')
			break;
	}
	*((*buf) + index - 1) = '\0';
	return (index);
}
