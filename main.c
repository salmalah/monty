#include "monty.h"
/**
 * main - function
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on successful
 */
int main(int argc, char *argv[])
{
	FILE *file;
	unsigned int line_number = 0;
	char *opcode, *buffer = NULL;
	size_t buffer_size = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (getline(&buffer, &buffer_size, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode != NULL)
		{
			execute_cmd(opcode, line_number);
		}
	}
	free(buffer);
	fclose(file);
	return (EXIT_SUCCESS);
}

