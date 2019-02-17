/*
 * Carl Miller
 * My-Cat
 * Reads a file and prints contents
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	//Loop for each file
	for(int filenum = 1; filenum < argc; filenum++){

		//Open File
		FILE *fp = fopen(argv[filenum], "r");
		//Case: Cannot read file
		if(fp == NULL){
			printf("cannot open file\n");
			exit(1);
		}

		//Crate Buffer
		char buf;
		buf = fgetc(fp);

		//Read File
		while(buf != EOF){
			printf("%c",buf);
			buf = fgetc(fp);
		}

		fclose(fp);
	}
	return(0);
}
