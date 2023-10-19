#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @counter: Line number of the opcode
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int sum;
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    sum = (*head)->n + (*head)->next->n;

    temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;

    free(temp);

    (*head)->n = sum;
}
