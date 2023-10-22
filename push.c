#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _push(stack_t **head, unsigned int counter)
{
        int n, index = 0, flag = 0;

        if (bus.value)
        {
                if (bus.value[0] == '-')
                        index++;
                for (; bus.value[index] != '\0'; index++)
                {
                        if (bus.value[index] > 57 || bus.value[index] < 48)
                                flag = 1; }
                if (flag == 1)
                { fprintf(stderr, "L%d: usage: push integer\n", counter);
                        fclose(bus.file_ptr);
                        free(bus.content_ptr);
                        release(*head);
                        exit(EXIT_FAILURE); }}
        else
        { fprintf(stderr, "L%d: usage: push integer\n", counter);
                fclose(bus.file_ptr);
                free(bus.content_ptr);
                release(*head);
                exit(EXIT_FAILURE); }
        n = atoi(bus.value);
        if (bus.flag == 0)
                addnode(head, n);
        else
                addqueue(head, n);
}
