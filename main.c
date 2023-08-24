#include "monty.h"

data_s mydata = {NULL, NULL, NULL, 0};
/**
 * execute - executes the monty bytecode instruction.
 * @content: the instruction to execute.
 * @stack: pointer to the top of the stack.
 * @counter: number of the instruction.
 * @file: pointer for error handling.
 *
 * Return: 0 when execution is success or 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push}, {"pall", _pall},/* {\"pint\", f_pint},*/
/*				{\"pop\", f_pop},*/
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	mydata.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		freestack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
 * main - the entry point.
 * @argc: number of arguments
 * @argv: mlocate
 *
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	char buffer[MAX_LINE_SIZE];
	FILE *file;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	mydata.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		size_t line_length = strlen(buffer);

		if (line_length > 0 && buffer[line_length - 1] == '\n')
		{
			buffer[line_length - 1] = '\0';
			line_length--;
		}
		mydata.content = buffer;
		counter++;
		if (line_length > 0)
		{
			execute(buffer, &stack, counter, file);
		}
	}
	freestack(stack);
	fclose(file);
	return (0);
}
