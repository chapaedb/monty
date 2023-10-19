#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @counter: Line number of the opcode
 */
void f_add(stack_t **head, unsigned int counter)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);  // Close the file before exiting
        free_stack(*head);  // Free the stack memory
        exit(EXIT_FAILURE);
    }

    int sum = (*head)->n + (*head)->next->n;

    stack_t *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;

    free(temp);

    (*head)->n = sum;
}
