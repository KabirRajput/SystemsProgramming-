#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ProducerConsumer.h"

void consumer(){
	char data;
	char turn;
	FILE *turn_file, *data_file;

	while(1){
		turn_file = fopen(TURN_FILE, "r+");
		if (turn_file == NULL) {
			perror("fopen:");
			exit(EXIT_FAILURE);
		}
		turn = fgetc(turn_file);
		fclose(turn_file);

		if (turn == ONE + '0') {
			data_file = fopen(DATA_FILE, "r");
			if (data_file == NULL) {
				perror("fopen:");
				exit(EXIT_FAILURE);
			}
			data = fgetc(data_file);
			fclose(data_file);

			if (data == EOF) {
				break;
			}
			printf("%c", data);
			fflush(stdout);

			turn_file = fopen(TURN_FILE, "r+");
			if (turn_file == NULL) {
				perror("fopen:");
				exit(EXIT_FAILURE);
			}
			fputc(ZERO + '0', turn_file);
			fclose(turn_file);
		}
	}
}
