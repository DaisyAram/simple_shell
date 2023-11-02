#include "shell.h"
/**
 * _puts - prints a string
 * @str: string to be printed
 *
 * Return: nothing
 */
void _puts(const char *str)
{
	while (str != NULL && *str != '\0')
	{
	_putchar(*str);
	str++;
	}
}

/**
 * _putchar - writes character c to stdout
 * @c: character to print
 *
 * Return: on success 1, -1 on err and sets errno appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
