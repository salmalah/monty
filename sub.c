#include "monty.h"
/**
 * sub_l - A function that subtracts the
 * top element of the stack from the second top element
 * @stack: The head
 * @num: Line number
 * Return: Nothing
 */
void sub_l(stack_t **stack, unsigned int num)
{
	stack_t = *s;
	int sub;

	s = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	s = s->next->n - s->n;
	pop_element(stack, num);
	s->n = s;
}

