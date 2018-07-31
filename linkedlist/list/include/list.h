/*
	Author: 	James Marjun Jallorina
	Description: 	Linklist Library
*/

#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *next;
};


void push(struct node **headref, int data)
{
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = *headref;
	*headref = newnode;
}

struct node *appendnode_with_push(struct node **headref, int data)
{
	struct node *current = *headref;
	if(current == NULL)
	{
		push(headref,data);
		return *headref;
	}
	else
	{
		while(current != NULL)
			current = current->next;
			
		push(&(current->next), data);
		return *headref;
	}
}

struct node *appendnode(struct node **headref, int data)
{
	struct node *current = *headref;
	struct node *newnode = NULL;
	
	newnode = malloc(sizeof(struct node));
	newnode->data = data;
	
	if(current == NULL)
	{
		*headref = newnode;
		return *headref;
	}
	else
	{
		while(current != NULL)
		{
			current = current->next;
		}
		current->next = newnode;
		return *headref;
	}
}

#endif


