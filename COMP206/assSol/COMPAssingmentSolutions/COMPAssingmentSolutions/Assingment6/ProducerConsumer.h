#ifndef PRO_CON
#define PRO_CON

#define ZERO 		0
#define ONE 		1
#define TWO 		2
#define MINUS_ONE	-1

#define TURN "TURN"
#define DATA "DATA"

#define TURN_FILE "TURN.TXT"
#define DATA_FILE "DATA.TXT"

#define PRODUCER_TURN "0"
#define CONSUMER_TURN "1"

void producer();
void consumer();
void tellConsumerToExit();

#endif