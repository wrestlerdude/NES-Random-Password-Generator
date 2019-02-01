#include "generators.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*GENERATE)();

GENERATE args_reader(int argc, char *argv[])
{
	if (argc != 2)
		exit(0);
	if (strcmp("metroid", argv[1]) == 0)
		return &metroid;
	else
		exit(0);
}

int main(int argc, char *argv[])
{
	GENERATE function = args_reader(argc, argv);
	(*function)();
	return 0;
}