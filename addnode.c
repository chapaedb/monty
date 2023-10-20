#include "monty.h"

/**
 * add_node - Adds a new node to the stack
 * @head: Double pointer to the head of the stack
 * @n: Value to be stored in the new node
 *
 * Return: Pointer to the new node
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(*head);
        fclose(bus.file_ptr);
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}
