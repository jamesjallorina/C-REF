/*
	Author: 	James Marjun Jallorina
	Description: 	This is a sample linklist
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};


int addnode(struct node **headRef, int data)
{
	struct node *newnode = malloc(sizeof(struct node));
	if(!newnode)
	{
		perror("error on adding on node\n");
		return -1;
	}
	newnode->data = data;
	newnode->next = *headRef;

	*headRef = newnode;
	return 0;
}

void printnode(struct node *head)
{
	struct node *iterator = NULL;
	
	if(!head)
	{
	 	printf("node is empty\n");
		return;
	}

	for(iterator = head; iterator != NULL; iterator = iterator->next)
		printf("node value: %d\n", iterator->data);

	return;
}

int Length(struct node *head)
{
	int count = 0;
	struct node *iterator = NULL;

	for(iterator = head; iterator != NULL; iterator = iterator->next)
		count++;

	return count;
}

int main(int argc, char **argv)
{
	int total = 0;
	struct node *head = NULL;
	
	addnode(&head, 1);
	addnode(&head, 2);
	addnode(&head, 3);

	total = Length(head);
	printf("total nodes in the list: %d\n", total);
	
	printnode(head);

	return 0;
	
}
