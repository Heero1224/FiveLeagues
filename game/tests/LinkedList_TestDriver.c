/*
Filename: LinkedList_TestDriver.c
Author: Joshua S. Andrews
Purpose: COntains a testing suite for a custom LinkedList library
*/
include <stdlib.h>
include <stdio.h>
include <assert.h>
include "LinkedList.h"

int main() {
	/* create LL */
	LinkedList * test_linked_list = linkedlist_init();
	/* add test */
	test1(test_linked_list);
	/* remove test */
	test2(test_linked_list);
	test3(test_linked_list);
}
/* add testing */
void test1(LinkedList * l) {
	printf("##### ADD TESTING #####\n");
	/* add to back */
	for (int i=1; i<6; i++) {
		linkedlist_add(l, i);
		assert(l->length==i);
		assert(l->head != NULL);
	}
	/* add to front */
	for (int i=-6; i>-11; i--) {
		linkedlist_push(l, i);
		assert(l->length==(i*(-1)));
		assert(l->head->data==i);
	}
	assert(l->length==10);
	/* add at index 5*/
	for (int i=0; i>-6; i--) {
		linkedlist_insert(l, i);
		assert(l->length==(10+(i*(-1))));
		Node * temp;
		temp = linkedlist_get_node(l, 5);
		assert(temp->data==i);
	}
	assert(l->length==16);
	/* Checking all data values */
	Node * curr = l->head;
	for (int i=-10; i<6; i++) {
		assert(curr->data==i);
		curr=curr->next;
	}
	/* l should now be [-10::5] */
}
/* remove nodes testing */
void test2(LinkedList * l) {
	assert(l->length==16);
	assert(l->head->dat==-10);
	/* remove front */
	for (int i=0; i<16; i++) {
		linkedlist_pop(l);
	}
	assert(l->length==0);
	assert(l->head==NULL);
	test1(l);
	/*remove back */
	for (int i=16; i>0;i--) {
		linkedlist_remove_index(l, i);
		assert(l->length==(i-1));
	}
	assert(l->length==0);
	assert(l->head==NULL);
}
