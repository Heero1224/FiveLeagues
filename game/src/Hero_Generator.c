/*
Filename: Hero_Generator.c
Author: Joshua S. Andrews
Purpose: All functions relating to a Hero
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "LinkedList.h"
#include "Hero_Generator.h"

/* requires name bank file with 3177 lines */
char * name_gen() {
	File *fptr;
	fptr = fopen("docs/names", "r");
	if (fptr==NULL) {
		printf("Error: Could not open 'names' file\n");
		exit(1);
	}
	srand(time(NULL));
	int target_line = (rand()%3178);
	int curr_line= 1;
	char buff[256];
	while (fgets(buff, sizeof(buff), fptr) != NULL) {
		if (curr_line==target_line) {
			fclose(fptr);
			return buff;
		}
		curr_line++;
	}
	fclose(fptr);
	return "";
}
char * origin_gen() {
	srand(time(NULL));
	switch (rand() % 101) {
		case 1...40:
			return "Human";
		case 41...50:
			return "Fey-Blood";
		case 51...60:
			return "Duskling";
		case 61...75:
			return "Preen";
		case 76...90:
			return "Halfling";
		case 91...100:
			return "Feral";
	}
}

Hero * hero_init() {
	/* Allocate memory */
	Hero *new_hero = (Hero *)malloc(sizeof(Hero));
	if (new_hero==NULL) return NULL;
	/* Generate name */
	new_hero->name = strdup(name_gen());
	/* Generate origin */
	new_hero->origin = strdup(origin_gen());
	/* default stats */
	new_hero->agility = 1;
	new_hero->speed = 4;
	new_hero->dash = 3;
	new_hero->combat = 0;
	new_hero->toughness = 3;
	new_hero->luck=0;
	new_hero->will=0;
	new_hero->casting=0;
	new_hero->xp = 0;
	new_hero->lvl=0;
	/* initializing lists */
	new_hero->proficiencies=linkedlist_init();
	new_hero->skills=linkedlist_init();
	new_hero->spells=linkedlist_init();
	
	/* Do generators */
}