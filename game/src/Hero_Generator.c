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
			break;
		case 41...50:
			return "Fey-Blood";
			break;
		case 51...60:
			return "Duskling";
			break;
		case 61...75:
			return "Preen";
			break;
		case 76...90:
			return "Halfling";
			break;
		case 91...100:
			return "Feral";
			break;
	}
}
void townsfolk_gen(Hero * hero) {
	/* capabilities */
	/* mentality */
	/* possesions */
	/* training */
}
void noble_gen(Hero * hero) {
	/* capabilities */
	/* mentality */
	/* possesions */
	/* training */
}
void frontier_gen(Hero * hero) {
	/* capabilities */
	int roll = rand() % 21;
	switch (roll) {
		case 1...4:
			hero->agility++;
			break;
		case 5...8:
			hero->combat++;
			break;
		case 9...12:
			hero->speed+=2;
			break;
		case 13...16:
			hero->toughness++;
			break;
		case 17:
		case 18:
			hero->agility++;
			hero->combat++;
			break;
		case 19:
		case 20:
			hero->combat++;
			hero->toughness++;
			break;
	}
	/* mentality */
	roll = rand()%21;
	switch (roll) {
		case 1:
			hero->will++;
		case 2:
		case 3;
			hero->will++;
			break;
		case 4...16:
			hero->xp++;
			break;
		case 17:
		case 18:
			hero->luck++;
			break;
		case 19:
		case 20:
			hero->will++;
			hero->luck++;
			break;
	}
	/* possesions */
	roll = rand()%21;
	switch (roll) {
		case 1...4:
			linkedlist_add(hero->equipment, "gold");
			break;
		case 5...8:
			linkedlist_add(hero->equipment, "gold");
			linkedlist_add(hero->equipment, "gold");
			break;
		case 9...11:
			linkedlist_add(hero->equipment, "Quality Weapon");
			break;
		case 12...15:
			linkedlist_add(hero->equipment, "Fine Weapon");
			break;
		case 16...20:
			/* add item */
			linkedlist_add(hero->equipment, "item");
	}
	/* training */
	roll = rand()%21;
	switch (roll) {
		case 1...12:
			skill_gen(hero);
			break;
		case 13...15:
			skill_gen(hero);
			skill_gen(hero);
			break;
		case 16...20:
			hero->xp++;
			break;
	}
}
void zealot_gen(Hero * hero) {
	/* capabilities */
	/* mentality */
	/* possesions */
	/* training */
}
void outsider_gen(Hero * hero) {
	/* capabilities */
	/* mentality */
	/* possesions */
	/* training */
}
void mystic_gen(Hero * mystic) {
	/* capabilities */
	/* mentality */
	/* possesions */
	/* training */
}
void background_gen(Hero * hero) {
	switch (hero->origin) {
		case "Human":
			int pick = rand() % 5;
			switch (pick) {
				case 1:
					townsfolk_gen(hero);
					break;
				case 2;
					noble_gen(hero);
					break;
				case 3:
					frontier_gen(hero);
					break;
				case 4:
					zealot_gen(hero);
					break;
			}
			break;
		case "Feral":
		case "Fey-Blood":
		case "Duskling":
			outsider_gen(hero);
			break;
		case "Preen":
			townsfolk_gen(hero);
			break;
		case "Halfling":
			frontier_gen(hero);
			break;
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
	
	/* Add origin stuff */
	/* Background generator */
}