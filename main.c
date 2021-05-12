#include "monty.h"

int main(int argc, char** argv)
{
	char* filename;

	if (argc != 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file_to_read(argv[1]);
	return (0);
}
