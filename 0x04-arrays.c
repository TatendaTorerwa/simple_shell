#include "main.h"


/**
 *  reverse_the_array - to reverse an array.
 * @arr: the array to be reversed.
 * @a_length: the length of the array.
 * Return: void.
 */
void reverse_the_array(char *arr, int a_length)
{
	int position;
	char a_temp;

	for (position = 0; position < (a_length / 2); position++)
	{
		a_temp = arr[position];
		arr[position] = arr[(a_length - 1) - position];
		arr[(a_length - 1) - position] = a_temp;
	}
}


/**
 * fill_the_array - to fill an array with a given element.
 * @arr: the array to be filled.
 * @a_element: the element to fill the array with.
 * @a_length: the length of the array.
 * Return: a void pointer to the array.
 */
void *fill_the_array(void *arr, int a_element, unsigned int a_length)
{
	char *current = arr;
	unsigned int index = 0;

	while (index < a_length)
	{
		*current = a_element;
		current++;
		index++;
	}
	return (arr);
}

