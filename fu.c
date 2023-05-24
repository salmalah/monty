#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


stack_t *stack = NULL;

void push(stack_t **stack, unsigned int line_number)
{
    char *argument = strtok(NULL, " \n");
    stack_t *new_node;
    if (argument == NULL || !isdigit(*argument))
    {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(argument);
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
    (void)line_number;

    current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void execute_opcode(const char *opcode, unsigned int line_number)
{
    if (strcmp(opcode, "push") == 0)
    {
        push(&stack, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(&stack, line_number);
    }
    
}

int main(int argc, char *argv[])
{
char *opcode,*line =NULL;
size_t line_len =0;
 FILE *file;
unsigned int line_number = 0;;
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

   file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

   

    while(fgets(line, line_len, file) != NULL)
    {
        line_number++;

       opcode = strtok(line, " \n");
        if (opcode != NULL)
        {
            execute_opcode(opcode, line_number);
        }
    }

    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}

