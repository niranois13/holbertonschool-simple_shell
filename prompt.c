#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
char *input;
size_t len = 0;
size_t read;

while (1) {
    printf("€ ");
    read = getline(&input, &len, stdin);

	if ((int) read == -1)
	{
		perror(":( No such file or directory");
		exit(EXIT_FAILURE);
	}
}
return (0);
}
