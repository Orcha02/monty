#include "monty.h"
int number; /*global*/
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
 * is_instrcution - Checks if is lowercase
 *@token: string to check
 * Return: 0
 */
/*char *is_instruction(char *token)
{
	int i;
	char func[7];

	for (i = 0; i != '\0'; i++)
	{
		if (islower(token[i]) > 0)
			func[i] = token[i];
	}
	return (func);
	}*/
/**
 * open_file - Open a monty files
 * @filename: Name if monty file
 */
void open_file_to_read(char *filename)
{
	char len_buff[1024], *buffer = len_buff;
	FILE *in_file;
	char *instruction, *line_buffer = NULL, *token = NULL;
	unsigned int line_counter = 1;
	int i, n;
	stack_t *stack;
	/* stack_t *top = NULL; */
	instruction_t operation[] = {
		/*{"push", push_stack},*/
		/*{"pall", pall_stack},*/
		/*{"pint", pint_stack},*/
		/*{"pop", pop_stack},*/
		/*{"swap", swap},*/
		{NULL, NULL}
	};
	stack = NULL;
	in_file = fopen(filename, "r");
	if (filename == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", filename);
	while (fgets(buffer, 1024, in_file) != NULL)
	{
		printf("%s\n", line_buffer);
		token = strtok(line_buffer, "\n\t\r ");
		/*if (token == '\0')
		  continue;*/
		/*instruction = is_instruction(token);*/
		number = is_number(token);
		for (n = 0; n != '\0'; n++)
		{
			if (strcmp(instruction, operation[n].opcode) == 0)
			{
				token = strtok(NULL, "\n\t\r ");
				/*if (token == NULL || number == -1)
				  not_int_err(line_counter);*/
/*take_func will receive the function to execute*/
				get_opcode(instruction,line_counter)(&stack, line_counter);
			}
		}
		line_counter++;
	}
	fclose(in_file);
}

