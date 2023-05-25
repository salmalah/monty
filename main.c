#include "monty.h"
#define MAX_LINE_LENGTH 100
int main(int argc, char* argv[])
{
	char content[MAX_LINE_LENGTH];
	FILE *file;
	char *op;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(content, sizeof(content), file) != NULL)
	{
		line_number++;
		op = strtok(content, " \n");
		while (op != NULL)
		{
			/*arg = strtok(NULL, " \n");*/

			if (strcmp(op, "push") == 0)
			{
				push_line(&stack, line_number);
				printf("push \n");
			}
			if (strcmp(op, "pall") == 0)
			{
				pall_lines(&stack, line_number);
				printf("pall\n");
			}
		}
		 

	}
	fclose(file);

	return (0);
}
