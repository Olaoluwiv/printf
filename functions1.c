#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints a number that is unssighed
 * @types: List all the  arguments
 * @buffer: list buffer array that needs to  handle print
 * @flags:  Calculate all  active flags
 * @width: get width size
 * @precision:list  Precision specification
 * @size: list size specifier
 * Return: Number the  charracter printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints  unsigned number of  octal notation
 * @types: List all the  arguments
 * @buffer: list buffer array to handle print
 * @flags:  Calculates all  active flags
 * @width: get widt hsize
 * @precision:  list precision specification
 * @size:list size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints all unsigned number in hexadecimal notation
 * @types: List all types of the  arguments
 * @buffer: list the buffer array to handle print
 * @flags:  Calculates all  active flags
 * @width: get width size
 * @precision: determine precision specification
 * @size: determine size specifier
 * Return: the number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints all unsigned number in upper hexadecimal notation
 * @types: List all the  arguments types
 * @buffer: determine buffer array to handle print
 * @flags:  Calculates the active flags
 * @width: get width size
 * @precision: determine precision specification
 * @size: determine size specifier
 * Return: Number the chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints all required hexadecimal number in lower or upper
 * @types: List all types  of arguments
 * @map_to: Array of values to map the number_ to
i * @buffer: list the buffer array to handle print
 * @flags:  Calculates all active flags
 * @flag_ch: Calculates ch active flags
 * @width: get width size
 * @precision: determine precision specification
 * @size: determine size specifier
 * @size: determine size specification
 * Return: Number the chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
