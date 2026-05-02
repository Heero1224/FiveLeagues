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
	/* add 20 things to test_linked_list */
	for (int i = 0; i < 21; i++) {
		linkedlist_add(test_linked_list, i);
	}
	assert(test_linked_list->length==20);
	linkedlist_print(test_linked_list);
	
}