/*
	Author: 	James Marjun Jallorina
	Description: 	A Code Technique in linklist
*/

#include <stdio.h>
#include <stdlib.h>

//virually you can construct any data type content in linklist
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

//technique 1: iterate over the list using for loop
int fLength(struct node *head)
{
	int count = 0;
	struct node *iterator = NULL;

	for(iterator = head; iterator != NULL; iterator = iterator->next)
		count++;

	return count;	//return 0 if list is empty
}

//technique 1: iterate over the list using while loop
int wLength(struct node *head)
{
	int count = 0;
	struct node *iterator = NULL;
	
	iterator = head;
	while(iterator != NULL)
	{
		count++;
		iterator = iterator->next;
	}
	return count;
}

int main(int argc, char **argv)
{
	struct node *head = NULL;
	addnode(&head, 1);
	addnode(&head, 2);
	addnode(&head, 3);
	addnode(&head, 4);

	int ftotal = fLength(head);
	
	printf("%d\n", ftotal);
	
	int wtotal = wLength(head);

	printf("%d\n", wtotal);
	
	return 0;
}
