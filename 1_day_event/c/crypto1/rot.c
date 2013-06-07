#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SHIFT_MAX      26
#define NUMBER_OF_LETTERS    26
#define NUMBER_OF_DIGITS    10
#define CAESAR_CIPHER_SPECIAL_CHARS  " .!?,;:'()[]{}`"

typedef enum {
 	OPERATION_SUCCESS = 1U,
 	OPERATION_FAILED  = 0U
}
OPERATION_STATUS;

int main (int argc, char **argv) {
	
	char codedMessage[50];
	char originalMessage[50];
	short highshift = 3;
	short loshift = 2;
	short dshift = 1;	
		
	printf("\nWelcome to DC612 1-Day Event\n\nCrypto Lvl 1\n");
	printf("\nWhat type of cipher is this, and what are the keys?\n");
	
	fflush(stdout);
	int t = fgets(originalMessage, 50, stdin);
	
	if ( t == NULL ) {
		printf("You must input something!");
		exit(1);
	}
	
	unsigned int size = strlen(originalMessage);
	unsigned int i = 0;
	
	for(i=0; i<size; i++) {
		if(islower(originalMessage[i])) {
			codedMessage[i] = (((short)(originalMessage[i]-'a') + loshift) %NUMBER_OF_LETTERS) + 'a';
		}
		else if(isupper(originalMessage[i])) {
			codedMessage[i] = (((short)(originalMessage[i]-'A') + highshift) %NUMBER_OF_LETTERS) + 'A';
		}
		else if(isdigit(originalMessage[i])) {
			codedMessage[i] = ((short)(originalMessage[i]-'0') + dshift) %NUMBER_OF_DIGITS + '0';
		}
  		else if(strchr(CAESAR_CIPHER_SPECIAL_CHARS, originalMessage[i])!=NULL) {
   			codedMessage[i] = originalMessage[i];
  		}
  		else {
   			return OPERATION_FAILED;
  		}
 	}
 	codedMessage[size] = '\0';
 	printf("Your message is:\n%s", codedMessage);
	exit(0);
}
	
