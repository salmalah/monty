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
	stack_t *s;

	s = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	s->next->n -= s->n;
	pop_element(stack, num);
}
/**
 * div_element - A functio divides the second top element of the stack
 * by the top element of the stack
 * @stack: the head of stack
 * @num: number of ligne
 * Return: nothing
 */
void div_element(stack_t **stack, unsigned int num)
{
	stack_t *div, *divid;

	div = *stack;
	divid = (*stack)->next;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error at line %d: can't div, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	if (divid->n == 0)
	{
		fprintf(stderr, "Error at line %d: division by zero\n", num);
		exit(EXIT_FAILURE);
	}
	divid->n = divid->n / div->n;
	*stack = divid;
	free(div);
}
