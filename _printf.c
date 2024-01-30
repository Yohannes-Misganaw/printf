#include "main.h"

void print_buf(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list argli;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(argli, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buf(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buf(buffer, &buff_ind);
			// flags = get_flags(format, &i);
			// width = get_width(format, &i, argli);
			// precision = get_precision(format, &i, argli);
			// size = get_size(format, &i);
			// ++i;
			// printed = handle_print(format, &i, argli, buffer,
			// 	flags, width, precision, size);
			// if (printed == -1)
			// 	return (-1);
			// printed_chars += printed;
		}
	}

	print_buf(buffer, &buff_ind);

	va_end(argli);

	return (printed_chars);
}

/**
 * print_buf - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buf(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
