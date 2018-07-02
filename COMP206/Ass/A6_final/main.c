//Chris Chan 260430627 and Kabir Rajput 260809334
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

						//prototyping
void consumer();
void producer();

int main(void){
	FILE *turn = fopen("TURN.txt", "wt");	//create TURN.txt file
	FILE *data = fopen("DATA.txt", "wt");	//creat DATA.txt file
	if(turn == NULL || data == NULL){
		printf("ERROR");
		exit(EXIT_FAILURE);
	}

	fputc('0', turn);			//initialize turn to 0, so that producer starts first

	fclose(turn);				//close both files
	fclose(data);

	int programID = fork();			//start forking
	if(programID == -1) exit(1);
	if(programID == 0){			//if programID is 0
		consumer();			//use consumer method
		wait();
	}
	if(programID != 0){			//if programID is not 0
		producer();			//use producer method
		wait();
	}
	exit(0);

}
