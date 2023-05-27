#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
/* Bibliotheque declaration */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *stack;
/* Decarations of prototypes functions */
void push_line(stack_t **stack, unsigned int line_number);
void pall_lines(stack_t **stack, unsigned int line_number);
void pint_line(stack_t **stack, unsigned int n);
void pchar_element(stack_t **stack, unsigned int line_number);
void unknown_opcode(unsigned int n, char *opcode);
void sub_l(stack_t **stack, unsigned int num);
int is_integer(const char *str);
void nop_f(stack_t **head, unsigned int n);
void error_pop(stack_t **head, unsigned int counter);
void pop_element(stack_t **stack, unsigned int n);
void mul_element(stack_t **stack, unsigned int num);
void div_element(stack_t **stack, unsigned int num);
void add_elements(stack_t **stack, unsigned int num);
void swap_element(stack_t **stack, unsigned int n);
void mod_element(stack_t **stack, unsigned int num);
void free_stack(stack_t **stack);
void execute_cmd(char *opcode, unsigned int line_number, stack_t **stack_ptr);
#endif
