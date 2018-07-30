Linklist Code Examples

linklist can store virtually anything.

define linklist:

struct node{
	//data part // you can add more data definitions here
	int data;
	struct node *next;		//this is important for linking //later will discuss how doubly linklist works
};


linklist mechanics

1. allocate
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
2. link next
	newnode->next = *headref;
3. link head
	*headref = newnode;