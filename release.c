#include "monty.h"
/**
* release - frees a doubly linked list
* @head: head of the stack
*/
void release(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
