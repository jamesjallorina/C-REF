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

//append node with push
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

//append node wihout using push
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

struct node *copylist(struct node *headref)
{
	struct node *current = headref;
	struct node *newlist = NULL;
	struct node *tail = NULL;
	
	while(current != NULL)
	{
		if(newlist == NULL)
		{
			newlist = malloc(sizeof(struct node));
			newlist->data = current->data;
			newlist->next = NULL;
			tail = newlist;
		}
		else
		{
			tail->next = malloc(sizeof(struct node));
			tail = tail->next;
			tail->data = current->data;
			tail->next = NULL;
		}
		current = current->next;
	}
	return (newlist);
}

struct node *copylist_with_push(struct node *headref)
{
	struct node *current = headref;
	struct node *newlist = NULL;
	struct node *tail = NULL:;
	
	while(current != NULL)
	{
		if(newlist == NULL)
		{
			push(&newlist, current->data);
			tail = newlist;
		}
		else
		{
			push(&(tail->next), current->data);
			tail = tail->next;
		}
		current = current->next;
	}
	return (newlist);
}

struct node *copylist_with_dummy_node(struct node *headref)
{
	struct node *current = headref;
	struct node dummy;
	dummy.next = NULL;
	struct node *tail = &dummy;

	while(current != NULL)
	{
		push(&(tail->next), current->data);
		tail = tail->next;
		current = current->next;
	}
	return (dummy.next);
}

#endif


