#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ProducerConsumer.h"

void producer(){
	char data;
	char turn;
	FILE *pFile, *turn_file, *data_file;

	pFile = fopen("mydata.txt", "r");
	if (pFile == NULL) {
		perror("[mydata.txt]:");
		tellConsumerToExit();
		printf("Producer Exiting...\n");
		exit(EXIT_FAILURE);
	}
	
	while (!feof(pFile)) {
		turn_file = fopen(TURN_FILE, "r+");
		if (turn_file == NULL) {
			perror("[TURN.txt]:");
			exit(EXIT_FAILURE);
		}
		turn = fgetc(turn_file);
		fclose(turn_file);

		if (turn == ZERO + '0') {
			data = fgetc(pFile);
			data_file = fopen(DATA_FILE, "r+");
			if (data_file == NULL) {
				perror("[DATA.txt]:");
				exit(EXIT_FAILURE);
			}
			fputc(data, data_file);
			fclose(data_file);
			
			turn_file = fopen(TURN_FILE, "r+");
			if (turn_file == NULL) {
				perror("[TURN.txt]:");
				exit(EXIT_FAILURE);
			}
			fputc(ONE + '0', turn_file);
		 	fclose(turn_file);
		} 
	}
	fclose(pFile);
}


void tellConsumerToExit(){
	FILE* data_file = fopen(DATA_FILE, "r+");
	
	if (data_file == NULL) {
		perror("[DATA.txt]:");
		exit(EXIT_FAILURE);
	}
	fputc(-1, data_file);
	fclose(data_file);

	FILE* turn_file = fopen(TURN_FILE, "r+");
	if (turn_file == NULL) {
		perror("[TURN.txt]:");
		exit(EXIT_FAILURE);
	}
	fputc(ONE + '0', turn_file);
	fclose(turn_file);
}
