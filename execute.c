#include "monty.h"

/**
 * execute - Executes the Monty bytecode instructions
 * @content: Instruction content to execute
 * @stack: Double pointer to the head of the stack
 * @counter: Line number of the instruction
 * @file: File pointer to the bytecode file
 *
 * Return: 0 on success, 1 on failure
 */
int execute(char *content_ptr, stack_t **stack, unsigned int counter, FILE *file_ptr)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{NULL, NULL}
			};
			unsigned int i = 0;
	char *op;

	op = strtok(content_ptr, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.value = strtok(NULL, " \n\t");
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
		fclose(file_ptr);
		free(content_ptr);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}


