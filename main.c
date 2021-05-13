#include "monty.h"
/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: EXIT_FAIlURE if fail or EXIT_SUCCESS otherwise
 */
int main(int argc, char **argv)
{
	FILE *filename = NULL;
	char **arr_tokens = NULL;
	int number_line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = fopen(av[1], "r");
	if (filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	for (number_line = 1; fgets(buffer, 1024, filename) != NULL; number_line++)
	{
		arr_tokens = tokenizer(buffer);
		get_opcode(arr_tokens[0], number_line)(&stack, number_line);
		free(arr_tokens);
	}
	fclose(filename);
	free_dlistint(stack);
	return (EXIT_SUCCESS);
}