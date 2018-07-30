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


int addnode(struct node **headref, int data)
{
	struct node *newnode = malloc(sizeof(struct node));
	if(!newnode)
	{
		perror("error on adding on node\n");
		return -1;
	}
	newnode->data = data;
	newnode->next = *headref;
	
	*headref = newnode;
	return 0;
}

void printlist(struct node *head)
{
	struct node *iterator = NULL;
	
	if(!head)
	{
		printf("list is empty\n");
		return;
	}
	
	for(iterator = head; iterator != NULL; iterator = iterator->next)
		printf("%d\n", iterator->data);

	return;
}

//code technique example 2
void freelist(struct node **headref)
{
	if(*headref != NULL)
	{
		printf("list is not empty . . .\n");
		printf("freeing list\n");
		free(*headref);
	}
	*headref = NULL;
}

int main(int argc, char **argv)
{
	struct node *head = NULL;
	addnode(&head, 1);
	addnode(&head, 2);
	addnode(&head, 3);
	printlist(head);
	freelist(&head);
	printlist(head);
	return 0;
}