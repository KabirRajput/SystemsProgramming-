#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
	char line[sizeof(int)];
	int newVal;
	newList();

	while(1){
		printf("\nMain::Give me a positive-integer - ");
		if (fgets(line, sizeof(line), stdin)) {
	    	if (1 != sscanf(line, "%d", &newVal)) {
	        	printf("Main::You entered something invalid. I can only take a positive-integer.\n");
	        	prettyPrint();
	        	exit(EXIT_FAILURE);
	    	}

	    	if (newVal < 0) {
				printf("Main:: %d is negative. I can only take a positive-integer\n", newVal);
				prettyPrint();
	        	exit(EXIT_FAILURE);
	    	}

	    	// printf("Main:: New number was: %d\n", newVal);
	    	int status = addNode(newVal);

	    	if (status == EXIT_FAILURE) {
	    		printf("Main:: Adding new NODE with value: %d failed.\n", newVal);
	    		prettyPrint();
	    		exit(EXIT_FAILURE);
	    	}
		}
	}

	return EXIT_SUCCESS;
}