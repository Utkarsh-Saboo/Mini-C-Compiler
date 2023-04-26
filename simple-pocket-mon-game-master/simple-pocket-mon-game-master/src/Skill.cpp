/*
* April 30, 2018 - Made by KeonHeeLee :: https://github.com/KeonHeeLee/simple-pocket-mon-game
* I want to refer this repositoy to understand FA (Finite Automata).
* Thanks to remain this comment if you would use or refer this repository's source code.
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Skill.h"
#include <string.h>

skill::skill(int damage, char *skill_name){
	this->damage = damage;
	strcpy(this->skill_name, skill_name);
}

int skill::get_damage(){
	return this->damage;
}

char *skill::get_skill_name(){
	return this->skill_name;
}