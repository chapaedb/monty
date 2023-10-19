#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @counter: Line number of the opcode
 */
void f_swap(stack_t **head, unsigned int counter)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    stack_t *first = *head;
    stack_t *second = first->next;

    first->prev = second;
    first->next = second->next;
    second->prev = NULL;
    second->next = first;

    if (first->next != NULL)
        first->next->prev = first;

    *head = second;
}
