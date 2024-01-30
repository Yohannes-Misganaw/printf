#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed excluding null byte
 */

int _printf(const char *format, ...)
{
	va_list argli;
	int ncount = 0;
	const char *ptr;
	char c;
	
	va_start(argli, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			switch (*(++ptr))
			{
			case 'c':
				c = va_arg(argli, int);
				putchar(c);
				ncount++;
				break;
			case 's':
				ncount += printf("%s", va_arg(argli, char *));
				break;
			case '%':
				putchar('%');
				ncount++;
				break;
			default:
				putchar('%');
				putchar(*ptr);
				ncount += 2;
				break;
			}
		}
		else
		{
			putchar(*ptr);
			ncount++;
		}
	}
	va_end(argli);
	return ncount;
}

