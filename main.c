#include "monty.h"

int main(int argc, char** argv)
{
	char* filename;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	strcpy(filename, argv[1]);
	open_file_to_read(filename);
	return (0);
}
