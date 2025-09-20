#include "monty.h"
#include <stdlib.h>

void freevec(char **vector)
{
	for (char **traverser = vector; *traverser; traverser++)
		free(*traverser);
	free(vector);
}
