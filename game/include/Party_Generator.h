/*
Filename: Party_Generator.h
Author: Joshua S. Andrews
Purpose: Generates a new Party for 5 Leagues campaign
*/
#ifndef PARTY_GEN_H
#define PARTY_GEN_H
struct Party {
	members; /* linked list */
	stash; /*linked List */
	backpack; /* Linked List */
}Party;

/* 
Generates New Party of 4 heroes and 2 followers where the caster variable is the 
number of casters to be in the party
*/
Party party_init(int caster);
/* removes all equipment from party members */
void party_remove_all(Party party);
/* equips an item to a character from a given source */
void equip_item(LinkedList source, Hero hero, char * item);

/* Returns a String representation of a party */
char * party_tostring(Party party);
/* Prints a String representation of a part */
void party_print(char * str);

#ENDIF // PARTY_GEN_H