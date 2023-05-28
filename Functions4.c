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

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	str = (*stack)->next;
	str->prev = NULL;
	t = *stack;
	while (t->next != NULL)
		t = t->next;
	t->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = t;
	(*stack) = str;
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
/**
 * rotr_element - Function rotates the stack to the bottom
 * @stack: the head
 * @n: number of line unused
 * Return: nothing
 */
void rotr_element(stack_t **stack, __attribute__((unused)) unsigned int n)
{
	stack_t *str;

	str = *stack;
	if (str == NULL || str->next == NULL)
		return;
	while (str->next)
		str = str->next;
	str->next = *stack;
	str->prev->next = NULL;
	str->prev = NULL;
	(*stack)->prev = str;
	(*stack) = str;

}
