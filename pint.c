#include "monty.h"
/**
 * rotl_element - Function otates the stack to the top
 * @stack: the stack head
 * @n: line_number
 * Return: nothing
 */
void rotl_element(stack_t **stack, unsigned int n)
{
	stack_t *t, *str;
	(void)n;

	t = *stack;
	if (stack == NULL || (*stack)->next == NULL)
		return;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	str = *stack;
	while (str->next != NULL)
		str = str->next;
	str->next = t;
	t->prev = str;
	t->next = NULL;
}

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
/**
 *
 * pstr_element - Functions rints the string starting at the top of the stack
 * @stack: the head
 * @n: number of line
 * Return: nothing
 */
void pstr_element(stack_t **stack, unsigned int n)
{
	stack_t *str;
	(void)n;

	str = *stack;
	while (str != NULL && str->n != 0 && str->n >= 0 && str->n <= 127)
	{
		printf("%c", str->n);
		str = str->next;
	}
	printf("\n");
}

