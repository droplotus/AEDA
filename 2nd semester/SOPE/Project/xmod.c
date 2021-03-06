
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close

struct InitialData {
	char OPTION;
	char *MODE;
	char *FILE_DIR;

};

int main(int argc, char **args, char **argv)
{
	if(argc != 4) { fprintf(stderr, "ERROR: misuse of arguments. [xmod OPTIONS MODE FILE/DIR]\n"); exit(1); }
	
	char option = args[1][1];
	char *mode = args[2];
	char *file_dir = args[3];

	int fd = open(args[3], O_CREAT, S_IRUSR); // open with read mode, otherwise it will give error trying to open it if it already exists

	// checking basic command syntax. [mode] to be developped
	if(strlen(args[1]) != 2 || (option != 'v' && option != 'c' && option != 'R')) { fprintf(stderr, "ERROR: misuse of options. [-v, -c, -R]\n"); exit(1); }
	if((mode[0] != 'u' && mode[0] != 'g' && mode[0] != 'o' && mode[0] != 'a')) { fprintf(stderr, "ERROR: misuse of mode. [u | g | o | a]\n"); exit(1); }
	if(fd < 0) { fprintf(stderr, "ERROR: path of file.\n"); exit(1); }
	
	// filling the data struct
	struct InitialData data = {.OPTION = option, .MODE = mode, .FILE_DIR = file_dir};

	close(fd);
	return 0;
}
