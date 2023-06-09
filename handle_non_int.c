#include "main.h"

/**
 * int_to_hex - convert int to string
 * @num: the integer number
 * @buf: number buffer
 * @cap: (1) capital or otherwise small
 * @flags: flags
 *
 * Return: length of the string
 */
int int_to_hex(unsigned int num, char *buf, int cap, flags_ty *flags)
{
	int i, j = 0;
	int digits_array[32];

	if (num == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}
	for (i = 0 ; num > 0 ; i++)
	{
		digits_array[i] = num % 16;
		num = num / 16;
	}
	if (flags->hash > 0)
	{
		buf[j] = '0';
		j++;
		if (cap == 1)
			buf[j] = 'X';
		else
			buf[j] = 'x';
		j++;
	}
	for (i = i - 1; i >= 0 ; i--)
	{
		if (digits_array[i] < 10)
			buf[j] = digits_array[i] + '0';
		else if (digits_array[i] >= 10)
		{
			if (cap == 1)
				buf[j] = (digits_array[i] - 10) + 'A';
			else
				buf[j] = (digits_array[i] - 10) + 'a';
		}
		j++;
	}
	buf[j] = '\0';
	return (j);
}


/**
 * uint_to_string - convert int to string
 * @num: the integer number
 * @buf: number buffer
 * @flags: flags
 *
 * Return: length of the string
 */
int uint_to_string(unsigned int num, char *buf, flags_ty *flags)
{
	int i, j = 0;
	int digits_array[32];

	(void)flags;
	if (num == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}

	for (i = 0 ; num > 0 ; i++)
	{
		digits_array[i] = num % 10;
		num = num / 10;
	}

	for (i = i - 1; i >= 0 ; i--)
	{
		buf[j] = digits_array[i] + '0';
		j++;
	}

	buf[j] = '\0';

	return (j);
}

/**
 * int_to_octal - convert int to string
 * @num: the integer number
 * @buf: number buffer
 * @flags: flags
 *
 * Return: length of the string
 */
int int_to_octal(unsigned int num, char *buf, flags_ty *flags)
{
	int i, j = 0;
	int digits_array[32];

	if (num == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}

	for (i = 0 ; num > 0 ; i++)
	{
		digits_array[i] = num % 8;
		num = num / 8;
	}

	if (flags->hash > 0)
	{
		buf[j] = '0';
		j++;
	}

	for (i = i - 1; i >= 0 ; i--)
	{
		buf[j] = digits_array[i] + '0';
		j++;
	}

	buf[j] = '\0';

	return (j);
}

/**
 * int_to_binary - convert int to string
 * @num: the integer number
 * @buf: number buffer
 * @flags: flags
 *
 * Return: length of the string
 */
int int_to_binary(unsigned int num, char *buf, flags_ty *flags)
{
	int i, j = 0;
	int digits_array[32];

	(void)flags;
	if (num == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}

	for (i = 0 ; num > 0 ; i++)
	{
		digits_array[i] = num % 2;
		num = num / 2;
	}

	for (i = i - 1; i >= 0 ; i--)
	{
		buf[j] = digits_array[i] + '0';
		j++;
	}

	buf[j] = '\0';

	return (j);
}
