#include "main.h"


/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */

int _printf(const char* format, ...)
{
	va_list li_args;
	va_start(li_args, format);

	int count = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				case 'c':
				{
					char c = va_arg(li_args, int);
					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					char* s = va_arg(li_args, char*);
					fputs(s, stdout);
					count += strlen(s);
					break;
				}
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}
	va_end(li_args);
	
	return count;
}
