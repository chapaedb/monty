#include "monty.h"

/**
 * f_push - Pushes an element to the stack
 * @head: Double pointer to the head of the stack
 * @number: Line number of the opcode
 */
void f_push(stack_t **head, unsigned int number)
{
    int num, index = 0, flag = 0;

    if (bus.value)
    {
        if (bus.value[0] == '-')
            index++;
        for (; bus.value[index] != '\0'; index++)
        {
            if (bus.value[index] < 48 || bus.value[index] > 57)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", number);
            fclose(bus.file_ptr);
            free(bus.content_ptr);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", number);
        fclose(bus.file_ptr);
        free(bus.content_ptr);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    num = atoi(bus.value);

    if (bus.flag == 0)
        addnode(head, num);
    else
            addqueue(head, num);
}
