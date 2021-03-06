
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **args, char **argv)
{
	char option = args[1][1];
	if((option != 'v' && option != 'c' && option != 'R') || strlen(args[1])!=2) fprintf(stderr, "ERROR: misuse of options. [-v, -c, -R]");
	/*char *option = args[1];
	if(strcmp(option, "-v") && strcmp(option, "-c") && strcmp(option, "-R")) {
		printf("ERROR: misuse of options. [-v, -c, -R], %s\n", option);
		exit(1);
	}*/
	printf("option: %c\n", option);

	return 0;
}
