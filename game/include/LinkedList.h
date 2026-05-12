/*
Filename: LinkedList.h
Author: Joshua S. Andrews
Purpose: A generic linked list library
*/

typedef struct Node {
	void *data;
	int index; /* Location of Node in LinkedList */
	Node *next;
	Node *prev;
}Node;

typedef struct LinkedList {
	int length; /* Number of Elements in LinkedList*/
	Node head;
}

/* create empty linked list */
LinkedList * linkedlist_init();
/* Add Node to end of LinkedList */
void linkedlist_add(LinkedList * l, void *new_data);
/* Removes and frees node from LinkedList at index */
void linkedlist_remove_index(LinkedList * l, int index);
/* removes and frees first node in LinkedList */
void linkedlist_pop(LinkedList * l);
/* gets Node at index of linked list */
Node linkedlist_get_node(LinkedList * l, int index);
/* insert Node at index of LinkedList */
void linkedlist_insert(LinkedList * l, int index, void *data);
/* add Node at front of LinkedList */
void linkedlist_push(LinkedList *l, void *data);
/* Safely free LinkedList */
void linkedlist_free(LinkedList * l);

/* creates a node with given values and returns it */
Node * node_init(void *data, Node * next);
/* Prints LinkedList */
void printLL(LinkedList l);
/* Look at next item on list and return a string descriptor */
char * peek(LinkedList l);