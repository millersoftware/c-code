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
int main(int argc, char *argv[]){
	//Create Buffer/Prepare getline
		char buf[MAX];
		char *bufp = buf;
		size_t bufsize = MAX;
		size_t temp; 

	//If no file or search term is entered
	if(argc < 2){
		printf("my-grep: searchterm [file ...] \n");
		exit(1);
	}

	if(argc == 2){
		temp = getline(&bufp, &bufsize, stdin);
		while(temp != -1){
			if(strstr(buf, argv[1]) != NULL){
				printf("%s", buf);
			}
			temp = getline(&bufp, &bufsize, stdin);
		}
		return (0);
	}

	//Loop for each file
	for(int filenum = 2; filenum < argc; filenum++){

		//Open File
		FILE *fp = fopen(argv[filenum], "r");
		if(fp == NULL){
			printf("cannot open file\n");
			exit(1);
		}

		temp = getline(&bufp, &bufsize, fp);//returns -1 if failed

		//Read File
		while(temp != -1){
			//Search Statement
			if(strstr(buf, argv[1]) != NULL){
				printf("%s",buf);
			}

			temp = getline(&bufp, &bufsize, fp);
		}

		fclose(fp);
	}
	return(0);
}
