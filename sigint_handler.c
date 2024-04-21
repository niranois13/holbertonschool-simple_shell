#include "main.h"


void sigint_handler(int sign)
{
	(void)sign;
	printf("\n");
	exit(EXIT_SUCCESS);
}
