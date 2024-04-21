#include "main.h"
#define BUFFER_SIZE 1024

/**
 * main - main function of the simpleShell
 * @argc: number of command-line arguments.
 * @argv: array of command-line arguments.
 * Return: 0, always succeed
*/
int main(int argc, char *argv[])
{
	int argc_number = 0;
	char **args = NULL;

	signal(SIGINT, sigint_handler);

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

/**
* sigint_handler - function that handles the SIGINT(CTRL+C) signal
*					by printing a newline and prompt
*/
void sigint_handler(void)
{
	printf("\n$$ ");
	fflush(stdout);
}
