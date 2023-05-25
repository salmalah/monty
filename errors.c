#include "monty.h"
/**
 * unknown_opcode - A function return error if unkonwnedopcode
 * @n: line of error
 * Return: nothing
 */
void unknown_opcode(unsigned int n, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", n, opcode);
	exit(EXIT_FAILURE);
}
/**
 * error_pop - A function display error if empty head
 * @head: the head
 * @counter: line counter
 * return: nothing
 */
void error_pop(stack_t **head, unsigned int counter)
{
	(void)head;
	fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
	exit(EXIT_FAILURE);
}
