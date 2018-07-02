#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static struct NODE *head;

void newList(){
	head = NULL;
}

int addNode(int value){
	printf("List:: Adding NODE with value %d to list.\n", value);
	struct NODE *new_node = (struct NODE*) malloc(sizeof(struct NODE));

	if (new_node == NULL) {
		printf("List:: malloc() failed for new value- %d\n", value);
		return EXIT_FAILURE;
	}

	new_node->data = value;
	new_node->next = head;
	head = new_node;
	return EXIT_SUCCESS;
}

void prettyPrint(){
	struct NODE *reverse_head = head;
	struct NODE *current = head;
	struct NODE *next = NULL;
	struct NODE *prev = NULL;
	
	printf("List:: The original list is: ");
	while(current->next != NULL){
		printf("[%d]->", current->data);
		current = current->next;
	}
	printf("[%d]\n", current->data);

	current = head;
	while (current->next != NULL) {
		next = current->next;
		current->next = prev;
		// next->next = current;
		prev = current;
		current = next;
	}
	current->next = prev;
	reverse_head = current;

	printf("List:: List in reverse: ");
	while(reverse_head->next != NULL){
		printf("[%d]->", reverse_head->data);
		reverse_head = reverse_head->next;
	}
	printf("[%d]\n", reverse_head->data);
	printf("---------------------------------------------------\n");
}
