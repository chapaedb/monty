#include "monty.h"

/**
 * f_pop - Removes the top element of the stack
 * @head: Double pointer to the head of the stack
 * @number: Line number of the opcode
 */
void f_pop(stack_t **head, unsigned int number)
{
    stack_t *temp;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", number);
        free_stack(*head);  // Free the entire stack before exiting
        fclose(bus.file);  // Close the file before exiting
        exit(EXIT_FAILURE);
    }

    temp = *head;
    *head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = NULL;
    free(temp);
}
