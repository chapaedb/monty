#include "monty.h"

/**
 * set_queue_mode - sets the queue mode
 * @head: stack head
 * @line_num: line number
 * Return: no return
 */
void set_queue_mode(stack_t **head, unsigned int line_num)
{
    (void)head;
    (void)line_num;
    bus.flag = 0;
}

/**
 * add_to_queue - add node to the tail of the stack
 * @head: head of the stack
 * @value: new value
 * Return: no return
 */
void addqueue(stack_t **head, int value)
{
    stack_t *new_node, *temp;

    temp = *head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->next = NULL;
    if (temp != NULL)
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
    else
    {
        *head = new_node;
        new_node->prev = NULL;
    }
}
