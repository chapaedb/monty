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
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	char *value_str;
	int value;

    char *opcode = strtok(content, " \n\t");
    if (opcode == NULL || opcode[0] == '#')
        return 0;

    if (strcmp(opcode, "push") == 0)
    {
        value_str = strtok(NULL, " \n\t");
        if (value_str == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            free(content);
	    fclose(file);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }
	value = atoi(value_str);
        f_push(stack, value);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        f_pop(stack, counter);
    }
    else if (strcmp(opcode, "swap") == 0)
    {
        f_swap(stack, counter);
    }
    else if (strcmp(opcode, "add") == 0)
    {
        f_add(stack, counter);
    }
    

    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
        free(content);
        free_stack(*stack);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    return 0;
}
