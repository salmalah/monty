#include "monty.h"

/**
 * pall_lines - A function prints the stack lines
 * @stack: stack head
 * @line_number: unused parametre
 * Return: Nothing
 */
void pall_lines(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", (*current).n);
		current = current->next;
	}
}
/**
 * execute_cmd - A fucntion executes the opcode enter by user
 * @opcode: content of opcode
 * @line_number: line content the cmd
 * @stack_ptr: a stack pointer
 * Return: nothing
 */
void execute_cmd(char *opcode, unsigned int line_number, stack_t **stack_ptr)
{

	instruction_t str[] = {
		{"push", push_line}, {"pall", pall_lines}, {"pint", pint_line},
		 {"pop", pop_element}, {"swap", swap_element}, {"add", add_elements},
		  {"nop", nop_f}, {"sub", sub_l}, 
		  {"div", div_element}, {"mul", mul_element}, 
		  {"mod", mod_element}, 
		  {"pchar", pchar_element}, {"pstr", pstr_element}, {NULL, NULL}
	};
	size_t length = sizeof(str) / sizeof(str[0]), i = 0;
	/*int opcode_found = 0;*/

	for (; i < length; ++i)
	{
		if (strcmp(opcode, str[i].opcode) == 0)
		{
			/*opcode_found = 1;*/
			if (str[i].f != NULL)
			{
				str[i].f(stack_ptr, line_number);
				break;
			}

		}
	}

}
/**
 * push_line - A function push in stack
 * @stack: the head of stack
 * @line_number: line number
 * Return: Nothing
 */
void push_line(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *argument = strtok(NULL, " \n");

	if (argument == NULL || !is_integer(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(argument);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
