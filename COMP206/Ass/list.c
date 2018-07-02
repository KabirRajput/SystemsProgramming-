#include <stdlib.h>
#include <stdio.h>
#include "list.h"
struct NODE *head;
void newList()
{
	head=NULL;
}

int addNode(int value)
{
	struct NODE *temp =(struct NODE *)malloc(sizeof(struct NODE));
	if(temp==NULL) EXIT_FAILURE;
	temp->data= value;
	temp->next = head;      	//chain to head of the list
	head = temp;
	EXIT_SUCCESS;
}

void prettyPrint()
{
	struct NODE *temp= head;			//head pointer
	while(temp!=NULL)		//stop at the end of the list
	  {printf("%d \n", temp->data);
	   temp=temp->next;		//move to the following node in the list
	}
}
