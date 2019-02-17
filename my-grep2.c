/*
 * Carl Miller
 * My-Grep
 * Takes a file as input and a user defined search term.
 * Porceeds to search through file, printing any line that contains term.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

//A function to print lines from file based on search term
void printfile(FILE *f, char *s){
	char buf[MAX];
	char *bufp = buf;
	size_t bufsize = MAX;
	size_t temp;

	temp = getline(&bufp, &bufsize, f);

	//Read File Loop
	while(temp != -1){
		if(strstr(buf, s) != NULL){
			printf("%s", buf);
		}
		temp = getline(&bufp, &bufsize, f);
	}
}

int main(int argc, char *argv[]){

	//Case: Incorrect informtion given
	if(argc < 2){
		printf("my-grep: searchterm [file ...] \n");
		exit(1);
	}
	//Case: No file specified. Use Stdin instead
	else if(argc == 2){
		printfile(stdin, argv[1]);
		return (0);
	}
	//Case; Regular Search
	else{
		//Loop for each file
		for(int filenum = 2; filenum < argc; filenum++){

			//Open File
			FILE *fp = fopen(argv[filenum], "r");
			//Case: Cannot read file
			if(fp == NULL){
				printf("cannot open file\n");
				exit(1);
			}

			printfile(fp, argv[1]);
			fclose(fp);
		}
		return(0);
	}
}
