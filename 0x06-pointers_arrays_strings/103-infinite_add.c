#include "main.h"

/**
 * rev_string - reverse array
 * @n: pointer to a string
 *
 * Description: Reverses the characters in the given string.
 */
void rev_string(char *n)
{
	int i = 0;
	int j = 0;
	char temp;

	// Find the length of the string
	while (n[i] != '\0')
	{
		i++;
	}
	i--;

	// Swap characters to reverse the string
	for (j = 0; j < i; j++, i--)
	{
		temp = n[j];
		n[j] = n[i];
		n[i] = temp;
	}
}

/**
 * infinite_add - add 2 numbers together
 * @n1: text representation of 1st number to add
 * @n2: text representation of 2nd number to add
 * @r: pointer to buffer
 * @size_r: buffer size
 *
 * Return: Pointer to the result string, or NULL on failure.
 *
 * Description: Adds two numbers represented as strings and stores the result
 *              in the given buffer.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, i = 0, j = 0, digits = 0;
	int val1 = 0, val2 = 0, temp_sum = 0;

	// Calculate the lengths of the input strings
	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;
	i--;
	j--;

	// Check if the result will fit in the buffer
	if (j >= size_r - 1 || i >= size_r - 1)
		return NULL;

	// Perform addition digit by digit
	while (j >= 0 || i >= 0 || overflow == 1)
	{
		// Convert characters to integers
		if (i < 0)
			val1 = 0;
		else
			val1 = n1[i] - '0';
		if (j < 0)
			val2 = 0;
		else
			val2 = n2[j] - '0';

		temp_sum = val1 + val2 + overflow;

		// Check for overflow
		if (temp_sum >= 10)
			overflow = 1;
		else
			overflow = 0;

		// Check if the result will fit in the buffer
		if (digits >= size_r - 1)
			return NULL;

		// Store the digit in the result buffer
		r[digits] = (temp_sum % 10) + '0';
		digits++;

		j--;
		i--;
	}

	// Null-terminate the result string
	r[digits] = '\0';

	// Reverse the result string
	rev_string(r);

	return r;
}

