#include "monty.h"
int is_queue = 0;
/**
 * queue_el - Function sets the format of the data to a queue (FIFO)
 * @stack: head of stack unused
 * @line_number: line number
 * Return: noting
 */
void queue_el(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	(void)stack;
	is_queue = 1;
}
/**
 * stack_el - Function sets the format of the data to a stack (LIFO)
 * @stack: head of stack unused
 * @line_number: line number
 * Return: noting
 */
void stack_el(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	(void)stack;
	is_queue = 0;
}
