/**
 * Invalid_instruction_error - If the file contains an invalid instruction
 * @inv_instruction: instruction that is invalid
 * @line: line
 * Return: void
 **/
void Invalid_instruction_error(char *inv_instruction, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, inv_instruction);
	exit(EXIT_FAILURE);
}
