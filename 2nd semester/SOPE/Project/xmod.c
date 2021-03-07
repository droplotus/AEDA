
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <stdbool.h>

struct InitialData {
	char OPTION;
	char *MODE;
	char *FILE_DIR;

};

bool checkingSyntax(int argc, char **args, struct InitialData* data){
	if(argc != 4) { fprintf(stderr, "ERROR: misuse of arguments. [xmod OPTIONS MODE FILE/DIR]\n"); return false; }
	
	data->OPTION = args[1][1];
	data->MODE = args[2];
	data->FILE_DIR = args[3];

	int fd = open(data->FILE_DIR, O_CREAT, S_IRUSR); // open with read mode, otherwise it will give error trying to open it if it already exists

	// checking basic command syntax. [mode] to be developped
	if(strlen(args[1]) != 2 || (data->OPTION != 'v' && data->OPTION != 'c' && data->OPTION != 'R')) { fprintf(stderr, "ERROR: misuse of options. [-v, -c, -R]\n"); return false; }

	if((data->MODE[0] != 'u' && data->MODE[0] != 'g' && data->MODE[0] != 'o' && data->MODE[0] != 'a') || !(strlen(data->MODE) <= 5 && strlen(data->MODE) >= 3)) { 
		fprintf(stderr, "ERROR: misuse of mode. [ u | g | o | a ][ - | + | = ][ rwx ]\n"); return false; }

	if((data->MODE[1] != '-' && data->MODE[1] != '+' && data->MODE[1] != '=')) {
		fprintf(stderr, "ERROR: misuse of mode. [ u | g | o | a ][ - | + | = ][ rwx ]\n"); return false; }

	char *rwx = malloc(3 * sizeof(char));
	int c = 2;
	while(c < strlen(data->MODE)){
		rwx[c-2] = data->MODE[c];
		c++;
	}
	if(strcmp(rwx, "r") && strcmp(rwx, "w") && strcmp(rwx, "x") && strcmp(rwx, "rw") && strcmp(rwx, "rx") && strcmp(rwx, "wx") && strcmp(rwx, "rwx")){
		fprintf(stderr, "ERROR: misuse of mode. [ u | g | o | a ][ - | + | = ][ rwx ]\n");
		return false;
	}
	
	if(fd < 0) { fprintf(stderr, "ERROR: path of file.\n"); return false; }

	close(fd);
	return true;
}

int main(int argc, char **args, char **argv)
{
	struct InitialData data;
	if(!checkingSyntax(argc, args, &data)) exit(1);
	
	printf("%c\n", data.OPTION);

	return 0;
}
