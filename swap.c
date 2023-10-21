#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @number: Line number of the opcode
 */
void _swap(stack_t **head, unsigned int number)
{
    stack_t *temp;

    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", number);
        free_stack(*head);
        fclose(bus.file_ptr);
        exit(EXIT_FAILURE);
    }

    temp = *head;
    *head = (*head)->next;
    temp->next = (*head)->next;
    temp->prev = *head;
    if ((*head)->next != NULL)
        (*head)->next->prev = temp;
    (*head)->next = temp;
    (*head)->prev = NULL;
}
