/*
* April 30, 2018 - Made by KeonHeeLee :: https://github.com/KeonHeeLee/simple-pocket-mon-game
* I want to refer this repositoy to understand FA (Finite Automata).
* Thanks to remain this comment if you would use or refer this repository's source code.
*/

class skill {
private:
	int damage;
	char skill_name[30];
public:
	skill(int, char *);

	int get_damage();
	char *get_skill_name();
};