#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv) {
	
	char overwrite[24]="DC612 Day";
	char buffer[128];
	int compare=9;

	printf ("Welcome to DC612 1-Day event!\n\tStack Overflow Lvl 0\n");
	printf ("Simple variable alteration wins this one!\n");

	gets(buffer);

	if (strncmp(overwrite,"DC612 Day",compare)==0) {
		printf ("Sorry try again...\n");
		exit(0);
	} else {
		system("/bin/bash");
		exit(0);
	}
	exit(1);

}
