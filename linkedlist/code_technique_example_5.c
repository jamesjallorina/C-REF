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
	newnode->data = data;
	newnode->next = *headref;
	
	*headref = newnode;
}

void printlist(struct node *head)
{
	if(!head)
	{
		printf("list is empty\n");
		return;
	}
	struct node *iterator = NULL;
	
	for(iterator=head; iterator!=NULL; iterator=iterator->next)
		printf("%d\n", iterator->data);
		
	return;
}

int main(int argc, char **argv)
{
	struct node dummy;	//code technique example 5
	dummy.next = NULL;
	
	struct node *tail;
	tail = &dummy;
	
	addnode(&(tail->next), 1);
	tail = tail->next;
	addnode(&(tail->next), 2);
	tail = tail->next;
	addnode(&(tail->next), 3);
	
	printlist(dummy.next);
	return 0;
}