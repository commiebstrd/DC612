#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char **argv) {
	
	//initialize create and variables with values or null 
	char key[9]="abcdefgh\0";
	char input[9] = "\0\0\0\0\0\0\0\0";
	char result[9] = "\0\0\0\0\0\0\0\0";
	int counter = 0;
	
	//print welcome messages
	printf("\nWelcome to DC612 1-Day event!\n\nCrypto Lvl 2");
	printf("\nFind the hidden key.\n");
	
	//clear stdout and get input. find stringlength of input
	fflush(stdout);
	int i = fgets(input, strlen(key)-1, stdin);
	unsigned int inputL = strlen(input);
	
	//print input in hex
	printf("\nInput:\n");
        for (counter=0; counter < inputL; counter ++) {
                if (&input[counter] == "\n") { break; }
		if (&input[counter] == "\0") { break; }
		printf("%X.", input[counter]);
        }
        printf("\n\n");

	//if input was typed
	if (&i != NULL ) {
		char c[1];
		
		//for counter less than input length and if not \n or \0 xor and add to result
		for (counter=0; counter < inputL; counter++) {

			if (&input[counter] == "\n") { break; }
			if (&key[counter] == "\0") { break; }

			c[0]=input[counter]^key[counter];
		
			result[counter] = c[0];
		
		}
		
		//print output in hex with new line
		printf("Final Output:\n");
		for (counter=0; counter < inputL; counter ++) {
			printf("%X.", result[counter]);
		}
		printf("\n\n");
	} else { //failed to input

		printf("Please enter some input\n");
		exit(0);
	}

exit(1);
}
