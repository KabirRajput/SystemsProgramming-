#ifndef LIST_H
#define LIST_H

struct NODE {
	int data;
	struct NODE *next;
};

void printMean();
void newList();
int addNode(int value);
void prettyPrint();

#endif

