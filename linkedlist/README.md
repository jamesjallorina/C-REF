#Linklist Code Examples <br/>

linklist can store virtually anything. <br/>

define linklist: <br/>

struct node{ <br/>
	//data part // you can add more data definitions here <br/>
	int data; <br/>
	struct node *next;		//this is important for linking //later will discuss how doubly linklist works <br/>
}; <br/>


linklist mechanics <br/> <br/>

1. allocate <br/>
	struct node *newnode = malloc(sizeof(struct node)); <br/>
	newnode->data = data; <br/>
2. link next <br/>
	newnode->next = *headref; <br/>
3. link head <br/>
	*headref = newnode; <br/>
