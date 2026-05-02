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
	test_linked_list = linkedlist_init();
	/* add 1, remove 1 */
	printf("Test 1\n");
	assert(test_linked_list->length==0);
	linkedlist_add(test_linked_list, 1);
	assert(test_linked_list->length==1);
	assert(test_linked_list->head);
	assert(test_linked_list->head->data==1);
	linkedlist_pop(test_linked_list);
	assert(test_linked_list->length==0);
	assert(test_linked_list->head==NULL);
	
	/* add 20 things to test_linked_list */
	printf("Test 2\n");
	for (int i = 0; i < 21; i++) {
		linkedlist_add(test_linked_list, i);
	}
	assert(test_linked_list->length==20);
	curr = test_linked_list->head;
	for (int i=0; i<21; i++) {
		assert(curr->data==i);
	}
	
}