/*
* April 30, 2018 - Made by KeonHeeLee :: https://github.com/KeonHeeLee/simple-pocket-mon-game
* I want to refer this repositoy to understand FA (Finite Automata).
* Thanks to remain this comment if you would use or refer this repository's source code.
*/

#include "Skill.h"
#include <vector>
using namespace std;

class PocketMon{
private:
	int HP;
	int damage;
	int avoid;
	char name[30];
	vector<skill> skill_set;

public:
	PocketMon();
	PocketMon(int, int, int, char[]);
	PocketMon(const PocketMon &);
	int getDamageByUser(int);
	int getHP();
	int getAvoid();
	int getDamage();
	char *getName();
	vector<skill> get_skillset();

	void setSkillSet(skill sk){this->skill_set.push_back(sk);}
};