/*
Filename: Hero_Henerator.h
Author: Joshua S. Andrews
Purpose: Generates a random hero
*/
typedef struct Hero {
	char * name;
	char * origin;
	char * background;
	// attributes
	int agility;
	int speed;
	int dash;
	int combat;
	int toughness;
	int luck;
	int will;
	int casting;
	LinkedList * proficiencies;
	LinkedList * skills;
	LinkedList * spells;
	LinkedList equipment;
	int xp;
	int lvl;
}Hero;

/* Create new template hero with base stats */
Hero * hero_init();
/* Generate hero attributes */
void hero_gen(Hero * hero);
/* Generate follower attributes */
void follower_gen(Hero * follower);
/* Remove all equipment from a Hero and return as LinkedList */
LinkedList * hero_remove_all(Hero * hero);
/* Equip an item to a hero and return 1 if failed, 0 if success*/
int hero_equip_item(Hero * hero, Item * item);
/* Unequip an item from Hero */
int hero_unequip_item(Hero * hero, Item * item);



