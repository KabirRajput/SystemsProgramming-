//Chris Chan 260430627
#include <stdio.h>
#include <stdlib.h>

//this method should prints out whatever is contained in DATA.txt, when it is it's turn to access it
void consumer(){

	while(1){
		char signal = '0';				//initialize signal
		while(signal == '0'){				//if signal is 0, continuously open TURN.txt until signal is 1
			FILE *myTurn = fopen("TURN.txt", "rt");	//read TURN.txt
			if(myTurn == NULL){
				printf("error in TURN.txt");
				exit(EXIT_FAILURE);
			}
			signal = fgetc(myTurn);			//read if signal is 0 or 1 in TURN.txt, if singal is 0 it is producer's turn, when signal is 1, it is consumer's turn
			fclose(myTurn);
		}

		FILE *consumerInput = fopen("DATA.txt", "rt");	//read DATA.txt
		if(consumerInput == NULL){
			printf("error in DATA.txt");
			exit(EXIT_FAILURE);
		}
		char character = fgetc(consumerInput);		//get character in DATA.text
		if(feof(consumerInput)){
			break;
		}
		printf("%c", character);			//print out character from DATA.text
		fclose(consumerInput);

		FILE *myTurn = fopen("TURN.txt", "wt");		//open TURN.txt and write in it
		if(myTurn == NULL){
			printf("error in TURN.txt");
			exit(EXIT_FAILURE);
		}
		fputc('0', myTurn);				//change signal to 0, to give turn to producer
		fclose(myTurn);
	}
}
