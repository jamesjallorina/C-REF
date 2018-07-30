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
	//struct node *newnode = (struct node *) malloc(sizeof(newnode));	//explicit type casting
	struct node *newnode = malloc(sizeof(newnode));	//new compilers automatically type cast it
	newnode->data = data;
	newnode->next = *headref;
	
	*headref = newnode;
}


int main(int argc, char **argv)
{
	struct node *head = NULL;
	struct node **lastheadptr = &head;		//code technique example 6
	
	addnode(lastheadptr, 1);
	lastheadptr = &((*lastheadptr)->next);
	addnode(lastheadptr, 2);
	lastheadptr = &((*lastheadptr)->next);
	addnode(lastheadptr, 3);
	lastheadptr = &((*lastheadptr)->next);
	addnode(lastheadptr, 4);
	
	struct node *iterator = NULL;
	
	for(iterator = head; iterator != NULL; iterator = iterator->next)
		printf("%d\n", iterator->data);
		
	return 0;
}