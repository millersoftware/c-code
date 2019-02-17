/*
 * Carl Miller
 * My-Zip
 * Takes a file and converts it into a zip file
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	//Case: Incorrect format
	if(argc < 2){
		printf("my-zip: file1 [file2 ...] \n");
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
		char buf;
		buf = fgetc(fp);

		//Temp Variables
		int count = 1;
		char temp = buf;
		buf = fgetc(fp);

		//Read File
		while(buf != EOF){
			//Checks for duplicate letter
			if(buf == temp){
				count++;
			}
			//Writes to stdout
			else{
				fwrite(&count, sizeof(int), 1, stdout);
				fwrite(&temp, sizeof(temp), 1, stdout);
				temp = buf;
				count = 1;
			}
			buf = fgetc(fp);
		}

		fclose(fp);
	}
	return(0);
}
