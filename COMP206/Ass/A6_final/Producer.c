//Kabir Rajput 260809334
#include <stdio.h>
#include <stdlib.h>

//this method should read from mydata.txt and copy character by character in to DATA.y=txt when it is's it turn to access DATA.txt
void producer(){

	FILE *producerInput = fopen("mydata.txt","rt");		//only read through mydata.txt once
	if(producerInput == NULL){
		printf("error in mydata.txt");
		exit(EXIT_FAILURE);
	}

	while(1){
		char signal = '1';				//initialize signal
		while(signal == '1'){   			//while signal is 1, continuously read TURN.txt until signal is 1
			FILE *myTurn = fopen("TURN.txt", "rt");
			if(myTurn == NULL){
				printf("error in TURN.txt");
				exit(EXIT_FAILURE);
			}
			signal = fgetc(myTurn);			//read if signal is 0 or 1, if signal is 0, it is producer turn, if signal is 1 it is consumer's turn
			fclose(myTurn);
		}

		char readChar = fgetc(producerInput);		//store the character from producer input into readChar
		if(feof(producerInput)){			//once it ends it copies every letter from mydata.txt, exit of infinite while loop
			break;
		}
		FILE *producerOutput = fopen("DATA.txt","wt");	//write to DATA.txt
		if(producerOutput == NULL){
			printf("error in DATA.txt");
			exit(EXIT_FAILURE);
		}
		fputc(readChar, producerOutput);		//write each char read in mydata.txt  to DATA.txt
		fclose(producerOutput);

		FILE *myTurn = fopen("TURN.txt","wt");		//open TURN.txt and write in it
		if(myTurn == NULL){
			printf("error in TURN.txt");
			exit(EXIT_FAILURE);
		}
		fputc('1', myTurn);				//set signal to 1, to give turn to consumer
		fclose(myTurn);

	}
	fclose(producerInput);
	FILE *blank = fopen("DATA.txt", "wt");			//create a blank file so that consumer knows that producer has finished reading mydata.txt
	fclose(blank);
	FILE *myTurn = fopen("TURN.txt", "wt");			//set signal to 1, to give turn to consumer
	fputc('1', myTurn);
	fclose(myTurn);
}
