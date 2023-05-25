#include "monty.h"
/**
 * pop_element - A function removes the top element from the stack
 * @stack: head of the stack
 * @n: line number
 * Return: nothing
 */
void pop_element(stack_t **stack, unsigned int n)
{
	stack_t *s;

	if (*stack == NULL)
	{
		error_pop(stack, n);
	}
	s = *stack;
	*stack = s->next;
	free(s);
}
/**
 * swap_element - A function that swaps the top two elements on the stack
 * @stack: The stack head
 * @n: Line number
 * Return: Nothing
 */
void swap_element(stack_t **stack, unsigned int n)
{
	stack_t *s = NULL;
	int num = 0;

	s = *stack;
	num = s->n;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	s->n = num;
	s->n = s->next->n;
	s->next->n = num;
}
/**
 * add_elements - A function adds the top two elements of the stack
 * @stack: The stack head
 * @num: number of line
 * Return: Nothing
 */
void add_elements(stack_t **stack, unsigned int num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop_element(stack, num);
}
/**
 * nop_f - A function does nothing
 * @head: head of stack
 * @n: Line number
 *
 * Return: Nothing
 */
void nop_f(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
}
