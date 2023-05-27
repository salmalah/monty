#include "monty.h"
/**
 * queue_el - Function sets the format of the data to a queue (FIFO)
 * @stack: head of stack unused
 * @line_number: line number
 * Return: noting
 */
void queue_el(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	(void)stack;
	
	is_queue_mode(1);
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
	
	is_queue_mode(0);
}
int is_queue_mode(int n)
{
	return (n);
}
