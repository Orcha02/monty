#include "monty.h"
int number; /*global*/
/**
 * open_file - Open a monty files
 * @filename: Name if monty file
 */
void open_file_to_read(char *filename)
{
	char *instruction;
	FILE *in_file;
	size_t len_buff = 0;
	char *line_buffer = NULL, *token = NULL;
	unsigned int line_counter = 1;
	/* stack_t *top = NULL; */

	in_file = fopen(filename, "r");
	if (filename == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", filename);
	
	while (getline(&line_buffer, &len_buff, in_file) != EOF)
	{
		token = strtok(line_buffer, "\n\t\r ");
		if (token == '\0')
			continue;
		instruction = is_instruction(token);
		number = is_number(token);
		if (strcmp(instruction, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			if (token == NULL || number == -1)
				not_int_err(line_counter);
/*take_func will receive the function to execute*/
			take_func = get_opcode(instruction,line_counter);
			
/*take_func will take the place of the function to execute: push, pall, pint*/
			take_func(&top, line_counter);
		}
		else
		{
			take_func = get_opcode(token, line_counter);
			take_func(&top, line_counter);
		}
		line_counter++;
	}
	fclose(in_file);
}
/**
 * is_number - Checks if string received is int or not
 * @token: string to check
 * Return: -1 if sring is not int or 1 if yes
 */
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
	num = atoi(token[i]);
	return (num);
}
/**
 * is_lower - Checks if is lowercase
 *@token: string to check
 * Return: 0
 */
char *is_instruction(char *token)
{
	int i;
	char func[7];

	for (i = 0; i != '\0'; i++)
	{
		if (islower(token[i]) > 0)
		{
			func[i] = token[i];
		}
	}
	return (func);
}
