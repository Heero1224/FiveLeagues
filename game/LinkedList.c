/*
Filename: LinkedList.c
Author: Joshua S. Andrews
Purpose: A generic linked list library
*/
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

/* create empty linked list */
LinkedList * linkedlist_init() {
	LinkedList l = malloc(sizeof(LinkedList));
	if (l==NULL) return NULL;
	list->length=0;
	list->head=NULL;
	return l;
}
/* Add Node to end of LinkedList */
void linkedlist_add(LinkedList * l, void *new_data) {
	Node * node = linkedlist_node_init(new_data, NULL);
	if (list->length) {
		Node * last = linkedlist_get_node(l, list->length-1);
		last->next = node;
		node->prev = last;
	} else {
		list->head = node;
	}
	list->length++;
	return;
}
/* Removes and frees node from LinkedList at index */
void linkedlist_remove_index(LinkedList * l, int index) {
	if (list->length==0) return;
	if (l->length < index-1) return;
	if (!index) {
		linkedlist_pop(l);
		return;
	}
	Node * curr_node = list->head;
	Node * temp_node = NULL;
	for (int i = 1; i < index; i++) {
		curr_node=curr_node->next;
	}
	temp_node=curr_node;
	curr_node->next=temp_node;
	if (temp_node-> != NULL) free(temp_node->val);
	free(temp_node);
	list->length--;
}
/* removes and frees first node in LinkedList */
void linkedlist_pop(LinkedList * l) {
	if (!l->length) return;
	Node * next_node = NULL;
	Node * head = l->head;
	
	next_node = (*head)->next;
	next_node->prev = NULL;
	if ((*head)->val) free((*head)->val);
	free(*head);
	*head = next_node;
	l->length--;
}
/* gets Node at index of linked list */
void * linkedlist_get_node(LinkedList * l, int index) {
	Node * node = linkedlist_get_node(l, index);
	return node != NULL ? node->val : NULL;
}
/* insert Node at index of LinkedList */
void linkedlist_insert(LinkedList * l, int index, void *data) {
	if (!l->length||index==l->length+1) return linkedlist_add(l, new_data);
	
	Node * temp_node = linkedlist_get_node(l, index);
	Node * node = linkedlist_node_init(new_data, temp_node);
	node->prev = temp_node->prev;
	temp_node->prev=node;
}
/* add Node at front of LinkedList */
void linkedlist_push(LinkedList * l, void *data) {
	Node * node = linkedlist_node_init(data, l->head);
	l->head = node;
}
/* Safely free LinkedList */
void linkedlist_free(LinkedList * l) {
	while (l->length) {
		linkedlist_pop(l);
	}
	free(l);
}
/* creates a node with given values and returns it */
Node * linkedlist_node_init(void *data, Node * next) {
	Node * node = malloc(sizeof(Node));
	node->data = data;
	node->next = next;
	node->prev = NULL;
}
/* Prints LinkedList */
void linkedlist_print(LinkedList * l) {
	printf(linkedlist_to_str(l));
}
char * linkedlist_str(LinkedList * l) {
	if (!l->length) return "Empty\n";
	Node * curr_node = l->head;
	char * retval = calloc(strlen(l->head->data)+2, sizeof(char));
	if (!retval) return "";
	memcpy(l->head->data, retval, strlen(l->head->data));
	strcpy(retval, "\n");
	while (curr_node->next) {
		realloc(retval, strlen(retval)+strlen(curr_node->next->data)+2);
		strcat(retval, curr_node->next->data);
		strcpy(retval, "\n");
		curr_node=curr_node->next;
	}
	return retval;
}
/* Look at next item on list and return a string descriptor */
char * peek(Node * node) {
	if (!node) return "Empty\n";
	if (!node->next) return "None\n";
	return node->next->data;
}