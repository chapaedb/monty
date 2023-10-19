#include "monty.h"

/**
 * f_push - Pushes an element to the stack
 * @head: Double pointer to the head of the stack
 * @number: Line number of the opcode
 */
void f_push(stack_t **head, unsigned int number)
{
    int num, index = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            index++;
        for (; bus.arg[index] != '\0'; index++)
        {
            if (!isdigit(bus.arg[index]))
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", number);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    
    num = atoi(bus.arg);

    if (bus.lifi == 0)
        addnode(head, num);
    else
        addqueue(head, num);
}
