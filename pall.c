#include "monty.h"

/**
 * f_pall - Prints all elements of the stack
 * @head: Double pointer to the head of the stack
 * @number: Line number of the opcode
 */
void _pall(stack_t **head, unsigned int number)
{
    stack_t *temp = *head;

    (void)number;

    if (temp == NULL)
        return;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
