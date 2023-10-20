#include "monty.h"

/**
 * f_push - Pushes an element to the stack
 * @head: Double pointer to the head of the stack
 * @number: Line number of the opcode
 */
void f_push(stack_t **head, unsigned int number)
{
    int num, index = 0, flag = 0;

    if (bus.value != NULL && bus.value[0] != '\0')
    {
        if (bus.value[0] == '-')
            index++;
        for (; bus.value[index] != '\0'; index++)
        {
            if (!isdigit(bus.value[index]))
            {
                flag = 1;
                break; // Exit the loop if a non-digit character is encountered
            }
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", number);
            fclose(bus.file_ptr);
            free(bus.content_ptr);
            // Free the stack
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", number);
        fclose(bus.file_ptr);
        free(bus.content_ptr);
        // Free the stack
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    num = atoi(bus.value);

    if (bus.flag == 0)
        addnode(head, num);
    else
        addqueue(head, num);
}
