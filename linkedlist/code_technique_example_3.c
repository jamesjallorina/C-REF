/*
	Author: 	James Marjun Jallorina
	Description: 	A Code Technique in linklist
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

//code technique example 3 -- push to head of the list
int addnode(struct node **headref, int data)
{
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = *headref;
	
	*headref = newnode;
}

int main(int argc, char **argv)
{
	struct node *head = NULL;
	addnode(&head, 1);
	addnode(&head, 2);
	addnode(&head, 3);
	
	struct node *iterator = NULL;
	for(iterator = head; iterator != NULL ; iterator = iterator->next)
		printf("%d\n", iterator->data);
		
	return 0;
}