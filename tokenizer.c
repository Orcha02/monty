#include "monty.h"
/**
 * tokenizer - Function that parse the line of the file.
 * @buffer: Pointer with address to the line buffer.
 * Return: Double pointer with address to tokens.
 */
char **tokenizer(char *buffer)
{
	int array_pos;
	char **array_tokens;

	if (!buffer)
		return (NULL);
	array_tokens = malloc(sizeof(char *) * 4);
	if (!array_tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	array_tokens[0] = strtok(buffer, " \t\n");
	for (array_pos = 1; array_pos < 2 && array_tokens != NULL; array_pos++)
		array_tokens[array_pos] = strtok(NULL, " \t\n");
	array_tokens[array_pos] = NULL;
	return (array_tokens);
}
