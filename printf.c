#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Prints a given character.
 * @c: The character to be printed.
 *
 * Return: The character c.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a char.
 * @ap: A list of arguments pointing to the character to be printed.
 */
void print_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	_putchar(c);
}

/**
 * print_string - Prints a string.
 * @ap: A list of arguments pointing to the string to be printed.
 */
void print_string(va_list ap)
{
	int i;
	char *s;
	char c;

	s = va_arg(ap, char *);
	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			c = s[i];
			_putchar(c);
		}
		i++;
	}
}

/**
 * _printf - Produces output according to a format.
 * @format: The character string to be written to the stdout.
 *
 * Return: The number of characters printed (excluding the null byte
 * used to end output to  string).
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, num_char;

	va_start(ap, format);
	i = 0;
	num_char = 0;
	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			print_char(ap);
			num_char++;
			break;
		case 's':
			print_string(ap);
			num_char++;
		}
		if (format[i] == '%')
		{
			_putchar('%');
			num_char++;
		}
		else
		{
			_putchar(format[i]);
			num_char++;
		}
		i++;
	}
	va_end(ap);
	return (num_char);
}
