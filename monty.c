#include "monty.h"
int take_num; /*global*/
int is_number(char *token)
{
        int i, num;

        if (token == NULL)
                return (-1);
        for (i = 0; token[i] != '\0'; i++)
        {
                if (token[i] >= '0' && token[i] <= '9')
                        break;
        }
        num = token[i] - '0';
        return (num);
}
/**
 * open_file - Open a monty files
 * @filename: Name if monty file
 */
int open_file_to_read(char *filename, stack_t **stack)
{
        FILE *in_file;
        char *token = NULL, *buff_line;
        unsigned int line_counter = 0;
        size_t buff_size;
        char *number;

        in_file = fopen(filename, "r");
        if (in_file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", filename);
                exit(EXIT_FAILURE);
        }

        while (getline(&buff_line, &buff_size, in_file) != EOF)
        {
                token = strtok(buff_line, "\n\t\r ");
                number = strtok(NULL, "\n\t\r ");
                line_counter++;
                if (token && strcmp(token, "push") == 0)
                        take_num = atoi(number);
		printf("token = %s, number = %d\n", token, take_num);
                if (get_opcode(token, line_counter, stack) == NULL)
                {
                        fprintf(stderr, "Unknown instruction%s\n", filename);
                        exit(EXIT_FAILURE);
                }
        }
        fclose(in_file);
        return (0);
}
