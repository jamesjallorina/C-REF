**Linklist Code Examples** <br/>

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
	
Appendix — Other Implementations <br/>
There are a many variations on the basic linked list which have individual advantages <br/>
over the basic linked list. It is probably best to have a firm grasp of the basic linked list <br/>
and its code before worrying about the variations too much. <br/>

• **Dummy Header** Forbid the case where the head pointer is NULL. <br/>
Instead, choose as a representation of the empty list a single "dummy" <br/>
node whose .data field is unused. The advantage of this technique is that <br/>
the pointer-to-pointer (reference parameter) case does not come up for <br/>
operations such as Push(). Also, some of the iterations are now a little <br/>
simpler since they can always assume the existence of the dummy header<br/>
node. The disadvantage is that allocating an "empty" list now requires<br/>
<br/>
allocating (and wasting) memory. Some of the algorithms have an ugliness <br/>
to them since they have to realize that the dummy node "doesn't count." <br/>
(editorial) Mainly the dummy header is for programmers to avoid the ugly <br/>
reference parameter issues in functions such as Push(). Languages which <br/>
don't allow reference parameters, such as Java, may require the dummy <br/>
header as a workaround. (See the "temporary dummy" variant below.) <br/>
<br/>
<br/>
• **Circular Instead** of setting the .next field of the last node to NULL,<br/>
set it to point back around to the first node. Instead of needing a fixed head<br/>
end, any pointer into the list will do.<br<br/>
<br/>
<br/>
• **Tail Pointer** The list is not represented by a single head pointer. Instead<br/>
the list is represented by a head pointer which points to the first node and a<br/>
tail pointer which points to the last node. The tail pointer allows operations<br/>
at the end of the list such as adding an end element or appending two lists<br/>
to work efficiently.<br/>
<br/>
<br/>
• **Head struct** A variant I like better than the dummy header is to have a<br/>
special "header" struct (a different type from the node type) which<br/>
contains a head pointer, a tail pointer, and possibly a length to make many<br/>
operations more efficient. Many of the reference parameter problems go<br/>
away since most functions can deal with pointers to the head struct<br/>
(whether it is heap allocated or not). This is probably the best approach to<br/>
use in a language without reference parameters, such as Java.<br/>
<br/>
<br/>
• **Doubly-Linked** Instead of just a single .next field, each node<br/>
incudes both .next and .previous pointers. Insertion and deletion now<br/>
require more operations. but other operations are simplified. Given a<br/>
pointer to a node, insertion and deletion can be performed directly whereas<br/>
in the singly linked case, the iteration typically needs to locate the point<br/>
just before the point of change in the list so the .next pointers can be<br/>
followed downstream.<br/>
<br/>
<br/>
<br/>
• **Chunk List** Instead of storing a single client element in each node, store<br/>
a little constant size array of client elements in each node. Tuning the<br/>
number of elements per node can provide different performance<br/>
characteristics: many elements per node has performance more like an<br/>
array, few elements per node has performance more like a linked list. The<br/>
Chunk List is a good way to build a linked list with good performance.<br/>
<br/>
<br/>
• **Dynamic Array** Instead of using a linked list, elements may be<br/>
stored in an array block allocated in the heap. It is possible to grow and<br/>
shrink the size of the block as needed with calls to the system function<br/>
realloc(). Managing a heap block in this way is a fairly complex, but can<br/>
have excellent efficiency for storage and iteration., especially because<br/>
modern memory systems are tuned for the access of contiguous areas of<br/>
memory. In contrast, linked list can actually be a little inefficient, since<br/>
they tend to iterate through memory areas that are not adjacent.<br/>


