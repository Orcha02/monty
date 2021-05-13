#include "monty.h"

int main(int argc, char *argv[])
{
        stack_t *stack = NULL;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        /* strcpy(filename, argv[1]); */
        open_file_to_read(argv[1], &stack);
        return (0);
}
