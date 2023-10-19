#include "monty.h"

/**
 * f_pint - Prints the value at the top of the stack
 * @head: Double pointer to the head of the stack
 * @number: Line number of the opcode
 */
void f_pint(stack_t **head, unsigned int number)
{
    stack_t *temp;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", number);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    temp = *head;
    printf("%d\n", temp->n);
    *head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = NULL;
    free(temp);
}
