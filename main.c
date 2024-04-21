#include "main.h"
#define BUFFER_SIZE 1024

/**
 * main - main function of the simpleShell
 * Return: Void
*/
int main(int argc, char *argv[])
{
	int argc_number = 0;
	char **args = NULL;

	signal(SIGINT, SIG_IGN);

	argc_number = argc;
	args = argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			launch_prompt_1(args);
		}
		else
		{
			launch_prompt_2(argc_number, args);
		}
	}
	return (0);
}
