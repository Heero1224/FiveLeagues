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
void skill_gen(Hero * hero) {
	int roll = rand()%101;
	switch (roll) {
		case 1...7:
			linkedlist_add(hero->skills, "Battlewise");
			break;
		case 8...16:
			linkedlist_add(hero->skills, "Crafting");
			break;
		case 17...23:
			linkedlist_add(hero->skills, "Devotion");
			break;
		case 24...33:
			linkedlist_add(hero->skills, "Expertise");
			break;
		case 34...41:
			linkedlist_add(hero->skills, "Leadership");
			break;
		case 42...49:
			linkedlist_add(hero->skills, "Pathwise");
			break;
		case 50...56:
			linkedlist_add(hero->skills, "Scholar");
			break;
		case 57...65:
			linkedlist_add(hero->skills, "Scouting");
			break;
		case 66...75:
			linkedlist_add(hero->skills, "Speech");
			break;
		case 76...85:
			linkedlist_add(hero->skills, "Traveling");
			break;
		case 86...94:
			linkedlist_add(hero->skills, "Wilderness");
			break;
		case 95...100:
			linkedlist_add(hero->skills, "Wits");
			break;
	}
}
char * origin_gen() {
	int roll = rand() % 101;
	printf("Origin Roll: %d\n", roll);
	switch (roll) {
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
	int roll = rand()%21;
	printf("Townsfolk Roll: %d\n", roll);
	switch(roll){
		case 1...3:
			hero->agility++;
			break;
		case 4...7:
			hero->combat++;
			break;
		case 8...11:
			hero->speed+=2;
			break;
		case 12...14:
			hero->toughness++;
			break;
		case 15...17:
			hero->speed+=2;
			hero->combat++;
			break;
		case 18...20:
			hero->agility++;
			hero->speed+=2;
			break;
	}
	/* mentality */
	roll = rand()%21;
	switch (roll) {
		case 1:
			hero->will++;
		case 2...3:
			hero->will++;
			break;
		case 4...16:
			hero->xp++;
			break;
		case 19:
			hero->luck++;
		case 17:
		case 18:
			hero->luck++;
			break;
		case 20:
			hero->will++;
			hero->luck++;
			break;
	}
	/* possesions */
	roll = rand()%21;
	switch (roll) {
		case 6...11:
			linkedlist_add(hero->equipment, "gold");
		case 1...5:
			linkedlist_add(hero->equipment, "gold");
			linkedlist_add(hero->equipment, "gold");
			break;
		case 12...14:
			linkedlist_add(hero->equipment, "quality weapon");
			break;
		case 15...17:
			linkedlist_add(hero->equipment, "fine basic weapon");
			break;
		case 18...20:
			linkedlist_add(hero->equipment, "item");
			break;
	}
	/* training */
	roll = rand()%21;
	switch (roll) {
		case 8...10:
			skill_gen(hero);
		case 1...7:
			skill_gen(hero);
			breakl;
		case 11...20:
			hero->xp++;
			break;
	}
}
void noble_gen(Hero * hero) {
	int roll = rand() % 21;
	printf("Noble Roll: %d\n", roll);
	/* capabilities */
	switch (roll) {
		case 1...4:
			hero->agility++;
			break;
		case 5...9:
			hero->combat++;
			break;
		case 10...13:
			hero->speed+=2;
			break;
		case 14...16:
			hero->toughness++;
			break;
		case 17:
		case 18:
			hero->agility++;
			hero->combat++;
			break;
		case 19:
		case 20:
			hero->speed+=2;
			hero->combat++;
			break;
	}
	/* mentality */
	roll = rand() % 21;
	switch (roll) {
		case 1:
			hero->will++;
		case 2:
			hero->will++;
			break;
		case 3...16:
			hero->xp++;
			break;
		case 17:
		case 18:
			hero->luck++;
			break;
		case 19:
			hero->luck+=2;
			break;
		case 20:
			hero->will++;
			hero->luck++;
			break;
	}
	/* possesions */
	roll = rand() % 21;
	switch (roll) {
		case 1...4:
			linkedlist_add(hero->equipment, "gold");
			linkedlist_add(hero->equipment, "gold");
			break;
		case 5:
		case 6:
			linkedlist_add(hero->equipment, "gold");
			linkedlist_add(hero->equipment, "gold");
			linkedlist_add(hero->equipment, "gold");
			break;
		case 7...11:
			linkedlist_add(hero->equipment, "Quality Weapon");
			break;
		case 12...14:
			linkedlist_add(hero->equipment, "fine basic Weapon");
			break;
		case 15...17:
			linkedlist_add(hero->equipment, "Full Armor");
			break;
		case 18...20:
			linkedlist_add(hero->equipment, "item");
			break;
	}
	/* training */
	roll = rand() % 21;
	switch (roll) {
		case 1...6:
			skill_gen(hero);
			break;
		case 7:
			skill_gen(hero);
			skill_gen(hero);
			break;
		case 8...20:
			hero->xp++;
			break;
	}
}
void frontier_gen(Hero * hero) {
	int roll = rand() % 21;
	printf("Frontier Roll: %d\n", roll);
	/* capabilities */
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
	int roll = rand()%21;
	printf("Frontier Roll: %d\n", roll);
	/* capabilities */
	switch (roll) {
		case 1...4:
			hero->agility++;
			break;
		case 17:
		case 18:
			hero->toughness++;
		case 5...7:
			hero->combat++;
			break;
		case 19:
		case 20:
			hero->toughness++;
		case 8...11:
			hero->speed+=2;
			break;
		case 12...16:
			hero->toughness++;
			break;
		
	}
	/* mentality */
	roll = rand()%21;
	switch (roll) {
		
	}
	/* possesions */
	roll = rand()%21;
	switch (roll) {
		case 1...6:
			linkedlist_add(hero->equipment, "gold");
			break;
		case 7...10:
			linkedlist_add(hero->equipment, "basic weapon");
			break;
		case 11:
		case 12:
			linkedlist_add(hero->equipment, "quality weapon");
			break;
		case 13...20:
			linkedlist_add(hero->equipment, "item");
			break;
	}
	/* training */
	roll = rand()%21;
	switch (roll) {
		case 11:
		case 12:
			skill_gen(hero);
		case 1...10:
			skill_gen(hero);
			break;
		case 13...20:
			hero->xp++;
			break;
	}
}
void outsider_gen(Hero * hero) {
	int roll = rand()%21;
	printf("Frontier Roll: %d\n", roll);
	/* capabilities */
	switch (roll) {
		case 1...4:
			hero->agility++;
			break;
		case 5...9:
			hero->combat++;
			break;
		case 10...13:
			hero->speed+=2;
			break;
		case 14...16:
			hero->toughness++;
			break;
		case 17:
		case 18:
			hero->agility++;
			hero->combat++;
			break;
		case 19:
		case 20:
			hero->speed+=2;
			hero->combat++;
			break;
	}
	/* mentality */
	roll = rand() %21;
	switch (roll) {
		case 1:
		case 2:
			hero->will++;
			break;
		case 3...16:
			hero->xp++;
			break;
		case 17:
		case 18:
			hero->luck++;
			break;
		case 19:
			hero->luck+=2;
			break;
		case 20:
			hero->will++;
			hero->luck++;
			break;
	}
	/* possesions */
	roll = rand()%21;
	switch (roll) {
		case 1...6:
			linkedlist_add(hero->equipment, "gold");
			break;
		case 7:
		case 8:
			linkedlist_add(hero->equipment, "gold");
			linkedlist_add(hero->equipment, "gold");
			break;
		case 9...11:
			linkedlist_add(hero->equipment, "quality weapon");
			break;
		case 12...15:
			linkedlist_add(hero->equipment, "fine basic weapon");
			break;
		case 16...20:
			linkedlist_add(hero->equipment, "item");
			break;
	}
	/* training */
	roll = rand()%21;
	switch (roll) {
		case 7:
			skill_gen(hero);
		case 1...6:
			skill_gen(hero);
			break;
		case 8...20:
			hero->xp++;
			break;
	}
}
void mystic_gen(Hero * mystic) {
	int roll = rand()%21;
	printf("Frontier Roll: %d\n", roll);
	/* capabilities */
	switch (roll) {
		case 1...5:
			hero->agility++;
			break;
		case 6...13:
			hero->casting++;
			break;
		case 14...17:
			hero->speed+=2;
			break;
		case 18...20:
			hero->toughness++;
			break;
	}
	/* mentality */
	roll = rand() % 21;
	switch (roll) {
		case 1...5:
			hero->will++;
		case 6...9:
			hero->will++;
			break;
		case 10...20:
			hero->xp++;
			break;
	}
	/* possesions */
	roll = rand() % 21;
	switch (roll) {
		case 1...4:
			linkedlist_add(hero->equipment, "gold");
			break;
		case 5...14:
			linkedlist_add(hero->equipment, "mystic item");
			break;
		case 15...20:
			linkedlist_add(hero->equipment, "item");
			break;
	}
	/* training */
	roll = rand() % 21;
	switch (roll) {
		case 1...5:
			linkedlist_add(hero->skill, "alchemy");
			break;
		case 6...11:
			skill_gen(hero);
			break;
		case 12...20:
			hero->xp++;
			break;
	}
}
void background_gen(Hero * hero) {
	switch (hero->origin) {
		case "Human":
			int pick = rand() % 5;
			int roll = rand()%21;
			printf("Human Background Roll: %d\n", roll);
			switch (pick) {
				case 1:
					printf("\tTownsfolk\n");
					hero->background = "Townsfolk";
					townsfolk_gen(hero);
					break;
				case 2:
					printf("\tNoble\n");
					hero->background = "Noble";
					noble_gen(hero);
					break;
				case 3:
					printf("\tFrontier\n");
					hero->background = "Frontier";
					frontier_gen(hero);
					break;
				case 4:
					printf("\tZealot\n");
					hero->background = "Zealot";
					zealot_gen(hero);
					break;
			}
			break;
		case "Feral":
			printf("\tFeral\n");
			hero->background = "Outside";
			outsider_gen(hero);
			break;
		case "Fey-Blood":
			printf("\tFey-Blood\n");
			hero->background = "Outside";
			outsider_gen(hero);
			break;
		case "Duskling":
			printf("\tDuskling\n");
			hero->background = "Outside";
			outsider_gen(hero);
			break;
		case "Preen":
			printf("\tPreen\n");
			hero->background = "Townsfolk";
			townsfolk_gen(hero);
			break;
		case "Halfling":
			printf("\tHalfling\n");
			hero->background = "Frontier";
			frontier_gen(hero);
			break;
	}
}
Hero * hero_init() {
	/* Allocate memory */
	Hero *new_hero = (Hero *)malloc(sizeof(Hero));
	if (new_hero==NULL) return NULL;
	srand(time(NULL));
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
	
	/* Add origin stuff ? */
	/* Background generator */
	char * background[256];
	background = background_gen(hero);
}
