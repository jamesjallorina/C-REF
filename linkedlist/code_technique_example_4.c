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
	//you can add error handler 
	if(!newnode)
	{
		//if fail to allocate in heapcheck
		perror("failed to allocate data in the heap\n");
		return -1;
	}
	
	newnode->data = data;
	newnode->next = *headref;
	
	*headref = newnode;
	return 0;
}

int main(int argc, char **argv)
{
	struct node *head = NULL;
	addnode(&head,1); //allocate 
	
	struct node *tail;	//code technique example 4
	tail = head;
	
	addnode( &(tail->next), 2);
	tail = tail->next;					//point tail to last node
	addnode( &(tail->next), 3);
	tail = tail->next;
	addnode( &(tail->next), 4);
	
	struct node *iterator = NULL;
	for(iterator= head; iterator; iterator = iterator->next)
		printf("%d\n", iterator->data);
	
	return 0;
}