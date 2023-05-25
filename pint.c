#include "monty.h"

/**
 * pint_line -  Functiion prints the top
 * @stack: the stack head
 * @n: line_number
 * Return: nothing
 */
void pint_line(stack_t **stack, unsigned int n)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


