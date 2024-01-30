#include "main.h"


/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char c;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            switch (*(++ptr))
            {
            case 'c':
                c = va_arg(args, int);
                putchar(c);
                count++;
                break;
            case 's':
                count += printf("%s", va_arg(args, char *));
                break;
            case '%':
                putchar('%');
                count++;
                break;
            default:
                putchar('%');
                putchar(*ptr);
                count += 2;
                break;
            }
        }
        else
        {
            putchar(*ptr);
            count++;
        }
    }

    va_end(args);

    return count;
}

