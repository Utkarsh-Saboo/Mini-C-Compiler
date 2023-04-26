/*
* April 30, 2018 - Made by KeonHeeLee :: https://github.com/KeonHeeLee/simple-pocket-mon-game
* I want to refer this repositoy to understand FA (Finite Automata).
* Thanks to remain this comment if you would use or refer this repository's source code.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <vector>
#include "PocketMon.h"
using namespace std;

class Game{
private:
	PocketMon myPocketMon;
	PocketMon com;

	int pika_01_cnt = 3; // 백만볼트 카운터
	int char_01_cnt = 3; // 불꽃 세례 카운터

	int originalComHP;
	int tempComHP;
	int random;
	int com_skill_set;

public:
	Game();
	void print_select();
	void run_skill(char *, char *);
	void print_game_over();
	void print_victory();

	void run();
};