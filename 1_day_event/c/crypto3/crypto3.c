#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void print_hex (const char* printme) {

	int counter;
	int length = strlen(printme);
	
        for (counter=0; counter < length; counter ++) {
                if (&printme[counter] == "\n") { break; }
                if (&printme[counter] == "\0") { break; }
                printf("%X.", printme[counter]);
        }
        printf("\n\n");
	return;
}

void right_shift (const char* input, char* output) {

        unsigned int length = strlen(input);
        unsigned int shift = 3;
        unsigned int counter;

        for (counter=0; counter < length; counter++) {

                //if shift+counter less than length, copy to output at counter, from input at shift+counter
                if ( shift + counter < length ) {
                        output[counter] = input[shift+counter];
                }
                else {
                        output[counter] = input[shift+counter-length];
                }
		//printf("Shift round: %d\n", counter);
		//print_hex(output);
        }
return;
}

int main (int argc, char **argv) {
	
	//initialize create and variables with values or null 
	char input[8] = "\0\0\0\0\0\0\0";
	char shifted[8] = "\0\0\0\0\0\0\0";
	char result[9] = "\0\0\0\0\0\0\0\0";
	int counter = 0;
	
	//print welcome messages
	printf("\nWelcome to DC612 1-Day event!\n\nCrypto Lvl 3");
	printf("\nExplain the cipher.\n");
	
	//clear stdout and get input. find stringlength of input
	fflush(stdout);
	int i = fgets(input, strlen(key)-1, stdin);
	unsigned int inputL = strlen(input);
	
	//print input in hex
	printf("\nInput:\n");
	print_hex(input);

	//if input was typed
	if (&i != NULL ) {
		
		//shift inpput to the right and return in shifted
		right_shift(input, shifted);

		//printf("\nShifted:\n");
		//print_hex(shifted);

		char c[1];
		
		//for counter less than input length and if not \n or \0 xor and add to result
		for (counter=0; counter < inputL; counter++) {

			if (&shifted[counter] == "\n") { break; }
			if (&input[counter] == "\0") { break; }

			c[0]=shifted[counter]^input[counter];
		
			result[counter] = c[0];
		
		}
		
		//print output in hex with new line
		printf("Final Output:\n");
		print_hex(result);
	} else { //failed to input

		printf("Please enter some input\n");
		exit(0);
	}

exit(1);
}
