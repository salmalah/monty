#include "monty.h"
void push_line(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = malloc(sizeof(stack_t));
	(void)line_number;

	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	 if (isdigit(line_number) == 0)
	 {
		 printf("L%d: usage: push integer\n", line_number);
		 exit(EXIT_FAILURE);
	 }
	new_stack->n = line_number;
	new_stack->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}
void pall_lines(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		 printf("%d\n", current->n);
		 current = current->next;
	}
}
