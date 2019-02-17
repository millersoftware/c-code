/*
 * Carl Miller
 * My-Unzip
 * Takes a zipped file and unzips it
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int main(int argc, char *argv[]){

	//Case: Incorrect format
	if(argc < 2){
		printf("my-unzip: file1 [file2 ...] \n");
		exit(1);
	}

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
		char buffer[5];

		//Loops in byets of 5
		while(fread(buffer, sizeof(buffer), 1, fp) == 1){
			int total = 0; //Used for # of letters

			// Calc size from binary
			for(int i = 0; i < 4; i++){
				total = total + buffer[i];
			}
			//Takes Ascii char and runs it through total loop to print out
			for(int i = 0; i < total; i++){
				printf("%c", buffer[4]);
			}
		}
		fclose(fp);
	}
	return(0);
}
