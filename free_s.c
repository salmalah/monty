#include "monty.h"
/**
 * free_stack - A function that free each node
 * @stack: the head of stack
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	if (*stack == NULL)
		return;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

