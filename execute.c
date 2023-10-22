#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
        instruction_t opls[] = {
                                {"push", _push}, {"pall", _pall}, {"pint", _pint},
                                {"pop", _pop},
                                {"swap", _swap},
                                {"add", _add},
                                {"nop", _nop},
                                {"div", _div},
                                {NULL, NULL}
                                };
        unsigned int i = 0;
        char *op;

        op = strtok(content, " \n\t");
        if (op && op[0] == '#')
                return (0);
        bus.value = strtok(NULL, " \n\t");
        while (opls[i].opcode && op)
        {
                if (strcmp(op, opls[i].opcode) == 0)
                {       opls[i].f(stack, counter);
                        return (0);
                }
                i++;
        }
        if (op && opls[i].opcode == NULL)
        { fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
                fclose(file);
 free(content);
                release(*stack);
                exit(EXIT_FAILURE); }
        return (1);
}
