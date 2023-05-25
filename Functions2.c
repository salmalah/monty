#include "monty.h"
/**
 * pop_element - A function removes the top element from the stack
 * @stack: head of the stack
 * @n: line number
 * Return: nothing
 */
void pop_element(stack_t **stack, unsigned int n)
{
	stack_t *s = NULL;

	if (*stack == NULL)
	{
		error_pop(stack, n);
	}
	s = *stack;
	*stack = s->next;
	free(s);
}
/**
 * swap_elemen - A function that swaps the top two elements on the stack
 * @stack: The stack head
 * @n: Line number
 * Return: Nothing
 */
void swap_element(stack_t **stack, unsigned int n)
{
	stack_t *s, *next;

	s = *stack;
	next = s->next;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	s->next = next->next;
	if (s->next != NULL)
		s->next->prev = s;
	next->prev = NULL;
	next->next = s;
	s->prev = next;
	*stack = next;
}
/**
 * add_elements - A function adds the top two elements of the stack
 * @tack: The stack head
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
