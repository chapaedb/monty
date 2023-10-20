#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    FILE *file_ptr;
    char *content = NULL;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int line_number = 1;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file_ptr = fopen(argv[1], "r");
    if (!file_ptr)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file_ptr);
        bus.content_ptr = content;
        bus.flag = 0;
	line_number++;
        if (read_line > 0)
        {
            execute(content, &stack, line_number, file_ptr);
        }
        free(content);
    }

    fclose(file_ptr);
    free_stack(stack);
    return 0;
}
