#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "ProducerConsumer.h"


int main(int argc, char *argv[]) {
	FILE* turn_file = fopen(TURN_FILE, "w");
	FILE* data_file = fopen(DATA_FILE, "w");

	if (data_file == NULL || turn_file == NULL || fputc(ZERO + '0', turn_file) == EOF){
		perror("Error accessing one of the required files [ TURN.TXT, DATA.txt]");
		exit(EXIT_FAILURE);
	}
	fclose(turn_file);
	fclose(data_file);

	if( access( "mydata.txt", F_OK ) == -1 ) {
    	perror("[mydata.txt]");
		exit(EXIT_FAILURE);
	}

	int pid = fork();
	if (pid == ZERO) {
		producer();
		wait(NULL);
	} else if (pid != MINUS_ONE) {
		consumer();
		wait(NULL);
		//wait(&status);
	} else {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}




