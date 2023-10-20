#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @number: Line number of the opcode
 */
void f_add(stack_t **head, unsigned int number)
{
    stack_t *temp;

    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", number);
        free_stack(*head);
        fclose(bus.file_ptr);
        exit(EXIT_FAILURE);
    }

    (*head)->next->n += (*head)->n;
    temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}
