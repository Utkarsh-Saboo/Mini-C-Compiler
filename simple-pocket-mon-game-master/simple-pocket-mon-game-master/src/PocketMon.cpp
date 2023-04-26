/* 
 * April 30, 2018 - Made by KeonHeeLee :: https://github.com/KeonHeeLee/simple-pocket-mon-game
 * I want to refer this repositoy to understand FA (Finite Automata).
 * Thanks to remain this comment if you would use or refer this repository's source code.
 */

#define _CRT_SECURE_NO_WARNINGS

#include "PocketMon.h"
#include <string.h>

PocketMon::PocketMon() {

}

PocketMon::PocketMon(int HP, int damage, int avoid, char *name){
	this->HP = HP;
	this->damage = damage;
	this->avoid = avoid;
	strcpy(this->name,name);
}

PocketMon::PocketMon(const PocketMon &pkm){
	this->HP = pkm.HP;
	this->damage = pkm.damage;
	this->avoid = pkm.avoid;
	strcpy(this->name, pkm.name);
}

int PocketMon::getDamageByUser(int damage){
	this->HP -= damage;
	return this->HP;
}

int PocketMon::getAvoid(){
	return this->avoid;
}

int PocketMon::getHP(){
	return this->HP;
}

int PocketMon::getDamage(){
	return this->damage;
}

char *PocketMon::getName(){
	return this->name;
}

vector<skill> PocketMon::get_skillset(){
	return this->skill_set;
}